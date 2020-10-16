/*
Matheus Henrique de Sousa
sf3 - computador - tentativa 2(???)
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
int n,q,seg[4*mxn];
pii l1[4*mxn],l2[4*mxn];
void add(int v1,int v2,int id,int i,int j,int no){
  if(v1<=0)return;
  if(id==1){
    l1[no].first+=v1;
    l1[no].second+=v2;
    seg[no]+=v1;
  }
  else{
    l2[no].first+=v1;
    l2[no].second+=v2;
    seg[no]+=v1;
  }
}
void upd(int id,int a,int b,int k,int i=1,int j=n,int no=1){
  if(b<i || a>j || i>j)return;
  if(a<=i && j<=b){
    if(id==1)add(k-(i-a),-1,1,i,j,no);
    else add(k-(b-j),-1,2,i,j,no);
    return;
  }
  int m=(i+j)/2;
  if(id==1){
    add(l1[no].first,l1[no].second,id,i,m,2*no);
    add(l1[no].first+l1[no].second*(m-i+1),l1[no].second,1,m+1,j,2*no+1);
    l1[no].first=l1[no].second=0;
    upd(id,a,b,k,i,m,2*no);
    upd(id,a,b,k,m+1,j,2*no+1);
  }
  else{
    add(l2[no].first+l2[no].second*(j-m),l2[no].second,2,i,m,2*no);
    add(l2[no].first,l2[no].second,2,m+1,j,2*no+1);
    l2[no].first=l2[no].second=0;
    upd(id,a,b,k,i,m,2*no);
    upd(id,a,b,k,m+1,j,2*no+1);
  }
}
int query(int a,int b,int i=1,int j=n,int no=1){
  if(b<i || a>j || i>j)return 0;
  if(a<=i && j<=b)return seg[no];
  int m=(i+j)/2;
  add(l1[no].first,l1[no].second,1,i,m,2*no);
  add(l1[no].first+l1[no].second*(m-i+1),l1[no].second,1,m+1,j,2*no+1);
  l1[no].first=l1[no].second=0;
  add(l2[no].first+l2[no].second*(j-m),l2[no].second,2,i,m,2*no);
  add(l2[no].first,l2[no].second,2,m+1,j,2*no+1);
  l2[no].first=l2[no].second=0;
  return query(a,b,i,m,2*no)+query(a,b,m+1,j,2*no+1);
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  cin>>n>>q;
  while(q--){
    int op,a,k;cin>>op;
    if(op==1){
      cin>>a>>k;
      upd(1,a,min(n,a+k-1),k);
    }
    else if(op==2){
      cin>>a>>k;
      upd(2,max(1LL,a-k+1),a,k);
    }
    else{
      cin>>a;
      cout<<query(a,a)<<"\n";
    }
  }
  return 0;
}
