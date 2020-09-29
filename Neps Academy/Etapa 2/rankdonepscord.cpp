#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,string>pii;
const int mxN=1e3+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int n,t,k;
string s;
map<string,int>mp;
map<string,int>mp1;
vector<pii>v;
bool comp(pii a ,pii b){
    if(a.first==b.first)return a.second<b.second;
    return a.first>b.first;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>s>>t;
        if(mp.find(s)==mp.end()){
            mp[s]=t;
            mp1[s]=25;
        }
        else if(t-mp[s]>=k){
            mp1[s]+=25;
            mp[s]=t;
        }
    }
    for(auto it=mp1.begin();it!=mp1.end();it++){
        v.pb({it->second,it->first});
    }
    sort(v.begin(),v.end(),comp);

    cout<<"--Rank do Nepscord--\n";
    int i=0;
    for(;i<sz(v);i++){
        if(i==3)break;
        cout<<"#"<<i+1<<". "<<v[i].second<<" - Nivel "<<(v[i].first/100)+1<<"\n";
    }
    if(i<3){
        for(;i<3;i++){
            cout<<"#"<<i+1<<".\n";
        }
    }

}
