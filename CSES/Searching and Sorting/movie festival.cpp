#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
typedef pair<int,int>pii;
const int mxN=2e5,M=1e9+7;
int n;
pii v[mxN];
int a,b;
bool comp(pii a,pii b){
    return a.second<b.second;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v,v+n,comp);
    int ans=0;
    for(int i=0;i<n;i++){
        if(v[i].first>=a){
            a=v[i].second;
            ans++;
        }
    }
    
    cout<<ans;
}