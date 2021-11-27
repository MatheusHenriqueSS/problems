#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long 
#define sz(x) int(x.size())
 
typedef pair<int,int> ii;
typedef vector<int> vi;
 
int n,t,k;
 
int query(int l,int r){
 
	cout<<"? "<<l<<" "<<r<<"\n";	
	cout.flush();
	int ans;cin>>ans;
 
	return ans;
}
 
 
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
 
	cin>>n>>t>>k;
 
	int l = 1, r = n;
 
	while(l < r){
 
		int m = (l+r)/2;
 
		int cur = query(l,m);
 
		int zr = (m-l+1)-cur;
 
		if(zr < k){
			l = m+1;
			k-=zr;
		}	
		else r = m;
 
	}
 
	cout<<"! "<<l<<"\n";
	return 0;
}
