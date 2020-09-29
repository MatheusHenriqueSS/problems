#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e7,M=1e9+9;
string s;
int x;
int32_t main(){
    cin>>s;
    for(auto c:s){
        x=(x*10+(c-'0'))%M;

    }
    //cout<<x;
    if(x==0 || x==1){
            cout<<"SIM";
            return 0;
    }
    int a=0,b=1,c;
    for(int i=0;i<mxN;i++){
        c=(a+b)%M;
        a=b;
        b=c;
        if(a==x || b==x){
            cout<<"SIM";
            return 0;
        }
        if(a==0 && b==1){
            cout<<"NAO";
            return 0;
        }
    }
    cout<<"NAO";
    return 0;
}
