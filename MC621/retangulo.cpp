#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) int(x.size())

typedef pair<int,int>ii;
typedef vector<int> vi;

const int mxn = 2e5+5;

int n;
ll a[mxn];

int ini[mxn],fim[mxn];
int aux[mxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);

	cin>>n;

	for(int i = 1;i <= n;i++){
		cin>>a[i];
		a[i+n] = a[i];
	}

	for(int i = 1;i <= 2*n;i++)a[i]+=a[i-1];

	if(a[n]&1){
		cout<<"N\n";
		return 0;
	}

	int val = a[n]/2;

	for(int i = 1;i <= n;i++){
		auto it = lower_bound(a+i,a+i+n,a[i-1]+val);
		int pos = it-a;
		if(a[pos] == a[i-1]+val){
			ini[i] = pos;
			fim[pos] = i;
			aux[i] = 1;
		}

	}

	for(int i = 1;i<=n;i++)aux[i]+=aux[i-1];


	for(int i = 1;i<=n;i++){
		int j = n+i-1;
		if(ini[i] && fim[j]){
			if(aux[ini[i]]-aux[i]){
				cout<<"S\n";
				return 0;
			}
		}
	}
	cout<<"N\n";
	return 0;
}
/*
8
3 3 4 2 6 2 2 2

4
14 16 15 15

6
3 7 7 3 10 10
*/
