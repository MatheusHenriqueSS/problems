#include<bits/stdc++.h>
using namespace std;

int main(){
    int cid[4];
    for(int i=0;i<4;i++){
        cin>>cid[i];
    }
    sort(cid,cid+4);

    if(cid[3]*cid[0]==cid[1]*cid[2] || cid[3]*cid[1]==cid[0]*cid[2]){
        cout<<"S";
    }
    else cout<<"N";
}
