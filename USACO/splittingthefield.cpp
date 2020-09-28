/*
Matheus Henrique de Sousa
splitting the field
9.14.20
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
int n,ans=LINF;
pii a[mxn],b[mxn],c[mxn];
void solve(){
  sort(a,a+n);
  int l=M,r=0;
  for(int i=0;i<n;i++){
    l=min(l,a[i].second);
    r=max(r,a[i].second);
    b[i]={l,r};
  }
  l=M,r=0;
  for(int i=n-1;i>=0;i--){
    l=min(l,a[i].second);
    r=max(r,a[i].second);
    c[i]={l,r}; 
  }
  for(int i=0;i<n-1;){
    while(i+1<n-1 && a[i].first==a[i+1].first)i++;
    ans=min(ans,(a[i].first-a[0].first)*(b[i].second-b[i].first)+(a[n-1].first-a[i+1].first)*(c[i+1].second-c[i+1].first));
    i++;
  }  
}

int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("split");
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i].first>>a[i].second;
  solve();
  for(int i=0;i<n;i++)swap(a[i].first,a[i].second);
  solve();
  cout<<(a[n-1].first-a[0].first)*(b[n-1].second-b[n-1].first)-ans;

  return 0;
}
