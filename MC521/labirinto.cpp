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
#define f first
#define s second
typedef pair<int,int>pii;
typedef pair<int,pii>ii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxn=55,M=1e9+7;
int g[mxn][mxn],vis[mxn][mxn],d[mxn][mxn];
int n,m;
int mod(int a){int ret=a%10;if(ret<0)ret+=10;return ret;}
priority_queue<ii,vector<ii>,greater<ii>>q;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cin>>g[i][j];
      d[i][j]=M;
    }
  }
  q.push({0,{0,0}});
  while(!q.empty()){
    ii cur=q.top();
    q.pop();
    //cout<<cur.f<<" "<<cur.s.f<<" "<<cur.s.s<<"\n";
    if(cur.s.f==n-1 && cur.s.s==m-1){
      cout<<cur.f<<"\n";
      return 0;
    }
    int i=cur.s.f,j=cur.s.s;
    if(vis[i][j])continue;
    vis[i][j]=1;
    for(int x=0;x<4;x++){
      int i1=i+dx[x];
      int j1=j+dy[x];
      if(i1>=0 && i1<n && j1>=0 && j1<m && !vis[i1][j1]){
        if((g[i][j]+cur.f)%10+1>=(g[i1][j1]+cur.f)%10){
          if(cur.f+1<d[i1][j1]){
            q.push({cur.f+1,{i1,j1}});
            d[i1][j1]=cur.f+1;
          }          
        }
        else{
          int he=(g[i1][j1]+cur.f)%10;
          if(cur.f+10-he+1<d[i1][j1]){
          q.push({cur.f+10-he+1,{i1,j1}});
          d[i1][j1]=cur.f+10-he+1;
          }
        }

      }
    }
  }
  return 0;
}
   
