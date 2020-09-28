#include<bits/stdc++.h>
using namespace std;
#define int long long
 
int n;
 
int C(int n){
    return n*(n-1)/2;
}
int32_t main(){
    cin>>n;
 
    for(int i=1;i<=n;i++){
        if(i==1)cout<<0<<"\n";
        else cout<<C(i*i)-((i-1)*(i-2)*4)<<"\n";
    }
 
 
