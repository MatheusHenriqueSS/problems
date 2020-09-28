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
//is mxN correct    ?
struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 
int n,m,in[mxN];
vi ans;
vector<pii>adj[mxN];
bool del[mxN];
void solve(int i){
    vector<int>aux;
    aux.pb(i);
    while(!aux.empty()){
        int x=aux.back();
        while(!adj[x].empty() && del[adj[x].back().second]){
            adj[x].pop_back();
            in[x]--;
        }
        if(!in[x]){
            ans.pb(x);
            aux.pop_back();
            continue;
        }
        pii v=adj[x].back();
        adj[x].pop_back();
        in[x]--;
        del[v.second]=1;
        aux.pb(v.first);
 
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
   
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        adj[a].pb({b,i});
        adj[b].pb({a,i});
        in[a]++;
        in[b]++;
    }
    for(int i=1;i<=n;i++)if(in[i]&1){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    solve(1);
    for(int i=1;i<=m;i++){
        if(!del[i]){
            cout<<"IMPOSSIBLE";
            return 0;
        }
    }
    for(int i:ans)cout<<i<<" ";
 
}
