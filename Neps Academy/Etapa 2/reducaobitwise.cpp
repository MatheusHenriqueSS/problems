#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=1e5+5,INF=(1LL<<31)-1;
//did u check when n=1?
//is mxN correct?
struct t{
    int mx,mn,a,o,x;
};
t tree[4*mxN];
int n,q,v[mxN];
void build(int i=0,int j=n-1,int no=1){
    if(i==j){
        tree[no].a=tree[no].o=tree[no].x=v[i];
        tree[no].mx=tree[no].mn=i;
        return;
    }
    int esq=2*no;
    int dir=2*no+1;
    int m=(i+j)/2;
    build(i,m,esq);
    build(m+1,j,dir);
    tree[no].mx=(v[tree[esq].mx]>v[tree[dir].mx]?tree[esq].mx:tree[dir].mx);
    tree[no].mn=(v[tree[esq].mn]<v[tree[dir].mn]?tree[esq].mn:tree[dir].mn);
    tree[no].a=(tree[esq].a & tree[dir].a);
    tree[no].o=(tree[esq].o | tree[dir].o);
    tree[no].x=(tree[esq].x ^ tree[dir].x);

}
int query(int idx,int A,int B,int i=0,int j=n-1,int no=1){
    if(A<=i && j<=B){
        if(idx==0)return tree[no].mx;
        if(idx==1)return tree[no].mn;
        if(idx==2)return tree[no].a;
        if(idx==3)return tree[no].o;
        if(idx==4)return tree[no].x;
    }
    if(i>B || j<A){
        if(idx<=1)return -1;
        if(idx==2)return INF;
        return 0;
    }
    int esq=2*no;
    int dir=2*no+1;
    int m=(i+j)/2;
    int qesq=query(idx,A,B,i,m,esq),qdir=query(idx,A,B,m+1,j,dir);
    if(idx==0){
        if(qesq==-1)return qdir;
        if(qdir==-1)return qesq;
        return v[qesq]>v[qdir]?qesq:qdir;
    }
    if(idx==1){
        if(qesq==-1)return qdir;
        if(qdir==-1)return qesq;
        return v[qesq]<v[qdir]?qesq:qdir;
    }
    if(idx==2)return (qesq&qdir);
    if(idx==3)return (qesq|qdir);
    if(idx==4)return (qesq^qdir);
}
void upd(int k,int pos,int i=0,int j=n-1,int no=1){
    if(i==j){
        tree[no].a=tree[no].o=tree[no].x=v[i]=k;
        tree[no].mx=tree[no].mn=i;
        return;
    }
    int esq=2*no;
    int dir=2*no+1;
    int m=(i+j)/2;
    if(pos<=m)upd(k,pos,i,m,esq);
    else upd(k,pos,m+1,j,dir);
    tree[no].mx=(v[tree[esq].mx]>v[tree[dir].mx]?tree[esq].mx:tree[dir].mx);
    tree[no].mn=(v[tree[esq].mn]<v[tree[dir].mn]?tree[esq].mn:tree[dir].mn);
    tree[no].a=(tree[esq].a & tree[dir].a);
    tree[no].o=(tree[esq].o | tree[dir].o);
    tree[no].x=(tree[esq].x ^ tree[dir].x);

}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>v[i];
    build();
    int a,b;
    char c;
    while(q--){
        cin>>c>>a>>b;
        a--;b--;
        if(c=='x'){
            int temp=query(0,a,b);
            if(query(4,a,b)==0LL)cout<<v[temp]<<"\n";
            else cout<<-1<<"\n";
        }
        if(c=='a'){
            int temp=query(1,a,b);
            if((query(2,a,temp-1)&query(2,temp+1,b))==v[temp])cout<<v[temp]<<"\n";
            else cout<<-1<<"\n";
        }
        if(c=='o'){
            int temp=query(0,a,b);
            if((query(3,a,temp-1)|query(3,temp+1,b))==v[temp])cout<<v[temp]<<"\n";
            else cout<<-1<<"\n";
        }
        if(c=='u')upd(b+1,a);
    }
}   
