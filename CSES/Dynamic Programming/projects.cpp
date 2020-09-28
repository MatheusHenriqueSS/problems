#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=4e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
struct pj{
    int s,f,m;
    bool operator < (const pj& p) const{
        return s>p.s;
    }
};
int n;
map<int,int>mp;
vector<int>aux;
priority_queue<pj>v;
int dp[mxN];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int a,b,c;
    for(int i=0;i<n;i++){
        cin>>a>>b>>c;
        b++;
        v.push({a,b,c});
        aux.pb(a);
        aux.pb(b);
    }
    sort(aux.begin(),aux.end());
    //sort(v.begin(),v.end());
    int idx=0;
    for(auto c:aux){
        if(mp.find(c)==mp.end()){
            mp[c]=++idx;
        }
    }
    for(int i=1;i<=idx;i++){
        dp[i]=max(dp[i-1],dp[i]);
        while(!v.empty() && mp[v.top().s]<i)v.pop();
        while(!v.empty() && mp[v.top().s]==i){
            pj u=v.top();
            v.pop();
            dp[mp[u.f]]=max(dp[mp[u.f]],dp[i]+u.m);
        }
        
    }
    cout<<dp[idx]<<"\n";
}
