#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=3e3+5,inf=1e9+5;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?   
int n,m,g[mxn][mxn],dp[mxn][mxn][2];
int solve(int i,int j,int dir){
  if(i<0 || j<0 || i>=n || j>=m)return -inf;
  if(i==n-1 && j==m-1)return g[i][j];
  if(dp[i][j][dir]!=-1)return dp[i][j][dir];
  int ans=-inf;
  if(dir==0)ans=max(ans,g[i][j]+solve(i,j-1,dir));
  else ans=max(ans,g[i][j]+solve(i,j+1,dir));
  ans=max(ans,g[i][j]+solve(i+1,j,0));
  ans=max(ans,g[i][j]+solve(i+1,j,1));
  return dp[i][j][dir]=ans;
}
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  memset(dp,-1,sizeof(dp));
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cin>>g[i][j];
  }
  cout<<solve(0,0,1)<<"\n";
  return 0;
}
