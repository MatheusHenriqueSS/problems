#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef pair<pii,int>ii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,q,v[mxN],bit[mxN],idx,ans[mxN],last[mxN];
vi aux;
struct st{
    int a,b,idx;
} r[mxN];
bool comp(st x,st y){return x.b<y.b;}
void upd(int pos,int val){
    for(;pos<=n;pos+=pos&-pos){
        //cout<<pos<<"\n";
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
    for(int i=1;i<=n;i++){
        cin>>v[i];
        aux.pb(v[i]);
    }
    sort(aux.begin(),aux.end());
    unordered_map<int,int>mp;
    mp.reserve(mxN);
    for(int i:aux){
        if(mp.find(i)==mp.end()){
            mp[i]=++idx;
        }
    }
    for(int i=1;i<=n;i++)v[i]=mp[v[i]];
    for(int i=0;i<q;i++){
        cin>>r[i].a>>r[i].b;
        r[i].idx=i;
    }
    sort(r,r+q,comp);   
    memset(last,-1,sizeof(last));
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(last[v[i]]!=-1){
            upd(last[v[i]],-1);
        }
        last[v[i]]=i;
        upd(i,1);
        for(;cnt<q && r[cnt].b==i;cnt++){
            ans[r[cnt].idx]=query(r[cnt].b)-query(r[cnt].a-1);
        }
    }
    for(int i=0;i<q;i++)cout<<ans[i]<<"\n";
 
}
