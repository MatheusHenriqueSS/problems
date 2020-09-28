#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef pair<pii,int>piii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?

int n,a,b,k,ans=1,idx;
int resp[mxN];
vector<piii>q;
priority_queue<pii,vector<pii>,greater<pii>>fila;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        q.push_back({{a,b},i});
    }
    sort(q.begin(),q.end());
    for(int i=0;i<n;i++){
        a=q[i].first.first;
        b=q[i].first.second;
        idx=q[i].second;
        if(fila.empty()){
            resp[idx]=1;
            fila.push({b,1});
        }
        else if(fila.top().first>=a){
            //cout<<a<<" "<<b<<" "<<fila.top().first<<"\n";            
            
            resp[idx]=++ans;
            fila.push({b,ans});
            //cout<<idx<<" "<<temp<<"\n";
        }
        else{
            int temp=fila.top().second;
            //cout<<idx<<" "<<temp<<"\n";
            fila.pop();
            resp[idx]=temp;
            fila.push({b,temp});
        }
    }
    cout<<ans<<"\n";
    for(int i=0;i<n;i++){
        cout<<resp[i]<<" ";
    }
   
}
