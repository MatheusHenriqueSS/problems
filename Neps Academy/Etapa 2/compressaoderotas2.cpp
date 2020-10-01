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
int n,m,pos[mxn][mxn],nxt[mxn][mxn],dp[mxn],lvl[mxn],pai[mxn];
vi g[mxn],path[mxn];
vector<pii>reg[mxn];
void dfs(int i,int p){
  for(int j:g[i])if(j!=p){
    lvl[j]=lvl[i]+1;
    pai[j]=i;
    dfs(j,i);
  }
}
void get_path(int u,int v,int i){
  vi a1,a2;
  while(v!=u){
    if(lvl[v]>lvl[u]){
      a2.pb(v);
      v=pai[v];
    }  
    else{
      a1.pb(u);
      u=pai[u];
    }
  }
  int j=0;
  for(int x:a1){
    pos[i][x]=++j;
    path[i].pb(x);
  }
  pos[i][u]=++j;
  path[i].pb(u);
  reverse(a2.begin(),a2.end());
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
    int a,b;cin>>a>>b;a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0,-1);
  cin>>m;
  int ans=0;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;a--;b--;
    get_path(a,b,i);
    ans+=pos[i][b]-pos[i][a]+1;
  }
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
      if(i==j)continue;
      int u=path[j][0],v=path[j].back();
      if(pos[i][u] && pos[i][v] && pos[i][u]<pos[i][v]){
        reg[i].pb({pos[i][u],pos[i][v]});
      }
    }
    sort(reg[i].begin(),reg[i].end());
    for(int j=0;j<sz(reg[i]);j++){
      auto it=upper_bound(reg[i].begin(),reg[i].end(),pii(reg[i][j].second,mxn));
      nxt[i][j]=it-reg[i].begin();
    }
    memset(dp,0,sizeof(dp));
    for(int j=sz(reg[i])-1;j>=0;j--){
      dp[j]=max(dp[j+1],dp[nxt[i][j]]+reg[i][j].second-reg[i][j].first);
    }
    ans-=dp[0];
  }
  cout<<ans;

  return 0;
}
