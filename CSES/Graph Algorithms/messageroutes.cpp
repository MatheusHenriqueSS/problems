#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,INF=1e18+7;
//did u check when n=1?
//is mxN correct?
int n,m;
int dist[mxN],pai[mxN],vis[mxN];
vector<int>adj[mxN];
void dji(){
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }
    dist[0]=0;
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,0});
    while(!q.empty()){
        int i=q.top().second;
        q.pop();
        if(vis[i])continue;
        vis[i]=true;
        for(int j:adj[i]){
            //int j=p.first;
            //int d=p.second;
            if(dist[j]>dist[i]+1){
                pai[j]=i;
                dist[j]=dist[i]+1;
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
        int a,b;cin>>a>>b;a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dji();
    if(dist[n-1]==INF){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    cout<<dist[n-1]+1<<"\n";
    stack<int>p;
    int temp=n-1;
    while(temp!=0){
        p.push(temp+1);
        temp=pai[temp];
    }
    p.push(1);
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
}
