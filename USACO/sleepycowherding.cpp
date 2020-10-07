/*
Matheus Henrique de Sousa
sleepy cow herding
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
const int LINF=0x3f3f3f3f3f3f3f3f;
int n,a[mxn];
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("herding");
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  int ma=0;
  if(a[n-2]-a[0]==n-2 && a[n-1]-a[n-2]>2)ma=2;
  else if(a[n-1]-a[1]==n-2 && a[1]-a[0]>2)ma=2;
  else{
    int j=0;
    for(int i=0;i<n;i++){
      while(j<n-1 && a[j+1]-a[i]<=n-1)j++;
      ma=max(ma,j-i+1);
    }
    ma=n-ma;
  }

  cout<<ma<<"\n";
  cout<<max(a[n-2]-a[0],a[n-1]-a[1])-(n-2)<<"\n";
  return 0;
}
