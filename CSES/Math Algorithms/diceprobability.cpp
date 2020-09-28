#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,a,b;
double dp[105][605];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>a>>b;
    dp[0][0]=1.0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=6*i;j++){
            for(int k=1;k<=6;k++){
                if(k<=j){
                    dp[i][j]+=(double)(1.0/6.0)*dp[i-1][j-k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=6*i;j++){
            dp[i][j]+=dp[i][j-1];
        }
    }
    cout<<fixed<<setprecision(6)<<(dp[n][b]-dp[n][a-1]);
    
}
