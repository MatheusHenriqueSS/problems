/*
Matheus Henrique de Sousa
*/
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0); 
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

#define ll long long
#define int long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxn=355,M=1e9+7;
const int LINF=0x3f3f3f3f3f3f3f3f;
int n,m,k,num[mxn][mxn];
int dp[mxn][mxn][7][20][5];
string g[mxn][mxn];
int solve(int x,int y,int ti,int mask,int dir){
  if(x<0 || x>=n || y<0 || y>=m)return -LINF;
  int& ans=dp[x][y][ti][mask][dir];
  if(ans!=-LINF)return ans;
  if(x==n-1 && y==m-1){
    if(ti)return 0;
    return num[x][y];
  }
  if(ti){
    ans=max(ans,solve(x+1,y,ti-1,0,0));
    ans=max(ans,solve(x+1,y,ti-1,0,1));
    if(!dir)ans=max(ans,solve(x,y+1,ti-1,0,0));
    else ans=max(ans,solve(x,y-1,ti-1,0,1));
    return ans;
  }
  if(mask==15){
    ans=max(ans,solve(x+1,y,k-1,0,0));
    ans=max(ans,solve(x+1,y,k-1,0,1));
    if(!dir)ans=max(ans,solve(x,y+1,k-1,0,0));
    else ans=max(ans,solve(x,y-1,k-1,0,1));
  }
  int mask1=mask;
  if('A'<=g[x][y][0] && g[x][y][0]<='Z'){
    if(g[x][y][0]=='N')mask1|=1;
    if(g[x][y][0]=='O')mask1|=2;
    if(g[x][y][0]=='K')mask1|=4;
    if(g[x][y][0]=='A')mask1|=8;
  }
  ans=max(ans,solve(x+1,y,0,mask1,0)+num[x][y]);
  ans=max(ans,solve(x+1,y,0,mask1,1)+num[x][y]);
  if(!dir)ans=max(ans,solve(x,y+1,0,mask1,0)+num[x][y]);
  else ans=max(ans,solve(x,y-1,0,mask1,1)+num[x][y]);
  return ans;
}
void init(){
    for(int i=0;i<mxn;i++){
    for(int j=0;j<mxn;j++){
      for(int l=0;l<7;l++){
        for(int o=0;o<20;o++){
          for(int d=0;d<5;d++){
            dp[i][j][l][o][d]=-LINF;
          }
        }
      }
    }
  }
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n>>m>>k;
  init();
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      string s;cin>>s;
      g[i][j]=s;
      if(s[0]=='-'){
        int pd=1;
        for(int cur=sz(s)-1;cur>=1;cur--){
          num[i][j]+=pd*(s[cur]-'0');
          pd*=10;
        }
        num[i][j]*=-1;
      }
      else if('0'<=s[0] && s[0]<='9'){
        int pd=1;
        for(int cur=sz(s)-1;cur>=0;cur--){
          num[i][j]+=pd*(s[cur]-'0');
          pd*=10;
        }
      } 
    }
  }
  cout<<solve(0,0,0,0,0);
  return 0;
}
