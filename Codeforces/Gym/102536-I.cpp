/* 
Matheus Henrique de Sousa
Glory to Algotzka
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
const int mxn=1e4+5;
//is it bb?
//is it dp?
//did you checked n=1?
//did you checked mxn?   
int n,q,id[mxn],dp[mxn][mxn][2],sz[mxn],aux[mxn][2];
vi g[mxn];

void solve(int i,int p){
//dp stores cmin
//tab stores smin
sz[i]=1;
dp[i][0][0]=0;
dp[i][1][0]=(!id[i]);
dp[i][0][1]=0;
dp[i][1][1]=id[i];
for(int j:g[i]){
    solve(j,i);
    for(int cur=1;cur<=sz[i];cur++){
        for(int cur_s=0;cur_s<=sz[j];cur_s++)aux[cur+cur_s][0]=aux[cur+cur_s][1]=mxn;
    }
    for(int cur=1;cur<=sz[i];cur++){
        for(int cur_s=0;cur_s<=sz[j];cur_s++){
            aux[cur+cur_s][0]=min(aux[cur+cur_s][0],dp[i][cur][0]+dp[j][cur_s][0]);
            aux[cur+cur_s][1]=min(aux[cur+cur_s][1],dp[i][cur][1]+dp[j][cur_s][1]);
        }
    }
    for(int cur=1;cur<=sz[i];cur++){
        for(int cur_s=0;cur_s<=sz[j];cur_s++){
            dp[i][cur+cur_s][0]=min(aux[cur+cur_s][0],dp[i][cur+cur_s][0]);
            dp[i][cur+cur_s][1]=min(aux[cur+cur_s][1],dp[i][cur+cur_s][1]);
        }
    }
    sz[i]+=sz[j];

} 
}

int32_t main(){
ios_base::sync_with_stdio(0);cin.tie(0);
cin>>n>>q;
for(int i=1;i<=n;i++){
    int x;cin>>x;
    g[x].pb(i);
}
string s;cin>>s;
for(int i=0;i<n;i++){
    if(s[i]=='S')id[i+1]=1;
}
for(int i=0;i<mxn;i++){
    for(int j=0;j<mxn;j++)dp[i][j][0]=dp[i][j][1]=mxn;
}
solve(1,0);
while(q--){
    int i,c,s;cin>>i>>c>>s;
    if(c+s<=sz[i] && c>=dp[i][c+s][0] && s>=dp[i][c+s][1])cout<<"COMPROMISED\n";
    else cout<<"NOT COMPROMISED\n";
}
return 0;
}
