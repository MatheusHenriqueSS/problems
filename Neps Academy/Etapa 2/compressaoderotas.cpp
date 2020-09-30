/*
Matheus Henrique de Sousa
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
const int mxn=1e3+5,M=1e9+7;
const int LINF=0x3f3f3f3f3f3f3f3f;
int n,m,pos[mxn][mxn],anc[mxn][20],lvl[mxn],dp[mxn];
vector<pii>reg[mxn],w;
vi g[mxn],ins[mxn],path[mxn];
bool v[mxn];
void dfs(int i){
  v[i]=1;
  for(int j:g[i])if(!v[j]){
    lvl[j]=lvl[i]+1;
    anc[j][0]=i;
    dfs(j);
  }
}
void init(){
  for(int j=1;j<20;j++){
    for(int i=1;i<=n;i++){
      if(anc[i][j-1])anc[i][j]=anc[anc[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v){
  if(lvl[u]<lvl[v])swap(u,v);
  for(int i=19;i>=0;i--){
    if(lvl[u]-(1<<i)>=lvl[v])u=anc[u][i];
  }
  if(u==v)return u;
  for(int i=19;i>=0;i--){
    if(anc[u][i] && anc[v][i] && anc[u][i]!=anc[v][i]){
      u=anc[u][i];
      v=anc[v][i];
    }
  }
  return anc[u][0];
}
void get_path(int u,int v,int i){
  int l=lca(u,v);
  vi a1,a2;
  int cur=u;
  while(cur!=l){
    a1.pb(cur);
    cur=anc[cur][0];
  }
  cur=v;
  while(cur!=l){
    a2.pb(cur);
    cur=anc[cur][0];
  }
  reverse(a2.begin(),a2.end());
  int j=0;
  for(int x:a1){
    pos[i][x]=++j;
    path[i].pb(x);  
  }
  path[i].pb(l);
  pos[i][l]=++j;
  for(int x:a2){
    pos[i][x]=++j;
    path[i].pb(x);
  }
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(1);
  init();
  cin>>m;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;
    w.pb({a,b});
    get_path(a,b,i);
  }
  int ans=0;
  for(int i=0;i<m;i++){
    for(int j=0;j<mxn;j++)ins[j].clear();
    for(int j=0;j<m;j++){
     if(i==j)continue;
     int u=w[j].first,v=w[j].second;
     if(pos[i][u] && pos[i][v] && pos[i][u]<pos[i][v]){
       if(pos[i][v]==pos[i][w[i].second])ins[u].pb(0);
       else ins[u].pb(path[i][pos[i][v]]);
     } 
    }
    memset(dp,0,sizeof(dp));
    dp[path[i].back()]=1;
    for(int j=sz(path[i])-2;j>=0;j--){
      int u=path[i][j];
      dp[u]=1+dp[path[i][j+1]];
      for(int v:ins[u]){
        dp[u]=min(dp[u],1+dp[v]);
      }
    }
    ans+=dp[path[i][0]];
  }
  cout<<ans;
  return 0;
}
