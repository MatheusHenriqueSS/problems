#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long  soma=0;
     long long n,result;
     int x;
 
    cin>>n;
 
    result=n*(n+1)/2;
    for(int i=1;i<n;i++){
        cin>>x;
        soma+=x;
    }
 
    cout<<result-soma;
 
}
