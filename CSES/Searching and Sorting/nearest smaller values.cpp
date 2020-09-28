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
int n,ans[mxN],x=0;
pii v[mxN];
set<int>s;
vector<int>temp;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    s.insert(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v+1,v+n+1);
    for(int i=1;i<=n;i++){
        if(v[i].first!=x){
            x=v[i].first;
            for(int c:temp)s.insert(c);
            temp.clear();
        }
        auto it=s.lower_bound(v[i].second);it--;
        ans[v[i].second]=*it;
        temp.pb(v[i].second);
        
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}