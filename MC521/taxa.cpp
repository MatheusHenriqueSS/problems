#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=405,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,vis[mxN][mxN];
double t;
double dp[mxN][mxN],v[mxN],pref[mxN];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        v[i+n]=v[i];
    }
    for(int i=1;i<=2*n;i++)pref[i]=pref[i-1]+v[i];
    for(int i=2*n;i>=1;i--){
        for(int j=i+1;j<=2*n;j++){
            for(int k=i;k<j;k++){
                double tmp=dp[i][k]+dp[k+1][j]+t*max(pref[k]-pref[i-1],pref[j]-pref[k]);
                dp[i][j]=(dp[i][j]==0?tmp:min(dp[i][j],tmp));
            }
        }
    }
    double ans=0;
    for(int i=1;i<=n;i++){
        ans=(ans==0?dp[i][i+n-1]:min(ans,dp[i][i+n-1]));
    }
    cout<<fixed<<setprecision(2)<<ans;
    
}
