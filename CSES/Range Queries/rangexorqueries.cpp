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
int n,q,a[mxn];
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n>>q;
  int cur=0;
  for(int i=1;i<=n;i++){
    int x;cin>>x;
    cur^=x;
    a[i]=cur;
  }
  while(q--){
    int l,r;cin>>l>>r;
    cout<<(a[r]^a[l-1])<<"\n";
  }
  return 0;
}
