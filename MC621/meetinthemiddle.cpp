#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define int long long
#define pb push_back
#define sz(x) (int)x.size()
 
typedef pair<int,int>pii;
typedef vector<int> vi;
int mxn=42;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?   
vi a,b,x,y;
int n,k,ans;
map<int,int>mp;
void solve(int i=0,int sum=0){
  //cout<<i<<" "<<sum<<" "<<sz(a)<<"\n";
  if(i>=sz(a)){
    x.pb(sum);
    return;
  }
  solve(i+1,sum);
  solve(i+1,sum+a[i]);
  
}
void solve1(int i=0,int sum=0){
  if(i==sz(b)){
    y.pb(sum);
    return;
  }
  solve1(i+1,sum);
  solve1(i+1,sum+b[i]);
}
 
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  for(int i=0;i<n/2;i++){
    int x;cin>>x;
    a.pb(x);
  }
  for(int i=n/2;i<n;i++){
    int x;cin>>x;
    b.pb(x);
  }
  solve();
  solve1();
  sort(y.begin(),y.end());
  for(int i=0;i<sz(x);i++){
    ans+=upper_bound(y.begin(),y.end(),k-x[i])-lower_bound(y.begin(),y.end(),k-x[i]);
  }
  cout<<ans<<"\n";
}
