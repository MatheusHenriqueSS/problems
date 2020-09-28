#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m,pai[mxN],vis[mxN],ok;
vi adj[mxN],ans;
void dfs(int i,int p){
    if(ok)return;
    if(vis[i]==2)return;
    if(vis[i]==1){
        ok=1;
        int cur=p;        
        ans.pb(cur);
        while(cur!=i){
            cur=pai[cur];
            ans.pb(cur);
        }
        ans.pb(p);        
        return;
    }
    pai[i]=p;
    vis[i]=1;
    for(int j:adj[i]){
        if(j==pai[i])continue;
        dfs(j,i);
    }
    vis[i]=2;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,0);    
    }
    if(!ok)cout<<"IMPOSSIBLE";
    else{
        cout<<sz(ans)<<"\n";
        for(int i:ans)cout<<i<<" ";   
    }
}
