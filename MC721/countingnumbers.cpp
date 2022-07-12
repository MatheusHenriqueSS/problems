#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define sz(x) int(x.size())
 
typedef pair<int,int>ii;
typedef vector<int> vi;
 
const int mod = 1e9+7;
 
string a,b,num;
int len;
ll dp[30][2][2][15];
 
ll solve(int pos,int e, int st, int last){
	if(pos == len)return 1;
	ll &ans = dp[pos][e][st][last];
 
	if(ans != -1ll)return ans;
 
	int lim = 9;
	if(e)lim = (int)(num[pos] - '0');
 
 
	ans = 0;
 
	for(int i = 0;i <= lim; i++){
		if(i == last && !(last == 0 && !st))continue;
 
		int nst = st;
		if(i!=0)nst = 1;
		int ne = e;
		if(e == 1 && i < lim)ne = 0;
		ans += solve(pos+1, ne, nst, i);
	}
 
	return ans;
 
}
 
int check(string cur){
	int ans  = 1;
	for(int i = 0;i < sz(cur) - 1;i++){
		if(cur[i] == cur[i+1])ans = 0;
	}
 
	return ans;
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin>>a>>b;
 
	num = b, len = sz(b);
	ll ans = solve(0, 1, 0, 0);
 
	memset(dp, -1, sizeof(dp));
 
	num = a, len = sz(a);
	ans -= solve(0, 1, 0, 0) - check(a);
 
	cout<<ans<<"\n";
	return 0;
}