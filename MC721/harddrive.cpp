#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
    
typedef pair<int,int>ii;
typedef vector<int> vi;
    
const int mod = 1e9 + 7;
    
int main(void) {_
    int t = 1;
    
    while(t--){
        int n, c, b;cin>>n>>c>>b;
        int ans[n] = {0};
    
        vi a;
    
        for (int i = 0; i < b; i++) {
            int x;cin>>x;x--;
            a.pb(x);
        }
    
        ans[0] = c&1;
        int index = 0, val = 0;
        for (int i = 1; i < n; i++) {
            if (i == a[index]){
                index++;
                continue;
            }
            ans[i] = 1 - ans[i - 1];
        }
    
    
        for (int i = 1; i < n; i++) {
            if (ans[i] != ans[i - 1])val++;
        }
        index = 0;
        for (int i = 1; i < n - 1; i++) {
            if (val == c)break;
            if (i == a[index]){
                index++;
                continue;
            }
            if (ans[i - 1] == ans[i + 1] && ans[i - 1] != ans[i]) {
                ans[i] = 1 - ans[i];
                val -= 2;
            }
        }
    
        for (int i = 0; i < n; i++)cout<<ans[i];
        cout<<"\n";
        
    }
    return 0;
}