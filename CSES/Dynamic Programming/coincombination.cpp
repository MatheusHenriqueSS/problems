#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=110,mxC=1e6+5,M=1e9+7;
int mod(int a){int ret=a%M;if(ret<0)ret+=M;return ret;}
//did u check when n=1?
//is mxN correct?
int n,x;
int v[mxN];
int dp[mxC];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    dp[0]=1LL;
    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            dp[i]=mod(dp[i]+(i-v[j]>=0?dp[i-v[j]]:0LL));
        }
    }
    cout<<dp[x];
}
