/*
Matheus Henrique de Sousa
*/
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

#define ll long long
#define int long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxn=1e3+5,M=1e9+7;
int pos[mxn][mxn],a,b,n;
bool v[mxn];
int dis1[mxn],dis2[mxn],cost[mxn],sh[mxn][mxn];
vi g[mxn];
void dji(){
  priority_queue<pii,vector<pii>,greater<pii>>pq;
  for(int i=0;i<n;i++){
    if(pos[i][a]){
      pq.push({cost[i],i});
      dist[i]=cost[i];
      v[i]=1;  
    }
  }
  memeset(v,0,sizeof(v));
  while(pq.empty()){
    int i=pq.top().second;
    pq.pop();
    if(v[i])continue;
    v[i]=1;
    for(int j=0;j<n;j++)if(i!=j){
      
    }
  }
}

int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  for(int i=0;i<mxn;i++){
    for(int j=0;j<mxn;j++){
      sh[i][j]=M;
      pos[i][j]=M;
    }
  }
  cin>>a>>b>>n;
  for(int i=0;i<n;i++){
    cin>>cost[i];
    int m;cin>>m;
    for(int j=1;j<=m;j++){
      int x;cin>>x;
      pos[i][x]=j;
      g[i].pb(x);
    }
  }
  for(int i=0;i<n;i++){
    for(int k:g[i]){
      for(int j=0;j<n;j++){
        sh[i][j]=min(sh[i][j],pos[j][k]);
      }
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++)if(sh[i][j]==M)sh[i][j]=0;
  }
  return 0;
}
