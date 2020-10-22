/*
Matheus Henrique de Sousa
silver18/19 - convention
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
int n,m,k,a[mxn];
bool calc(int x){
  int i=0,j=0;
  int tm=m;
  while(tm--){
    while(j<n && j-i<k && a[j]-a[i]<=x)j++;
    i=j;
  }
  return i==n;
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0);
  setIO("convention");
  cin>>n>>m>>k;
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  int l=0,r=mod,ans=-1;
  while(l<=r){
    int m=(l+r)/2;
    if(calc(m)){
      r=m-1;
      ans=m;
    }
    else l=m+1;
  }
  cout<<ans<<"\n";
  return 0;
}
