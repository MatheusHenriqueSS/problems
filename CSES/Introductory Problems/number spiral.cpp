#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
int x,y;
int c;
int32_t main(){
    cin>>t;
    while(t--){
        cin>>x>>y;
        c=max(x,y);
 
        if(c%2==1){
            if(x==c){
                cout<<(long long)(y+(c-1)*(c-1))<<"\n";
            }
            else{
                cout<<(long long)(c*c-x+1)<<"\n";
            }
        }
        else{
            if(y==c){
                cout<<(long long)(x+(c-1)*(c-1))<<"\n";
            }
            else cout<<(long long)(c*c-y+1)<<"\n";
        }
 
    }
}
