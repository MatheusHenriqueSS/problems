/*
Matheus Henrique de Sousa
*/
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

#define ll long long
#define int long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxn=2e5+5,M=1e9+7;
vii mul(vii a,vii b){
  vii c(3,vi(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }
  return c;
}
vii exp(vii a,int b){
  if(b==1)return a;
  vii t=exp(a,b/2);
  if(b&1)return mul(mul(t,t),a);
  return mul(t,t);
}
int solve(int x){
  vii M={
    {1,1,-1},
    {1,0,0},
    {0,1,0}
  };
  vi A={50,5,1};
  int ans=0;
  M=exp(M,x);
  for(int i=0;i<3;i++){
    ans+=M[0][i]*A[i];
  }
  return ans;

}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  int n;cin>>n;
  if(n<=4)cout<<1;
  else if(n<=49)cout<<2;
  else if(n<=53)cout<<3;
  else{
    int l=1,r=n,ans;
    while(l<=r){
      int m=(l+r)/2;
      if(solve(m)<=n){
        ans=m;
        l=m+1;
      }
      else r=m-1;
    }
    cout<<ans+3;  
  }  

  return 0;
}
