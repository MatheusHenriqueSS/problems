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
int n,m,pai[mxN],dp[mxN],vis[mxN];
vi adj[mxN];
void dfs(int i){
    dp[i]=(i==n)?1:-M;
    vis[i]=1;
    for(int j:adj[i]){
        if(!vis[j]){
            pai[j]=i;
            dfs(j);
        }
        if(dp[j]+1>dp[i]){
            dp[i]=dp[j]+1;
            pai[i]=j;
        }
    }
    
 
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
    }
    dfs(1);
    if(dp[1]<0)cout<<"IMPOSSIBLE";
    else{
        vi ans;
        ans.pb(1);
        int u=pai[1];
        while(u^n){
            ans.pb(u);
            u=pai[u];
        }
        ans.pb(n);
        cout<<sz(ans)<<"\n";
        for(int i:ans)cout<<i<<" ";
    }
    
}
