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
int mod(int a,int M){int ret=a%M;if(ret<0)ret+=M;return ret;}
int exp(int a,int b,int M){
    if(b==0LL)return 1LL;
    if(b==1LL)return mod(a,M);
    int t=mod(exp(a,b/2,M),M);
    if(b&1)return mod(a*mod(t*t,M),M);
    return mod(t*t,M);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,a,b,c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        cout<<exp(a,exp(b,c,M-1),M)<<"\n";
    }
}
