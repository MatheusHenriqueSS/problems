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
void build(int i=0,int j=n-1,int no=1){
    if(i==j)seg[no]=v[i];
    else{
    int m=(i+j)/2;
    build(i,m,2*no);
    build(m+1,j,2*no+1);
    seg[no]=min(seg[2*no],seg[2*no+1]);
    }
}
int query(int A,int B,int i=0,int j=n-1,int no=1){
    if(A<=i && j<=B)return seg[no];
    if(i>B || j<A)return M;
    int m=(i+j)/2;
    return min(query(A,B,i,m,2*no),query(A,B,m+1,j,2*no+1));
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>v[i];
    build();
    while(q--){
        int a,b;cin>>a>>b;a--;b--;
        cout<<query(a,b)<<"\n";
    }
}
