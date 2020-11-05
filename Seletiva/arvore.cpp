/* Matheus Henrique de Sousa
Seletiva 2018 - árvore*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=1e5+5,mxl=20;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?
int n,q,lvl[mxn],anc[mxn][mxl],a[mxn],rm[mxn],N=1;
vi g[mxn];
map<int,int>mp;   
struct node{
  node* l,*r;
  int val;
  node(){
    l=r=NULL;
    val=0;
  }
};
node* t[mxn];
void build(node* root,int i=1,int j=N){
  if(i==j){
    root->val=0;
    return;
  }
  int m=(i+j)/2;
  root->l=new node();
  build(root->l,i,m);
  root->r= new node();
  build(root->r,m+1,j);
}
void upd(node* prev,node* cur,int pos,int i=1,int j=N){
  if(i==j){
    cur->val=prev->val+1;
    return;
  }
  int m=(i+j)/2;
  if(pos<=m){
    cur->r=prev->r;
    cur->l=new node();
    upd(prev->l,cur->l,pos,i,m);
  }
  else{
    cur->l=prev->l;
    cur->r =new node();
    upd(prev->r,cur->r,pos,m+1,j);
  }
  cur->val=cur->l->val+cur->r->val;

}
void dfs(int i,int p){
  t[i]=new node();
  upd(t[p],t[i],mp[a[i]]);
  for(int j:g[i])if(j!=p){
    lvl[j]=lvl[i]+1;
    anc[j][0]=i;
    dfs(j,i);
  }
}
void init(){
  for(int j=1;j<mxl;j++){
    for(int i=1;i<=n;i++)if(anc[i][j-1]){
      anc[i][j]=anc[anc[i][j-1]][j-1];
    }
  }
}
int query(node* a,node* b,node* c,node* d,int k,int i=1,int j=N){
  if(i==j)return rm[i];
  int cur=a->l->val+b->l->val-c->l->val-d->l->val;
  int m=(i+j)/2;
  if(cur>=k)return query(a->l,b->l,c->l,d->l,k,i,m);
  return query(a->r,b->r,c->r,d->r,k-cur,m+1,j);

}
int lca(int u,int v){
  if(lvl[u]<lvl[v])swap(u,v);
  for(int i=mxl-1;i>=0;i--){
    if(lvl[u]-(1<<i)>=lvl[v])u=anc[u][i];
  }
  if(u==v)return u;
  for(int i=mxl-1;i>=0;i--){
    if(anc[u][i] && anc[u][i]!=anc[v][i]){
      u=anc[u][i];
      v=anc[v][i];
    }
  }
  return anc[u][0];
}
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>q;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    mp[a[i]]=1;
  }
  for(auto it=mp.begin();it!=mp.end();it++){
    it->second=N;
    rm[N]=it->first;
    N++;
  }
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;
    g[a].pb(b);
    g[b].pb(a);
  }
  t[0]=new node();
  build(t[0]);
  dfs(1,0);
  init();
  while(q--){
    int u,v,k;cin>>u>>v>>k;
    int l=lca(u,v);
    cout<<query(t[u],t[v],t[l],t[anc[l][0]],k)<<"\n";
  }
  return 0;
}
