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
int pref[mxN];
map<int,int>mp;
int mod(int a){int ret=a%n;if(ret<0)ret+=n;return ret;}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        pref[i+1]=mod(pref[i]+x);
    }
    mp[0]=1;
    int ans=0;
    for(int i=1;i<=n;i++){
        ans+=mp[pref[i]];
        mp[pref[i]]++;
    }
    cout<<ans;
}