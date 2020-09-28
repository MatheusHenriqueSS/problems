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
int n,x;
int v[105];
int dp[105][mxN];
int mod(int a){int ret=a%M;if(ret<0)ret+=M;return ret;}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v+1,v+n+1);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(j==0)dp[i&1][j]=1;
            else if(i==0)dp[i&1][j]=0;
            else dp[i&1][j]=mod(dp[~i&1][j]+(j>=v[i]?dp[i&1][j-v[i]]:0LL));
        }
    }
    cout<<dp[n&1][x];
    
}
