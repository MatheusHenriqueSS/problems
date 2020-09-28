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
int n,q;
int v[mxN],bit[mxN];
void upd(int pos,int val){
    while(pos<mxN){
        bit[pos]+=val;
        pos+=(pos&-pos);
    }
}
int query(int pos){
    int ans=0;
    while(pos>0){
        ans+=bit[pos];
        pos-=(pos&-pos);
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        upd(i,v[i]);
    }
    while(q--){
        int a,b,c;cin>>a>>b>>c;
        if(a==1){
            upd(b,-v[b]);
            v[b]=c;
            upd(b,v[b]);
        }
        else{
            cout<<query(c)-query(b-1)<<"\n";
        }
    }
}
