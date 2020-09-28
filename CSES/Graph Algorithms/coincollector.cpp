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
int n,m,vis[mxN],ans[mxN],scc[mxN],val[mxN],t;
vi adj[mxN],adj1[mxN],adj2[mxN],aux;
void dfs(int i){
    if(vis[i])return;
    vis[i]=1;
    for(int j:adj[i]){
        dfs(j);
    }
    aux.pb(i);
}
void dfs1(int i){
    if(scc[i])return;
    scc[i]=t;
    for(int j:adj1[i]){
        if(scc[j] && scc[j]!=scc[i]){
            adj2[scc[j]].pb(scc[i]);
            //*
        }
        dfs1(j);
    }
}
int solve(int i){
    if(vis[i])return ans[i];
    vis[i]=1;
    int res=0;
    for(int j:adj2[i])res=max(res,solve(j));
    return ans[i]+=res;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>val[i];
    while(m--){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].pb(b);
        adj1[b].pb(a);
    }
    for(int i=0;i<n;i++){
        if(!vis[i])dfs(i);
    }
    reverse(aux.begin(),aux.end());
    for(int i:aux){
        if(!scc[i]){
            t++;
            dfs1(i);
        }
    }
    for(int i=0;i<n;i++)ans[scc[i]]+=val[i];
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=t;i++){
        if(!vis[i])solve(i);
    }
    int res=0;
    for(int i=1;i<=t;i++)res=max(res,ans[i]);
    cout<<res;
    
    
}
