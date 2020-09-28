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
int n,m,v[mxN];
struct node{
    int opt=0,tot=0,pref=0,suf=0;
} seg[4*mxN];
node merge(node a,node b){
    node ans;
    ans.tot=a.tot+b.tot;
    ans.pref=max(a.pref,a.tot+b.pref);
    ans.suf=max(b.suf,b.tot+a.suf);
    ans.opt=max(a.suf+b.pref,max(a.opt,b.opt));
    return ans;
}
void build(int i=0,int j=n-1,int no=1){
    if(i==j){
       seg[no].opt=seg[no].pref=seg[no].suf=seg[no].tot=v[i];
        return;
    }
    int m=(i+j)/2;
    build(i,m,2*no);
    build(m+1,j,2*no+1);
    seg[no]=merge(seg[2*no],seg[2*no+1]);
}
void upd(int pos,int k,int i=0,int j=n-1,int no=1){
    if(i==j){
        v[i]=k;
        seg[no].opt=seg[no].pref=seg[no].suf=seg[no].tot=v[i];
        return;
    }
    int m=(i+j)/2;
    if(pos<=m)upd(pos,k,i,m,2*no);
    else upd(pos,k,m+1,j,2*no+1);
    seg[no]=merge(seg[2*no],seg[2*no+1]);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>v[i];
    build();
    //cout<<seg[1].opt<<"\n"; 
    for(int i=0;i<m;i++){
        int k,x;cin>>k>>x;k--;
        upd(k,x);
        cout<<max(0LL,seg[1].opt)<<"\n";
    }
 
}
