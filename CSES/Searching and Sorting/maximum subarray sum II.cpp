#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,INF=1e15+7;
//did u check when n=1?
//is mxN correct?
int n,v[mxN],seg[4*mxN],a[mxN],l,r;
void build(int i=0,int j=n,int no=1){
    if(i==j)seg[no]=i;
    else{
        int m=(i+j)/2;
        build(i,m,2*no);
        build(m+1,j,2*no+1);
        seg[no]=(v[seg[2*no]]<=v[seg[2*no+1]]?seg[2*no]:seg[2*no+1]);
    }    
}
int query(int A,int B,int i=0,int j=n,int no=1){
    if(A<=i && j<=B)return seg[no];
    if(i>B || j<A)return -1;
    int m=(i+j)/2;
    int esq=query(A,B,i,m,2*no);
    int dir=query(A,B,m+1,j,2*no+1);
    if(esq==-1)return dir;
    if(dir==-1)return esq;
    return v[esq]<=v[dir]?esq:dir;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        cin>>a[i];
        v[i+1]=a[i]+v[i];
    }
    build();
    int ans=-INF;
    for(int i=l;i<=n;i++){
        //cout<<v[l]<<"\n";
        ans=max(ans,v[i]-v[query(max(0LL,i-r),max(0LL,i-l))]);
    }
    cout<<ans;

    
}
//-1 3 -2 5 3 -5 2 2
//-1 2  0 5 8  3 5 5
 