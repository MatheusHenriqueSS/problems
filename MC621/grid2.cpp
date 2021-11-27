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
int mod(int a){int ret=a%M;if(ret<0)ret+=M;return ret;}
int exp(int a,int b){
    if(b==0LL)return 1LL;
    if(b==1LL)return mod(a);
    int t=exp(a,b/2);
    if(b&1)return mod(a*mod(t*t));
    return mod(t*t);
}
int h,w,n;
int fat[mxN],inv[mxN],dp[mxN];
vector<pii> aux;
bool comp(pii a,pii b){
    return a.first+a.second<b.first+b.second;
}
int add(int a,int b){
    return (a+b)%M;
}
int mul(int a,int b){
    return (a*b)%M;
}
int sub(int a,int b){
    return (a-b+M)%M;
}
int solve(int a,int b){
    return mul(fat[a+b],mul(inv[a],inv[b]));
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fat[0]=inv[0]=1;
    for(int i=1;i<mxN;i++){
        fat[i]=(fat[i-1]*i)%M;
    }
    inv[mxN-1]=exp(fat[mxN-1],M-2);
    for(int i=mxN-2;i>=1;i--)inv[i]=(inv[i+1]*(i+1))%M;
    cin>>h>>w>>n;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        aux.pb({x,y});
    }
    sort(aux.begin(),aux.end(),comp);
    aux.pb({h,w});
    for(int i=0;i<=n;i++){
        int cur=solve(aux[i].first-1,aux[i].second-1);
        for(int j=0;j<i;j++){
            if(aux[j].first<=aux[i].first && aux[j].second<=aux[i].second){
                cur=sub(cur,mul(dp[j],solve(aux[i].first-aux[j].first,aux[i].second-aux[j].second)));
            }
        }
        dp[i]=cur;
    }
    cout<<dp[n];
    
}
