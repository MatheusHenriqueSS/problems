#include<bits/stdc++.h>
#define MAXN 1000010
using namespace std;
 
int n=0;
char seq[MAXN];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    while(cin>>seq[n]){
        n++;
    }
    int tot=1,resp=1;
    char x=seq[0],y;
 
    for(int i=1;i<n;i++){
        y=seq[i];
        if(y==x)tot++;
        else{
            x=y;
            resp=max(tot,resp);
            tot=1;
        }
    }
 
    resp=max(resp,tot);
 
    cout<<resp<<"\n";
 
