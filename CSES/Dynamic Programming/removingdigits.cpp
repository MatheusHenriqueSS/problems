#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=1e6+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,dp[mxN];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]=mxN;
        int x=i;
        while(x>0){
            int temp=x%10;
            dp[i]=min(dp[i],dp[i-temp]+1);
            x/=10;
        }
    }
    cout<<dp[n];
}
