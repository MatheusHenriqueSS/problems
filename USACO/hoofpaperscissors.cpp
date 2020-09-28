/*
Matheus Henrique de Sousa
hoof,paper and scissors
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
int pref[3][mxn],n;
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("hps");
  cin>>n;
  for(int i=0;i<n;i++){
    for(int j=0;j<3;j++)pref[j][i+1]=pref[j][i];
    char c;cin>>c;
    if(c=='P')pref[0][i+1]++;
    if(c=='H')pref[1][i+1]++;
    if(c=='S')pref[2][i+1]++;

  }
  int ans=0;
  for(int i=1;i<=n;i++){
    for(int j=0;j<3;j++){
      for(int j1=0;j1<3;j1++){
        ans=max(ans,pref[j][i]+pref[j1][n]-pref[j1][i]);
      }
    }
  }
  cout<<ans;
  return 0;
}
