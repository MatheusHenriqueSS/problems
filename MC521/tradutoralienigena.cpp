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
string s1,s2;
int l1,l2,dp[mxN];
int check(int l,int r){
    if(r-l+1<l1)return l;
    for(int i=0;i<l1;i++){
        if(s1[i]==s2[i+l])continue;
        if(s1[i]>s2[i+l])return l;
        if(s1[i]<s2[i+l])return l+1;        
    }
    return l;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp[0]=1;
    cin>>s1>>s2;
    l1=sz(s1);
    l2=sz(s2);
    for(int i=0;i<l2;i++){
        int l=check(max(0LL,i-l1+1),i);
        for(;l<=i;l++){
            if(s2[l]=='0')continue;
            dp[i+1]=(dp[i+1]+dp[l])%M;
        }
    }
    cout<<dp[l2]%M;
}
