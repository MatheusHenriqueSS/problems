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

int32_t main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  int n;cin>>n;

  for(int x = 1; x <= n; x++) {
    
    int sq = x*x;

    int tot = sq * (sq - 1ll);
    tot = tot / 2ll;

    // cout<<tot<<endl;

    int rec = max(0ll, (x - 3 + 1)) * max(0ll, (x - 2 + 1));
    rec = rec * 4;

    // cout<<rec<<endl;


    tot -= rec;
    cout<<tot<<endl;

  }
}