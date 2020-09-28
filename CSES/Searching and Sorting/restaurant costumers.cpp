#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
typedef pair<int,int>pii;
const int mxN=4e5+10,M=1e9+7;
int n,a,b;
pii v[mxN];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i=0;i<2*n;i+=2){
        cin>>a>>b;
        v[i]={a,1};
        v[i+1]={b,-1};
    }
    sort(v,v+2*n);
    int temp=0,ans=0;
    for(int i=0;i<2*n;i++){
        //cout<<v[i].first<<" "<<v[i].second<<"\n";
        if(temp+=v[i].second)ans=max(ans,temp);
    }
    cout<<ans;  
}