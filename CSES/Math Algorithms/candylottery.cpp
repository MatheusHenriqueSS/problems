#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m;
double ans;
double v[105];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        v[i]=1.0;
        for(int j=0;j<n;j++){
            v[i]*=(double)((double)(i)/(double)(m));
        }
    }
    for(int i=m;i>=1;i--){
        v[i]-=v[i-1];
        //cout<<i*v[i]<<"\n";
        ans+=(double)(i*v[i]);
        //cout<<ans<<"\n";    
    }
    cout<<fixed<<setprecision(6)<<ans;
}
