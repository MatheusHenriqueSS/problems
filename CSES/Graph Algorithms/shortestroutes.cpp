#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1e5+5,INF=1e18+7;
//did u check when n=1?
//is mxN correct?
int n,m;
int dist[mxN],vis[mxN];
vector<pii>adj[mxN];
void dji(){
    for(int i=0;i<n;i++)dist[i]=INF;
    dist[0]=0;
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,0});
    while(!q.empty()){
        int i=q.top().second;
        q.pop();
        if(vis[i])continue;
        vis[i]=true;
        for(pii p:adj[i]){
            int j=p.first;
            int d=p.second;
            if(dist[j]>dist[i]+d){
                dist[j]=dist[i]+d;
                q.push({dist[j],j});
            }
        }
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        adj[a].pb({b,c});
 
    }
    dji();
    for(int i=0;i<n;i++)cout<<dist[i]<<" ";
}
