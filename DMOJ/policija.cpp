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
const int mxn=2e5+5;
int n,m,t,cnt,nc,in[mxn],low[mxn],a[mxn],id[mxn];
int lv[mxn],anc[mxn][20];
vi g[mxn],bg[mxn];
vector<vi>aux;
stack<int> st;
map<ii,int>mp;
void dfs(int i,int p){
	in[i]=low[i]=++t;
	st.push(i);

	for(int j:g[i])if(j!=p){
		if(in[j])low[i]=min(low[i],in[j]);
		else{
			nc+=(p==1);
			dfs(j,i);
			low[i]=min(low[i],low[j]);

			if(low[j]>=in[i]){
				if(low[j]>in[i])mp[{i,j}]=mp[{j,i}]=1;
				a[i]=(i!=1);
				aux.pb({i});
				while(aux.back().back()!=j){
					aux.back().pb(st.top());
					st.pop();
				}

			}
		}
	}

}

void dfs1(int i,int p){
	for(int j:bg[i])if(j!=p){
		lv[j]=lv[i]+1;
		anc[j][0]=i;
		dfs1(j,i);
	}
}

void init(){
	for(int j=1;j<20;j++){
		for(int i=1;i<=cnt;i++){
			if(anc[i][j-1])anc[i][j]=anc[anc[i][j-1]][j-1];
		}
	}
}

int lca(int u,int v){
	if(lv[u]<lv[v])swap(u,v);

	for(int i=19;i>=0;i--){
		if(lv[u]-(1<<i)>=lv[v])u=anc[u][i];
	}
	if(u==v)return u;

	for(int i=19;i>=0;i--){
		if(anc[u][i] && anc[u][i]!=anc[v][i]){
			u=anc[u][i];
			v=anc[v][i];
		}
	}

	return anc[u][0];
}
 
bool check(int u,int v,int x){
	int l=lca(id[u],id[v]);
	int l1=lca(id[u],id[x]);
	int l2=lca(id[v],id[x]);
	return (l1==l && l2==id[x]) || (l2==l && l1==id[x]);
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//setIO("sort");
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	
	dfs(1,0);
	a[1]=(nc>1);
	for(int i=1;i<=n;i++){
		if(a[i])id[i]=++cnt;
	}

	for(vi i:aux){
		cnt++;
		for(int j:i){
			if(a[j]){
				bg[id[j]].pb(cnt);
				bg[cnt].pb(id[j]);
			}
			else id[j]=cnt;
		}
	}

	dfs1(1,0);
	init();

	int q;cin>>q;
	while(q--){
		int op;cin>>op;
		if(op==1){
			int u,v,x,y;cin>>u>>v>>x>>y;
			if(id[u]!=id[v] && mp[{x,y}] && check(u,v,x) && check(u,v,y))cout<<"no\n";
			else cout<<"yes\n";
		}
		else{
			int u,v,x;cin>>u>>v>>x;
			if(id[u]!=id[v] && a[x] && check(u,v,x))cout<<"no\n";
			else cout<<"yes\n";
		}
	}

	return 0;
}
