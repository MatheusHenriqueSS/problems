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
int n,tot,del[mxN],cnt=0,in[mxN];
vector<pii>adj[mxN];
string ans="";
void solve(int i){
    vi aux;
    aux.pb(i);
    while(!aux.empty()){
        int x=aux.back();
        //cout<<x<<" "<<sz(adj[x])<<"\n";
        while(!adj[x].empty() && del[adj[x].back().second]){
            in[x]--;
            adj[x].pop_back();
        }
        if(!in[x]){
            aux.pop_back();
            continue;
        }
        //cout<<x<<" "<<sz(adj[x])<<"\n";
        pii v=adj[x].back();
        //cout<<x<<" "<<v.first<<"\n";
        in[x]--;
        adj[x].pop_back();
        del[v.second]=1;
        aux.pb(v.first);
        if((v.first&1))ans+='1';
        else ans+='0';
        //cout<<ans<<"\n";
    }
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    int  tot=(1<<n-1)-1;
    for(int i=0;i<=tot;i++){
        in[i]=2;
        int temp=i;
        if((temp&(1<<n-2))){
                temp^=(1<<n-2);
        }
        temp=(temp<<1);
        cnt++;
        adj[i].pb({temp,cnt});
        cnt++;
        adj[i].pb({temp|1,cnt});
    }
    solve(0); 
    cout<<string(n-1,'0')<<ans;
 
}
