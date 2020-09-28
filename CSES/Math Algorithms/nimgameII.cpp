#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1e6+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int dp[mxN];
void solve(){
    int n,a=0;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        a^=x;
    }
    cout<<(a%4==0?"second\n":"first\n");
 
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;cin>>t;
    while(t--)solve();
    
}
