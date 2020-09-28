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
int n,q,anc[mxN][20];
vi adj[mxN];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;  
    for(int i=2;i<=n;i++){
        int x;cin>>x;
        adj[x].pb(i);
        anc[i][0]=x;
    }
    for(int j=1;j<=19;j++){
        for(int i=1;i<=n;i++){
            anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
 
    while(q--){
        int a,k;cin>>a>>k;
        for(int j=19;j>=0;j--){
            if(k>=(1<<j)){
                k-=(1<<j);
                a=anc[a][j];
                //cout<<k<<" "<<a<<"\n";
            }
        }
        cout<<(a==0?-1:a)<<"\n";
    }
}
