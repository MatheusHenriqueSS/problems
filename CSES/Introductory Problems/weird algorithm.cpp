#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;
 
long long n;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>n;
 
    while(n!=1){
        cout<<n<<" ";
        if(n%2==0){
            n=n/2;
        }
        else{
            n=3*n+1;
        }
    }
    cout<<n<<"\n";
}
