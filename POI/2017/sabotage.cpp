#include<bits/stdc++.h>
#include<fstream>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) int(x.size())

typedef pair<int,int>ii;
typedef vector<int> vi;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
const int mxn=5e5+5;
int sz[mxn],n,k;
bool c[mxn];
vi g[mxn];
double eps=0.0000001;
/*
* It's always optimal to the saboteur to be a leaf

*/
void dfs(int i,int p){
	for(int j:g[i])if(j!=p){
		dfs(j,i);
		sz[i]+=sz[j]+1;
	}
}
void dfs1(int i,int p,double x){
	int ma=0;
	for(int j:g[i])if(j!=p){
		dfs1(j,i,x);
		if(c[j])ma=max(ma,sz[j]+1);
	}
	if(!sz[i])c[i]=1;
	else{
		double tmp=(double) ma/(double)sz[i];
		if(tmp>=x)c[i]=1;
	}
}
bool check(double x){
	memset(c,0,sizeof(c));
	dfs1(1,0,x);
	int ans=0;
	for(int i=1;i<=n;i++)if(c[i]){
		ans=max(ans,sz[i]+1);
	}
	return ans<=k;
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//setIO("sort");
	cin>>n>>k;
	for(int i=2;i<=n;i++){
		int x;cin>>x;
		g[x].pb(i);
		g[i].pb(x);
	}
	dfs(1,0);
	double l=0,r=1.0;
	while(r-l>eps){
		double m=(l+r)/2.0;
		if(check(m))r=m;
		else l=m+eps;
	}
	cout<<setprecision(10)<<fixed<<l<<"\n";
	return 0;
}
/*
9 3
1
1
2
2
2
3
7
3*/
