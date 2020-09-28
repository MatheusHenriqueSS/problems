/*
Matheus Henrique de Sousa
triangles
9.16.20
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
int add(int a,int b){int ret=(a+b)%M;if(ret<0)ret+=M;return ret;}
int mul(int a,int b){int ret=(a*b)%M;if(ret<0)ret+=M;return ret;}
int n;
vi sum[mxn];
vector<pii>g[mxn];
pii a[mxn];
void solve(){
  for(int i=0;i<mxn;i++){
    int len=sz(g[i]);
    if(!len)continue;
    sort(g[i].begin(),g[i].end());
    int cnt=0;
    for(int j=0;j<len;j++){
      cnt=add(cnt,g[i][j].first-g[i][0].first);
    }
    sum[g[i][0].second].pb(cnt);
    for(int j=1;j<len;j++){
      cnt=add(cnt,mul((2*j-len),(g[i][j].first-g[i][j-1].first)));
      sum[g[i][j].second].pb(cnt);
    }
  }
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("triangles");
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
  for(int i=0;i<n;i++){
    g[a[i].first+10000].pb({a[i].second,i});
  }
  solve();
  for(int i=0;i<mxn;i++)g[i].clear();
  for(int i=0;i<n;i++){
    g[a[i].second+10000].pb({a[i].first,i});
  }
  solve();
  int ans=0;
  for(int i=0;i<n;i++)ans=add(ans,mul(sum[i][0],sum[i][1]));
  cout<<ans;
  return 0;
}
