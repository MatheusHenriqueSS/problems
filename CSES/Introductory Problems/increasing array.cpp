#include<bits/stdc++.h>
using namespace std;
 
const int mxN=2e5 +10;
int n,v[mxN];
long long resp;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
        if(i>0 && v[i]<v[i-1]){
            resp+=v[i-1]-v[i];
            v[i]+=v[i-1]-v[i];
        }
    }
 
 
    cout<<resp;
 
}
