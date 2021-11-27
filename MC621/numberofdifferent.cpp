#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define pb push_back
#define sz(x) int(x.size())
 
typedef pair<int,int>ii;
typedef vector<int> vi;
 
const int mxn = 1e5+5;
 
int n, q, arr[mxn];
 
struct t{
	int cnt = 0;
	int cur[41] = {0};
} seg[4*mxn];
 
t add(t a,t b){
	if(!a.cnt)return b;
	if(!b.cnt)return a;
 
	t ret;
 
	ret.cnt = a.cnt + b.cnt;
 
	for(int i = 1; i <= 40; i++) if(a.cur[i] && b.cur[i]){
		ret.cnt --;
	}
 
	for(int i = 1; i <= 40; i++)ret.cur[i] = a.cur[i] + b.cur[i];
 
	return ret;
}
 
void build(int no = 1,int i = 0,int j = n-1){
	if(i == j){
		seg[no].cur[arr[i]] = 1;
		seg[no].cnt = 1;
 
		return;
	}
 
	int mid = (i+j)/2;
	build(2*no, i, mid);
	build(2*no + 1,mid + 1, j);
 
	seg[no] = add(seg[2*no], seg[2*no + 1]);
}
 
void upd(int pos, int val, int no = 1 , int i = 0,int j = n-1){
	if(i == j){
		arr[i] = val;
		for(int k = 1; k <= 40;k++)seg[no].cur[k] = 0;
		seg[no].cur[arr[i]] = 1;
 
		return;
	}
 
	int mid  = (i+j)/2;
	if(pos <= mid)upd(pos, val, 2*no, i, mid);
	else upd(pos, val, 2*no + 1, mid + 1, j);
 
	seg[no] = add(seg[2*no], seg[2*no + 1]);
 
}
 
t query(int a,int b,int no = 1,int i = 0,int j = n-1){
	t null;
	if(i > b || j < a)return null;
	if(a <= i && j <= b)return seg[no];
 
	int mid = (i+j)/2;
 
	return add(query(a, b, 2*no, i, mid),query(a, b, 2*no + 1, mid + 1, j)); 
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
 
	cin>>n>>q;
 
	for(int i = 0;i < n;i++)cin>>arr[i];
 
	build();
 
	while(q--){
		int op,i,j;cin>>op>>i>>j;
		if(op == 1)cout<<query(i-1,j-1).cnt<<"\n";
		else upd(i-1, j);
	}
	return 0;
}
