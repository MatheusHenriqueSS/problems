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

const int M = 1e9 + 7;

int32_t main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  //setIO("convention");

  int n;cin>>n;
  int ans = 1ll;
  for(int i = 0; i < n; i++) {
    ans = ans * 2ll;
    ans = ans % M;
  }

  cout<<ans<<endl;
}