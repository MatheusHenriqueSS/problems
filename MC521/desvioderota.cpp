#include<bits/stdc++.h>

#define INF 99999999
#define MAXN 300
using namespace std;
typedef pair<int,int> pii;

int n,m,c,k,u,v,p;
int vis[MAXN];
int dis[MAXN];
vector<pii> rot[MAXN];

void djikstra(int s){
    dis[s]=0;
    priority_queue<pii,vector<pii>,greater<pii>>fila;

    fila.push(pii(0,s));

    while(!fila.empty()){
        int dist=fila.top().first;
        int atual=fila.top().second;
        //cout<<dist<<" "<<atual<<"\n";
        fila.pop();

        if(!vis[atual]){


            if(atual<c){
                for(int i=0;i<rot[atual].size();i++){
                int d=rot[atual][i].first;
                int u=rot[atual][i].second;

                if(u==atual+1 && dis[u]>dist+d){
                    dis[u]=dist+d;
                    fila.push(pii(dis[u],u));
                }


            }

                }
            else{
                    for(int i=0;i<rot[atual].size();i++){
                int d=rot[atual][i].first;
                int u=rot[atual][i].second;
                //cout<<d<<" "<<u<<"\n";

                if( dis[u]>dist+d){
                    dis[u]=dist+d;
                    //cout<<"mudou\n";
                    fila.push(pii(dis[u],u));
                }


            }

            }

        }
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>n>>m>>c>>k && (n+m+c+k)){
        for(int i=0;i<n;i++){
            vis[i]=false;
            dis[i]=INF;
            rot[i].clear();


        }




        for(int i=0;i<m;i++){
            cin>>u>>v>>p;
            rot[u].push_back(pii(p,v));
            rot[v].push_back(pii(p,u));
        }
        djikstra(k);
        cout<<dis[c-1]<<"\n";
    }

}
