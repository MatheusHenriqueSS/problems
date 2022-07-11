#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define f first
#define L(x) (x<<1)
#define R(x) ((x<<1)+1)
#define s second
#define lsb(x) ((x)&(-x))
#define all(x) x.begin(),x.end()
#define inf 1e9
typedef pair<int,int>ii;
typedef vector<int> vi;
const ll mod = 1e9 + 7;
    
void setIO(string S) {
    freopen((S+".in").c_str(),"r",stdin);
    freopen((S+".out").c_str(),"w",stdout);
}
    
int main(){_
    
    setIO("distribution");
    
    int t = 1;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
    
        vector<ll> ans;
        ll pow2 = 1;
        while(n){
            while (!(n&1)){
                pow2 *= 2;
                n /= 2;
            }
    
            ll pow3 = 1;
            while(pow3 * 3 <= n) pow3 *= 3; 
                
            n -= pow3;
            ans.pb(pow3 * pow2);
        }
    
        cout<<sz(ans)<<'\n';
        for(auto item : ans) cout<<item<<' ';
        cout<<'\n';
    }
    
    return 0;
    
}