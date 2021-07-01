#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1e5+5,INF=1e18+7;
//did u check when n=1?
//is mxN correct?
int n,v[mxN],bit[mxN],ans;
void upd(int pos){
    while(pos<mxN){
        bit[pos]++;
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
     cin>>n;
     for(int i=0;i<n;i++){
         cin>>v[i];
     }
     for(int i=n-1;i>=0;i--){
         ans+=query(v[i]-1);
         upd(v[i]);
     }
     cout<<ans;


}   
