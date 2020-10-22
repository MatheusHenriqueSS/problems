/*
Matheus Henrique de Sousa
silver19/20 - social distancing
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
const int mxn=2e5+5,mod=1e9+7;
int n,m;
pii a[mxn];
bool calc(int x){
  //cout<<x<<"\n";
  int cnt=0,last=-2e18;
  for(int i=0;i<m;i++){
    int l=a[i].first,r=a[i].second;
    l=max(l,last+x);
    if(l>r)continue;
    cnt+=(r-l)/x+1;
    last=l+((r-l)/x)*x;
    if(cnt>=n)break;
  }
  return cnt>=n;
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0);
  setIO("socdist");
  cin>>n>>m;
  for(int i=0;i<m;i++)cin>>a[i].first>>a[i].second;
  sort(a,a+m);
  int l=1,r=1e18+5,ans=-1;
  while(l<=r){
    int m=(l+r)/2;
    if(calc(m)){
      l=m+1;
      ans=m;  
    }
    else r=m-1;
  }
  //calc(1);
  cout<<ans<<"\n";
  return 0;
}
