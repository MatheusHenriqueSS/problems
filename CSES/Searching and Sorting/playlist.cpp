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
int n,ans=1,temp,x;
vector<int>aux;
map<int,int>mp;
int v[mxN],a[mxN];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        aux.pb(a[i]);
        

    }
    sort(aux.begin(),aux.end());
    int idx=0;
    for(int c:aux){
        if(mp.find(c)==mp.end())mp[c]=++idx;
    }
    for(int i=1;    i<=n;i++){
        temp++;
        a[i]=mp[a[i]];
        //cout<<temp<<" "<<a[i]<<" "<<v[a[i]]<<"\n";
        temp=min(temp,i-v[a[i]]);    
        ans=max(ans,temp);
        //cout<<ans<<"\n";
        v[a[i]]=i;
       
    }
    cout<<ans;
    



}