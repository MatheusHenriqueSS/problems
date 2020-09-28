#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=1e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m,v[mxN];
int dp[mxN][105];
int mod(int a){int ret=a%M;if(ret<0)ret+=M;return ret;}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    if(v[0]==0){
        for(int i=1;i<=m;i++){
            dp[0][i]=1;
        }
    }
    else{
        dp[0][v[0]]=1;
    }
    for(int i=1;i<n;i++){
        if(v[i]!=0){
            dp[i][v[i]]=mod(dp[i-1][v[i]-1]+mod(dp[i-1][v[i]]+dp[i-1][v[i]+1]));
        }
        else{
            for(int j=1;j<=m;j++){
                dp[i][j]=mod(dp[i-1][j-1]+mod(dp[i-1][j]+dp[i-1][j+1]));
            }
        }
    }
    int ans=0LL;
    for(int i=1;i<=m;i++){
        ans=mod(ans+dp[n-1][i]);
    }
    cout<<ans;
 
}
