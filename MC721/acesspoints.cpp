#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
    
typedef pair<int,int>ii;
typedef vector<int> vi;
    
const int mod = 1e9 + 7;
const int mxn = 1e5 + 5;
    
int main(void) {_

    int t = 1;
    
    while(t--){
        int n;cin>>n;
        double s[mxn][2];
        double x[mxn], y[mxn];
    
        for (int i = 0; i < n; i++) {
            cin>>s[i][0]>>s[i][1];
        }
    
        double meta[mxn];
        int last = 0;
        int st[mxn];
        for (int i = 0; i < n; i++) {
            if (s[i][0] >= last) {
                x[i] = s[i][0];
                st[i] = i;
                meta[i] = s[i][0];
            }
            else {
                meta[i] = meta[i - 1] + s[i][0];
                st[i] = st[i - 1];
                x[i] = meta[i] / (double)(i - st[i] + 1);
                while (st[i] != 0 && x[st[i] - 1] > x[i]) {
                    meta[i] += meta[st[i] - 1];
                    st[i] = st[st[i] - 1];
                    x[i] = meta[i] / (double)(i - st[i] + 1);
                }
            }
            last = x[i];
        }
        
        for (int i = n - 2; i >= 0; i--) {
            x[i] = min(x[i], x[i + 1]);
        }
    
        last = 0;
    
        for (int i = 0; i < n; i++) {
            if (s[i][1] >= last) {
                y[i] = s[i][1];
                st[i] = i;
                meta[i] = s[i][1];
            }
            else {
                meta[i] = meta[i - 1] + s[i][1];
                st[i] = st[i - 1];
                y[i] = meta[i] / (double)(i - st[i] + 1);
                while (st[i] != 0 && y[st[i] - 1] > y[i]) {
                    meta[i] += meta[st[i] - 1];
                    st[i] = st[st[i] - 1];
                    y[i] = meta[i] / (double)(i - st[i] + 1);
                }
            }
            
            last = y[i];
        }
        
        for (int i = n - 2; i >= 0; i--) {
            y[i] = min(y[i], y[i + 1]);
        }
    
        double ans = 0.0;
    
        for (int i = 0; i < n; i++) {
            ans += (x[i] - s[i][0]) * (x[i] - s[i][0]);
        }
    
        for (int i = 0; i < n; i++) {
            ans += (y[i] - s[i][1]) * (y[i] - s[i][1]);
        }
    
        cout<<fixed<<setprecision(10)<<ans<<"\n";
    
    }
    return 0;
}