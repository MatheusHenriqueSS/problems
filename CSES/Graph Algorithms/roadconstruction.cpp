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
int n,m,cnt,ma=1;
int pai[mxN],size[mxN];
int find(int x){
    if(x==pai[x])return x;
    return pai[x]=find(pai[x]);
}
void join(int a,int b){
    a=find(a);
    b=find(b);
    if(size[a]<size[b])swap(a,b);
    pai[b]=a;    
    size[a]+=size[b];
    ma=max(size[a],ma);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    cnt=n;
    for(int i=1;i<=n;i++){
        pai[i]=i;
        size[i]=1;
    }
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        if(find(a)!=find(b)){
            cnt--;
            join(a,b);
            
        }
        cout<<cnt<<" "<<ma<<"\n";
    }
 
}
