#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1e6+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int mod(int a){int ret=a%M;if(ret<0)ret+=M;return ret;}
int exp(int a,int b){
    if(b==0LL)return 1LL;
    if(b==1LL)return mod(a);
    int t=mod(exp(a,b/2));
    if(b&1)return mod(a*mod(t*t));
    return mod(t*t);
}
string s;
int alfa[30];
int fat[mxN],inv[mxN];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inv[0]=fat[0]=1;
    for(int i=1;i<mxN;i++){
        fat[i]=(fat[i-1]*i)%M;
    }
    inv[mxN-1]=exp(fat[mxN-1],M-2);
    for(int i=mxN-2;i>=1;i--){
        inv[i]=(inv[i+1]*(i+1))%M;
    }
    cin>>s;
    for(auto c:s){
        alfa[c-'a']++;
    }
    int ans=fat[sz(s)];
    for(int i=0;i<26;i++)ans=mod(ans*inv[alfa[i]]);
    cout<<ans;
 
}
