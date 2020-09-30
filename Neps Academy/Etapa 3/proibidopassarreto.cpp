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
map<pii,int>mp;
int n;
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n;
  for(int tp=0;tp<n;tp++){
    int i,j,i1,j1;
    cin>>i>>j>>i1>>j1;
    j1-=j;
    i1-=i;
    int cur=__gcd(i1,j1);
    i1/=cur;
    j1/=cur;
    if(j1<0){
      i1*=-1;
      j1*=-1;
    }
    mp[{j1,i1}]++;
  }
  for(auto it=mp.begin();it!=mp.end();it++){
    int a=it->first.second;
    int b=it->first.first;
    a*=-1;
    if(a<0){
      a*=-1;
      b*=-1;
    }
    if(mp.find({a,b})==mp.end())mp[{a,b}]=0;
  }
  int ans=0;
  for(auto it=mp.begin();it!=mp.end();it++){
    int a=it->first.second;
    int b=it->first.first;
    a*=-1;
    if(a<0){
      a*=-1;
      b*=-1;
    }
    ans+=max(it->second,mp[{a,b}]);
  }
  cout<<ans/2;

  return 0;
}
