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
int n,q,anc[mxN][20],lvl[mxN];
vi adj[mxN];
void dfs(int i,int p){
    for(int j:adj[i])if(j!=p){
        lvl[j]=lvl[i]+1;
        dfs(j,i);
    }
}
int lca(int u,int v){
    if(lvl[u]<lvl[v])swap(u,v);
    for(int j=19;j>=0;j--){
        if(lvl[u]-(1<<j)>=lvl[v]){
            u=anc[u][j];
        }
    }
    if(u==v)return u;
    for(int j=19;j>=0;j--){
        if(anc[u][j] && anc[u][j]!=anc[v][j]){
            u=anc[u][j];
            v=anc[v][j];
        }
    }
    return anc[u][0];
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;  
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        adj[x].pb(i);
        anc[i][0]=x;
    }
    dfs(1,0);
    for(int j=1;j<=19;j++){
        for(int i=1;i<=n;i++){
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
 
    while(q--){
        int a,b;cin>>a>>b;
        cout<<lca(a,b)<<"\n";
    }
}
