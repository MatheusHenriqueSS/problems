#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"

typedef pair<int,int>ii;
typedef vector<int> vi;

int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  int n;cin>>n;

  for(int mask = 0; mask < (1<<n); mask++) {
    string s = "";
    for(int i = 0; i < n; i++) {
      int pot = (1<<(n - i));
      int div = mask / pot;
      int idx = div * pot;
      //idx is the beginning idx of the current group

      bool ok = mask < (idx + pot / 2);

      if(ok) {
        if (div&1)s += "1";
        else s += "0";
      }
      else {
        if(div&1) s+= "0";
        else s += "1";
      }


    }
    cout<<s<<endl;
  }
}