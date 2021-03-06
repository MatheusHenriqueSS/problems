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
int n,m,a[mxn],lvl[mxn];
vi g[mxn];
vector<ii>ans;
void dfs(int i,int p){
	for(int j:g[i])if(j!=p){
		if(!lvl[j]){
			lvl[j]=lvl[i]+1;
			dfs(j,i);
			if(a[j]&1){
				ans.pb({j,i});
				a[j]++;
			}
			else{
				ans.pb({i,j});
				a[i]++;
			}
		}
		else if(lvl[j]<lvl[i]){
			ans.pb({i,j});
			a[i]++;
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//setIO("sort");
	cin>>n>>m;
	if(m&1){
		cout<<"IMPOSSIBLE\n";
		return 0;
	}
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		if(!lvl[i]){
			lvl[i]=1;
			dfs(i,0);
		}
		if(a[i]&1){
			cout<<"IMPOSSIBLE\n";
			return 0;
		}
	}
	for(ii p:ans)cout<<p.first<<" "<<p.second<<"\n";
	return 0;
}
