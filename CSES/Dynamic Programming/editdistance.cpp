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
int dp[mxN][mxN];
string s1=".",s2=">",x;
int n1,n2;
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>x;
    s1+=x;
    cin>>x;
    s2+=x;
    n1=sz(s1);
    n2=sz(s2);
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(i==0)dp[i][j]=j;
            else if(j==0)dp[i][j]=i;
            else if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1];
            else {
                dp[i][j]=1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
            }
 
        }        
    }
    
    cout<<dp[n1-1][n2-1];
 
}
