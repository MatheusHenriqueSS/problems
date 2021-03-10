#include<bits/stdc++.h>
#include<fstream>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) int(x.size())

typedef pair<int,int>ii;
typedef vector<int> vi;

/*
first attempt = 0/100 pts
*/
const int mxn=2e5+5;
int n,m,nc,t,bcc,in[mxn],low[mxn],id[mxn],a[mxn],v[mxn];
int lv[mxn],anc[mxn][20];
vi g[mxn],bg[mxn];
stack<int>st;
set<ii>s;
vector<ii>edges,brid,ord,ans;
vector<vi>aux;

void dfs(int i,int p){
	in[i]=low[i]=++t;
	st.push(i);

	bool ok=false;
	for(int j:g[i]){
		if(j==p && !ok){
			ok=1;
			continue;
		}
		if(in[j])low[i]=min(low[i],in[j]);
		else{
			dfs(j,i);
			low[i]=min(low[i],low[j]);
			nc+=(i==1);

			if(low[j]>=in[i]){
				if(low[j]>in[i])brid.pb({min(i,j),max(i,j)});
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
void up(int x,int l){
	if(a[x] || x==l)return;
	a[x]=1;
	up(anc[x][0],l);
}
void check(int i,int p){
	for(int j:bg[i])if(j!=p){
		check(j,i);
		if(a[j])ans.pb({j,i});
		else ans.pb({i,j});
	}
}
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//mp.reserve(mxn);
	//setIO("sort");
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y;cin>>x>>y;
		edges.pb({x,y});
		if(x==y)continue;
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
	int q;cin>>q;
	while(q--){
		int x,y;cin>>x>>y;
		x=id[x],y=id[y];
		int l=lca(x,y);
		ord.pb({x,l});
			
	}
	sort(ord.begin(),ord.end(),[](ii a,ii b){return lv[a.second]<lv[b.second];});
	for(ii tmp:ord){
		up(tmp.first,tmp.second);
	}
	check(1,0);
	sort(ans.begin(),ans.end());
	sort(brid.begin(),brid.end());
	for(ii tmp:edges){
		int x=tmp.first;
		int y=tmp.second;

		if(!binary_search(brid.begin(),brid.end(),ii(min(x,y),max(x,y))))cout<<"B";
		else if(binary_search(ans.begin(),ans.end(),ii(id[x],id[y])))cout<<"R";
		else cout<<"L";
	}

	cout<<"\n";
	return 0;
}
