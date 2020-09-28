#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m,cnt,cic[mxN],vis[mxN],pai[mxN],ok;
vi adj[mxN],ans,aux;
void dfs(int i,int p){
    if(ok==1)return;
    if(vis[i]==2)return;
    if(vis[i]==1){
        int cur=p;
        aux.pb(cur);
        while(cur^i){
            cur=pai[cur];
            aux.pb(cur);
        }
        aux.pb(p);
        ok=1;
        return;
 
    }
    pai[i]=p;
    vis[i]=1;
    for(int j:adj[i]){
        if(j==p){
            aux={p,i,p};
            ok=1;
            return;
        }
        dfs(j,i);
    }
    vis[i]=2;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
    }
    for(int i=1;i<=n;i++){
      if(!vis[i])dfs(i,0);
    }
    if(sz(aux)){
        cout<<sz(aux    )<<"\n";
        reverse(aux.begin(),aux.end());
        for(int i:aux)cout<<i<<" ";
    }
    else cout<<"IMPOSSIBLE";
}
