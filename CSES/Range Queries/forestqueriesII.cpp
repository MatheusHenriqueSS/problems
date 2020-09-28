#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1e3+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,q;
int bit[mxN][mxN];
int g[mxN][mxN];
void upd(int x,int y,int val){
    for(int i=x;i<mxN;i+=i&-i){
        for(int j=y;j<mxN;j+=j&-j){
            bit[i][j]+=val;
        }
    }
}
int query(int x,int y){
    int ans=0;
    for(int i=x;i>0;i-=(i&-i)){
        for(int j=y;j>0;j-=(j&-j)){
            ans+=bit[i][j];
        }
    }
    return ans;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            char c;cin>>c;
            if(c=='*'){
                upd(i,j,1);
                g[i][j]=1;
            }
        }
    }
    while(q--){
        int op;cin>>op;
        if(op==1){
            int a,b;cin>>a>>b;
            if(g[a][b]==1){
                g[a][b]=0;
                upd(a,b,-1);
            }
            else{
                g[a][b]=1;
                upd(a,b,1);
            }
        }
        else{
            int xi,yi,xf,yf;
            cin>>xi>>yi>>xf>>yf;
            cout<<query(xf,yf)-query(xf,yi-1)-query(xi-1,yf)+query(xi-1,yi-1)<<"\n";
        }
    }
 
}
