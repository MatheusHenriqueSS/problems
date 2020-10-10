/*
Matheus Henrique de Sousa
obi 2019 - sf1 - sequência
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
const int mxn=1e5+5,M=1e9+7;
const int LINF=0x3f3f3f3f3f3f3f3f;
int n,l,h;
int dp[mxn][25],a[mxn],b[mxn];
//dp[i][j]=best in indice i with j itens marked
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  for(int i=0;i<mxn;i++){
    for(int j=0;j<25;j++)dp[i][j]=-M;
  }
  cin>>n>>l>>h;
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  if(b[0]){
    dp[0][0]=0;
    dp[0][1]=a[0];
  }
  else dp[0][0]=max(a[0],0LL);
  for(int i=1;i<n;i++){
    for(int j=0;j<=h;j++){
      if(b[i]){
        if(!j)dp[i][j]=0LL;
        else if(dp[i-1][j-1]!=-M)dp[i][j]=dp[i-1][j-1]+a[i];
      }
      else{
        if(!j)dp[i][j]=max(0LL,dp[i-1][j]+a[i]);
        else if(dp[i-1][j]!=-M)dp[i][j]=dp[i-1][j]+a[i];
      }
    }
  }
  int ans=-M;
  for(int i=0;i<n;i++){
    for(int j=l;j<=h;j++)ans=max(ans,dp[i][j]);
  }
  cout<<ans<<"\n";
  return 0;
}
