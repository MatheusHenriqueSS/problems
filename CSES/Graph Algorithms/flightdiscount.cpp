#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef pair<int,pii>ii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1e5+5,INF=1e18+7;
//did u check when n=1?
//is mxN correct?
int n,m,dist[2][mxN],vis[2][mxN];
vector<pii>adj[mxN];
void dji(){
    for(int i=1;i<=n;i++)dist[0][i]=dist[1][i]=INF;
    dist[0][1]=0;
    dist[1][1]=0;
    priority_queue<ii,vector<ii>,greater<ii>>q;
    q.push({0,{1,0}});
    while(!q.empty()){
        int i=q.top().second.first;
        int ok=q.top().second.second;
        int w=q.top().first;
        q.pop();
        if(vis[ok][i])continue;
        vis[ok][i]=1;
        //cout<<i<<" "<<ok<<" "<<w<<"\n";
        for(pii p:adj[i]){
            int j=p.first;
            int d=p.second;
            
            if(ok==1){
                //se eu já usei o desconto
                if(dist[1][j]>w+d){
                    dist[1][j]=w+d;
                    q.push({dist[1][j],{j,1}});
                }
            }
            else{
                if(dist[0][j]>w+d){
                    dist[0][j]=w+d;
                    q.push({dist[0][j],{j,0}});
                }
                if(dist[1][j]>w+d/2){
                    dist[1][j]=w+d/2;
                    q.push({dist[1][j],{j,1}});
                }
            }
        }
    }
   
   
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({b,c});
    }
    dji();
   // cout<<dist[n]-(ma[n]+1)/2;
   cout<<dist[1][n];   
}
