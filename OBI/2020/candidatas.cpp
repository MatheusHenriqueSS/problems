// 19/09/2021 - Matheus Henrique
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) int(x.size())

typedef pair<int,int>ii;
typedef vector<int> vi;

const int mxn = 2e5+5;

int n, q, a[mxn];

int gcd(int a,int b){
	while(b) a %= b, swap(a,b);
	return a;
}

struct t{
	vector<ii> l,r;
	ll cnt = 0;
} seg[4*mxn];

void expand(vector<ii> &cur, const vector<ii> &add){
	int sz_init = cur.back().first;

	for(auto it : add){
		int sz = sz_init + it.first;
		if( it.second % cur.back().second == 0)cur.back().first = sz;
		else cur.pb({sz, gcd(it.second, cur.back().second)}); 
	}
}

t add(t a,t b){
	if(a.l.empty())return b;
	if(b.l.empty())return a;

	t ret;

	ret.l = a.l;
	ret.r = b.r;
	expand(ret.l,b.l);
	expand(ret.r,a.r);

	ret.cnt = a.cnt + b.cnt;

	int rt = (int)b.l.size()-1;

	for(int lt = 1; lt < (int)a.r.size(); lt++){
		while(rt > 0 && gcd(a.r[lt].second, b.l[rt].second) == 1) rt--;

		ret.cnt += (ll)(a.r[lt].first - a.r[lt-1].first) * b.l[rt].first;
	}

	return ret;
}


void build(int no = 1,int i = 0, int j = n - 1){
	if(i == j){
		seg[no].l = seg[no].r = {{0, 0}, {1, a[i]}};
		seg[no].cnt = (a[i] != 1) ? 1 : 0;

		return;
	}

	int mid = (i+j)/2;
	build(2*no, i, mid);
	build(2*no + 1, mid + 1, j);

	seg[no] = add(seg[2*no],seg[2*no + 1]);

}

void upd(int pos, int val, int no = 1,int i = 0,int j = n-1){
	if(i == j){
		a[i] = val;
		seg[no].l = seg[no].r = {{0,0}, {1, a[i]}};
		seg[no].cnt = (a[i] != 1) ? 1 : 0;

		return;
	}

	int mid = (i + j)/2;
	if(pos <= mid)upd(pos, val, 2*no, i, mid);
	else upd(pos, val, 2*no + 1,mid + 1,j);

	seg[no] = add(seg[2*no],seg[2*no + 1]);
}

t query(int a,int b,int no = 1,int i = 0,int j = n-1){
	//cout<<a<<" "<<b<<" "<<no<<" "<<i<<" "<<j<<" "<<"\n";
	t null;
	if(i > b || j < a)return null;
	if(a <= i && j <= b)return seg[no]; 

	int mid = (i+j)/2;

	return add(query(a, b, 2*no, i, mid), query(a, b, 2*no + 1, mid+1,j));
}



int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	cin>>n>>q;

	for(int i = 0;i < n;i++)cin>>a[i];

	build();

	/*for(int i = 0; i < 13;i++){
		cout<<i<<"\n";
		for(auto it: seg[i].l)cout<<it.first<<" "<<it.second<<" ";
		cout<<"\n";
		for(auto it : seg[i].r)cout<<it.first<<" "<<it.second<<" ";
		cout<<"\n";
		cout<<seg[i].cnt<<"\n";
		cout<<"\n";
	}*/

	while(q--){
		int op,i,j;cin>>op>>i>>j;
		if(op == 1)upd(i-1,j);
		else cout<<query(i-1,j-1).cnt<<"\n";
	}
	return 0;
}
