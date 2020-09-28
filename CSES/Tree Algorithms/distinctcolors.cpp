#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
//#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,res[mxN];
vi adj[mxN];
struct node{
    map<int,int>mp;
}t [mxN];
void dfs(int i,int p){
    //t[i].mp[t[i].cor]=1;
    for(int j:adj[i])if(j!=p){
        dfs(j,i);
        if(sz(t[j].mp)>sz(t[i].mp))swap(t[i].mp,t[j].mp);
        t[i].mp.merge(t[j].mp);
    }
    res[i]=sz(t[i].mp);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
 
    for(int i=0;i<n;i++){
        int x;cin>>x;
        t[i].mp[x]++;
    }
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(0,-1);  
    for(int i=0;i<n;i++)cout<<res[i]<<" ";
}
