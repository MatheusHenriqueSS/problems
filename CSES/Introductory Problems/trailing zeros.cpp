#include<bits/stdc++.h>
using namespace std;
 
int n,resp,k=5;
int main(){
 
    cin>>n;
    while(n>=k){
        resp+=n/k;
        k*=5;
    }
 
    cout<<resp;
}
