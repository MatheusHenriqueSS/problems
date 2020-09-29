#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define INF 0x3f3f3f3f
typedef pair<int,int>pii;
int n,m,a,b,t,o,ans;
int disc[MAXN],low[MAXN],dist[MAXN];

map<pii,bool>bri;
vector<int>adj[MAXN];

void tarjan(int u,int pai){
    disc[u]=low[u]=++t;

    for(int v:adj[u]){
        if(v==pai)continue;

        if(!disc[v]){
            tarjan(v,u);

            if(low[v]==disc[v]){
                bri[{u,v}]=1;
                bri[{v,u}]=1;
            }



        }
        low[u]=min(low[u],low[v]);



    }

}

void bfs(int u){
    for(int i=0;i<n;i++){
        dist[i]=INF;
    }
    dist[u]=0;
    ans=0;

    deque<int>fila;
    fila.push_front(u);
    while(!fila.empty()){
    u=fila.front();
    fila.pop_front();

    for(int v:adj[u]){
        bool k=bri[{u,v}];

        if(dist[v]>dist[u]+k){
            dist[v]=dist[u]+k;

            if(k)fila.push_back(v);
            else fila.push_front(v);
        }
    }


}
    for(int i=0;i<n;i++){
        if(dist[i]!=INF && dist[i]>ans){
            o=i;
            ans=dist[i];
        }
    }
}
int main(){

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    tarjan(0,-1);
    /*for(auto it=bri.begin();it!=bri.end();it++){
            pii p=it->first;
        cout<<p.first<<" "<<p.second<<" "<<it->second<<"\n";
    }*/

    bfs(o);
    bfs(o);
    cout<<ans<<"\n";



}
