#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"

typedef pair<int,int>ii;
typedef vector<int> vi;

const int mxn = 62;

ll po[mxn];

ll index(string s) {
    if (s == "0")return 0ll;
    if (s == "1")return 1ll;

    if(s[0] == '1')return po[sz(s)] - index(s.substr(1, sz(s) - 1)) - 1ll;
    return index(s.substr(1, sz(s) - 1)); 
}

void solve() {

    po[0] = 1ll;
    for (int i = 1; i < mxn; i++)po[i] = po[i - 1] * 2ll;

    int n;
    string s1, s2;
    cin>>n>>s1>>s2;

    cout<<index(s2) - index(s1) - 1<<"\n";

}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    int t = 1;
    //cin>>t;

    while(t--) solve();
}