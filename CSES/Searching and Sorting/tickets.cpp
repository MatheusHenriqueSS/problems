#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
typedef pair<int,int>pii;
const int mxN=2e5,M=1e9+7;
int n,m,x;
int a[mxN];
vector<int>v;

int buscab(int u){
    int ini=0,fim=sz(v)-1,meio,resp=-1,idx;
    while(ini<=fim){
        meio=(ini+fim)/2;
        if(v[meio]==u){
            resp=v[meio];
            v.erase(v.begin()+meio);
            return resp;
        }
        else if(v[meio]<u){
            resp=v[meio];
            idx=meio;
            ini=meio+1;
        }
        else {
            fim=meio-1;
        }
    }
    if(resp!=-1){
        v.erase(v.begin()+idx);
    }
    return resp;
    
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x;
        v.pb(x);
    }
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    sort(v.begin(),v.end());

    for(int i=0;i<m;i++){
        cout<<buscab(a[i])<<"\n";
    }
 

}