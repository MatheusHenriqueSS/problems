/*
Matheus Henrique de Sousa
Seletiva 2017 - caminhos minímos
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=1e4+5,inf=2e9+10;
int n,m,tab[mxn],dist[mxn],cur[mxn];
vi g1[mxn];
vector<pii>g[mxn];
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?
void init(){
  for(int i=0;i<n;i++)tab[i]=mxn;
  tab[0]=0;
  priority_queue<pii,vector<pii>,greater<pii>>pq;
  pq.push({0,0});
  while(!pq.empty()){
    int i=pq.top().second;
    int tmp=pq.top().first;
    pq.pop();
    if(tmp!=tab[i])continue;
    for(int j:g1[i]){
      if(tab[j]>tab[i]+1){
        tab[j]=tab[i]+1;
        pq.push({tab[j],j});
      }
    }

  }
}
bool dji(int k){
  for(int i=0;i<n;i++)dist[i]=-1;
  cur[0]=0;
  dist[0]=0;
  priority_queue<pii,vector<pii>,greater<pii>>pq;
  pq.push({0,0});
  while(!pq.empty()){
    int i=pq.top().second;
    int tmp=pq.top().first;
    pq.pop();
    if(tmp!=dist[i])continue;
    for(pii p:g[i]){
      int j=p.second;
      int d=p.first;
      if(dist[j]>dist[i]+d+k || (dist[j]==dist[i]+k+d && cur[i]+1<cur[j] || dist[j]==-1)){
        dist[j]=dist[i]+d+k;
        cur[j]=cur[i]+1;
        pq.push({dist[j],j});
      }
    }
  }
  for(int i=0;i<n;i++)if(tab[i]!=cur[i])return false;
  return true;
}
int32_t main(){
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b,c;cin>>a>>b>>c;a--;b--;
    g[a].pb({c,b});
    g[b].pb({c,a});
    g1[a].pb(b);
    g1[b].pb(a);
  }
  init();
  int l=0,r=inf,ans=-1;
  while(l<=r){
    int mid=(l+r)/2;
    if(dji(mid)){
      ans=mid;
      r=mid-1;
    }
    else l=mid+1;
  }
  cout<<ans<<"\n";
  return 0;
}
