/*
Matheus Henrique de Sousa
Seletiva 2017 - cabo de guerra
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=2505;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?
int n,w[mxn],dp[55][55][mxn],tot;
int solve(int i,int cnt,int sum){
  if(i==n){
    if(cnt!=n/2)return 100000000;
    return abs(tot-2*sum);
  }
  if(dp[i][cnt][sum]!=-1)return dp[i][cnt][sum];
  return dp[i][cnt][sum]=min(solve(i+1,cnt+1,sum+w[i]),solve(i+1,cnt,sum));

}
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  memset(dp,-1,sizeof(dp)); 
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>w[i];tot+=w[i];
  }
  cout<<solve(0,0,0)<<"\n";

  return 0;
}
