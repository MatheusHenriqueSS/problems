#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=130000,M=1e9+7;
int mod(int a){int ret=a%M;if(ret<0)ret+=M;return ret;}
//did u check when n=1?
//is mxN correct?
int n,cnt;
int dp[mxN];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    cnt=(n*(n+1))/2;
    if(cnt&1){
        cout<<0;
        return 0;
    }
    dp[0]=1;
    for(int i=1;i<=n-1;i++){
        for(int j=cnt/2;j>=1;j--){
            if(i<=j)dp[j]=mod(dp[j]+dp[j-i]);
        }
    }
    cout<<dp[cnt/2];
}
