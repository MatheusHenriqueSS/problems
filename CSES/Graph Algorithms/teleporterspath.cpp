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
int n,m,in[mxN],out[mxN],id[mxN];
int st,en;
vi adj[mxN],aux;
map<pii,bool>del;
void solve(int i){
    for(int j:adj[i]){
        if(del[{i,j}]==true)continue;
        del[{i,j}]=true;
        solve(j);
    }
    aux.pb(i);
 
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        adj[a].pb(b);
        out[a]++;
        in[b]++;
    }
    for(int i=1;i<=n;i++){
        if((out[i]>in[i] && st)||(in[i]>out[i])&& en){
            cout<<"IMPOSSIBLE";
            return 0;
        }
        else if(out[i]>in[i])st=i;
        else if(in[i]>out[i])en=i;
    }
    if(st!=1 || en!=n){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    solve(st);
    reverse(aux.begin(),aux.end());
    for(int i=1;i<=n;i++){
        for(int j:adj[i]){
            if(del[{i,j}]==false){
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }
    for(int i:aux)cout<<i<<" ";
    
}
