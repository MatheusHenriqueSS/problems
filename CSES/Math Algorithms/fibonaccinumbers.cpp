#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int>vi;
typedef vector<vi>vii;
const int mxN=2e5+5,MOD=1e9+7;
//did u check when n=1?
//is mxN correct?
int n;
vii M={{1,1},{1,0}};
vi V={1,0};
vii mult(vii a,vii b){
    vii c(2,vi(2));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
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
    cin>>n;
    if(n==0){
        cout<<0;
        return 0;
 
    }
    if(n==1){
        cout<<1;
        return 0;
    }
    M=exp(M,n-1);
    vi ans(2);
    for(int i=0;i<2;i++){
        for(int k=0;k<2;k++){
            ans[i]=(ans[i]+(M[i][k]*V[k])%MOD)%MOD;
        }
    }
    cout<<ans[0]%MOD;
}
