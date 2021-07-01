#include<bits/stdc++.h>
#define debug3(x,y,z) cout<<x<<" "<<y<<" "<<z;
using namespace std;

int n,tot=0;
vector<int>a;

int kadane(int k){
    int resp=0,maior=0;
    for(int i=0;i<n;i++){
        maior=max(0,maior+k*a[i]);
        resp=max(resp,maior);
    }

    return resp;
}

int main(){
    cin>>n;

    for(int i=0,x;i<n;i++){
        cin>>x;
        tot+=x;
        a.push_back(x);

    }

    int max_kadane=kadane(1);
    int max_wrap=kadane(-1);
    cout<<max(max_kadane,max_wrap+tot);
}
