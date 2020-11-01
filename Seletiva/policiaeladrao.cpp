/*Matheus Henrique de Sousa
Seletiva 2018 tentativa 0/100*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=1e5+5,mxl=20;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?   
int n,q,sz[mxn],anc[mxn][mxl],lvl[mxn],dp[mxn];
bool v[mxn];
vi g[mxn];
vector<pii> lf[mxn];
void dfs(int i,int p){
  for(int j:g[i])if(j!=p){
    lvl[j]=lvl[i]+1;
    anc[j][0]=i;
    dfs(j,i);
    dp[i]=max(dp[i],dp[j]+1);
  }
}
void dfs1(int i,int p,int pd){
  lf[i].pb({pd,p});
  for(int j:g[i])if(j!=p){
    lf[i].pb({dp[j]+1,j});
  }
  lf[i].pb({0,-1});
  sort(lf[i].begin(),lf[i].end(),greater<pii>());
  for(int j:g[i])if(j!=p)dfs1(j,i,1+(lf[i][0].second==j?lf[i][1].first:lf[i][0].first));
}
void init(){
  for(int j=1;j<mxl;j++){
    for(int i=1;i<=n;i++){
      if(anc[i][j-1])anc[i][j]=anc[anc[i][j-1]][j-1];
    }
  }
}
int lca(int u,int v){
  if(lvl[u]<lvl[v])swap(u,v);
  for(int i=mxl-1;i>=0;i--){
    if(lvl[u]-(1<<i)>=lvl[v])u=anc[u][i];
  }
  if(u==v)return u;
  for(int i=mxl-1;i>=0;i--){
    if(anc[u][i] && anc[v][i] && anc[u][i]!=anc[v][i]){
      u=anc[u][i];
      v=anc[v][i];
    }
  }
  return anc[u][0];
}
int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>q;
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(1,0);
  dfs1(1,0,0);
  init();
  while(q--){
    int a,b;cin>>a>>b;
    int l=lca(a,b);
    int ans=0;
    if(l==a){
      int d=lvl[b]-lvl[a];
      ans=max(ans,lf[b][0].second==anc[b][0]?lf[b][1].first:lf[b][0].first+lvl[b]-lvl[a]);
      int cur=b;
      for(int i=0;i<(d-1)/2;i++){
        cur=anc[cur][0];
        ans=max(ans,lf[cur][0].second==anc[cur][0]?lf[cur][1].first:lf[cur][0].first+lvl[cur]-lvl[a]);
      }
    }
    else if(l==b){
      int d=lvl[a]-lvl[b];
      int cur=a,last=-1;
      for(int i=0;i<d/2+1;i++){
        last=cur;
        cur=anc[cur][0];
      }
      while(cur!=1){
        ans=max(ans,lf[cur][0].second==last?lf[cur][1].first:lf[cur][0].first+lvl[a]-lvl[cur]);
        last=cur;
        cur=anc[cur][0];
      }
      ans=max(ans,lf[1][0].second==last?lf[1][1].first:lf[1][0].first+lvl[a]-lvl[1]);

    }
    else{
      int cur=a;
      while(lvl[b]-lvl[l]+lvl[cur]-lvl[l]>=lvl[a]-lvl[cur] && lvl[cur]>lvl[l])cur=anc[cur][0];
      while(cur!=l){
        ans=max(ans,)
      }

    }
    cout<<ans*2<<"\n";

  }  
  return 0;
}
