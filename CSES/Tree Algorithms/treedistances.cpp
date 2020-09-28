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
int n,dp[2][mxN],ans[mxN],d[mxN];
vi adj[mxN];
void dfs(int i,int p){
    for(int j:adj[i])if(j!=p){
        dfs(j,i);
        d[i]=max(d[i],d[j]+1);
    
    }
}
void dfs1(int i,int p,int pd){
    ans[i]=max(d[i],pd);
    vector<pii>v={{pd,-1}};
    for(int j:adj[i])if(j!=p){
        v.push_back({d[j]+1,j});
    }
    v.pb({0,-1});
    sort(v.begin(),v.end(),greater<pii>());
    for(int j:adj[i])if(j!=p){
        dfs1(j,i,1+(v[0].second==j?v[1].first:v[0].first));
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
    dfs1(0,-1,0);
    for(int i=0;i<n;i++)cout<<ans[i]<<" ";    
}
