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
int n;
double dp[105][10][10],ans[10][10];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++)ans[i][j]=1;
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<=n;k++){
                for(int i2=0;i2<8;i2++){
                    for(int j2=0;j2<8;j2++){
                        dp[k][i2][j2]=0;
                    }
                }
            }
            dp[0][i][j]=1;
            for(int k=0;k<n;k++){
                for(int i2=0;i2<8;i2++){
                    for(int j2=0;j2<8;j2++){
                        int cnt=(i2>0)+(i2<7)+(j2>0)+(j2<7);
                        if(i2>0)dp[k+1][i2-1][j2]+=dp[k][i2][j2]/cnt;
                        if(i2<7)dp[k+1][i2+1][j2]+=dp[k][i2][j2]/cnt;
                        if(j2>0)dp[k+1][i2][j2-1]+=dp[k][i2][j2]/cnt;
                        if(j2<7)dp[k+1][i2][j2+1]+=dp[k][i2][j2]/cnt;                       
                    }
                }
            }
            for(int i2=0;i2<8;i2++){
                for(int j2=0;j2<8;j2++){
                    ans[i2][j2]*=(1-dp[n][i2][j2]);
                }
            }
        }
    }
    double res=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            res+=ans[i][j];
        }
    }
    cout<<fixed<<setprecision(6)<<res;
 
 
}
