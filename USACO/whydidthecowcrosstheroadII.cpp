/*
Matheus Henrique de Sousa
why did the cow cross the road II
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
int n,k,b,a[mxn];
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("maxcross");
  cin>>n>>k>>b;
  for(int i=0;i<b;i++){
    int x;cin>>x;
    a[x]++;
  }
  int ans=M;
  for(int i=1;i<=n;i++)a[i]+=a[i-1];

  for(int i=k;i<=n;i++){
    ans=min(ans,a[i]-a[i-k+1]);
  }
  //XX..X...XX
  cout<<ans;
  return 0;
}
