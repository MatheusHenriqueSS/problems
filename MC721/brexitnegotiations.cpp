#include <bits/stdc++.h>
using namespace std;
        
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"
    
typedef pair<int,int>ii;
typedef vector<int> vi;
    
const int mxn = 4e5 + 5;
int n, e[mxn], in[mxn], ma[mxn];
vi g[mxn];
bool v[mxn];
    
int dfs(int i) {
    if (v[i])return ma[i];
    v[i] = 1;
    
    ma[i] = e[i];
    for (int j: g[i]){
        ma[i] = max(ma[i], dfs(j));
    }
    
    return ma[i];
}
    
void solve() {
    cin>>n;
    
    for (int i = 1; i <= n; i++) {
        cin>>e[i];
        int d;cin>>d;
    
        for (int x, j = 0; j < d; j++) {
            cin>>x;
            g[x].pb(i);
            in[i]++;
        }
    }
    
    for (int i = 1; i <= n; i++)if(!in[i]) {
        dfs(i);
    }
    
    priority_queue<ii> pq;
    
    for (int i = 1; i <= n; i++)if(!in[i]) {
        pq.push({ma[i], i});
    }
    
    int ans = 0, cnt = 0;
    while(!pq.empty()) {
        int i = pq.top().second;
        int p = pq.top().first;
        pq.pop();
    
        ans = max(ans, p + cnt);
        cnt++;
    
        for (int j: g[i]) {
            in[j]--;
            if(!in[j])pq.push({ma[j], j});
        }
    }
    
    cout<<ans<<"\n";   
}
    
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    
    int t = 1;
    while(t--) solve();
}