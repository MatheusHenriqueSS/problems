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
int n,m;
vi g[mxn];
bool v[mxn];
vector<vi>ans;
int dfs(int i,int p){
	v[i]=1;
	vi aux;
	for(int j:g[i])if(j!=p){
		if(v[j]){
			if(i<j)aux.pb(j);
		}
		else if(dfs(j,i))aux.pb(j);
	}
	for(int k=0;k<sz(aux)-1;k+=2){
		ans.pb({aux[k],i,aux[k+1]});
	}
	if(sz(aux)%2==0)return 1;
	if(p)ans.pb({aux.back(),i,p});
	return 0;
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
	for(int i=1;i<=n;i++){
		if(!v[i]){
			dfs(i,0);
		}
	}
	cout<<sz(ans)<<"\n";
	for(vi res:ans)cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<"\n";
	return 0;
}
