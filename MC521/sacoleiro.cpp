#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=305,inf=205;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?   
int n,m,cost[35],f[35],ans=105;
int v[35][105][105];
vi g[35];
int dfs(int i,int a,int b){
  v[i][a][b]=1;
  ans=min(ans,abs(a-b)+(a+b==0)*505);
  for(int j:g[i]){
    if(!v[j][a][b])dfs(j,a,b);
  }
  for(int cur=1;1;cur++){
    if(a+b+cur*cost[i]>m)break;
    int na=a,nb=b;
    if(!f[i]){
      if(!v[i][a+cur*cost[i]][b])dfs(i,a+cur*cost[i],b);
    }
    else{
      if(!v[i][a][b+cur*cost[i]]) dfs(i,a,b+cur*cost[i]);
    }
  }
  return ans;
}
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m;
  while(n--){
    int i,k;char c;
    cin>>i;
    cin>>cost[i]>>c;
    f[i]=(c-'A');
    cin>>k;
    while(k--){
      int j;cin>>j;
      g[i].pb(j);
    }
  }
  cout<<dfs(0,0,0);
  return 0;
}
