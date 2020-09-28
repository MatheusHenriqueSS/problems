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
int n,vis[mxN],t,pai[mxN];
int adj[mxN],len[mxN],id[mxN];//comprimento do ciclo/qual ciclo
void dfs(int i,int p){
    if(vis[i]==2){
        return;
    }
    if(vis[i]==1){
        id[i]=++t;
        int k=p;
        int cnt=1;
        while(k!=i){
            id[k]=t;
            cnt++;
            k=pai[k];
        }
        len[t]=cnt;
        return;
    }
    vis[i]=1;
    int j=adj[i];
    pai[j]=i;
    dfs(j,i);
    vis[i]=2;
 
}
int dfs2(int i){
    if(id[i])return len[id[i]];
    id[i]=++t;
    return len[id[i]]=1+dfs2(adj[i]);
 
}
 
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>adj[i];
    for(int i=1;i<=n;i++){
        if(!vis[i])dfs(i,0);
    }
    for(int i=1;i<=n;i++){
        if(!id[i]){             
            int temp=dfs2(i);
        }
    }
    for(int i=1;i<=n;i++)cout<<len[id[i]]<<" ";
}
