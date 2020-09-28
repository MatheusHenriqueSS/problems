#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7,INF=1e18;
//did u check when n=1?
//is mxN correct?
int n,dist[mxN],st,ans,vis[mxN];
vi adj[mxN];
int bfs(){
    memset(vis,0,sizeof(vis));
    memset(dist,0,sizeof(dist));
    vis[st]=1;
    queue<int>q;
    q.push(st);
    while(!q.empty()){
        int i=q.front();
        q.pop();
        vis[i]=1;
        for(int j:adj[i]){
            if(!vis[j]){
                dist[j]=dist[i]+1;
                q.push(j);
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i]>ans){
            ans=dist[i];
            st=i;
        }
    }
 
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs();
    bfs();
    cout<<ans;
}
