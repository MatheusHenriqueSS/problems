#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=1e6+5,M=1e9+7;
int mod(int a){int ret=a%M;if(ret<0)ret+=M;return ret;}
//did u check when n=1?
//is mxN correct?
int dp[mxN];
int n;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    dp[0]=1LL;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=6;j++){
            dp[i]=mod(dp[i]+(i-j>=0LL?dp[i-j]:0LL));
        }
    }
    cout<<dp[n];
}
