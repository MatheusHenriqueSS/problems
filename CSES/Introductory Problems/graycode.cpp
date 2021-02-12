#include<bits/stdc++.h>
using namespace std;
  
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
  
typedef pair<int,int>ii;
typedef vector<int>vi;
int n;
int v[(1<<16)+5];
void solve(int x){
  for(int i=0;i<n;i++){
    if(x&(1<<i))cout<<1;
    else cout<<0;
  }
  cout<<"\n";
}
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n;
  int cur=0;
  for(int i=0;i<(1<<n);i++){
    solve(cur);
    v[cur]=1;
    for(int j=0;j<n;j++){
      if(!v[cur^(1<<j)]){
        cur^=(1<<j);
        break;
      }
    }
    
  }
  return 0;
}
