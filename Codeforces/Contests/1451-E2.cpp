/*
Matheus Henrique de Sousa
Bitwise Queries
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=65600;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?   
int n,ans[mxn],vxor[mxn];
vi pos[mxn];
int query(string s,int x,int y){
  cout<<s<<" "<<x<<" "<<y<<"\n";
  int res;cin>>res;
  return res;
}
int32_t main(){
  cin>>n;
  pos[0].pb(1);
  for(int i=2;i<=n;i++){
    vxor[i]=query("XOR",1,i);
    pos[vxor[i]].pb(i);
  }
  int a=1,b=-1,c=-1;
  for(int i=0;i<mxn;i++){
    if(sz(pos[i])>1){
      b=pos[i][0];
      c=pos[i][1];
    }
  }
  if(b!=-1){
    ans[b]=query("AND",b,c);
    ans[1]=(ans[b]^vxor[b]);
  }
  else{
    for(int i=2;i<=3;i++){
      for(int j=i+1;j<=n;j++){
        if((vxor[i]^vxor[j])==n-1){
          b=i;
          c=j;
        }
      }
    }
    int xorab=vxor[a]^vxor[b],xorac=vxor[a]^vxor[c],xorbc=vxor[b]^vxor[c];
    int andab=query("AND",a,b);
    int andac=query("AND",a,c);
    int andbc=0;
    int sumab=xorab+2*andab;
    int sumbc=xorbc+2*andbc;
    int sumac=xorac+2*andac;
    ans[a]=(sumab+sumac-sumbc)/2;

  }
  for(int i=2;i<=n;i++){
    ans[i]=(ans[1]^vxor[i]);
  }
  cout<<"! ";
  for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
  cout<<"\n";
  cout.flush();
  return 0;
}
