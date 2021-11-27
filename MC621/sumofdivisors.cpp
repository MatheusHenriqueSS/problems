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
int n;
int sum(int n){
    return (n%M*((n-1)%M))%M*((M+1)/2)%M;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
    int r=(n/(n/i));
    ans+=n/i%M*(sum(r+1)-sum(i)+M)%M;
    i=r;
    }
    cout<<ans%M;
}
