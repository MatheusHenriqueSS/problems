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
int n,v[mxN],bit[mxN];
void upd(int pos,int val){
    for(;pos<=n;pos+=pos&-pos){
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
int busca_bit(int val){
    int pos=0;
    int ans=0;
    for(int i=30;i>=0;i--){
        if(pos+(1<<i)<n && ans+bit[pos+(1<<i)]<val){
            ans+=bit[pos+(1<<i)];
            pos+=(1<<i);
            
        }
    }
    return pos+1;
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<=n;i++)upd(i,1);
    for(int i=0;i<n;i++){
        int x;cin>>x;
        int temp=busca_bit(x);
        upd(temp,-1);
        cout<<v[temp]<<" ";
    } 
}
