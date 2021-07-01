#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,c,d,e,f,g;
    cin>>n;
    cin>>a>>b>>c>>d>>e>>f>>g;
    n-=g;

    if(a+b+c-d-e-f==n)cout<<"N\n";
    else cout<<"S\n";
}
