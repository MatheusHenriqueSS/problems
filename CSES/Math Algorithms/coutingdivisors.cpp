#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=1e6+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int menor[mxN],ans[mxN],n;
void sieve(){
    for(int i=2;i<=1000000;i++){
        if(!menor[i]){
            for(int j=i;j<mxN;j+=i){
                menor[j]=(menor[j]==0?i:min(menor[j],i));
            }
        }
    }   
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    cin>>n;
    
    for(int i=0;i<n;i++){
        ans[i]=1;
        int x;cin>>x;
        while(x>1){
            int cnt=0;
            int k=menor[x];
            while(x%k==0){
                x/=k;
                cnt++;
            }
            ans[i]*=(cnt+1);
        }
        cout<<ans[i]<<"\n";
        
    }
}
