#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,MOD=1e9+7,INF=1e18+100;
//did u check when n=1?
//is mxN correct?
int n,m,k;
vii mult(vii a,vii b){
    vii c(n,vi(n,INF));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j]=min(c[i][j],(a[i][k]+b[k][j]));
            }
        }
    }
    return c;
}
vii exp(vii a,int b){
    if(b==1)return a;
    vii t=exp(a,b/2);
    if(b&1)return mult(a,mult(t,t));
    return mult(t,t);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    vii M(n,vi(n,INF));
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;a--;b--;
        M[a][b]=min(M[a][b],c);
    }
 
    M=exp(M,k);
    cout<<(M[0][n-1]==INF?-1:M[0][n-1]);    
 
    //cout<<ans;
 
}
