#include<bits/stdc++.h>
#define MAXN 1010
using namespace std;
typedef pair<int,int>pii;
 
int n,m,lvl=0;
char matriz[MAXN][MAXN];
int vis[MAXN][MAXN];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
 
void bfs(int x,int y){
    queue<pii>fila;
    fila.push(pii(x,y));
 
    while(!fila.empty()){
        int i=fila.front().first;
        int j=fila.front().second;
        fila.pop();
 
        if(!vis[i][j]){
            vis[i][j]=lvl;
            for(int k=0;k<4;k++){
                int i2=i+dx[k];
                int j2=j+dy[k];
 
                if(i2<n && j2<m && min(i2,j2)>=0 && matriz[i2][j2]=='.' && !vis[i2][j2] ){
                    fila.push(pii(i2,j2));
                }
            }
        }
 
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
     memset(vis,0,sizeof(vis));
 
    cin>>n>>m;
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matriz[i][j];
        }
    }
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matriz[i][j]=='.' && !vis[i][j] ){
                lvl++;
 
                bfs(i,j);
 
            }
        }
    }
 
    cout<<lvl<<"\n";
 
 
}
