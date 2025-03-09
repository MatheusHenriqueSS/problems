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

void solve() {

}

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  string s;
  cin>>s;

  char last = '$';
  int cur = 1;
  int ans = 0;
  for (auto c: s) {
    if(c != last) {
      ans = max(ans, cur);
      cur = 1;
      last = c;
    }
    else {
      cur++;
    }
  }

  ans = max(ans, cur);
  cout<<ans<<endl;
}
