/*
Matheus Henrique de Sousa
obi 2009 - p2f2- simulador
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
int n,m;
vector<pii>w;
void cut(int a){
  int sum=0,id;
  for(int i=0;i<sz(w);i++){
    int cur=abs(w[i].first-w[i].second)+1;
    if(sum+cur>a){
      id=i;
      break;
    }
    sum+=cur;
  }
  a-=sum;
  if(!a)return;
  int mid;
  pii tmp;
  if(w[id].first<=w[id].second){
    mid=w[id].first+a;
    tmp=pii(mid,w[id].second);
    w[id].second=mid-1;
  }
  else{
    mid=w[id].first-a;
    tmp=pii(mid,w[id].second);
    w[id].second=mid+1;
  }
  w.pb(tmp);
  for(int i=sz(w)-1;i>id+1;i--){
    swap(w[i],w[i-1]);
  }
}
int sum(int a,int b){
  int ans=0,sum=0;
  for(int i=0;i<sz(w);i++){
    int cur=abs(w[i].first-w[i].second)+1;
    if(a<=sum+cur && sum+cur<=b)ans+=((w[i].first+w[i].second)*(cur))/2LL;
    sum+=cur;
  }
  return ans;
}
void inv(int a,int b){
  int ini,fim,sum=0;
  for(int i=0;i<sz(w);i++){
    int cur=abs(w[i].first-w[i].second)+1;
    if(sum==a-1)ini=i;
    if(sum+cur==b)fim=i;
    sum+=cur;
  }
  for(int i=ini;i<=(ini+fim)/2LL;i++){
    swap(w[i],w[fim-(i-ini)]);
  }
  for(int i=ini;i<=fim;i++)swap(w[i].first,w[i].second);
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n>>m;
  w.pb({1,n});
  while(m--){
    char op;int a,b;cin>>op>>a>>b;
    cut(a-1);cut(b);
    if(op=='I'){
      inv(a,b);
    }
    else{
      cout<<sum(a,b)<<"\n";
    }
  }
  return 0;
}
