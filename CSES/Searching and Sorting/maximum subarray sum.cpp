#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=2e5,M=1e9+7;
int n,v[mxN],ma=-M,temp,ans;

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
        ma=max(ma,v[i]);
    }
    //cout<<ma<<"\n";
    for(int i=0;i<n;i++){
        temp=max(0LL,temp+v[i]);
        ans=max(temp,ans);        
        //cout<<temp<<" "<<ans<<"\n";
    }
    

    cout<<(ans==0 ? ma:ans);


}