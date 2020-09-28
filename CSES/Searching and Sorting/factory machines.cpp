#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=2e5+5,mxT=1e18+5,M=1e9+7;
int n,t;
int v[mxN];
 
int calc(int x){
    int ans=0LL;
    for(int i=0;i<n;i++){
        ans+=x/v[i];
        if(ans>=t)break;
    }
    return ans;
}
 
int buscab(){
    int ini=0,fim=mxT,m,resp;
    while(ini<=fim){
        m=(ini+fim)/2;
        //cout<<m<<"\n";
        if(calc(m)>=t){
            resp=m;
            fim=m-1;
        }
        else ini=m+1;
    }
    return resp;
}
 
//did u check when n=1?
//is mxN correct?
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>t;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<buscab();
 
}
