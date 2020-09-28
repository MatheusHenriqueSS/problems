#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=25;
int n,a,b,v[mxN];
int resp=2e10 +10;
 
int solve(int index=0,int a=0,int b=0){
    if(index==n){
        return resp=min(resp,abs(a-b));
 
    }
    solve(index+1,a+v[index],b);
    solve(index+1,a,b+v[index]);
}
 
 
int32_t main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    solve();
    cout<<resp;
 
}
Test d
