/* Matheus Henrique de Sousa
Seletiva 2018 - empresa*/
#include<bits/stdc++.h>
using namespace std;

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
int pai[mxn],ans[mxn],lvl[mxn],tc[mxn],n;
vi g[mxn],g1[mxn],aux;
bool cmp(int a,int b){
  return lvl[a]>lvl[b];
}
queue<int>q;
set<pii>s;
void dfs(int i){
  ans[i]=1;
  for(int j:g[i]){
    lvl[j]=lvl[i]+1;
    pai[j]=i;
    dfs(j);
    ans[i]=max(ans[i],ans[j]+1);
  }
}
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  for(int i=2;i<=n;i++){
    int x;cin>>x;
    g[x].pb(i);
    g1[i].pb(x);
  }
  dfs(1);
  for(int i=1;i<=n;i++)cin>>tc[i];
  int ma=0;
  for(int i=1;i<=n;i++)ma=max(ma,lvl[i]);
  for(int i=1;i<=n;i++)aux.push_back(i);
  sort(aux.begin(),aux.end(),cmp);
  for(int i=0;i<n;i++)q.push(aux[i]);
  for(int i=ma;i;i--){
    while(lvl[q.front()]==i){
      int j=q.front();
      q.pop();
      s.insert({tc[j],j});
    }
    s.insert({0,0});
    for(auto it=s.begin();it!=s.end();it++)if(it!=s.begin()){
      int y=it->second,x=prev(it)->second;
      ans[y]=max(ans[y],ans[x]+1);
      ans[pai[y]]=max(ans[pai[y]],ans[y]+1);
    }
    s.clear();
  }
  int res=0;
  for(int i=1;i<=n;i++)res+=ans[i];
  cout<<res<<"\n";
  

  return 0;
}
