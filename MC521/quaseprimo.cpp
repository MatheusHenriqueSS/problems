#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxk=45,M=1e9+7;
int prime[mxk];
int n,k;
int ans;
void solve(int idx=0,int prod=1,int qtd=0){
    if(prod>n)return;
    //cout<<idx<<" "<<prod<<" "<<qtd<<"\n";
    if(idx==k){
        if(qtd>0){
        if(qtd&1)ans+=n/prod;
        else ans-=n/prod;
        
        }
        return;
        
    }
    solve(idx+1,prod*prime[idx],qtd+1);
    solve(idx+1,prod,qtd);

}
// LONG LONG CASE
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>prime[i];
    }
    solve();
    cout<<n-ans;
}
