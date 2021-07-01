#include<bits/stdc++.h>
#include <fstream>
using namespace std;
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
}
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxn=5e5+5,M=1e9+7;
const int LINF = 0x3f3f3f3f3f3f3f3f;
int n,p,q,ans,bit[mxn];
map<int,int>aux;
pii a[mxn];
// the comparison might be made by tmp=y*q-p*x
// but it depends on the x
void upd(int pos){
  while(pos<mxn){
    //cout<<pos<<"\n";
    bit[pos]++;
    pos+=pos&-pos;
  }
}
int query(int pos){
  int ans=0;
  for(;pos>0;pos-=pos&-pos)ans+=bit[pos];
  return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>p>>q;
    if(q<0){
      p*=-1;
      q*=-1;
    }
    for(int i=0;i<n;i++){
      cin>>a[i].first>>a[i].second;
    }
    sort(a,a+n);
    for(int i=0;i<n;i++){
      int tmp=a[i].second*q-p*a[i].first;
      aux[tmp];
    }
    int cnt=1;
    for(auto it=aux.begin();it!=aux.end();it++){
      it->second=cnt;
      cnt++;
    }
    for(int i=0;i<n;i++){
      int tmp=a[i].second*q-p*a[i].first;
      ans+=query(aux[tmp]);
      upd(aux[tmp]);
    }


    cout<<ans;
}
