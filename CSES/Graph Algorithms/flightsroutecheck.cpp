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
const int mxn=2e5+5,M=1e9+7;
const int LINF=0x3f3f3f3f3f3f3f3f;
int n,m,ans[mxn],t;
vi g[mxn],g1[mxn],aux;
bool v[mxn];
void dfs(int i){
  if(v[i])return;
  v[i]=1;
  for(int j:g[i])dfs(j);
  aux.pb(i);
}
void dfs1(int i){
  if(ans[i])return;
  ans[i]=t;
  for(int j:g1[i])if(!ans[j])dfs1(j);
}

int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;cin>>a>>b;a--;b--;
    g[a].pb(b);
    g1[b].pb(a);
  }
  for(int i=0;i<n;i++)if(!v[i]){
    dfs(i);
  }
  reverse(aux.begin(),aux.end());
  for(int i:aux){
    if(!ans[i]){
      t++;
      dfs1(i);
    }
  }
  if(t==1){
    cout<<"YES\n";
    return 0;
  }
  cout<<"NO\n";
  for(int i=0;i<n;i++){
    for(int j:g1[i])if(ans[i]!=ans[j]){
      
      cout<<i+1<<" "<<j+1<<"\n";
      return 0;
    }
  }
  for(int i=0;i<n;i++){
    for(int  j=i+1;j<n;j++){
      if(ans[i]!=ans[j]){
        cout<<i+1<<" "<<j+1<<"\n";
        return 0;
      }
    }
  }
}
