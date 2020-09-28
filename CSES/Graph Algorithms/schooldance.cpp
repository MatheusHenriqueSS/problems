#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1005,M=1e9+7,INF=1e18+7;
//did u check when n=1?
//is mxN correct?
int n,m,k,adj[mxN][mxN],pai[mxN];
vi g[mxN];
vector<pii>ans;
bool vis[mxN];
int bfs(){
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    queue<pii>q;
    q.push({0,INF});
    while(!q.empty()){
        int i=q.front().first;
        int d=q.front().second;
        q.pop();
        if(i==n+m+1){
            int j=pai[i];
            while(i){
                adj[i][j]+=d;
                adj[j][i]-=d;
                i=j;
                j=pai[j];
            }
            return d;
        }
        for(int j:g[i]){
            if(!vis[j] && adj[i][j]){
                vis[j]=1;
                q.push({j,min(d,adj[i][j])});
                pai[j]=i;
            }
        }
 
    }
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int a,b;cin>>a>>b;
        b+=n;
        g[a].pb(b);
        g[b].pb(a);
        adj[a][b]=1;
    }
    for(int i=1;i<=n;i++){
        g[0].pb(i);
        g[i].pb(0);
        adj[0][i]=1;
    }
    for(int i=n+1;i<=n+m;i++){
        g[i].pb(n+m+1);
        g[n+m+1].pb(i);
        adj[i][n+m+1]=1;
    }
    int res=0;
    int cur=bfs();
    while(cur){
        res+=cur;
        cur=bfs();
 
    }
    //cout<<res;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        for(int j:g[i]){
            if(j>n && j<n+m+1 && !adj[i][j] && !vis[i] && !vis[j]){
                ans.pb({i,j-n});
                vis[i]=1;
                vis[j]=1;
            }
        }
    }
    cout<<sz(ans)<<"\n";
    for(pii p:ans)cout<<p.first<<" "<<p.second<<"\n";
    
}
