#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
typedef pair<int,int>pii;
const int mxN=2e5+10,M=1e9+7;
int n,k,x;
pii v[mxN];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x;
        v[i]={x,i+1};
    }
    sort(v,v+n);
    int ini=0,fim=n-1;
    while(ini<fim){
        if(v[ini].first+v[fim].first==k){
            cout<<min(v[ini].second,v[fim].second)<<" "<<max(v[ini].second,v[fim].second);
            return 0;
        }
        else if(v[ini].first+v[fim].first>k)fim--;
        else ini++;
    }
    cout<<"IMPOSSIBLE";

}