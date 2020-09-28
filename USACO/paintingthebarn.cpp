/*
Matheus Henrique de Sousa
painting the barn
9.22.20
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
int n,k;
int dp[mxn][mxn];
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("paintbarn");
  cin>>n>>k;
  while(n--){
    int i,j,i1,j1;
    cin>>i>>j>>i1>>j1;
    dp[i][j]++;
    dp[i][j1]--;
    dp[i1][j]--;
    dp[i1][j1]++;
  }
  int ans=0;
  for(int i=0;i<=1000;i++){
    for(int j=0;j<=1000;j++){
      if(i)dp[i][j]+=dp[i-1][j];
      if(j)dp[i][j]+=dp[i][j-1];
      if(i && j)dp[i][j]-=dp[i-1][j-1];
      if(dp[i][j]==k)ans++;
    }
  }
  cout<<ans;
  return 0;
}
