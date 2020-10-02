/*
Matheus Henrique de Sousa
OBI 2014-p2f2-mapa
*/
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

#define ll long long
#define int long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxn=2e5+5,M=1e9+7;
const int LINF=0x3f3f3f3f3f3f3f3f;
int n,ans[mxn],sz[mxn];
vector<pii>g[mxn];
void dfs(int i,int pai){
  sz[i]=1;
  for(pii p:g[i])if(p.first!=pai){
    dfs(p.first,i);
    sz[i]+=sz[p.first];
    if(p.second)ans[i]+=sz[p.first];
    else ans[i]+=ans[p.first];
  }
}
void dfs1(int i,int pai){
  for(pii p:g[i])if(p.first!=pai){
    if(!p.second)ans[p.first]=ans[i];
    else ans[p.first]+=n-sz[p.first];
    dfs1(p.first,i);
  }
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b,c;cin>>a>>b>>c;a--;b--;
    g[a].pb({b,c});
    g[b].pb({a,c});
  }
  dfs(0,-1);
  dfs1(0,-1);
  int res=0;
  for(int i=0;i<n;i++)res+=ans[i];
  cout<<res/2;
  return 0;
}
