#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef pair<pii,int>piii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m,pai[mxN],size[mxN],ans;
vector<piii>edges;
bool comp(piii a,piii b){
    return a.second<b.second;
}
int find(int x){
    if(x==pai[x])return x;
    return pai[x]=find(pai[x]);
}
void join(int a,int b){
    a=find(a);b=find(b);
    if(size[a]<size[b])swap(a,b);
    size[a]+=size[b];
    pai[b]=a;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        size[i]=1;
        pai[i]=i;
    }
    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        edges.pb({{a,b},c});
    }
    sort(edges.begin(),edges.end(),comp);
    for(auto e:edges){
        int a=e.first.first;
        int b=e.first.second;
        int c=e.second;
        if(find(a)!=find(b)){
            ans+=c;
            join(a,b);
        }
    }
    if(size[find(1)]!=n)cout<<"IMPOSSIBLE";
    else cout<<ans;
 
 
 
}
