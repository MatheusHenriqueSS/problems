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
int n,m,q,t,bcc,nc,in[mxn],low[mxn],a[mxn],id[mxn];
int anc[mxn][20],lv[mxn];
vi g[mxn],bg[mxn];
vector<vi>aux;
stack<int>st;

void dfs(int i,int p){
	in[i]=low[i]=++t;
	st.push(i);

	for(int j:g[i])if(j!=p){
		if(in[j])low[i]=min(low[i],in[j]);
		else{
			dfs(j,i);
			nc+=(i==1);
			low[i]=min(low[i],low[j]);

			if(low[j]>=in[i]){
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
		for(int i=1;i<=bcc;i++){
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
bool check(int x,int y,int z){
	int l=lca(id[x],id[y]);
	int l1=lca(id[x],id[z]);
	int l2=lca(id[y],id[z]);
	if((l==l1 && l2==id[z]) || (l==l2 && l1==id[z]))return true;
	return false;
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//setIO("sort");
	cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}

	dfs(1,0);
	a[1]=(nc>1);
	for(int i=1;i<=n;i++)if(a[i]){
		id[i]=++bcc;
	}
	for(vi i:aux){
		bcc++;
		for(int j:i){
			if(id[j]){
				bg[id[j]].pb(bcc);
				bg[bcc].pb(id[j]);
			}
			else id[j]=bcc;
		}
	}
	dfs1(1,0);
	init();

	while(q--){
		int u,v,x;cin>>u>>v>>x;
		if(u==x || v==x){
			cout<<"NO\n";
			continue;
		}
		if(id[u]!=id[v] && a[x] && check(u,v,x))cout<<"NO\n";
		else cout<<"YES\n";
	}

	return 0;
}
