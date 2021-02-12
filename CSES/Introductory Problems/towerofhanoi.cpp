#include<bits/stdc++.h>
using namespace std;
  
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
  
typedef pair<int,int>ii;
typedef vector<int>vi;

int n;
vector<ii> cur,tmp;
int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cur.pb({1,3});
  cin>>n;
  cout<<(1<<n)-1<<"\n";
  for(int i=1;i<n;i++){
    tmp=cur;
    cur.clear();
    for(auto p:tmp){
      ii x=p;
      if(x.first==2)x.first=3;
      else if(x.first==3)x.first=2;
      if(x.second==2)x.second=3;
      else if(x.second==3)x.second=2;
      cur.pb(x);
    }
    cur.pb({1,3});
    for(auto p:tmp){
      ii x=p;
      if(x.first==1)x.first=2;
      else if(x.first==2)x.first=1;
      if(x.second==1)x.second=2;
      else if(x.second==2)x.second=1;
      cur.pb(x);
    }
  }
  for(auto p:cur){
    cout<<p.first<<" "<<p.second<<"\n";
  }
  return 0;
}
