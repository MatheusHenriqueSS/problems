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
int n,m;
int v[mxN],seg[4*mxN];
void build(int i=0,int j=n-1,int no=1){
    if(i==j) seg[no]=i;
    else{
        int esq=2*no;
        int dir=2*no+1;
        int m=(i+j)/2;
        build(i,m,esq);
        build(m+1,j,dir);
        seg[no]=(v[seg[esq]]>=v[seg[dir]]?seg[esq]:seg[dir]);
    }
}
void upd(int pos,int k,int i=0,int j=n-1,int no=1){
    if(i==j){
        v[i]=k;
        seg[no]=i;
    }
    else{
        int esq=2*no;
        int dir=2*no+1;
        int m=(i+j)/2;
        if(pos<=m)upd(pos,k,i,m,esq);
        else upd(pos,k,m+1,j,dir);
        seg[no]=(v[seg[esq]]>=v[seg[dir]]?seg[esq]:seg[dir]);
 
    }
}
int query(int k,int i=0,int j=n-1,int no=1){
    if(i==j){
        if(v[i]<k)return -1;
        upd(i,v[i]-k);
        return i;
    }
    int m=(i+j)/2;
    if(v[seg[2*no]]>=k)return query(k,i,m,2*no);
    if(v[seg[2*no+1]]>=k)return query(k,m+1,j,2*no+1);
    return -1;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>v[i];
    build();
    for(int i=0;i<m;i++){
        int x;cin>>x;
        cout<<query(x)+1<<" ";
    }
    
}
