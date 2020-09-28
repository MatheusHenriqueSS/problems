#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
 
//did u check when n=1?
//is mxN correct?
const int mxN=1e5+5;
int dp[110][mxN];
int n,val[110];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>val[i];
 
    for(int i=0;i<=n;i++){
        for(int j=0;j<=mxN;j++){
            if(j==0)dp[i][j]=1;
            if(i==0)continue;
            else{
                if(dp[i-1][j])dp[i][j]=1;
                else if(val[i]<=j && dp[i-1][j-val[i]]==1)dp[i][j]=1;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=100000;i++){
        if(dp[n][i])ans++;
    }
    cout<<ans<<"\n";
    for(int i=1;i<=100000;i++)if(dp[n][i])cout<<i<<" ";
    //o valor do número é o "peso"
    //o valor é apenas saber se eu posso ou n
}
