/*Matheus Henrique de Sousa
Seletiva 2018 - tentativa (66/100)
marcos soluções tecnológicas*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=1e5+5;
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
int n,m,k,q,cur;
int pai[mxn],peso[mxn];
multiset<int> opt,g2;
multiset<pii>g1;
int find(int x){
  if(pai[x]==x)return x;
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
  vector<t>edges(m);
  for(int i=0;i<m;i++){
    cin>>edges[i].x>>edges[i].y>>edges[i].w;
  }
  sort(edges.begin(),edges.end(),cmp);
  for(int i=1;i<=n;i++){
    pai[i]=i;
    peso[i]=1;
  }
  for(t i:edges){
    int a=i.x,b=i.y;
    a=find(a);b=find(b);
    if(a==b)continue;
    join(a,b);
    opt.insert(i.w);
    cur+=i.w;

  }
  for(int i=0;i<k;i++){
    int x;cin>>x;
    g2.insert(x);
  }
  while(!g2.empty() && !opt.empty() && *g2.begin()<*opt.rbegin()){
      int x=*g2.begin(),y=*opt.rbegin();
      g1.insert({x,y});
      g2.erase(g2.begin());
      opt.erase(opt.find(y));
      cur-=y;
      cur+=x;
  }
  cout<<cur<<"\n";
  while(q--){
    int op,x;cin>>op>>x;
    if(op==1){
      if(!opt.empty() && x<*opt.rbegin()){
        int y=*opt.rbegin();
        opt.erase(opt.find(y));
        g1.insert({x,y});
        cur-=y;
        cur+=x;
      }
      else if(!g1.empty()){
        pii p=*g1.rbegin();
        if(x<p.first){
          g1.erase(g1.find(p));
          g1.insert({x,p.second});
          g2.insert(p.first);
          cur-=p.first;
          cur+=x;
        }
        else g2.insert(x);
      }
      else g2.insert(x);
    }
    else{
      auto it=g2.find(x);
      if(it!=g2.end()){
        g2.erase(it);
      }  
      else{
        pii p=*g1.upper_bound({x,-1});
        g1.erase(g1.find(p));
        if(!g2.empty() && *g2.begin()<p.second){
          int x=*g2.begin();
          g2.erase(g2.begin());
          g1.insert({x,p.second});
          cur-=p.first;
          cur+=x;
        }
        else{
          opt.insert(p.second);
          cur-=p.first;
          cur+=p.second;
        }
      }
    }
    cout<<cur<<"\n";
  }
  return 0;
}
