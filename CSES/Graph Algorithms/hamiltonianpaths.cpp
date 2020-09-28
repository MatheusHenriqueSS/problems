#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=25,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m,tot;
int dp[1<<20][mxN];
vi adj[mxN];
int solve(int mask,int i){
    //cout<<mask<<" "<<i<<"\n";
    if(i==n-1){
        if(mask==tot)return dp[mask][i]=1;
        return dp[mask][i]=0;
    }
    if(dp[mask][i]!=-1)return dp[mask][i];
    int ans=0;
    for(int j:adj[i]){
        if(!(mask&(1<<j))){
            ans=(ans+solve(mask|(1<<j),j))%M;
        }
    }
    return dp[mask][i]=ans%M;
 
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    tot=(1<<n)-1;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].pb(b);
 
    }
    solve(1,0);
    cout<<dp[1][0]%M;
 
}
