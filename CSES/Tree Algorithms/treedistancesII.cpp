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
int n;
int sz[mxN],pai[mxN],ans[mxN],dist[mxN];
vi adj[mxN];
void dfs(int i,int p){
    sz[i]=1;
    for(int j:adj[i]){
        if(j==p)continue;
        dist[j]=dist[i]+1;
        pai[j]=i;
        ans[1]+=dist[j];
        dfs(j,i);        
        sz[i]+=sz[j];
        
    }
}
void dfs2(int i,int p){
    //cout<<i<<" "<<p<<"\n";
    for(int j:adj[i]){
        if(j==p)continue;
        ans[j]=ans[i]-sz[j]+(n-sz[j]);  
        //cout<<i<<" "<<j<<" "<<ans[i]<<" "<<ans[j]<<"\n";
        dfs2(j,i);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,0);
    //cout<<ans[1]<<"\n";
    dfs2(1,0);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
 
}
