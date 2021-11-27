#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
 
typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=1e5+5,mod=1e9+7;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?   
// check long long
int add(int a,int b){
  return a+b>=mod?a+b-mod:a+b;
}
int sub(int a,int b){
  a-=b;
  if(a<0)a+=mod;
  return a;
}
int n,k,dp[105][mxn],a[mxn];
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<=k;j++){
      if(i==n-1){
        if(j<=a[i])dp[i][j]=1;
      }
      else{
        dp[i][j]=add(dp[i][j],sub(dp[i+1][max(0,j-a[i])],dp[i+1][j+1]));
      }
    }
    for(int j=k-1;j>=0;j--){
      dp[i][j]=add(dp[i][j],dp[i][j+1]);
    }
  }
  cout<<dp[0][k]<<"\n";
  return 0;
}
