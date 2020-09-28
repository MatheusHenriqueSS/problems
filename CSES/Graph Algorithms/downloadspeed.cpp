#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=505,M=1e9+7,INF=1e18+7;
//did u check when n=1?
//is mxN correct?
int n,m;
int adj[mxN][mxN],pai[mxN];
vi g[mxN];
bool v[mxN];
 
int bfs(){
    memset(v,0,sizeof(v));
    //memset(pai,-1,sizeof(pai));
    queue<pii>q;
    v[0]=1;
    q.push({0,INF});
    while(!q.empty()){
        int i=q.front().first;
        int d=q.front().second;
        q.pop();
        //cout<<i<<"\n";
        if(i==n-1){
            int j=pai[i];
            while(i){
                adj[i][j]+=d;
                adj[j][i]-=d;
                i=j;
                j=pai[j];
            }
            return d;
        }
        for(int j:g[i]){
            if(!v[j] && adj[i][j]){
                v[j]=1;
                q.push({j,min(d,adj[i][j])});
                pai[j]=i;
            }
        }
    }
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        g[a].pb(b);
        g[b].pb(a);
        adj[a][b]+=c;
    }
    int ans=0;
    int cur=bfs();
    while(cur!=0){
        ans+=cur;
        cur=bfs();
    }
    cout<<ans;
}
