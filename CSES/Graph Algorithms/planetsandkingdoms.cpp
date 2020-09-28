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
int n,m,vis[mxN],ans[mxN],t;
vi adj[mxN],adj1[mxN],aux;
void dfs(int i){
    if(vis[i])return;
    vis[i]=1;
    for(int j:adj[i]){
        dfs(j);
    }
    aux.pb(i);
}
void dfs1(int i){
    if(ans[i])return;
    ans[i]=t;
    for(int j:adj1[i])dfs1(j);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    while(m--){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj1[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i);
    }
    reverse(aux.begin(),aux.end());
    for(int i:aux){
        if(!ans[i]){
            t++;
            dfs1(i);
        }
    }
    cout<<t<<"\n";
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
