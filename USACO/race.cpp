//Matheus Henrique de Sousa Silva
//race
//9.9.20
#include<bits/stdc++.h>
#include <fstream>
using namespace std;
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxn=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int k,n;
int32_t main(){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  setIO("race");
  cin>>k>>n;
  for(int i=0;i<n;i++){
    int x;cin>>x;
    int l=0,r=0,ans=0;
    for(int j=1;;j++){
        l+=j;
        ans++;
        if(l+r>=k){
           cout<<ans<<"\n";
           break;
        }
        if(j>=x){
          r+=j;
          ans++;
          if(l+r>=k){
            cout<<ans<<"\n";
            break;
          }
        }
    }
  }
  return 0;
}
