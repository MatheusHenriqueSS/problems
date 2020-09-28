#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
const int mxN=1e3+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,m;
pii v[mxN];

pii bb(int sum,int ini,int fim){
    int l=ini,r=fim;
    while(l<r){
        if(v[l].first+v[r].first==sum)return {v[l].second,v[r].second};
        else if(v[l].first+v[r].first>sum)r--;
        else l++;
    }
    return {-1,-1};
}
void resp(int a,int b,int c,int d){
    vector<int>ans={a,b,c,d};
    sort(ans.begin(),ans.end());
    for(int i:ans)cout<<i<<" ";
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i].first;
        v[i].second=i;
    }
    sort(v+1,v+n+1);
    if(n<4){
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(v[i].first + v[j].first>=m)continue;
            pii temp1=bb(m-v[i].first-v[j].first,i+1,j-1);
            pii temp2=bb(m-v[i].first-v[j].first,j+1,n);
            if(temp1.first!=-1){
                resp(temp1.first,temp1.second,v[i].second,v[j].second);
                return 0;
            }
            if(temp2.first!=-1){
                resp(temp2.first,temp2.second,v[i].second,v[j].second);
                return 0;
            }
        }
    }
    cout<<"IMPOSSIBLE";
}