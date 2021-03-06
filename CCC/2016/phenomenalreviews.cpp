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

const int mxn=1e5+5;
int r[mxn],n,m,t,ans,a[mxn];
vi g[mxn];
void dfs(int i,int p){
	for(int j:g[i])if(j!=p){
		dfs(j,i);
		r[i]|=r[j];//is there any restaurant until we get to the leaf?
	}
}
void dfs1(int i,int p){
	t++;//number of vertices in the "restaurant tree"
	int ma=0;
	for(int j:g[i])if(j!=p && r[j]){
		dfs1(j,i);
		ans=max(ans,ma+a[j]);
		ma=max(ma,a[j]);
	}
	a[i]=ma+1;
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//setIO("sort");
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x;cin>>x;r[x]=1;
	}
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i=0;i<n;i++)if(r[i]){
		dfs(i,-1);
		break;
	}
	for(int i=0;i<n;i++)if(r[i]){
		dfs1(i,-1);
		break;
	}
	cout<<2*(t-1)-ans<<"\n";
	return 0;
}
