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
int n,sz[mxN];
vi adj[mxN];
void dfs(int i,int p){
    sz[i]=1;
    for(int j:adj[i]){
        if(j!=p){
            dfs(j,i);
            sz[i]+=sz[j];
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int x;cin>>x;x--;
        adj[x].pb(i);
    }
    dfs(0,-1);
    for(int i=0;i<n;i++)cout<<sz[i]-1<<" ";
}
