#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define sz(x) int(x.size())
 
typedef pair<int,int>ii;
typedef vector<int> vi;
 
const int mxn = 1e5+5, inf = 1e9+10;
 
int n, q, arr[mxn],seg[4*mxn];
 
void upd(int pos,int val,int no = 1,int i = 0,int j = n-1){
	if(i == j){
		arr[i] = val;
		seg[no] = arr[i];
		return;
	}
 
	int m = (i+j)/2;
 
	if(pos <= m)upd(pos, val, 2*no, i, m);
	else upd(pos, val, 2*no + 1,m + 1, j);
 
	seg[no] = min(seg[2*no], seg[2*no + 1]);
}
 
int query(int p, int a, int b, int no = 1,int i = 0,int j = n-1){
	if( i > b || j < a) return 0;
	if( seg[no] > p)return 0;
	if(i == j){
		seg[no] = inf;
		return 1;
	}
 
	int m = (i+j)/2;
	
	int ans = query(p, a, b, 2*no, i, m) + query(p, a, b, 2*no + 1, m + 1, j);
	seg[no] = min(seg[2*no], seg[2*no + 1]);
	return ans;
	
}
 
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	for(int i = 0;i < 4*mxn;i++)seg[i] = inf;
 
	cin>>n>>q;
 
	while(q--){
		int op,i,j,p;cin>>op>>i>>j;
		if(op == 1)upd(i, j);
		else {
			j -= 1;
			cin>>p;
			cout<<query(p,i,j)<<"\n";
		}
	}
	return 0;
}
