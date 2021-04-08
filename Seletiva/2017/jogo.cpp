#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define pb push_back
#define sz(x) int(x.size())

typedef pair<int,int> ii;
typedef vector<int> vi;

const int mxn=3e3+5;
struct pt{
	int x,y;
	ll val;

	int half(){
		return y<0 || (y==0 && x<0);
	}

	pt operator-(pt p){return {x-p.x,y-p.y,val};}
} a[mxn],b[mxn];

int cross(pt a,pt b){
	ll res = 1ll*a.x*b.y-1ll*b.x*a.y;

	if(!res)return 0;
	if(res > 0)return 1;
	return -1;
}

bool cmp(pt a,pt b){

	if(a.half() != b.half())return a.half() < b.half();
	int c=cross(a,b);
	if(!c)return abs(a.x)+abs(a.y) < abs(b.x)+abs(b.y);		
	return c > 0;
}

int n;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);

	cin>>n;

	for(int i = 0;i < n;i++){
		int x,y,val;cin>>a[i].x>>a[i].y>>a[i].val;
	}

	ll ans = a[0].val+a[1].val;

	for(int i = 0;i < n;i++){

		for(int j = 0;j < n;j++)b[j] = a[j]-a[i];
		sort(b,b+n,cmp);

		ans = max(ans,b[0].val+b[1].val);
		
		for(int j = 2;j < n;j++){
			if(!cross(b[j],b[j-1]))b[j].val+=b[j-1].val;
			ans = max(ans,b[0].val+b[j].val);

		}

	}

	cout<<ans<<"\n";

	return 0;												
}
