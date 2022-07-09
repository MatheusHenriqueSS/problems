#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"

typedef pair<int,int>ii;
typedef vector<int> vi;

void solve() {
    int n; cin>>n;
    vector<ii> aux(n);

    for (int i = 0; i < n; i++)cin>>aux[i].first;
    for (int i = 0; i < n; i++)cin>>aux[i].second;

    int l = 0, r = 1e9, ans = 0;
    while(l <= r) {
        int mid = (l + r)/2;
        bool ok = true;
        vi a, b;
        for (int i = 0; i < n; i++)if(aux[i].first > mid) {
            a.pb(aux[i].first);
        }
        for (int i = 0; i < n; i++)if(aux[i].second > mid) {
            b.pb(aux[i].second);
        }

        if(sz(a) % 2 != 0 || sz(b) % 2 != 0) {
            l = mid + 1;   
        }
        else {
            for (int i = 0; i < sz(a); i += 2) {
                if(a[i + 1] != a[i]){
                    ok = false;
                    break;
                }
            }
            for (int i = 0; i < sz(b); i += 2) {
                if(b[i + 1] != b[i]){
                    ok = false;
                    break;
                }
            }

            if(!ok) {
                l = mid + 1;
            }
            else {
                ans = mid;
                r = mid - 1;
            }
        }
    }

    cout<<ans<<"\n";
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

    int t = 1;
    //cin>>t;

    while(t--) solve();
}