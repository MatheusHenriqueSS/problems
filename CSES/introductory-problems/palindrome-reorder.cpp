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
  //setIO("convention");

  string s;cin>>s;
  map<char, int> mp;
  for(auto c: s) {
    mp[c]++;
  }

  char odd = '$';
  bool ok = false;


  for(auto it = mp.begin(); it != mp.end(); it++) {
    if(it->second &1) {
      if(ok){
        cout<<"NO SOLUTION\n";
        return 0;
      }
      ok = true;
      odd = it->first;
      
    }
  }

  string fs = "";

  for (auto it = mp.begin(); it != mp.end(); it++) {
    fs += string(it->second/2, it->first);
  }

  string sd = fs;
  reverse(sd.begin(), sd.end());
  if(odd == '$')cout<<fs<<sd<<endl;
  else cout<<fs<<odd<<sd<<endl;



}