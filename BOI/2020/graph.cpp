#include<bits/stdc++.h>
#include<fstream>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) int(x.size())

typedef pair<int,int>ii;
typedef vector<int> vi;

const int mxn=1e5+5;
int n,m,t;
ii x[mxn];
double ans[mxn],res[mxn];
int cara[mxn];
vector<ii>g[mxn],aux;
bool ok;
void dfs(int i){
	if(x[i].first==-2){
		x[i].first=1;
		x[i].second=0;
	}
	double val=0;
	for(ii p:g[i]){
		int j=p.first;
		int k=p.second;
		//esse cara sou eu?
		if(j!=i){
			double nval=(double)k/2.0;
			if(val!=0.0 && nval!=val){
					ok=false;
				return;
			}
			val=nval;
			cara[t]=i;
			ans[t]=val;
		}
		else{
			int a=-x[i].first;
			int b=k-x[i].second;
			if(x[j].first==-2){
				x[j].first=a;
				x[j].second=b;
				dfs(j);
			}
			else{
				if(a==x[j].first && b!=x[j].second){
					ok=false;
					return;
				}
				if(a*x[j].first==-1){
					double nval=(double)(b-x[j].second)/(double)(x[j].first-a);
					if(val!=0.0 && nval!=val){
						ok=false;
						return;
					}
					val=nval;
					ans[t]=val;
					cara[t]=i;
				}
			}
		}


	}
	aux.pb({(-x[i].second)/x[i].first,i});
}
void dfs1(int i){

	if(x[i].first!=0){
		res[i]=ans[t];
		ans[t]=(double)(res[i]-x[i].second)/(double)x[i].first;
	}
	for(ii p:g[i]){
		int j=p.first;
		if(x[j].first!=0.0){
			res[j]=(double)x[j].first*ans[t]+x[j].second;
			x[j].first=0;
			dfs1(j);
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//setIO("sort");
	ok=true;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,c;cin>>x>>y>>c;
		g[x].pb({y,c});
		g[y].pb({x,c});
	}
	for(int i=1;i<=n;i++){
		x[i].first=-2;
		ans[i]=1e9+10;
	}
	for(int i=1;i<=n;i++){
		if(x[i].first==-2){
			t++;
			aux.clear();
			dfs(i);
			if(!ok){
				cout<<"NO\n";
				return 0;
			}
			if(ans[t]==1e9+10){
				sort(aux.begin(),aux.end());
				ans[t]=(double)(aux[sz(aux)/2].first);
				dfs1(aux[sz(aux)/2].second);
			}
			else dfs1(cara[t]);
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)cout<<setprecision(10)<<fixed<<res[i]<<" ";
	cout<<"\n";
	return 0;
}
