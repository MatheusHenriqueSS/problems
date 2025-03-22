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
#define int long long

typedef pair<int,int>ii;
typedef vector<int> vi;

// if the sum is odd -> no

// if the sum is even
// if n is multiple of 4 or n + 1 is multiple of 4 we can split


//1 2 3 4 5 6 7 


//(n + 1)/4 + (n + 1)/2

int32_t main(void) {
  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
  //setIO("convention");

  int n;cin>>n;


  if(n % 4 == 0) {
    cout<<"YES\n";
    cout<<n/2<<endl;
    for(int i = 1; i <= n/4; i++) {
      cout<<i<<" "<<n + 1 - i <<" ";
    }
    cout<<endl;
    cout<<n/2<<endl;
    for(int i = n/4 + 1; i <= n/2; i++)cout<<i<<" "<<n + 1 - i<<" ";
    cout<<endl;
    return 0;
  }

  if((n + 1) % 4 == 0) {
    cout<<"YES\n";
    cout<<(n + 1)/2<<endl;
    for(int i = 1; i < (n + 1)/4; i++) {
      cout<<i<<" "<<n + 1 - i <<" ";
    }
    cout<<(n + 1)/4<<" ";
    cout<<(n + 1)/2<<endl;
    cout<<n/2<<endl;
    cout<<3*(n + 1)/4<<" ";
    for(int i = (n + 1)/4 + 1; i < (n + 1)/2; i++){
      cout<<i<<" "<<n + 1 - i<<" ";
    }
    cout<<endl;
    return 0;
  }



  cout<<"NO\n";
 

}