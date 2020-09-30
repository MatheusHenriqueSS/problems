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
const int mxn=1e5+5,M=1e9+7;
int n,cor[mxn],vis[mxn];
vi g[mxn];
void dfs(int i){
  vis[i]=1;
  for(int j:g[i]){
    if(!vis[j]){
      cor[j]=cor[i]^1;
      dfs(j);
    }
  }
}
bool dfs1(int i){
  vis[i]=1;
  for(int j:g[i]){
    if(cor[j]==cor[i])return false;
    if(!vis[j])return dfs1(j);
  }
  return true;
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n;
  for(int i=0;i<n-1;i++){
    int a,b;cin>>a>>b;a--;b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfs(0);
  memset(vis,0,sizeof(vis));
  if(dfs1(0)){
  int ans=0;
  for(int i=0;i<n;i++)ans+=cor[i];
  if(2*ans==n)cout<<"Y";
  else cout<<"N";
  return 0;
  }
  cout<<"N";
  
  return 0;
}
