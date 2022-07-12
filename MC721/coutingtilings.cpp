#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define sz(x) int(x.size())
 
typedef pair<int,int>ii;
typedef vector<int> vi;
 
const int mxn = 1e3+5, mxm = (1<<10), mod = 1e9+7;
int n, m, dp[mxn][mxm];
 
void solve(int i,int j, int mask, int nmask){
	if(i == n)return;
	if(j >= m)dp[i+1][nmask] = (dp[i+1][nmask] + dp[i][mask])%mod;
 
	else{
		if(mask&(1<<j)){
			solve(i, j+1, mask, nmask);
		}
		else{
			solve(i, j+1, mask, nmask|(1<<j));
			if(j + 1 < m && !(mask&(1<<(j+1)))){
				solve(i, j+2, mask, nmask);
			}
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>m>>n;
 
	dp[0][0] = 1;
 
	for(int i  = 0;i < n;i++){
		for(int mask = 0; mask < (1<<m);mask++){
			solve(i, 0, mask, 0);
		}
	}
 
	cout<<dp[n][0]<<"\n";
 
	return 0;
}