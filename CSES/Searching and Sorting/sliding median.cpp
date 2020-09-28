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
int n,k,v[mxN],bit[mxN];
vector<int>aux;
map<int,int>mp1,mp2;
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
void bb(){
    int l=1,r=n,m,resp;
    while(l<=r){
        //cout<<m<<"\n";
        m=(l+r)/2;
        int temp=query(m);
        if(temp<(k+1)/2)l=m+1;
        else{
            if(temp>=(k+1)/2)resp=m;
            r=m-1;
        }

    }
    cout<<mp2[resp]<<" ";
}
int32_t main(){

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
    for(int i=0;i<k;i++)upd(mp1[v[i]],1);
    for(int i=k;i<n;i++){
        bb();
        upd(mp1[v[i-k]],-1);
        upd(mp1[v[i]],1);
    }
    bb();
    
}