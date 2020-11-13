/*
Matheus Henrique de Sousa
Seletiva 2018 - bolsa de brinquedos
*/;
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=1e6+5,len=1000;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?   
struct t{
  int l,r,id;
};
bool cmp(t a, t b){
  if(a.l/len!=b.l/len)return a.l/len<b.l/len;
  return a.r<b.r;
}

int n,m,a[mxn],cnt[mxn];
ll cost[mxn],k;
set<ll>s;

inline void add(int x){
  cnt[a[x]]++;
  if(cnt[a[x]]==k)s.insert(cost[a[x]]);
}
inline void rmv(int x){
  cnt[a[x]]--;
  if(cnt[a[x]]==k-1)s.erase(cost[a[x]]);
}

int32_t main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>n>>m>>k;
  for(int i=0;i<m;i++){
    cin>>cost[i];
    cost[i]*=k;
  }
  for(int i=0;i<n;i++){
    cin>>a[i];a[i]--;
  }
  int q;cin>>q;
  vector<t>aux(q);
  vector<ll>ans(q);
  for(int i=0;i<q;i++){
    cin>>aux[i].l>>aux[i].r;aux[i].l--;aux[i].r--;
    aux[i].id=i;
  }
  sort(aux.begin(),aux.end(),cmp);
  int c_l=0,c_r=-1;
  for(t x:aux){
    while(c_l>x.l)add(--c_l);
    while(c_r<x.r)add(++c_r);
    while(c_l<x.l)rmv(c_l++);
    while(c_r>x.r)rmv(c_r--);
    if(s.empty())ans[x.id]=-1;
    else ans[x.id]=*s.begin();   
  }
  for(int i=0;i<q;i++)cout<<ans[i]<<"\n";
  return 0;
}
