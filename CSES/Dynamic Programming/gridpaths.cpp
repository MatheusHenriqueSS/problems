#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=1e3+5,M=1e9+7;
//did u check when n=1?
//is mxN correct
int n;
int dp[mxN][mxN];
char matriz[mxN][mxN];
int vis[mxN][mxN];
int mod(int a){int ret=a%M;if(ret<0)ret+=M;return ret;}
int solve(int h,int w){
    if(matriz[h][w]=='*')return 0;
    if(h==0 && w==0)return 1;
    if(h==0)return mod(solve(h,w-1));
    if(w==0)return mod(solve(h-1,w));
    if(dp[h][w]>=0)return mod(dp[h][w]);
    return dp[h][w]=mod(solve(h-1,w)+solve(h,w-1));
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matriz[i][j];
        }
    }
    cout
