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
int n,k;
int v[105];
int dp[mxN];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<k;i++)cin>>v[i];
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            if(v[j]<=i && !dp[i-v[j]])dp[i]=1;
        }
    }
    for(int i=1;i<=n;i++)cout<<(dp[i]==1?'W':'L');
}
