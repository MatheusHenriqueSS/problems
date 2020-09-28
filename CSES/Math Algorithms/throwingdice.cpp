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
vi V={32,16,8,4,2,1};
int n,dp[mxN];
vii mult(vii a,vii b){
    vii c(6,vi(6));
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            for(int k=0;k<6;k++){
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
    vii M(6,vi(6));
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(i==0)M[i][j]=1;
            if(j+1==i)M[i][j]=1;
        }
    }
    cin>>n;
    if(n<=6){
        cout<<V[6-n];
        return 0;
    }
    M=exp(M,n-6);
    vi ans(6);
    for(int i=0;i<6;i++){
        for(int k=0;k<6;k++){
            ans[i]=(ans[i]+(M[i][k]*V[k])%MOD)%MOD;
        }
    }
    cout<<ans[0]%MOD;   
}
