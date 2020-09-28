#include<bits/stdc++.h>
#include <fstream>
using namespace std;
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
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
int n,k;
int b[mxN],c[mxN];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    setIO("diamond");    
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        auto it=upper_bound(a.begin()+i+1,a.end(),a[i]+k);
        it--;
        b[i]=it-a.begin();
    }
    int ans=0,tmp=0;
    for(int i=n-1;i>=0;i--){
        tmp=max(tmp,b[i]-i+1);
        c[i]=tmp;
    }
    for(int i=0;i<n;i++){
        ans=max(ans,b[i]-i+1+c[b[i]+1]);
    }
    cout<<ans; 
    return 0;
}
