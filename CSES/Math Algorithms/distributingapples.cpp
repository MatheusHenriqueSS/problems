    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    
    const int mxN=1000005,M=1e9+7;
    int n,a,b,tot,m;
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
    int ans=1LL;
    for(int i=n;i>=n-k+1;i--){
        ans=mod(ans*i,M);
    }
    return mod(ans*inv[k],M);
}
 
    
    int32_t main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0); 
        cin>>n>>m;
        fat[0]=inv[0]=1; 
        for(int i=1;i<mxN;i++){
            fat[i]=(i*fat[i-1]%M); 
        }
        inv[mxN-1] = exp(fat[mxN-1],M-2,M);
        for(int i=mxN-2;i>=1;i--){
            inv[i] = (inv[i+1]*(i+1))%M;
        }
        cout<<C(n+m-1,m);
    
    }
