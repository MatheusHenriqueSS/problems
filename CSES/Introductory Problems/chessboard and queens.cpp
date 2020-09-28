#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
typedef pair<int,int>pii;
const int mxN=2e5,M=1e9+7;
ll ans;
int col[16],dig1[16],dig2[16];
int matriz[16][16];
void solve(int x=0){
    if(x==8){
        ans++;
        return;
    }
    for(int i=0;i<8;i++){
        if(col[i]||dig1[x+i]||dig2[x-i+7]||matriz[x][i])continue;
        col[i]=dig1[x+i]=dig2[x-i+7]=true;
        solve(x+1);
        col[i]=dig1[x+i]=dig2[x-i+7]=false;
 
    }
}
char s;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cin>>s;
            if(s=='*'){
                matriz[i][j]=1;
            }
        }
    }
    solve();
    cout<<ans;
    
}
