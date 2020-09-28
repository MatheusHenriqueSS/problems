#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=505,M=1e9+7,INF=1e18+7;
//did u check when n=1?
//is mxN correct?
int n,m,pai[mxN],adj[mxN][mxN],e[mxN][mxN];
vi g[mxN],ans[mxN],g1[mxN];
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
        for(int j:g[i]){
            if(!vis[j] && adj[i][j]){
                vis[j]=1;
                pai[j]=i;
                q.push({j,min(d,adj[i][j])});
                if(j==n-1)return min(d,adj[i][j]);
            }
        }
    }
    return 0;
}
void dfs(int i=0){
    if(i==n-1)return;
    for(int j:g1[i]){
        //cout<<i<<" "<<j<<" "<<e[i][j]<<"\n";
        if(!e[i][j] && !adj[i][j]){
            e[i][j]=1;
            pai[j]=i;
            return dfs(j);
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;a--;b--;
        g[a].pb(b);
        g[b].pb(a);
        g1[a].pb(b);
        adj[a][b]=1;
    }
    int res=0;
    int cur=bfs();
    while(cur){
        res+=cur;
        int i=n-1;
        int j=pai[i];
        while(i){
            adj[i][j]+=cur;
            adj[j][i]-=cur;
            i=j;
            j=pai[j];
 
        }
        cur=bfs();
    }
    cout<<res<<"\n";
    for(int k=0;k<res;k++){
        dfs();
        int i=n-1;
        int j=pai[i];
        while(i){
            ans[k].pb(i);
            i=j;
            j=pai[j];
 
        }
        ans[k].pb(0);
        reverse(ans[k].begin(),ans[k].end());
        cout<<sz(ans[k])<<"\n";
        for(int i:ans[k])cout<<i+1<<" ";
        cout<<"\n";
    }
 
}
