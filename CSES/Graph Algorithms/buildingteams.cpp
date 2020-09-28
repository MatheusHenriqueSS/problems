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
int n,m;
int col[mxN],vis[mxN];
vector<int> adj[mxN];
void dfs(int x,int l=0){
    if(vis[x])return;
    vis[x]=true;
    col[x]=l^1;
    for(int u:adj[x]){
        dfs(u,col[x]);
    }
 
}   
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=0;i<n;i++){
        if(!vis[i])dfs(i);
    }
    for(int i=0;i<n;i++){
        for(int u:adj[i])if(col[u]==col[i]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    for(int i=0;i<n;i++)cout<<col[i]+1<<" ";
 
 
}
