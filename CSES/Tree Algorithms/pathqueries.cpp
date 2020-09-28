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
int n,q,t,pos[mxN],pai[mxN],h[mxN],v[mxN],sz[mxN],val[mxN];
int seg[4*mxN];
vi adj[mxN];
void dfs(int i,int p=-1){
    sz[i]=1;
    for(int& j:adj[i])if(j!=p){
        dfs(j,i);
        sz[i]+=sz[j];
        if(sz[j]>sz[adj[i][0]]||adj[i][0]==p)swap(adj[i][0],j);
    }
}
void build_hdl(int i,int p){
    pos[i]=t++;v[pos[i]]=val[i];
    for(int j:adj[i])if(j!=p){
        pai[j]=i;
        h[j]=(j==adj[i][0]?h[i]:j);
        build_hdl(j,i);
    }
}
void build_t(int i=0,int j=n-1,int no=1){
    if(i==j){
        seg[no]=v[i];
        return;
    }
    int m=(i+j)/2;
    build_t(i,m,2*no);
    build_t(m+1,j,2*no+1);
    seg[no]=seg[2*no]+seg[2*no+1];
}
int query(int A,int B,int i=0,int j=n-1,int no=1){
    if(j<A || i>B|| i>j)return 0;
    if(A<=i && j<=B)return seg[no];
    int m=(i+j)/2;
    return query(A,B,i,m,2*no)+query(A,B,m+1,j,2*no+1);
}
void upd(int pos,int k,int i=0,int j=n-1,int no=1){
    if(i==j){
        v[i]=k;
        seg[no]=v[i];
        return;
    }
    int m=(i+j)/2;
    if(pos<=m)upd(pos,k,i,m,2*no);
    else upd(pos,k,m+1,j,2*no+1);
    seg[no]=seg[2*no]+seg[2*no+1];
 
}
int query_path(int a,int b){
    if(pos[a]<pos[b])swap(a,b);
    if(h[a]==h[b])return query(pos[b],pos[a]);
    return query(pos[h[a]],pos[a])+query_path(pai[h[a]],b);
}
void build(){
    dfs(0,-1);
    build_hdl(0,-1);
    build_t();
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>val[i];
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    build();
    while(q--){
        int op;cin>>op;
        if(op==1){
            int x,y;cin>>x>>y;x--;
            upd(pos[x],y);
        }
        else{
            int x,y;cin>>x;x--;
            cout<<query_path(0,x)<<"\n";
        }
    }
}
