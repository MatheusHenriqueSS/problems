#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m,k,cnt,vis[mxN];
vector<pii>adj[mxN];
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].pb({c,b});
    }
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,1});
    while(true){
        int i=q.top().second;
        int d=q.top().first;
        q.pop();
        if(vis[i]==k)continue;
        if(i==n){
            cout<<d<<" ";
            cnt++;
            if(cnt==k)break;
        }
        vis[i]++;
        for(pii p:adj[i]){
            int j=p.second;
            int w=p.first;
            q.push({w+d,j});
        }
    }
}
