#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=5e3+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,v[mxN],pref[mxN];
int dp[2][mxN];
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;    
    for(int i=0;i<n;i++){
        cin>>v[i];
        pref[i+1]=pref[i]+v[i];
    }    
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(j<i)continue;
            if(i==j) dp[i&1][j]=v[i];
            else dp[i&1][j]=(pref[j+1]-pref[i])-min(dp[~i&1][j],dp[i&1][j-1]);
        }
    }
    cout<<dp[0][n-1];
}
