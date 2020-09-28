#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=505,M=1e18+5;
//did u check when n=1?
//is mxN correct?
int n,m,q;
int adj[mxN][mxN];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    for(int i=0;i<mxN;i++){
        for(int j=0;j<mxN;j++){
            if(i==j)continue;
            adj[i][j]=M;
        }
    }
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        adj[a][b]=min(adj[a][b],c);
        adj[b][a]=min(adj[b][a],c);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    while(q--){
        int a,b;cin>>a>>b;
        int ans=min(adj[a][b],adj[b][a]);
        cout<<(ans==M?-1:ans)<<"\n";
    }
}
