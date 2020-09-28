#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
typedef pair<int,int>pii;
const int mxN=2e5,M=1e9+7;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
ll resp;
int vis[10][10];
string s;
void dfs(int x,int y,int v=0){
    //cout<<x<<" "<<y<<" "<<v<<"\n";
    if((vis[x][y])|| ((x>0 && x<6) && ((y==0 && !vis[x+1][y] && !vis[x-1][y] && vis[x][y+1])||
    (y==6 && !vis[x+1][y] && !vis[x-1][y] && vis[x][y-1]) ))||((y>0 && y<6)&&((x==0 && !vis[x][y-1] && !vis[x][y+1] && vis[x+1][y])||
    (x==6 && !vis[x][y-1] && !vis[x][y+1] && vis[x-1][y])))||((x>0 && x<6 && y>0 && y<6)&&(vis[x][y+1]&& vis[x][y-1] && !vis[x-1][y] && !vis[x+1][y])
    )||((x>0 && x<6 && y>0 && y<6)&&(vis[x+1][y]&& vis[x-1][y] && !vis[x][y+1] && !vis[x][y-1])
    ))return;
    if(x==6 && y==0){
        if(v==48)resp++;
        return;        
    }
    vis[x][y]=true;
    
     
    if(x>0 && !vis[x -1][y]){
        if(s[v]=='U'||s[v]=='?')dfs(x-1,y,v+1);
    }
    if(x<6 && !vis[x+1][y]){
        if(s[v]=='D'||s[v]=='?')dfs(x+1,y,v+1);
    }
    if(y>0 && !vis[x][y-1]){
        if(s[v]=='L'||s[v]=='?')dfs(x,y-1,v+1);
    }
    if(y<6 && !vis[x][y+1]){
        if(s[v]=='R'||s[v]=='?')dfs(x,y+1,v+1);
    }
    
    vis[x][y]=false;



//cout<<resp<<"\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    dfs(0,0);
    cout<<resp;


}
