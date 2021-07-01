#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=1e5+5,inf=1e9+7;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn? 
struct t{
  int x,y,w;
};
bool cmp(t a,t b){
  return a.w<b.w;
}
multiset<int>g,opt;
int n,m,k,q,cur;
int pai[mxn],peso[mxn];
int find(int x){
  if(x==pai[x])return x;
  return pai[x]=find(pai[x]);
}
void join(int a,int b){
  a=find(a);
  b=find(b);
  if(a==b)return;
  if(peso[b]>peso[a]){
    pai[a]=b;
    peso[b]+=peso[a];
  }
  else{
    pai[b]=a;
    peso[a]+=peso[b];
  }
} 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>k>>q;
  vector<t>aux(m);
  for(int i=0;i<m;i++)cin>>aux[i].x>>aux[i].y>>aux[i].w;
  sort(aux.begin(),aux.end(),cmp);
  for(int i=1;i<=n;i++){
    pai[i]=i;
    peso[i]=1;
  }
  for(int i=0;i<m;i++){
    int x=aux[i].x,y=aux[i].y;
    x=find(x),y=find(y);
    if(x==y)continue;
    opt.insert(aux[i].w);
    cur+=aux[i].w;
    join(x,y);
  }
  while(k--){
    int x;cin>>x;
    if(x<*opt.rbegin()){
      int y=*opt.rbegin();
      opt.erase(opt.find(y));
      opt.insert(x);
      g.insert(y);
      cur+=x-y;
    }
    else g.insert(x);
       
  }
  cout<<cur<<"\n";
  while(q--){
    int op,x;cin>>op>>x;
    if(op==1){
      if(x<*opt.rbegin()){
        int y=*opt.rbegin();
        opt.erase(opt.find(y));
        opt.insert(x);
        g.insert(y);
        cur+=x-y;
      }
      else g.insert(x);
    }
    else{
      if(g.find(x)!=g.end()){
        g.erase(g.find(x));
      }
      else{
        assert(opt.find(x)!=opt.end());
        opt.erase(opt.find(x));
        int y=*g.begin();
        g.erase(g.find(y));
        opt.insert(y);        
        cur+=y-x;
      }
    }
    cout<<cur<<"\n";
  }
  return 0;
}
