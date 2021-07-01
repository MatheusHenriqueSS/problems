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
const int mxn=1e3+5,M=1e9+7;
const int LINF=0x3f3f3f3f3f3f3f3f;
int n,a[mxn][4],cost[mxn][mxn];
int dist[mxn];
bool v[mxn];
void dji(){
    for(int i=0;i<n;i++)dist[i]=M;
    dist[0]=0;
    priority_queue<pii,vector<pii>,greater<pii>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        int i=pq.top().second;
        pq.pop();
        if(v[i])continue;
        v[i]=1;
        for(int j=0;j<=n;j++){
            if(v[j])continue;
            if(dist[i]+cost[i][j]<dist[j]){
                dist[j]=dist[i]+cost[i][j];
                pq.push({dist[j],j});
            }
        }
    }
    cout<<dist[1];
}
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  //setIO("test");
  int x,y;cin>>x>>y;
  a[0][0]=a[0][2]=x;
  a[0][1]=a[0][3]=y;
  cin>>x>>y;
  a[1][0]=a[1][2]=x;
  a[1][1]=a[1][3]=y;
  cin>>n;
  n+=2;
  for(int i=2;i<n;i++){
    for(int j=0;j<4;j++)cin>>a[i][j];
  }
  for(int i=0;i<n;i++){
      for(int j=i+1;j<n;j++){
          int dx=max(0LL,max(a[i][0],a[j][0])-min(a[i][2],a[j][2]));
          int dy=max(0LL,max(a[i][1],a[j][1])-min(a[i][3],a[j][3]));
          cost[i][j]=cost[j][i]=dx+dy;
      }
  }
  dji();
  return 0;
}
