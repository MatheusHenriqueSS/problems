/*
Matheus Henrique de Sousa
obi 2019 - sf2 - robô marciano
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
const int mxn=1e3+5,M=1e9+7;
const int LINF=0x3f3f3f3f3f3f3f3f;
int n,tab[mxn][mxn],dist[mxn];
bool v[mxn];
int xi[mxn],xf[mxn],yi[mxn],yf[mxn];
void dji(){
  for(int i=0;i<n;i++)dist[i]=LINF;
  dist[0]=0;
  priority_queue<pii,vector<pii>,greater<pii>>pq;
  pq.push({0,0});
  while(!pq.empty()){
    int i=pq.top().second;
    pq.pop();
    if(v[i])continue;
    v[i]=1;
    for(int j=0;j<n;j++)if(!v[j]){
      if(dist[i]+tab[i][j]<dist[j]){
        dist[j]=dist[i]+tab[i][j];
        pq.push({dist[j],j});
      }
    }
  }
  cout<<dist[n-1]<<"\n";

  
}
int32_t main(void){

  //setIO("test");
  int a,b,c,d;cin>>a>>b>>c>>d;
  xf[0]=xi[0]=a;
  yf[0]=yi[0]=b;
  cin>>n;
  n+=2;
  xf[n-1]=xi[n-1]=c;
  yf[n-1]=yi[n-1]=d;
  for(int i=1;i<n-1;i++)cin>>xi[i]>>yi[i]>>xf[i]>>yf[i];
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int dx=max(0LL,max(xi[i],xi[j])-min(xf[i],xf[j]));
      int dy=max(0LL,max(yi[i],yi[j])-min(yf[i],yf[j]));
      tab[i][j]=tab[j][i]=dx+dy;
    }
 
  }
  dji();
  return 0;
}
