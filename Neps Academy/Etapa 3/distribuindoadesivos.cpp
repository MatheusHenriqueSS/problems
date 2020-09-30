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
const int mxn=2e3+5,M=1e9+7;
int dp[mxn][mxn];
int n,m,k;
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(i==1){
        if(j<=k)dp[i][j]=1;
      }
      else dp[i][j]=(dp[i][j]+(dp[i-1][j-1]-dp[i-1][j-min(j-1,k)-1]+M)%M)%M;
      dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
    }

  }
  cout<<(dp[m][n]-dp[m][n-1]+M)%M;
  return 0;
}
