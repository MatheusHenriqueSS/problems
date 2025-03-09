#include <bits/stdc++.h>
using namespace std;

void setIO(string s) {
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  freopen((s+ ".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"

typedef pair<int,int>ii;
typedef vector<int> vi;
/**
we can print all the ods decreasingly
and after that all ods decreasingly

between ods/even the difference will be always 2

in the odd/even neighbouhood the difference will be
1 and the largest even, that from n = 4 onwards, is large enough

 **/
int main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  int n;cin>>n;

  if(n == 1) {
    cout<<1<<endl;
    return 0;
  }

  if(n <= 3) {
    cout<<"NO SOLUTION\n";
    return 0;
  }

  int largest_odd = (n&1) ? n : n - 1;
  int largest_even = (n&1) ? n - 1: n;
  
  for(int i = largest_odd; i >=1; i -= 2) {
    cout<<i<<" ";
  }

  for(int i = largest_even; i > 0; i -= 2) {
    cout<<i<<" ";
  }

  cout<<endl;
}

//1
//1

//2
//no solutions

//3
//no solutions

//4
//3 1 4 2