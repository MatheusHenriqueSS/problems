#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,MOD=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m,k;
vii mult(vii a,vii b){
    vii c(n,vi(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                c[i][j]=(c[i][j]+(a[i][k]*b[k][j])%MOD)%MOD;
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
    vii M(n,vi(n));
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;a--;b--;
        M[a][b]++;
    }
    M=exp(M,k);
    vi V(n),ans(n);
    V[n-1]=1;
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            ans[i]=(ans[i]+(M[i][k]*V[k])%MOD)%MOD;
        }
    }
    cout<<ans[0]%MOD;
}
