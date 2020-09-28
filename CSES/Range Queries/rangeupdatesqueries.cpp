#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,q,v[mxN],seg[4*mxN],lazy[4*mxN];
void build(int i=0,int j=n-1,int no=1){
    if(i==j){
        seg[no]=v[i];
        return;
    }
    int m=(i+j)/2;
    build(i,m,2*no);
    build(m+1,j,2*no+1);
    seg[no]=seg[2*no]+seg[2*no+1];
}
void upd(int val,int A,int B,int i=0,int j=n-1,int no=1){
    if(lazy[no]){
        seg[no]+=(j-i+1)*lazy[no];
        if(i!=j){
            lazy[2*no]+=lazy[no];
            lazy[2*no+1]+=lazy[no];
        }
        lazy[no]=0;
    }
    if(i>j || i>B || j<A)return;
    if(A<=i && j<=B){
        seg[no]+=(j-i+1)*val;
        if(i!=j){
            lazy[2*no]+=val;
            lazy[2*no+1]+=val;
        }
    }
    else{
        int m=(i+j)/2;
        upd(val,A,B,i,m,2*no);
        upd(val,A,B,m+1,j,2*no+1);  
        seg[no]=seg[2*no]+seg[2*no+1];
    }
}
int query(int A,int B,int i=0,int j=n-1,int no=1){
    if(lazy[no]){
    seg[no]+=(j-i+1)*lazy[no];
    if(i!=j){
        lazy[2*no]+=lazy[no];
        lazy[2*no+1]+=lazy[no];
    }
    lazy[no]=0;
    }
    if(i>j || i>B || j<A)return 0;
    if(A<=i && j<=B)return seg[no];
    int m=(i+j)/2;
    return query(A,B,i,m,2*no)+query(A,B,m+1,j,2*no+1);  
        //seg[no]=seg[2*no]+seg[2*no+1];
    
 
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>v[i];
    build();
    while(q--){
        int a;cin>>a;
        if(a==1){
            int b,c,d;cin>>b>>c>>d;
            upd(d,b-1,c-1);
        }
        else{
            int b;cin>>b;
            cout<<query(b-1,b-1)<<"\n";
        }
    }
 
}
