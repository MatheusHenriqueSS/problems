#include<bits/stdc++.h>
#include<fstream>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) int(x.size())

typedef pair<int,int>ii;
typedef vector<int> vi;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

const int mxn=105;
int n,a[mxn],dp[mxn][mxn],ans[mxn];

void init(){
	for(int i=0;i<mxn;i++){
		for(int j=0;j<mxn;j++)dp[i][j]=mxn;
	}
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	setIO("taming");	
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		init();		
		dp[0][n]=0;
		// i have to put i zeros in the sequence
		for(int k=1;k<=i;k++){
			for(int j=0;j<n;j++){
				int val=0;
				for(int l=j;l<n;l++){
					val+=((l-j)!=a[l]);
					dp[k][j]=min(dp[k][j],val+dp[k-1][l+1]);
				}
			}
		}

		/*for(int k=1;k<=i;k++){
			for(int j=0;j<n;j++){
				cout<<k<<" "<<j<<" "<<dp[k][j]<<"\n";
			}
		}
		cout<<"\n";
		*/
		ans[i]=dp[i][0];


	}
	for(int i=1;i<=n;i++)cout<<ans[i]<<"\n";
	return 0;
}
