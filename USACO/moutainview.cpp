/*
Matheus Henrique de Sousa
9.14.20
mountain view
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
map<int,int>aux;
int n,ans;
pii a[mxn];
bool comp(pii a,pii b){
  if(a.first!=b.first)return a.first<b.first;
  return a.second>b.second;
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("mountains"); 
  cin>>n;
  for(int i=0;i<n;i++){
    int x,y;cin>>x>>y;
    a[i].first=x-y;
    a[i].second=x+y;
  }
  sort(a,a+n,comp);
  int ma=-M;
  for(int i=0;i<n;i++){
    if(ma<a[i].second)ans++;
    ma=max(ma,a[i].second);
  }
  cout<<ans;

  

  return 0;
}
