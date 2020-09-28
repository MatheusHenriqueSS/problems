#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a=0,b=0;
vector<int>A,B;
int32_t main(){
    cin>>n;
    a=n;
    A.push_back(n);
    n--;
 
    while(n>0){
        if(abs(a-b-n)<abs(b-a-n)){
            b+=n;
            B.push_back(n);
        }
        else {
            a+=n;
            A.push_back(n);
        }
        n--;
       // cout<<a<<" "<<b<<"\n";
    }
 
 
    if(a==b){
        cout<<"YES\n";
        cout<<(int)A.size()<<"\n";
        for(auto it=A.begin();it!=A.end();it++)cout<<*it<<" ";
        cout<<"\n";
        cout<<(int)B.size()<<"\n";
        for(auto it=B.begin();it!=B.end();it++)cout<<*it<<" ";
        cout<<"\n";
    }
    else cout<<"NO";
 
}
