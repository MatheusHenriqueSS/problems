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

int n,a,b,ans,s;
pii v[mxN];

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i].second>>v[i].first;
    }
    sort(v,v+n);
    for(int i=0;i<n;i++){
        //cout<<v[i].first<<" "<<v[i].second<<"\n";
        s+=v[i].second;
        ans=max(ans,max(0LL,s-v[i].first));
    }
    cout<<ans;
}
