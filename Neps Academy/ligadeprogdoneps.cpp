#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
#define MOD 1000000007
#define MAXN 100005
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pb push_back
#define f first
#define s second
#define debug(x) cout << "debug 1: " << x << "\n";
#define debug2(x, y) cout << "debug 2: " << x << " " << y << "\n";
#define debug3(x, y, z) cout << "debug 3: " << x << " " << y << " " << z << "\n";

int n;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;

    if(n<9){
        n+=24;
        cout<<n-9;
    }
    else cout<<n-9;
}
