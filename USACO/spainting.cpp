//17 - 02 - 22
#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);
     freopen((s+ ".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

#define int long long
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"

typedef pair<int,int>pii;
typedef vector<int> vi;

const int mod = 1e9 + 7, mxn = 1e6 + 5;
int dp[mxn], sum[mxn];

int exp(int a, int b) {
    a %= mod;

    int res = 1;

    while(b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b   /= 2;
    }
    return res;
}

int add(int a, int b) {
    a %= mod;
    b %= mod;
    int ret = a + b;
    if (ret > mod)ret -= mod;
    return ret;
}

void solve() {
    int n, k, m;cin>>n>>m>>k;
    dp[0] = 0;
    dp[1]= sum[1] = m;

    for (int i = 2; i <= n; i++) {
        if (i < k) {
            dp[i] = m * dp[i - 1] % mod;
        }
        else {
            //for (int c = 1; c < k; c++) dp[i] = add(dp[i], dp[i - c] * (m - 1) % mod);
            dp[i] = add(dp[i], (m - 1) * ((sum[i - 1] - sum[i - k] + mod) % mod) % mod);
        }
        sum[i] = add(dp[i], sum[i - 1]);

    }

    cout<<(exp(m, n) - dp[n] + mod) % mod<<endl;
}

int32_t main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    setIO("spainting");

    int t = 1;
    //cin>>t;

    while(t--) solve();
}
