#include<bits/stdc++.h>
#include<fstream>
using namespace std;
 
#define ll long long
#define int long long
#define pb push_back
#define sz(x) (int)x.size()
 
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
 
const int mxn=2e5+5,M=1e9+7;
set<int>dif;
string s;
int n,m,cnt[mxn];
priority_queue<int>pq;
 
void solve(int x){
  if(x==0 || x==n)return;
  auto it=dif.find(x);
  if(it==dif.end()){
    it=dif.insert(x).first;
    int a=*prev(it),b=*next(it);
    cnt[b-a]--;
    cnt[x-a]++;cnt[b-x]++;
    pq.push(x-a);pq.push(b-x);
  }
  else{
    int a=*prev(it),b=*next(it);dif.erase(it);
    cnt[x-a]--;
    cnt[b-x]--;
    cnt[b-a]++;pq.push(b-a);
  }
}
 
int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0); 
  cin>>s>>m;
  n=sz(s);
  dif.insert(0);dif.insert(n);
  for(int i=0;i<n-1;i++){
    if(s[i+1]!=s[i])dif.insert(i+1);
  }
  for(auto it=dif.begin();next(it)!=dif.end();it++){
    cnt[*next(it)-*it]++;
    pq.push(*next(it)-*it);
  }
  for(int i=0;i<m;i++){
    int x;cin>>x;
    solve(x-1);solve(x);
    while(!cnt[pq.top()])pq.pop();
    cout<<pq.top()<<" ";
  }
  return 0;
}
