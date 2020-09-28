#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef pair<pii,int >ii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,INF=1e18+7;
//did u check when n=1?
//is mxN correct?
int n,m,pai[mxN],vis[mxN],dist[mxN];
vector<ii>edges;
bool comp(ii a,ii b){
    return a.second<b.second;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        edges.pb({{a,b},c});
    }
    for(int i=1;i<=n;i++)dist[i]=INF;
    dist[1]=0;
    sort(edges.begin(),edges.end(),comp);
    for(int i=0;i<n-1;i++){
        for(auto e:edges){
            int a=e.first.first;
            int b=e.first.second;
            int c=e.second;
            if(dist[b]>dist[a]+c){
                pai[b]=a;
                dist[b]=dist[a]+c;    
            }
            
        }
    }
    for(auto e:edges){
        int a=e.first.first;
        int b=e.first.second;
        int c=e.second;
        if(dist[b]>dist[a]+c){
            pai[b]=a;
            dist[b]=dist[a]+c;
            int u=b;
            while(!vis[u]){
                vis[u]=1;
                u=pai[u];
            }    
            vi ans;
            int k=u;
            ans.pb(k);
            k=pai[k];
            while(k^u){
                ans.pb(k);
                k=pai[k];
            }
            ans.pb(u);
            reverse(ans.begin(),ans.end());
            cout<<"YES\n";
            for(int c:ans)cout<<c<<" ";
            return 0;
        }
    }
    cout<<"NO";
 
}
