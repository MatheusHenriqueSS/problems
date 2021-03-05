#include<bits/stdc++.h>
#include<fstream>
using namespace std;

#define int long long
#define pb push_back
#define sz(x) int(x.size())

typedef pair<int,int>ii;
typedef vector<int> vi;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}
const int M=1e9+7,mxn=2e3+5;
int fat[mxn],inv[mxn];
int mod(int a){int ret=a%M;if(ret<0)ret+=M;return ret;}
int exp(int a,int b){
	if(b==0)return 1ll;
	if(b==1)return mod(a);
	int t=mod(exp(a,b/2));
	if(b&1)return mod(a*mod(t*t));
	return mod(t*t);
}
int C(int n,int k){
	if(k>n)return 0ll;
	return mod(mod(fat[n]*inv[k])*inv[n-k]);
}
int q;
string s;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	//setIO("sort");
	fat[0]=inv[0]=1ll;
	for(int i=1;i<mxn;i++)fat[i]=(fat[i-1]*i)%M;
	inv[mxn-1]=exp(fat[mxn-1],M-2);
	for(int i=mxn-2;i>=1;i--)inv[i]=(inv[i+1]*(i+1))%M;
	cin>>s;
	int n=s.size();
	cin>>q;
	while(q--){
		int len;cin>>len;
		string p;cin>>p;
		char x=p[0],y=p[1];
		int cnt=0,ans=0;
		for(int i=n-1;i>=max(0ll,len-2);i--){
			
			if(s[i]==x){
				int tmp=C(i,len-2);
				ans=mod(ans+mod(tmp*cnt));
			}
			if(s[i]==y)cnt++;
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}
