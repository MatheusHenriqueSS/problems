    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define pb push_back
    #define sz(x) (int)x.size()
    #define int long long
    typedef pair<int,int>pii;
    const int mxN=1e5+5,M=1e9+7;
    //did u check when n=1?
    //is mxN correct?
    int n,q,t;
    int pai[mxN],pos[mxN],h[mxN],v[mxN],val[mxN],sz[mxN];
    int tree[4*mxN];
    vector<int>adj[mxN];
    void dfs(int i,int p=-1){
        sz[i]=1;
        for(int& j:adj[i])if(j!=p){
            dfs(j,i);
            sz[i]+=sz[j];
            if(sz[j]>sz[adj[i][0]] || adj[i][0]==p)swap(adj[i][0],j);
        }
    }
    void build_hdl(int i,int p=-1){
        pos[i]=t++;v[pos[i]]=val[i];
        for(int j:adj[i])if(j!=p){
            pai[j]=i;
            h[j]=(j==adj[i][0]?h[i]:j);
            build_hdl(j,i);
        }
    }
    void build_t(int i=0,int j=n-1,int no=1){
        if(i==j)tree[no]=v[i];
        else{
            int esq=2*no;
            int dir=2*no+1;
            int m=(i+j)/2;
            build_t(i,m,esq);
            build_t(m+1,j,dir);
            int temp=tree[esq];
            temp|=tree[dir];
            tree[no]=temp;
        }
    }
    int query(int A,int B,int i=0,int j=n-1,int no=1){
        if(A<=i && j<=B)return tree[no];
        if(i>B || j<A)return 0;
        int esq=2*no;
        int dir=2*no+1;
        int m=(i+j)/2;
        int temp=query(A,B,i,m,esq);
        temp|=query(A,B,m+1,j,dir);
        return temp;
    }
    void upd(int p,int k,int i=0,int j=n-1,int no=1){
        if(i==j){
            v[i]=k;
            tree[no]=v[i];
        }
        else{
            int esq=2*no;
            int dir=2*no+1;
            int m=(i+j)/2;
            if(p<=m)upd(p,k,i,m,esq);
            else upd(p,k,m+1,j,dir);
            int temp=tree[esq];
            temp|=tree[dir];
            tree[no]=temp;
        }
    }
    int query_path(int a,int b){
        if(pos[a]<pos[b])swap(a,b);
        if(h[a]==h[b])return query(pos[b],pos[a]);
        return (query(pos[h[a]],pos[a])|query_path(pai[h[a]],b));
    }
    void build(int root=0){
        dfs(root);
        t=0;
        h[root]=root;
        build_hdl(root);
        build_t();
    }
    int32_t main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cin>>n;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            val[i]=(1LL<<x);
        }
        for(int i=0;i<n-1;i++){
            int a,b;cin>>a>>b;a--;b--;  
            adj[a].pb(b);
            adj[b].pb(a);
        }
        build();
        cin>>q;
        while(q--){
            int op,a,b;cin>>op>>a>>b;
            if(op==1){
                a--;
                upd(pos[a],(1LL<<b));
            }
            else{
                a--;b--;
                cout<<__builtin_popcountll(query_path(a,b))<<"\n";
            }
        }
    }
