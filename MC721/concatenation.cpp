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

int cur[26];
int main(){_
    setIO("concatenation");
    string a,b;cin>>a>>b;
    
    int lena = sz(a), lenb = sz(b);
    
    for (char c: a) {
        cur[(int)c-'a']++;
    }
    
    cur[(int)a[0] - 'a']--;
    
    ll ans = (ll)lena * (ll)lenb;
    
    for (int i = 0; i < lenb - 1; i++) {
        ans -= (ll)cur[(int)b[i] - 'a'];
    }
    
    cout<<ans<<"\n";
    
    return 0;
    
}