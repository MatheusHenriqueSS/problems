#include <bits/stdc++.h>
using namespace std;
    
#define int long long
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"
    
typedef pair<int,int>ii;
typedef vector<int> vi;
    
const int inf = 1e18;
    
int log(int x) {
    int ans = 0;
    while(x > 1) {
        x /= 2;
        ans++;
    }
    
    return ans;
}
    
void solve() {
    int n;cin>>n;
    vi a(n - 1);
    int ma;cin>>ma;
    
    for (int i = 0; i < n - 1; i++){
        int x;cin>>x;
        a[i] = ma - x;
    }
    
    sort(a.begin(), a.end());
    int last = -1, counter = 0;
    
    vector<ii> b;
    
    
    for (int i = 0; i < n - 1; i++){
        if(a[i] == last)counter++;
        else {
            if(last != -1)b.pb({last, counter});
            counter = 1;
            last = a[i];
        }
    }
    
    b.pb({last, counter});
    
    
    int t = inf, pos = b[0].first;
    counter = 0;
    
    int ans = 0;
    for (ii p: b) {
        p.first -= ans;
        assert(p.first >= 0);
        assert(p.first >= pos);
        int cat = (p.first - pos) * (log(counter) + 1);
        if(cat > t)break;
        pos -= (p.first - pos) * log(counter);
        assert(pos >= 0);
        ans += cat;
        counter += p.second;
        if(counter >= 2) {
            t = pos + pos/log(counter);
        }
    }
    cout<<ans+t<<"\n";
}
    
int32_t main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    
    int t = 1;
    while(t--) solve();
}