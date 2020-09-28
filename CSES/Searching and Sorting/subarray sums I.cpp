#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,x,v[mxN];
int buscab(int k){
    int ini=k+1,fim=n,m;
    while(ini<=fim){
        m=(ini+fim)/2;
        if(v[m]-v[k]==x)return m;
        else if(v[m]-v[k]>x)fim=m-1;
        else ini=m+1;
    }
    return -1;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x;
    for(int i=0;i<n;i++){
        int k;cin>>k;
        v[i+1]=k+v[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(buscab(i)!=-1)ans++;
    }
    cout<<ans;  
}