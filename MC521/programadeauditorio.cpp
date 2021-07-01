#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=62505,mod=1e9+7;
bitset<250> tab[mxn];
int n,m,a[255];
bool dp[mxn];
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>n>>m;
  for(int i=0;i<n;i++)cin>>a[i];
  dp[0]=1;
  for(int i=n-1;i>=0;i--){
    for(int j=m;j>=a[i];j--)if(!dp[j]){
      if(dp[j-a[i]]){
        tab[j]=tab[j-a[i]];
        tab[j][i]=1;
        dp[j]=1;
      }
      if(dp[m])break;
    }
  }
  if(!dp[m]){
    cout<<"N\n";
    return 0;
  }
  cout<<"S\n";
  for(int i=0;i<n;i++){
    if(tab[m][i])cout<<i<<" ";
  }
  return 0;
}
