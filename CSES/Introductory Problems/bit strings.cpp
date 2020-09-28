#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7;
int n;
int mod(int x,int M){int ret=x%M;if(ret<0)ret+=M;return ret;}
int exp(int a,int b,int M){
    if(b==0LL)return 1LL;
    if(b==1LL)return mod(a,M);
 
    int t=exp(a,b/2,M);
    if(b%2==1){
        return mod(a*mod(t*t,M),M);
 
    }
    return mod(t*t,M);
}
 
 
int32_t main(){
    cin>>n;
    cout<<exp(2,n,M);
 
}
 
