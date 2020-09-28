#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
//#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,q,t=1,tin[mxN],tout[mxN],lvl[mxN],anc[mxN][20],bit[2*mxN],ans[mxN];
vi adj[mxN];
// ans = tout[i]-tin[i];
void dfs(int i,int p){
    tin[i]=t++;
    for(int j:adj[i])if (j!=p){
        anc[j][0]=i;
        lvl[j]=lvl[i]+1;
        dfs(j,i);
    }
    tout[i]=t++;
}
int lca(int u,int v){
    if(lvl[u]<lvl[v])swap(u,v);
    for(int j=19;j>=0;j--){
        if(lvl[u]-(1<<j)>=lvl[v]){
            u=anc[u][j];
        }
    }
    if(u==v)return u;
    for(int j=19;j>=0;j--){
        if(anc[u][j] && anc[u][j]!=anc[v][j]){
            u=anc[u][j];
            v=anc[v][j];
        }
    }
    return anc[u][0];
}
void upd(int pos,int val){
    for(;pos<2*mxN;pos+=pos&-pos){
        bit[pos]+=val;
    }
}
int query(int pos){
    int ans=0;
    for(;pos>0;pos-=pos&-pos){
        ans+=bit[pos];
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,0);
    for(int j=1;j<=19;j++){
        for(int i=1;i<=n;i++){
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
 
    while(q--){
        int a,b;cin>>a>>b;
        int l=lca(a,b);
        ans[l]++;
        if(tout[a]>tout[b])swap(a,b);
        bit[tout[a]]++;
        bit[tout[b]]++;
        bit[tout[l]]-=2;   
 
    }
    for(int i=tin[1];i<=tout[1];i++)bit[i]+=bit[i-1];
    //for(int i=tin[1];i<=tout[1];i++)cout<<bit[i]<<" ";
    //cout<<"\n";
    for(int i=1;i<=n;i++){
        cout<<bit[tout[i]]-bit[tin[i]]+ans[i]<<" ";
    }
    
 
 
 
}
