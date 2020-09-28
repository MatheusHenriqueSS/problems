/*
Matheus Henrique de Sousa
haybale stacking
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
int n,k,a[mxn];
vi aux;
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n>>k;
  while(k--){
    int l,r;cin>>l>>r;
    a[l]++;
    a[r+1]--;
  }
  for(int i=1;i<=n;i++)a[i]+=a[i-1];
  sort(a+1,a+n+1);
  cout<<a[(n+1)/2];
  return 0;

}
