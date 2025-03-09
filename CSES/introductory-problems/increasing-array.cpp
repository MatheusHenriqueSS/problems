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
  int n;cin>>n;
  int last = 0;
  int ans = 0;
  for(int i = 0; i < n; i++) {
    int x;cin>>x;
    if(x < last) {
      ans += abs(x - last);
    }
    else last = x;
  }

  cout<<ans<<endl;
}