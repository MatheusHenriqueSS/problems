#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  freopen((s+ ".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"
#define int long long
typedef pair<int,int>ii;
typedef vector<int> vi;

void solve() {

}



int32_t main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  //setIO("convention");

  int n;cin>>n;

  while(n--) {
    int x;int y;
    cin>>x>>y;

    int ma = max(x, y);


    //n2 -n + 1

    int val = ma*ma - ma + 1ll;

    if (x == y){
      cout<<val<<endl;
      continue;
    }
    if(ma&1) {
      if(y < ma) {
        cout<<val - abs(y - ma)<<endl;
      }
      else {
        cout<<val + abs(x - ma)<<endl;
      }
    }
    else {
      if(y < ma) {
        cout<<val + abs(y - ma)<<endl;
      }
      else {
        cout<<val - abs(x - ma)<<endl;
      }
    }
  }
}