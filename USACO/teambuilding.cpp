//25/02/2022
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

#define int long long
#define pb push_back
#define sz(x) (int)x.size()

typedef pair<int,int>ii;
typedef vector<int> vi;

const int mod = 1e9 + 9, mxn = 1e3 + 5, mxk = 12;
int dp[mxn][mxn][mxk], n, m, k;
int a[mxn], b[mxn];

int add(int a, int b) {
  int ret = a + b;
  if (ret >= mod)ret -= mod;
  return ret;
}

int solve(int i, int j, int l) {
  if (l == 0)return 1;
  if (dp[i][j][l] != -1)return dp[i][j][l];
  int ans = 0;

  for (int i1 = 1; i1 <= i; i1++) {
    for (int j1 = 1; j1 <= j; j1++) {
      if (a[i1] > b[j1])ans += solve(i1 - 1, j1 - 1, l - 1);
    }
  }

  return dp[i][j][l] = ans;
}

int32_t main(void){
  ios_base::sync_with_stdio(0); cin.tie(0);
  setIO("team");

  cin>>n>>m>>k;

  for(int i = 1; i <= n; i++)cin>>a[i];
  for(int i = 1; i <= m; i++)cin>>b[i];

  sort(a, a + n + 1);
  sort(b, b + m + 1);
  //memset(dp, -1, sizeof(dp));

  //solve(n, m, k);

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++)dp[i][j][0] = 1;
  }

  for (int l = 1; l <= k; l++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (a[i] > b[j])dp[i][j][l] = add(dp[i][j][l], dp[i-1][j-1][l-1]);
        dp[i][j][l] = add(dp[i][j][l], dp[i][j-1][l]);
        dp[i][j][l] = add(dp[i][j][l], dp[i-1][j][l]);
        dp[i][j][l] = (dp[i][j][l] - dp[i-1][j-1][l] + mod) % mod;
      }
    }
  }

  cout<<dp[n][m][k]<<"\n";

  return 0;
}
