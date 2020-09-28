#include<bits/stdc++.h>
using namespace std;
int t,a,b,ok;
 
int main(){
    cin>>t;
    while(t--){
        cin>>a>>b;
        if(2*a-b>=0 && 2*b-a>=0 && (2*a-b)%3==0 && (2*b-a)%3==0){
            cout<<"YES\n";
        }
       else cout<<"NO\n";
    }
}
