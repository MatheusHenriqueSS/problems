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
int n;
int v[mxN];
int solve(){
    vector<int>aux;
    for(int i=0;i<n;i++){
        auto it=lower_bound(aux.begin(),aux.end(),v[i]);
        if(it==aux.end())aux.pb(v[i]);
        else *it=v[i];
    }
    return sz(aux);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
 
    }
    cout<<solve();
}
