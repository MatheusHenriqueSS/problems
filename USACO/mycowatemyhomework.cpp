/*
Matheus Henrique de Sousa
my cow ate my homework
9.21.20
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
int n,a[mxn],suf[mxn],me[mxn];
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("homework");
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  suf[n]=a[n];
  me[n]=a[n];
  for(int i=n-1;i>=1;i--){
     suf[i]=a[i]+suf[i+1];
     me[i]=min(a[i],me[i+1]);
  }
  int div=1,ans=0;
  for(int i=1;i<=n-2;i++){
    if((suf[i+1]-me[i+1])*div>ans*(n-i-1)){
      div=n-i-1;
      ans=suf[i+1]-me[i+1];
    }
  }
  for(int i=1;i<=n-2;i++){
    if((suf[i+1]-me[i+1])*div==ans*(n-i-1))cout<<i<<"\n";
  }

  return 0;
}
