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
int n,k,v[mxN],pref[mxN];
int calc(int val){
  int cnt=0,x=0;
  for(int i=1;i<=n && cnt<k-1;i++){
      if(pref[i]-pref[x]>val){
          x=i-1;
          if(pref[i]-pref[x]>val)return 0;
          cnt++;
      }
  }
  if(pref[n]-pref[x]>val)return 0;
  return 1;

}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>v[i];
        pref[i+1]=v[i]+pref[i];
    }
    int l=0,r=pref[n],m,resp;
    while(l<=r){
        m=(l+r)/2;
        if(calc(m)){
            r=m-1;
            resp=m;
        }
        else l=m+1;
    }
    cout<<resp;
    


}