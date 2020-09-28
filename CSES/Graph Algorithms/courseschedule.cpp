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
int n,m,peso[mxN];
vector<int>adj[mxN];
//did u check when n=1?
//is mxN correct?
vi ans;
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        peso[b]++;
    }
    queue<int>fila;
    for(int i=1;i<=n;i++){
        if(!peso[i])fila.push(i);
    }
    for(int i=0;i<n;i++){
        if(!fila.empty()){
            int u=fila.front();
            fila.pop();
            ans.pb(u);
            for(int i:adj[u]){
                peso[i]--;
                if(!peso[i])fila.push(i);
            }
        }
    }
    if(sz(ans)!=n)cout<<"IMPOSSIBLE";
    else {
        for(int i:ans)cout<<i<<" ";
    }
 
}
