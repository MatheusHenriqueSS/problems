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
string s;

int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>s;
  int ans=0;
  ans+=min((s[0]-'0'),10-(s[0]-'0'));
  for(int i=0;i<sz(s)-1;i++){
    int cur=(s[i]-'0'),tmp=(s[i+1]-'0');
    ans+=min(abs(cur-tmp),10-abs(cur-tmp));

  }
  cout<<ans;
  return 0;
}
