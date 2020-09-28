//Matheus Henrique de Sousa Silva
//rest stops
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
int l,n,x,y,ma[mxn];
pii a[mxn];
int32_t main(){
     ios_base::sync_with_stdio(0); cin.tie(0); 
    setIO("reststops");
	cin>>l>>n>>x>>y;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int cur=0;
	for(int i=n;i>=0;i--){
		cur=max(cur,a[i].second);
		ma[i]=cur;
	}
	int ans=,last=0;
	for(int i=1;i<=n;i++){
		if(ma[i]==a[i].second){
			ans+=(x-y)*(a[i].first-last)*a[i].second;
			last=a[i].first;
		}
	}
	cout<<ans;

    return 0;
}
