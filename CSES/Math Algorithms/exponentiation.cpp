#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=2e5,M=1e9+7;
int mod(int a,int M){int ret=a%M;if(ret<0)ret+=M;return ret;}
int exp(int a,int b,int M){
    if(b==0LL)return 1LL;
    if(b==1LL)return mod(a,M);
    int t=exp(a,b/2,M);
    if(b&1)return mod(a*mod(t*t,M),M);
    return mod(t*t,M);
}
int t;
void solve(){
    int a,b;
    cin>>a>>b;
    cout<<exp(a,b,M)<<"\n";
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    while(t--)solve();
}
