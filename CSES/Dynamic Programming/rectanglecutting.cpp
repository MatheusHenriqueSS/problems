#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=5e2+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int dp[mxN][mxN]={mxN};
int a,b;
 
int32_t main(){
 
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j)dp[i][j]=0;
            else{
                int temp=M;
                //cout<<i<<" "<<j<<"\n";
                for(int k=1;k<=i/2;k++){
                    //cout<<k<<" "<<j<<"\n";
                    //cout<<dp[k][j]<<"\n";
                    
                    temp=min(temp,dp[i-k][j]+dp[k][j]+1);
                    
                }
                for(int k=1;k<=j/2;k++){
                    //cout<<i<<" "<<k<<"\n";
                    //cout<<dp[i][k]<<"\n";
                    if(k!=j){
                    temp=min(temp,dp[i][j-k]+dp[i][k]+1);
                    }
                }
                dp[i][j]=temp;
                //cout<<dp[i][j]<<"\n";
                //cout<<"\n";
            }
        }
    }
    cout<<dp[a][b];
  
    
}
