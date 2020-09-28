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
int vis[mxN];
vi ans,adj[mxN];
void dfs(int i){
    if(vis[i])return;
    vis[i]=t;
    for(auto j:adj[i])dfs(j);
 
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
        if(!vis[i]){
            ans.pb(i+1);
            t++;
            dfs(i);
 
        }
    }
    cout<<t-1<<"\n";
    for(int i=0;i<t-1;i++){
        cout<<ans[i]<<" "<<ans[i+1]<<"\n";
    }
}
