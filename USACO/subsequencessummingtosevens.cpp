/*
Matheus Henrique de Sousa
subsequences summing to sevens
9.21.20
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
int n,a[mxn],pref[mxn];
map<int,pii>mp;
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("div7");
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
    pref[i+1]=pref[i]+a[i];
  }
  int ma=0;
  for(int i=0;i<=6;i++)mp[i]={M,-1};
  for(int i=1;i<=n;i++){
    pref[i]=pref[i]%7;
    pii& p=mp[pref[i]];
    p.second=max(p.second,i);
    p.first=min(p.first,i);
    ma=max(ma,p.second-p.first);
  }
  cout<<ma;
  return 0;
}
