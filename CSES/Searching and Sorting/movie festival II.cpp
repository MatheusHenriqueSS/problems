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
int n,k;
bool comp(pii a,pii b){
    return a.second>b.second;
}
priority_queue<pii,vector<pii>,function<bool(pii a,pii b)>>fila(comp);
multiset<int>q;
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        fila.push({a,b});
    }
    if(n<=k){
        cout<<n;
        return 0;
    }
    int ans=0,cnt=0;
    for(int i=0;i<n;i++){        
        auto it=q.upper_bound(fila.top().first);
        if(it==q.begin()){
            if(cnt<k){
                ans++;
                cnt++;
                q.insert(fila.top().second);
            }            
        }
        else{
            ans++;
            it--;
            q.erase(it);
            q.insert(fila.top().second);
        }
        fila.pop();
    
    }
    cout<<ans;


    
    
    
}