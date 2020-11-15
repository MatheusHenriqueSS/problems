/*
Matheus Henrique de Sousa
Seletiva 2017 - tribo
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=1e4+5,inf=5e8+100;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?   
int n,k,dp[mxn][55];
vector<pii>g[mxn];
vi aux;
bool v[mxn];
void dfs(int i,int pa){
  for(pii p:g[i])if(p.second!=pa){
    dfs(p.second,i);
  }
  aux.pb(i);
}
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;k--;
  for(int i=0;i<n-1;i++){
    int a,b,c;cin>>a>>b>>c;a--;b--;
    g[a].pb({c,b});
    g[b].pb({c,a});
  }
  dfs(0,-1);
  for(int i=0;i<mxn;i++){
    for(int j=0;j<=50;j++){
      dp[i][j]=inf;
    }
  }
  for(int i:aux){
    dp[i][0]=0;
    for(pii p:g[i])if(v[p.second]){
      for(int j=k;j>=1;j--){
        for(int j1=1;j1<=j;j1++){
          //if(i==1)cout<<p.second<<" "<<j<<" "<<j1<<" "<<p.first<<" "<<dp[i][j]<<" "<<dp[p.second][j1-1]<<" "<<dp[i][j-j1]<<"\n";
          dp[i][j]=min(dp[i][j],dp[p.second][j1-1]+p.first+dp[i][j-j1]);
          //if(i==1)cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
        }
      }
    }
    v[i]=1;
  }
  int ans=inf;
  //for(int i=0;i<n;i++)cout<<i<<" "<<dp[i][k]<<"\n";
  for(int i=0;i<n;i++){
    ans=min(dp[i][k],ans);
  }
  cout<<ans<<"\n";
  return 0;
}
