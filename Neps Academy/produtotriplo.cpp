#include <iostream>
using namespace std;

const int mxN=2e5+10;

int n;
int v[mxN];
long long int x=1LL,y=1LL;
int main()
{

    cin>> n;



    for(int i = 0; i<n; i++)
        {cin>> v[i];}

    x*=v[0];
    x*=v[1];
    x*=v[n-1];

    y*=v[n-1];
    y*=v[n-2];
    y*=v[n-3];
    cout<<max(x,y);
}
