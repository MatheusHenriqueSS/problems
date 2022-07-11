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
        setIO("hash");
     
        int k;
        cin >> k;
        
        string ans = string(1000, 'B');
     
        cout << ans << '\n';
        k--;
        for (int i = 0; i < k; i++) {
            ans[i]--;
            ans[i + 1] += 31;
            cout << ans << '\n';
            ans[i]++;
            ans[i + 1] -= 31;
        }
        return 0;
    }