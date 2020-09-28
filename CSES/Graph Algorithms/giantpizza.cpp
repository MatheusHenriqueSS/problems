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
int n,m,ans[mxN],vis[mxN],id[mxN],t;
vi aux,adj[mxN],adj1[mxN];
void dfs(int i){
    if(vis[i])return;
    vis[i]=1;
    for(int j:adj[i])dfs(j);
    aux.pb(i);    
}
void dfs1(int i){
    if(id[i])return;
    id[i]=t;
    for(int j:adj1[i])dfs1(j);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b;char c,d;
        cin>>c>>a>>d>>b;
        if(c=='-')a=m+a;
        if(d=='-')b=m+b;
        adj[(a>m?a-m:a+m)].pb(b);
        adj[(b>m?b-m:b+m)].pb(a);
        adj1[b].pb((a>m?a-m:a+m));
        adj1[a].pb((b>m?b-m:b+m));
    }
    for(int i=1;i<=2*m;i++){
        if(!vis[i])dfs(i);
    }
    reverse(aux.begin(),aux.end());
    for(int i:aux){
        if(!id[i]){
            t++;
            dfs1(i);
        }
    }
    for(int i=1;i<=m;i++){
        if(id[i]==id[i+m]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    reverse(aux.begin(),aux.end());
    for(int i:aux){
        if(i>m){
            if(!ans[i-m])ans[i-m]=-1;
        }
        else{
            if(!ans[i])ans[i]=1;
        }
    }
    for(int i=1;i<=m;i++)cout<<(ans[i]==1?'+':'-');
 
 
}
