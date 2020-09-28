#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=1e3+5,mxV=1e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,x;
int dp[2][mxV];
int val[mxN],peso[mxN];
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>peso[i];
    }
    for(int i=0;i<n;i++){
        cin>>val[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(!i || !j)dp[i&1][j]=0;
            if(peso[i-1]<=j){
                dp[i&1][j]=max(dp[~i&1][j],dp[~i&1][j-peso[i-1]]+val[i-1]);
            }
            else dp[i&1][j]=dp[~i&1][j];
        }
    }
       cout<<dp[n&1][x];
       
}
