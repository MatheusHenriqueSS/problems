#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=2e5+10,M=1e9+7;
int n,v[mxN],k,ans;
// LONG LONG CASE
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    sort(v+1,v+n+1);

    if(n&1){
        k=v[n/2+1];
    }
    else k=(v[n/2]+v[n/2+1]+1)/2;
    //cout<<k<<"\n";
    for(int i=1;i<=n;i++){
        ans+=abs(k-v[i]);
        //cout<<v[i]<<" "<<ans<<"\n";
        
    }

    cout<<ans;
}