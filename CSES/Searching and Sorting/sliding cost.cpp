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
int n,k;
int bit1[mxN],bit2[mxN],v[mxN];
vi aux;
map<int,int>mp1,mp2;
void upd(int bit[],int pos,int val){
    while(pos<=n){
        bit[pos]+=val;
        pos+=(pos&-pos);
    }
}
int query(int bit[],int pos){
    int ans=0;
    while(pos>0){
        ans+=bit[pos];
        pos-=(pos&-pos);
    }
    return ans;
}
void u(int x,int y){
    upd(bit1,mp1[x],1*y);
    upd(bit2,mp1[x],x    *y);
}
void bb(){
    int l=1,r=n,m,ans;
    while(l<=r){
        m=(l+r)/2;
        if(query(bit1,m)<(k+1)/2)l=m+1;
        else{
            ans=m;
            r=m-1;
        }
    }
    int temp1,temp2,tot1,tot2;
    temp1=query(bit1,ans-1);
    temp2=query(bit1,n)-query(bit1,ans);
    tot1=query(bit2,ans-1);
    tot2=query(bit2,n)-query(bit2,ans);
    //cout<<ans<<"\n";
    //cout<<temp1<<" "<<temp2<<" "<<tot1<<" "<<tot2<<"\n";
    cout<<abs(temp1*mp2[ans]-tot1)+abs(temp2*mp2[ans]-tot2)<<" ";
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>v[i];
        aux.pb(v[i]);
    }
    sort(aux.begin(),aux.end());
    int idx=0;
    for(auto c:aux){
        if(mp1.find(c)==mp1.end()){
            mp1[c]=++idx;
            mp2[idx]=c;
        }
    }
    for(int i=0;i<k;i++){
        u(v[i],1);
    }
    for(int i=k;i<n;i++){
        bb();     
        u(v[i-k],-1);
        u(v[i],1);
    }
    bb();
 


}