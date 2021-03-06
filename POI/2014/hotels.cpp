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
/*
O(N²)
Lets simulate for each vertex if it is the center of the tree others,
For three hotels at distance x, i check for each subtree how many vertices
have this distance from the centre
*/
const int mxn=5e3+5;
int n,t,a[mxn],dist[mxn];
ll sub[mxn];
vi g[mxn];
ll res;
vector<int>aux;
void dfs(int i,int p){
	for(int j:g[i])if(j!=p){
		if(!p){
			t++;
			aux.clear();
			aux.resize(n+1);
		}
		a[j]=a[i]+1;
		dist[a[j]]++;
		aux[a[j]]++;
		dfs(j,i);
		if(!p){
			//casos em que escolho 3 de uma mesma subtree
			for(int i=1;i<=n;i++){
				if(aux[i]<3)continue;
				res-=(1ll*aux[i]*(aux[i]-1ll)*(aux[i]-2ll))/6ll;
			}
			for(int i=1;i<=n;i++){
				if(aux[i]<2)continue;
				sub[i]+=(1ll*aux[i]*(aux[i]-1ll))/2ll;
				res+=(1ll*aux[i]*(aux[i]-1ll))/2ll*aux[i]*1ll;
			}
		}
	}
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//setIO("sort");
	cin>>n;
	aux.resize(n);
	for(int i=0;i<n-1;i++){
		int x,y;cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		memset(a,0,sizeof(a));
		memset(dist,0,sizeof(dist));
		memset(sub,0,sizeof(sub));
		dfs(i,0);
		for(int i=1;i<=n;i++){
			if(dist[i]<3)continue;
			res+=(1ll*dist[i]*(dist[i]-1ll)*(dist[i]-2ll))/6ll;

		}
		for(int i=1;i<=n;i++){
			if(dist[i]<2)continue;
			res-=sub[i]*dist[i];
		}

	}
	cout<<res<<"\n";
	return 0;
}
