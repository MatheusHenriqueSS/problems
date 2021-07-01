#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) int(x.size())

typedef pair<int,int>ii;
typedef vector<int> vi;

const int inf = 1e9+10;
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int n,k;
	cin>>n>>k;
	vi a(n+2);
	int sum = 0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	a[n+1] = inf;

	ll ans = 0;
	for(int i = 1;i <= n;i++){
		//cout<<upper_bound(a.begin()+1,a.end(),a[i-1]+k)-a.begin()<<" "<<max(int(lower_bound(a.begin(),a.end(),a[i-1]+k)-a.begin()),i-1)<<"\n";
		ans+=(upper_bound(a.begin()+1,a.end(),a[i-1]+k)-a.begin())-max(int(lower_bound(a.begin(),a.end(),a[i-1]+k)-a.begin()),i);
	}
	cout<<ans<<"\n";
	return 0;
}
