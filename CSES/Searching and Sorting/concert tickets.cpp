#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define int long long
#define sz(x) (int)x.size()
typedef pair<int,int>pii;
const int mxN=2e5,M=1e9+7;
int n,m,x;
int a[mxN];
multiset<int>v;
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        v.insert(x);
    }    
    for(int i=0;i<m;i++){
        cin>>x;
        auto it=v.upper_bound(x);
        if(it==v.begin())cout<<-1<<"\n";
        else{
            it--;
            cout<<*it<<"\n";
            v.erase(it);
        }
    }
 
}
