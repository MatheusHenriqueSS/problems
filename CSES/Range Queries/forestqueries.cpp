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
const int mxn=1e3+5,M=1e9+7;
int n,q,bit[mxn][mxn];
void upd(int x,int y){
  for(int i=x;i<mxn;i+=(i&-i)){
    for(int j=y;j<mxn;j+=(j&-j)){
      bit[i][j]++;
    }
  }
}
int query(int x,int y){
  int ans=0;
  for(int i=x;i>0;i-=(i&-i)){
    for(int j=y;j>0;j-=(j&-j)){
      ans+=bit[i][j];
    }
  }
  return ans;
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n>>q;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      char c;cin>>c;if(c=='*')upd(i,j);
    }
  }
  while(q--){
    int i,j,i1,j1;
    cin>>i>>j>>i1>>j1;
    cout<<query(i1,j1)-query(i1,j-1)-query(i-1,j1)+query(i-1,j-1)<<"\n";
  }
  return 0;
}
