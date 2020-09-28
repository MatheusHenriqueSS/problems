/*
Matheus Henrique de Sousa
snowboots
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
int n,m;
int a[mxn],b[mxn],nxt[mxn],prv[mxn];
int snow[mxn],dep[mxn],len[mxn];
bool ans[mxn];
bool cmp(int a,int b){
  return snow[a]<snow[b];
}
bool cmp1(int a,int b){
  return dep[a]<dep[b];
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("snowboots");
  cin>>n>>m;
  for(int i=0;i<n;i++){
    cin>>snow[i];
    a[i]=i;
  }
  sort(a,a+n,cmp);
  for(int i=0;i<m;i++){
    cin>>dep[i]>>len[i];
    b[i]=i;
  }
  for(int i=0;i<n;i++){
    nxt[i]=i+1;
    prv[i]=i-1;
  }
  sort(b,b+m,cmp1);
  int j=n-1;
  int ma=1;
  for(int i=m-1;i>=0;i--){
    while(j>=0 && snow[a[j]]>dep[b[i]] ){
      int cur=a[j];
      nxt[prv[cur]]=nxt[cur];
      prv[nxt[cur]]=prv[cur];
      ma=max(ma,nxt[cur]-prv[cur]);
      j--;
    }
    ans[b[i]]=(ma<=len[b[i]]);
  }
  for(int i=0;i<m;i++)cout<<ans[i]<<"\n";
  return 0;
}
