#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7,INF=1e18+7;
//did u check when n=1?
//is mxN correct?
int n,m,dist[mxN],vis[mxN],dp[mxN],dp1[mxN],dp2[mxN];
vi adj[mxN];
vector<pii>adj2[mxN];
void dji(){
    for(int i=1;i<=n;i++)dist[i]=INF;
    dist[1]=0;
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,1});
    while(!q.empty()){
        int i=q.top().second;
        q.pop();
        if(vis[i])continue;
        vis[i]=1;
        for(pii p:adj2[i]){
            int j=p.second;
            int d=p.first;
            if(dist[j]>dist[i]+d){
                dist[j]=dist[i]+d;
                q.push({dist[j],j});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(pii p:adj2[i]){
            int j=p.second;
            int d=p.first;
            if(dist[i]+d==dist[j])adj[i].pb(j);
        }
    }
}
int dfs(int i){
    if(i==n)return 1;
    if(dp[i]!=-1)return dp[i];
    int ans=0;
    for(int j:adj[i]){
        ans=(ans+dfs(j))%M;
    }
    return dp[i]=ans%M;
 
}
int dfs1(int i){
    if(i==n)return dp1[i]=0;
    if(dp1[i]!=-M)return dp1[i];
    for(int j:adj[i]){
        dp1[i]=max(dp1[i],dfs1(j)+1);
    }
    return dp1[i];
}
int dfs2(int i){
    if(i==n)return dp2[i]=0;
    if(dp2[i]!=M)return dp2[i];
    for(int j:adj[i]){
        dp2[i]=min(dp2[i],dfs2(j)+1);
    }
    return dp2[i];
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        adj2[a].pb({c,b});
    }
    for(int i=1;i<=n;i++)dp1[i]=-M;
    for(int i=1;i<=n;i++)dp2[i]=M;
    dji();
    dfs(1);
    dfs1(1);
    dfs2(1);
    cout<<dist[n]<<" "<<dp[1]<<" "<<dp2[1]<<" "<<dp1[1]<<"\n";  
}
