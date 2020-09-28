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
int n,q,v[mxN],seg[4*mxN];
pii lazy[4*mxN];
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
void down(int i,int j,int no){
    int ad=lazy[no].first;
    int se=lazy[no].second;
    if(ad+se==0)return;
    lazy[no]={0,0};
    if(se){
        seg[no]=(j-i+1)*se;
        if(i!=j){
            lazy[2*no].first=lazy[2*no+1].first=0;
            lazy[2*no].second=lazy[2*no+1].second=se;
 
        }
    }
    if(ad){
        seg[no]+=(j-i+1)*ad;
        if(i!=j){
            if(lazy[2*no].second)lazy[2*no].second+=ad;
            else lazy[2*no].first+=ad;
            if(lazy[2*no+1].second)lazy[2*no+1].second+=ad;
            else lazy[2*no+1].first+=ad;
        }
    }       
}
void up(int i,int j,int no){
    down(i,j,no);
    if(i!=j){
        int m=(i+j)/2;
        down(i,m,2*no);
        down(m+1,j,2*no+1);
    }
    seg[no]=seg[2*no]+seg[2*no+1];
}
int query(int A,int B,int i=0,int j=n-1,int no=1){
    if(i>j||j<A||i>B)return 0;
    down(i,j,no);
    if(A<=i && j<=B)return seg[no];
    int m=(i+j)/2;
    return query(A,B,i,m,2*no)+query(A,B,m+1,j,2*no+1);     
}
void upd(int op,int val,int A,int B,int i=0,int j=n-1,int no=1){
    if(i>j||j<A||i>B)return;
    down(i,j,no);
    if(A<=i && j<=B){
        if(op==1){
            lazy[no]={val,0};
        }
        else{
            lazy[no]={0,val};
        }
        down(i,j,no);
        return;
    }
    int m=(i+j)/2;
    upd(op,val,A,B,i,m,2*no);
    upd(op,val,A,B,m+1,j,2*no+1);
    up(i,j,no);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>v[i];
    build();
    while(q--){
        int op,a,b,x;
        cin>>op;
        if(op==3){
            cin>>a>>b;
            cout<<query(a-1,b-1)<<"\n";
        }
        else{
            cin>>a>>b>>x;
            upd(op,x,a-1,b-1);
        }
    }
}
