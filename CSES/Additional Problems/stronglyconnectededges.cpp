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
const int mxn=2e5+5;
int n,m,t,in[mxn],low[mxn];
vector<ii>ans;
vi g[mxn];
bool ok=true;
void dfs(int i,int p){
	in[i]=low[i]=++t;
	for(int j:g[i])if(j!=p){
		if(in[j]){
			if(in[j]<in[i])ans.pb({i,j});
			low[i]=min(low[i],in[j]);
		}
		else{
			dfs(j,i);
			ans.pb({i,j});
			low[i]=min(low[i],low[j]);
			if(low[j]>in[i]){
				ok=false;
				return;
			}
 
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//setIO("sort");
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		if(!in[i])ok=false;
	}
	if(!ok){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	for(ii p:ans)cout<<p.first<<" "<<p.second<<"\n";
	return 0;
}
