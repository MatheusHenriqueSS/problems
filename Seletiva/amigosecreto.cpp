/*Matheus Henrique de Sousa
Seletiva 2018 - amigo secreto
*/
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
int g[mxn],tx[mxn],h[mxn],v[mxn],sz[mxn];
int n,cnt,ans;
vector<pii> ed[mxn];
bool out[mxn];
void dfs(int i){
  v[i]=1;
  if(out[i]==1 || v[g[i]]==2){
    v[i]=2;
    return;
  }
  if(v[g[i]]==1){
    h[cnt++]=i;
    v[i]=2;
    return;
  }
  dfs(g[i]);
  v[i]=2;
  return;

}

int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  if(n==1){
    cout<<0<<"\n";
    return 0;
  }
  for(int i=1;i<=n;i++){
    ed[i].pb({0,0});
    ed[i].pb({0,0});
    sz[i]=2;
  }
  for(int i=1;i<=n;i++){
    int j;
    cin>>j>>tx[i];
    if(i==j){
      ans+=tx[i];
      out[i]=1;
    }
    else{
      g[i]=j;
      sz[j]++;
      ed[j].pb({tx[i],i});
    }
  }
  for(int i=1;i<=n;i++){
    sort(ed[i].begin(),ed[i].end());
    for(int j=0;j<sz(ed[i])-1;j++){
      ans+=ed[i][j].first;
      out[ed[i][j].second]=1;
      //apago todos os edges exceto pelo maior
    }
  }
  for(int i=1;i<=n;i++){
    if(!v[i])dfs(i);
  } 
  if(cnt==1){
    int sz=1,cur=h[0];
    while(g[cur]!=h[0]){
      sz++;
      cur=g[cur];
    }
    if(sz==n){
      cout<<0<<"\n";
      return 0;
    }
  }
  for(int i=0;i<cnt;i++){
    int me=inf;
    int j=h[i];
    me=min(me,tx[j]-ed[g[j]][sz[g[j]]-2].first);
    j=g[j];
    while(j!=h[i]){
    me=min(me,tx[j]-ed[g[j]][sz[g[j]]-2].first);
    j=g[j];
    }
    ans+=me;
  }
  cout<<ans<<"\n";

  return 0;
}
