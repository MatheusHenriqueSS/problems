#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7;
//did u check when n=1?
//is mxN correct?
int ans[10][10],cnt[10][10],x,y;
int dx[]={+2,+2,-2,-2,+1,+1,-1,-1};
int dy[]={+1,-1,+1,-1,+2,-2,+2,-2};
bool check(int x,int y){
    if(min(x,y)>=0 && max(x,y)<8 && ans[x][y]==-1)return true;
    return false;
}
bool tour(int x,int y,int move){  
    if(!check(x,y))return false;
    ans[x][y]=move;
    if(move==64)return true;
    int me=10;
    for(int k=0;k<8;k++){
        int i=x+dx[k];
        int j=y+dy[k];
        if(!check(i,j))continue;
        cnt[i][j]--;
        me=min(me,cnt[i][j]);
    }
    for(int k=0;k<8;k++){
        int i=x+dx[k];
        int j=y+dy[k];
        if(!check(i,j))continue;
        if(cnt[i][j]!=me)continue;
        if(tour(i,j,move+1))return true;
    }
    for(int k=0;k<8;k++){
        int i=x+dx[k];
        int j=y+dy[k];
        if(!check(i,j))continue;
        cnt[i][j]++;
    }
    ans[x][y]=-1;
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(ans,-1,sizeof(ans));
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            for(int k=0;k<8;k++){
                int x=dx[k]+i;
                int y=dy[k]+j;
                if(max(x,y)<8 && min(x,y)>=0)cnt[i][j]++;
            }
        }
    }
    cin>>y>>x;x--;y--;
    tour(x,y,1);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
  
 
}
