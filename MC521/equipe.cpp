#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=205,mxm=1030;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?   
int n,sk[2][mxn],dp[2][mxm][mxm],pot,k;
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  pot=(1<<k)-1;
  for(int i=0;i<n;i++){
    int j;cin>>j;
    sk[1][i]=pot;
    while(j--){
      int x;cin>>x;x--;
      sk[0][i]|=(1<<x);
      sk[1][i]^=(1<<x);
    }
  }
  for(int i=0;i<2;i++){
    for(int j=0;j<mxm;j++){
      for(int j1=0;j1<mxm;j1++){
        dp[i][j][j1]=mxn;
      }
    }
  }
  for(int i=n;i>=0;i--){
    for(int j=pot;j>=0;j--){
      for(int j1=pot;j1>=0;j1--){
        if(j==pot && j1==pot)dp[i&1][j][j1]=0;
        else{
          dp[i&1][j][j1]=min(dp[~i&1][j][j1],dp[~i&1][j|sk[0][i]][j1|sk[1][i]]+1);
        }
      }
    }
  }
  cout<<(dp[0][0][0]==mxn?-1:dp[0][0][0])<<"\n";

  return 0;
}
