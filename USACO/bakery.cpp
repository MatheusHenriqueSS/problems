//Matheus Henrique de S. Silva
//10/06/2023
#include<bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    freopen((s+ ".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

#define int long long


const int mxn = 105;
int a[mxn], b[mxn], c[mxn];
int n, tc, tb;


bool check(int w) {
    int l = tc - w, r = tc + tb - w - 1;
    for (int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            if(a[i] * (tc + tb - w) > c[i])return false;
        }
        else if(a[i] > b[i]) {
            int cur = c[i] - b[i]*(tc + tb - w);
            // cout<<i<<" "<<cur<<"\n";
            cur /= a[i] - b[i];
            r = min(r, cur);
            // cout<<i<<" "<<cur<<"\n";
        }
        else {
        //have to round up to guarantee that x >= l
            int cur = c[i] - b[i]*(tc + tb - w);
            // cout<<i<<" "<<cur<<"\n";
            cur += (cur >= 0) ? -(a[i] - b[i] + 1): a[i] - b[i] + 1;
            // cout<<i<<" "<<cur<<"\n";
            cur /= a[i] - b[i];
            // cout<<i<<" "<<cur<<"\n";
            l = max(l, cur);
        }
    }

    // cout<<w<<" "<<l<<" "<<r<<"\n";

    return l <= tc && r >= 1 && l <= r;

}

void solve() {
    cin>>n>>tc>>tb;

    for (int i = 0; i < n; i++)cin>>a[i]>>b[i]>>c[i];

    int l = 0, r = tc + tb - 2, ans = tc + tb - 2;

    while (l <= r) {
        int mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout<<ans<<"\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    // setIO("convention");
    int t;cin>>t;
    while(t--)solve();
}
