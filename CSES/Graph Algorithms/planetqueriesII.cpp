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
int n,m,t;
int adj[mxN],p[mxN],sz[mxN],pos[mxN],id[mxN],vis[mxN],h[mxN],d[mxN],c[mxN];
int anc[mxN][30];
queue<int>q;
vector<int>adj1[mxN];
void dfs(int i){
    if(vis[i]==2)return;
    if(vis[i]==1){
        int cnt=1;
        id[i]=++t;
        pos[i]=cnt;
        int u=p[i];
        while(u!=i){
            id[u]=t;
            pos[u]=++cnt;
            u=p[u];
        }
        sz[t]=cnt;
        return;
    }
    vis[i]=1;
    int j=adj[i];
    p[j]=i;
    dfs(j);
    vis[i]=2;
}
void bfs(){
    while(!q.empty()){
        int i=q.front();
        q.pop();
        if(vis[i])continue;
        vis[i]=1;
        int cnt=0;
        for(int j:adj1[i]){
        if(!id[j]){ 
            h[j]=h[i];
            d[j]=d[i]+1;
            q.push(j);
        }
        }
 
    }
}
bool dfs1(int i,int dest){
    if(i==dest)return true;
    for(int j:adj1[i])if(dfs1(j,dest))return true;
    return false;
}
int solve(int a,int b){
    swap(a,b);
    return (pos[b]-pos[a]<0?pos[b]-pos[a]+sz[id[a]]:pos[b]-pos[a]);
}
int lca(int a,int b){
    for(int i=29;i>=0;i--){
        if(d[a]-(1<<i)>=d[b]){
            a=anc[a][i];
        }
    }
    if(a==b)return a;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>adj[i];
        anc[i][0]=adj[i];
        adj1[adj[i]].pb(i);
 
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++){
        if(id[i]){
            h[i]=i;
            q.push(i);
        }
    }
    bfs();
    for(int j=1;j<30;j++){
        for(int i=1;i<=n;i++){
            if(anc[i][j-1]){
                anc[i][j]=anc[anc[i][j-1]][j-1];
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        cout<<i<<"\n";
        for(int j=0;j<=10;j++)cout<<anc[i][j]<<" ";
        cout<<"\n";
    }*/
    //cout<<lca(6,4)<<"\n";
   while(m--){
        int a,b;cin>>a>>b;
        if(a==b){
            cout<<0<<"\n";
            continue;   
        }
        if(d[a] && d[b]){
            if(d[a]>d[b] && h[a]==h[b] && lca(a,b)==b){
                cout<<d[a]-d[b]<<"\n";
            }
            else cout<<-1<<"\n";
        }
        else if(id[b] && d[a] && id[h[a]]==id[b]){
            cout<<d[a]+solve(h[a],b)<<"\n";
        }
        else if(id[b] && id[a] && id[b]==id[a])cout<<solve(a,b)<<"\n";
        else cout<<-1<<"\n";
 
    }
 
 
    
}
