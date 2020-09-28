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
int n;
double v[105], ans[105];
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){
        for(int j=1;j<=v[i];j++){
            //cout<<i<<" "<<j<<"\n";
            for(int k=0;k<=i-1;k++){
                if(v[k]>(double)(j)){
                    ans[i]+=(double)((v[k]-j)/v[k]);
                    //cout<<i<<" "<<j<<" "<<(double)((v[k]-j)/v[k])<<"\n";
                }
            }
        }
    }
 
    double res=0;
    for(int i=0;i<n;i++){
        res+=(1.0/v[i])*ans[i];
    }
    cout<<fixed<<setprecision(6)<<res;
 
}
