#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7,mxM=6e5+10;
//did u check when n=1?
//is mxN correct?
int n,q,val[mxN],idx;
int bit[mxM];
struct quer{
    char op;
    int x,y;
}a[mxN];
vi aux;
 
void upd(int pos,int val){
    for(;pos<=idx;pos+=pos&-pos){
        bit[pos]+=val;
    }
}
int query(int pos){
    int ans=0;
    for(;pos>0;pos-=pos&-pos){
        ans+=bit[pos];
    }
    return ans;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>val[i];
        aux.pb(val[i]);
    }
    for(int i=0;i<q;i++){
        char c;int x,y;
        cin>>c>>x>>y;
        if(c=='?'){
            aux.pb(x);
            aux.pb(y);
        }
        else{
            aux.pb(y);
        }
        a[i]={c,x,y};
    }
    sort(aux.begin(),aux.end());
    unordered_map<int,int>mp;
    mp.reserve(mxM);
    for(int i:aux){
        if(mp.find(i)==mp.end()){
            mp[i]=++idx;
        }
    }
    for(int i=0;i<n;i++){
        upd(mp[val[i]],1);
    }
    for(int i=0;i<q;i++){
        char op=a[i].op;
        int x=a[i].x;
        int y=a[i].y;
        if(op=='?'){
            cout<<query(mp[y])-query(mp[x]-1)<<"\n";
        }
        else{
            x--;
            upd(mp[val[x]],-1);
            val[x]=y;
            upd(mp[val[x]],1);
        }
    }
 
}
