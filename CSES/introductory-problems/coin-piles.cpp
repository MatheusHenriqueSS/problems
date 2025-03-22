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

typedef pair<int,int>ii;
typedef vector<int> vi;

#define int long long

void solve() {
  int a, b;cin>>a>>b;

  int tot = 2ll*min(a,b) - max(a,b);
  if(tot >= 0 && tot%3 == 0)cout<<"YES\n";
  else cout<<"NO\n";
}

int32_t main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  int t;cin>>t;
  while(t--)solve();
}