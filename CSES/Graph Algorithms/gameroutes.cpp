#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m,dp[mxN];
vi adj[mxN];
int dfs(int i){
    if(i==n)return 1;
    if(dp[i]!=-1)return dp[i];
    int ans=0;
    for(int j:adj[i]){
        ans=(ans+dfs(j))%M;
    }
    return dp[i]=ans%M;
 
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
    }
    dfs(1);
    cout<<dp[1]%M;
}
