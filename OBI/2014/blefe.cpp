/*
Matheus Henrique de Sousa
OBI 2014 - p2f2 - blefe
*/
#include<bits/stdc++.h>
#include <fstream>
using namespace std;
void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
}
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxn=1e6+5,M=1e9+7;
const int LINF = 0x3f3f3f3f3f3f3f3f;
int n,m,v[mxn];
unordered_set<int> a,b;
bool check(int j,int val){
    for(int i=0;i<j;i++){
      if(b.find(val-v[i])!=b.end())return true;
    }
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //setIO("galactic");
    cin>>n>>m;
    for(int i=0;i<n;i++){
      int x;cin>>x;
      a.insert(x);
    }
    for(int i=0;i<m;i++){
      int x;cin>>x;
      v[i]=x;
      if(a.find(x)==a.end() && !check(i,x)){
        cout<<x;
        return 0;
      }
      b.insert(x);
    }
    cout<<"sim";


    return 0;
}
