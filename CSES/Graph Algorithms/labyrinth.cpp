#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1e3+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m,xi,yi,xf,yf;
int vis[mxN][mxN];
pii pai[mxN][mxN];
char g[mxN][mxN];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void bfs(){
    queue<pii>q;
    q.push({xi,yi});
    vis[xi][yi]==1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(g[x][y]=='B')return;
        for(int i=0;i<4;i++){
            int x2=x+dx[i];
            int y2=y+dy[i];
            if(x2>=0 && x2<n && y2>=0 && y2<m){
                if(!vis[x2][y2] && g[x2][y2]!='#'){
                    vis[x2][y2]=1;
                    pai[x2][y2]={x,y};
                    q.push({x2,y2});
                }
            }
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
            if(g[i][j]=='A'){
                xi=i;
                yi=j;
            }
            if(g[i][j]=='B'){
                xf=i;
                yf=j;
            }
        }
    }
    bfs();
    
    if(vis[xf][yf]){
        cout<<"YES\n";
        vector<char>ans;
        int x=xf;
        int y=yf;
        pii p=pai[x][y];
        make_pair(x,y)=p;
        while(x!= xi || y!=yi){
            pii p=pai[x][y];
            if(p.first == x+1)ans.pb('U');
            else if(p.first==x-1)ans.pb('D');
            else if(p.second==y+1)ans.pb('L');
            else ans.pb('R');
            //make_pair(x,y)=p;
            x=p.first;
            y=p.second;
        }
        cout<<sz(ans)<<"\n";
        reverse(ans.begin(),ans.end());
        for(auto c:ans)cout<<c;
    }
    else cout<<"NO";
    //cout<<pai[xf][yf].first<<" "<<pai[xf][yf].second;   
}
