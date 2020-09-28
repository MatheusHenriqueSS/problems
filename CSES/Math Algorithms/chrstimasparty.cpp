#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=1e9+7,mxN=1e6+10;
int fat[mxN],inv[mxN],n;
int mod(int a,int M){int ret=a%M;if(ret<0)ret+=M;return ret;}
int exp(int a,int b,int M){
    if(b==0LL)return 1LL;
    if(b==1LL)return mod(a,M);
 
    int t=exp(a,b/2,M);
    if(b%2==0)return mod(t*t,M);
    return mod(a*mod(t*t,M),M);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fat[0]=inv[0]=1;
    for(int i=1;i<=n;i++){
        fat[i]=(i*fat[i-1])%M;
        //cout<<fat[i]<<" ";
    }
    //cout<<"\n";
    inv[n]=exp(fat[n],M-2,M);
    //cout<<inv[n]<<" ";
    for(int i=n-1;i>=1;i--){
        inv[i]=(inv[i+1]*(i+1))%M;
        //cout<<inv[i]<<" ";
    }   
    int resp=0LL;
    for(int i=0;i<=n;i++){
        if(i%2==0)resp=mod(resp+mod(fat[n]*inv[i],M),M);
        else resp=mod(resp-mod(fat[n]*inv[i],M),M);
    }
 
    cout<<resp;
}
