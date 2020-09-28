#include<bits/stdc++.h>
using namespace std;
#define int long long
 
const int mxN=1000005,M=1e9+7;
int n,a,b,tot;
int fat[mxN],inv[mxN];
int mod(int x,int M){int ret=x%M;if(ret<0)ret+=M;return ret;}
 
int exp(int a,int b,int M){
    if(b==0LL)return 1LL;
    if(b==1LL)return mod(a,M);
 
    int t=mod(exp(a,b/2,M),M);
    if(b%2==1)return mod(a*mod(t*t,M),M);
    return mod(t*t,M);
 
}
int C(int n,int k){
    int ans=mod(fat[n]*inv[n-k],M);
    return mod(ans*inv[k],M);
}
 
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin>>n;
    fat[0]=inv[0]=1; 
    for(int i=1;i<mxN;i++){
        fat[i]=(i*fat[i-1]%M); 
    }
    inv[mxN-1] = exp(fat[mxN-1],M-2,M);
	for(int i=mxN-2;i>=1;i--){
		inv[i] = (inv[i+1]*(i+1))%M;
	}
    for(int i=0;i<n;i++){
        cin>>a>>b;
        cout<<C(a,b)<<"\n";
    }
 
 
 
 
}
