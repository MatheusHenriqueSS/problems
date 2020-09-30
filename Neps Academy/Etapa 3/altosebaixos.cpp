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
vi aux;
int n,me=M;
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n;
  int cur=0;
  for(int i=0;i<n-1;i++){
    char c;cin>>c;
    if(c=='A'){
      aux.pb(1);
      cur++;
    }
    else {
      aux.pb(-1);
      cur--;
    }
    me=min(me,cur);
  }
  if(me<0)cur=-me;
  else cur=0;
  cout<<cur<<" ";
  for(int x:aux){
    cur+=x;
    cout<<cur<<" ";
  }
  return 0;
}
