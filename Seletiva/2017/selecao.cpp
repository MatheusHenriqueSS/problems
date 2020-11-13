/*
Matheus Henrique de Sousa
Seletiva 2017 - seleção
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?
int n,a,b,c,m,k;
vi x,y;
bool calc(int val){
  int j=n,sum=0;
  for(int i=0;i<n;i++){
    while(j>0 && x[i]+y[j]>=val)j--;
    sum+=j;
  }
  return sum<k;
}   
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>k;
  cin>>a>>b>>c>>m;
  x.pb(a);
  int cur=a;
  for(int i=0;i<n-1;i++){
    cur=(b+c*cur)%m;  
    x.pb(cur);
  }
  cin>>a>>b>>c>>m;
  y.pb(a);
  cur=a;
  for(int i=0;i<n-1;i++){
    cur=(b+c*cur)%m;  
    y.pb(cur);
  }
  y.pb(0);
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  int l=0,r=2e6+5,ans=-1;
  while(l<=r){
      int mid=(l+r)/2;
      if(calc(mid)){
        l=mid+1;
        ans=mid;
      }
      else r=mid-1;
  }
  cout<<ans<<"\n";
  return 0;
}
