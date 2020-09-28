/*
Matheus Henrique de Sousa
convention II
9.19.20
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
typedef pair<int,pii>ii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxn=2e5+5,M=1e9+7;
int n;
ii a[mxn];
bool cmp1(ii a,ii b){
  return a.second.first<b.second.first;
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("convention2");
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i].second.first>>a[i].second.second;
    a[i].first=i;
  }
  sort(a,a+n,cmp1);
  int last=0,cnt=-1,ans=0;
  priority_queue<ii,vector<ii>,greater<ii>>pq;
  while(cnt<n){
    last=a[cnt].second.first+a[cnt].second.second;
    cnt++;
    for(;cnt<n && a[cnt].second.first<=last;cnt++){
      pq.push(a[cnt]);
    } 
    while(!pq.empty()){
      ii cur=pq.top();
      pq.pop();
      ans=max(ans,last-cur.second.first);
      last+=cur.second.second;
      for(;cnt<n && a[cnt].second.first<=last;cnt++){
        pq.push(a[cnt]);
      } 
    }
  }
  cout<<ans;
  return 0;
}
