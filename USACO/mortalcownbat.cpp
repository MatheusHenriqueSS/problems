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
const int mxn=1e5+5,inf=1e9+5;

int n,m,k,a[mxn],dp[mxn][30],tab[30][30],pref[mxn][30],best[mxn];
string s;

void init(){
	for(int i=0;i<mxn;i++){
		best[i]=inf;
		for(int j=0;j<30;j++)dp[i][j]=inf;

	}

}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	setIO("cowmbat");
	//dp[i]stores the minimum cost to make string until i good
	cin>>n>>m>>k;
	cin>>s;
	for(int i=1;i<=n;i++)a[i]=s[i-1]-'a';
	for(int i=0;i<m;i++){
		for(int j=0;j<m;j++){
			cin>>tab[i][j];
		}
	}

	for(int l=0;l<m;l++){
		for(int i=0;i<m;i++){
			for(int j=0;j<m;j++)tab[i][j]=min(tab[i][j],tab[i][l]+tab[l][j]);
		}
	}

	for(int j=0;j<26;j++){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=tab[a[i]][j];
			pref[i][j]=sum;
		}
	}
	

	init();
	best[0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=min(dp[i][j],dp[i-1][j]+tab[a[i]][j]);
			if(i>=k){
				dp[i][j]=min(dp[i][j],pref[i][j]-pref[i-k][j]+best[i-k]);
			}
			best[i]=min(best[i],dp[i][j]);
		}
	}
	cout<<best[n]<<"\n";
	return 0;
}
