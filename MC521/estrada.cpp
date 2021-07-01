#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=2e5+5,mod=1e9+7;
double t,ans[mxn],cid[mxn];
int n;
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin>>t>>n;
  for(int i=0;i<n;i++)cin>>cid[i];
  sort(cid,cid+n);
  for(int i=0;i<n-1;i++){
    double tmp=(double)((cid[i+1]-cid[i])/2.0);
    ans[i]+=tmp;
    ans[i+1]+=tmp;
  }
  ans[0]+=cid[0];
  ans[n-1]+=t-cid[n-1];
  double res=ans[0];
  for(int i=1;i<n;i++)res=min(res,ans[i]);
  cout<<fixed<<setprecision(2)<<res<<"\n";
  return 0;
}
