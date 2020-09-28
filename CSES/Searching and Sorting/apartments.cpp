#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=2e5,M=1e9+7;
int n,m,k,ans;
 
int v[mxN];
int a[mxN];
// LONG LONG CASE
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
       cin>>v[i];     
    }
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    v[n]=M;
    a[m]=M;
    sort(v,v+n);
    sort(a,a+m);

    int i,j;
    i=j=0; 
    int resp=0LL;
    
    while(i<n && j<m){
        if(abs(v[i]-a[j])<=k){
            resp++;
            j++;
            i++;
        }
        else if(v[i]<a[j])i++;
        else j++;
    }
    cout<<resp;
}
