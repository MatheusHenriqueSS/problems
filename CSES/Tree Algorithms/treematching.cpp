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
//dp se eu uso o cara com um filho-> n usando esse filho + max de dp de qq um dos filhos +1;
//se eu n uso max de todos os filhs 
int n,dp[2][mxN];
vi adj[mxN];
void dfs(int i,int p){
    //if(sz(adj[i]))return;
    for(int j:adj[i])if(j!=p){
        dfs(j,i);
        dp[0][i]+=max(dp[0][j],dp[1][j]);
    }
    for(int j:adj[i])if(j!=p){
        dp[1][i]=max(dp[1][i],1+dp[0][i]-max(dp[0][j],dp[1][j])+dp[0][j]);
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);
    cout<<max(dp[0][0],dp[1][0]);
}
