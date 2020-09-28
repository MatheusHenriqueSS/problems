#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=5e3+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m;
pii v[mxN];
pii solve(int sum,int ini,int fim){
    int l=k+1,r=n;
    while(l<r){
        if(v[l].first+v[r].first==sum)return {v[l].second,v[r].second};
        else if(v[l].first+v[r].first>sum)r--;
        else l++;
    }
    return {-1,-1};
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v+1,v+n+1);
    if(n<3){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=1;i<=n-2;i++){
        pii temp=solve(m-v[i].first,i);
        if(temp.first!=-1){
            int a=v[i].second,b=temp.first,c=temp.second;
            cout<<min(a,min(b,c))<<" "<<a+b+c-min(a,min(b,c))-max(a,max(b,c))<<" "<<max(a,max(b,c));
            return 0;
        }
    }
    cout<<"IMPOSSIBLE";
    return 0;
}