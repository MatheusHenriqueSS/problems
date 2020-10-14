/*
Matheus Henrique de Sousa
computador- rascunho - (0pts)
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
struct t{
  int p1,p2,c;
} lazy[4*mxn];
int seg[4*mxn],n,q,a[mxn];
void build(int i=0,int j=n-1,int no=1){
  if(i==j){
    seg[no]=a[i];
    return;
  }
  int m=(i+j)/2;
  build(i,m,2*no);
  build(m+1,j,2*no+1);
  seg[no]=seg[2*no]+seg[2*no+1];
}
void down(int i,int j,int no){
  int m=(i+j)/2;
  if(lazy[no].p1){
    seg[no]+=(((j-i+1)*(j-i+2))/2)*lazy[no].p1;
    if(i!=j){
      lazy[2*no].p1+=lazy[no].p1;
      lazy[2*no+1].p1+=lazy[no].p1;
      lazy[2*no+1].c+=(m-i+1)*lazy[no].p1;
    }
  }
  if(lazy[no].p2){
    seg[no]+=(((j-i+1)*(j-i+2))/2)*lazy[no].p2;
    if(i!=j){
      lazy[2*no].p2+=lazy[no].p2;
      lazy[2*no+1].p2+=lazy[no].p2;
      lazy[2*no].c+=(j-m)*lazy[no].p2;
    }
  }
  if(lazy[no].c){
    seg[no]+=(j-i+1)*lazy[no].c;
    if(i!=j){
      lazy[2*no].c+=lazy[no].c;
      lazy[2*no+1].c+=lazy[no].c;
    }
  }
  lazy[no].p1=lazy[no].p2=lazy[no].c=0;
}
void up(int i,int j,int no){
  down(i,j,no);
  if(i!=j){
    int m=(i+j)/2;
    down(i,m,2*no);
    down(m+1,j,2*no+1);
    seg[no]=seg[2*no]+seg[2*no+1];
  }
}
void upd(int a,int b,int k,int id,int i=0,int j=n-1,int no=1){
  if(i>j || b<i || a>j)return;
  down(i,j,no);
  if(a<=i && j<=b){
    lazy[no].p1++;
    lazy[no].c+=(i-a);
    down(i,j,no);
    return;
  }
  int m=(i+j)/2;
  upd(a,b,k,id,i,m,2*no);
  upd(a,b,k,id,m+1,j,2*no+1);
  up(i,j,no);
}
int query(int a,int b,int i=0,int j=n-1,int no=1){
  if(b<i || a>j)return 0;
  down(i,j,no);
  if(a<=i && j<=b)return seg[no];
  int m=(i+j)/2;
  return query(a,b,i,m,2*no)+query(a,b,m+1,j,2*no+1);
}

int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  cin>>n>>q;
  for(int i=0;i<n;i++)cin>>a[i];
  build();
  while(q--){
    int op,a,b;cin>>op>>a>>b;a--;b--;
    if(op==1)upd(a,b,0,0);
    else cout<<query(a,b)<<"\n";
  }
  return 0;
}
