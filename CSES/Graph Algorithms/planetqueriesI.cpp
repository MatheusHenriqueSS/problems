#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,mxM=31,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,q,adj[mxN];
int anc[mxN][mxM];
int dfs(int i,int k){
    //cout<<i<<" "<<k<<"\n";
    if(k==0)return i;
    for(int j=30;j>=0;j--){
        if(k>=(1<<j)){
            return dfs(anc[i][j],k-(1<<j));
        }
    }
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>adj[i];
        anc[i][0]=adj[i];
    }
    for(int j=1;j<mxM;j++){
        for(int i=1;i<=n;i++){
            if(anc[i][j-1]){
                anc[i][j]=anc[anc[i][j-1]][j-1];
            }
        }
    }
    while(q--){
        int a,b;cin>>a>>b;
        cout<<dfs(a,b)<<"\n";
        //cout<<"\n";
    }
}
