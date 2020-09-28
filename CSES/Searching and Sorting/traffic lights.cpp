#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
//#define int long long
typedef pair<int,int>pii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m;
multiset<int>res;
set<pii>s;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    res.insert(n);
    s.insert({0,n});
    for(int i=0;i<m;i++){
        int x;cin>>x;
        auto it =s.upper_bound({x,0});it--;
        pii temp=*it;
        s.erase(it);
        auto itr=res.find(temp.second-temp.first);
        if(itr!=res.end())res.erase(itr);
        s.insert({temp.first,x});
        s.insert({x,temp.second});
        res.insert({x-temp.first});
        res.insert({temp.second-x});
        auto ans=res.rbegin();
        cout<<*ans<<" ";
    }
}