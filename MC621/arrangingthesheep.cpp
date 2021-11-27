#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long 
#define sz(x) int(x.size())
 
typedef pair<int,int> ii;
typedef vector<int> vi;
 
 
int n,tot;	
string s;
vi sp;
 
ll calc(int x){
 
	if(x < 0 || x >= n)return 1e18;
 
	ll cur = 0;
	for(int j = 0; j < tot;j++){
		cur+=(ll)(abs(sp[j]-(x+j)));
	}
 
	return cur;
 
}
 
void solve(){
 
	cin>>n>>s;
 
	sp.clear();
	tot = 0;
 
	for(int i = 0; i < n;i++){
		if(s[i] == '*'){
			sp.pb(i);
			tot++;
		}
	}	
 
	int l = 0,r = n-tot;
	ll res = 1e18;
 
	while(l <= r){	
		//cout<<l<<" "<<r<<"\n";
 
		int m = (l+r)/2;
		int m1 = m-1;
		int m2 = m+1;
 
		ll cm = calc(m);
		ll cm1 = calc(m1);
		ll cm2 = calc(m2);
 
		if(cm1 >= cm && cm <= cm2){
			cout<<cm<<"\n";
			return;
		}
		else if(cm1 >= cm && cm >= cm2 ){
			res =min(res,cm2);
			l = m2+1;
		}
		else{
			res=min(res,cm1);
			r = m1-1;
		}
 
	}
 
	/*for(int i = 0;i < n-tot;i++){
		int cur = 0;
		for(int j = 0;j < tot;j++){
			cur+=abs(sp[j]-(i+j));
		}
		cout<<cur<<" ";
	}
	cout<<"\n";
	*/
 
	cout<<res<<"\n";
}
 
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
 
	int t;cin>>t;
	while(t--)solve();
	return 0;
}
