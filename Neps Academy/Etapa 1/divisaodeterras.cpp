#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;
#define MOD 1000000007
#define MAXN 100005
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define ll long long
#define pb push_back
#define f first
#define s second
#define debug(x) cout << "debug 1: " << x << "\n";
#define debug2(x, y) cout << "debug 2: " << x << " " << y << "\n";
#define debug3(x, y, z) cout << "debug 3: " << x << " " << y << " " << z << "\n";

struct terra{
int     xa,xb,ya,yb;
};

int n,k,menor=INF,maior=-INF;
terra T[MAXN];

ll area(int m){
    ll resp=0;
    for(int i=0;i<n;i++){
    if(T[i].ya<m){
        resp+=((T[i].xb-T[i].xa)*(min(m,T[i].yb)-T[i].ya));
        //debug3(T[i].ya,m,resp);
    }
    }
    return resp;
}



int buscab(){
    int ini=menor,fim=maior,meio,resp=INF;

    while(ini<=fim){
        meio=(ini+fim)/2;
        //debug(meio);
        ll p=area(meio);
        //debug(p);
        if(p==k)return meio;
        else if(p>=k){
                fim=meio-1;
                resp=min(resp,meio);
        }
        else ini=meio+1;
    }
    return resp;

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
          cin>>T[i].xa>>T[i].ya>>T[i].xb>>T[i].yb;
          menor=min(menor,T[i].ya);
          maior=max(maior,T[i].yb);
    }
    int m=buscab();
    if(m==INF)cout<< "PERDAO MEU REI";
    else cout<<m;
    //cout<<maior<<" "<<menor<<"\n";

}
