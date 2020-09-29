#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=110,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,v[mxN],ans=1;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<n;i++){
        if(v[i]!=v[i-1])ans++;
    }
    cout<<ans;
}
