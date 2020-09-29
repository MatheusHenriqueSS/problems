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
int n,t,cor[mxN],tin[mxN],tout[mxN],lvl[mxN];
int bit[55][mxN];
int anc[mxN][20];
vector<int>adj[mxN];
void dfs(int  i,int p){
    tin[i]=++t;
    for(int j:adj[i]){
        if(j!=p){
            lvl[j]=lvl[i]+1;
            anc[j][0]=i;
            dfs(j,i);
        }
    }
    tout[i]=++t;
}
void upd(int pos,int k,int val){
    for(int i=pos;i<mxN;i+=i&-i){
        bit[k][i]+=val;
    }
}
int query(int pos,int k){
    int ans=0;
    for(int i=pos;i>0;i-=i&-i){
        ans+=bit[k][i];
    }
    return ans;
}
int lca(int u,int v){
    if(lvl[u]<lvl[v])swap(u,v);
    for(int i=19;i>=0;i--){
        if(lvl[u]-(1<<i)>=lvl[v])u=anc[u][i];
    }
    if(u==v)return u;
    for(int i=19;i>=0;i--){
        if(anc[u][i] && anc[v][i] && anc[u][i]!=anc[v][i]){
            u=anc[u][i];
            v=anc[v][i];
        }
    }
    return anc[u][0];
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //memset(anc,-1,sizeof(anc));
    cin>>n;
    for(int i=1;i<=n;i++)cin>>cor[i];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;//a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,0);
    for(int j=1;j<=19;j++){
        for(int i=1;i<=n;i++){
           anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        upd(tin[i],cor[i],1);
        upd(tout[i],cor[i],-1);
    }
    //for(int i=1;i<=n;i++)cout<<tin[i]<<" "<<tout[i]<<"\n";
    int q;
    cin>>q;
    while(q--){
        int op,a,b;cin>>op>>a>>b;
        if(op==1){
            //a--;
            upd(tin[a],cor[a],-1);
            upd(tout[a],cor[a],1);
            cor[a]=b;
            upd(tin[a],cor[a],1);
            upd(tout[a],cor[a],-1);
        }
        else{
            //a--;b--;
            int l=lca(a,b);
            int ans=0;
            for(int i=1;i<=50;i++){
                if(query(tin[a],i)+query(tin[b],i)-2*query(tin[l],i)+(cor[l]==i))ans++;
            }
            cout<<ans<<"\n";
        }
    }
    
}
