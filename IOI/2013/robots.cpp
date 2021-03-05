#include<bits/stdc++.h>
#include "robots.h"
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) int(x.size())

typedef pair<int,int>ii;
typedef vector<int> vi;
const int mxn=1e6+5,mxm=5e4+5;
int x[mxm],y[mxm],w[mxn],s[mxn];
int a,b,t;
bool solve(int p){
	int id=0;//onde eu parei nos brinquedu
	priority_queue<ii,vector<ii>>pq;
	for(int i=0;i<a;i++){
		for(;id<t;id++){
			if(w[id]>=x[i])break;
			pq.push({s[id],w[id]});
		}
		int cnt=0;
		while(!pq.empty() && cnt<p){
			cnt++;
			pq.pop();
		}

	}	
	for(;id<t;id++)pq.push({s[id],w[id]});
	for(int i=b-1;i>=0;i--){
		int cnt=0;
		while(!pq.empty() && pq.top().first<y[i] && cnt<p){
			cnt++;
			pq.pop();
		}
	}
	return pq.empty();
}
int putaway(int A, int B, int T,int X[], int Y[], int W[], int S[]){
	a=A,b=B,t=T;
	for(int i=0;i<a;i++)x[i]=X[i];
	for(int i=0;i<b;i++)y[i]=Y[i];
	for(int i=0;i<t;i++)w[i]=W[i];
	for(int i=0;i<t;i++)s[i]=S[i];

	sort(x,x+a);
	sort(y,y+b);
	vector<ii>aux;
	for(int i=0;i<t;i++)aux.pb({w[i],s[i]});
	sort(aux.begin(),aux.end());
	for(int i=0;i<t;i++){
		w[i]=aux[i].first;
		s[i]=aux[i].second;
	}
	int l=0,r=t+10;
	while(l<r){
		int m=(l+r)/2;
		if(solve(m))r=m;
		else l=m+1;
	}
	if(l==t+10)l=-1;
	return l;
}
