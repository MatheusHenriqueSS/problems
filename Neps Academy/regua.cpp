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
int ans[2];
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  int n;cin>>n;
  cin>>ans[0]>>ans[1];
  sort(ans,ans+2);
  if((ans[1]-ans[0])>=n)cout<<"EH SUFICIENTE\n";
  else cout<<"NAO EH SUFICIENTE\n";
  return 0;
}
