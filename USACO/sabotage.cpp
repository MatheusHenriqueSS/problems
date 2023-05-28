//Matheus Henrique de S. Silva
//28/05/2023
#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    freopen((s+ ".in").c_str(),"r",stdin);
    freopen((s+".out").c_str(),"w",stdout);
}

#define int long long
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"

typedef pair<int,int>ii;
typedef vector<int> vi;

vi a;
int n;

bool check(int x) {
    int total = 0ll;
    for (int i = 0; i < n; i++)total += a[i] -x;
    int cur, best;
    cur = a[1] - x;
    best = a[1] - x;

    for (int i = 2; i < n - 1; i++) {
        cur = max(cur, 0ll);
        cur += a[i] - x;
        best = max(best ,cur);
    }
    // cout<<x<<" "<<total<<" "<<best<<"\n";
    return total - best <= 0;
}

int32_t main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    setIO("sabotage");

    cin>>n;
    a.resize(n);

    for (int i = 0; i < n; i++)cin>>a[i];
    for (int i = 0; i < n; i++)a[i] = a[i] * 100000;

    int l = 1ll, r = 1000000000ll, ans = 1000000005ll;

    while(l <= r) {
        int mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }


    double val = (double)ans/100000.0;


    cout<<fixed<<setprecision(3)<<val<<"\n";
}
