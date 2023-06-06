//Matheus Henrique de S. Silva
//06/06/23
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

const int mxn = 2e5 + 5;
int n, q;
int seg[4*mxn][2], v[mxn];

void build(int i = 0, int j = n -1, int no = 1) {
    if(i == j) {
        seg[no][0] = i + v[i];
        seg[no][1] = n - 1 - i + v[i];
        return;
    }

    int m = (i + j)/2;
    build(i, m, 2*no);
    build(m + 1, j, 2*no + 1);
    seg[no][0] = min(seg[2*no][0], seg[2*no + 1][0]);
    seg[no][1] = min(seg[2*no][1], seg[2*no + 1][1]);
}

void upd(int pos, int val, int i = 0, int j = n -1, int no = 1) {
    if(i == j) {
        seg[no][0] -= v[i];
        seg[no][1] -= v[i];
        v[i] = val;
        seg[no][0] += v[i];
        seg[no][1] += v[i];
        return;
    }

    int m = (i + j)/2;
    if(pos <= m)upd(pos, val, i, m, 2*no);
    else upd(pos, val, m + 1, j, 2*no + 1);

    seg[no][0] = min(seg[2*no][0], seg[2*no + 1][0]);
    seg[no][1] = min(seg[2*no][1], seg[2*no + 1][1]);
}

int query(int k, int pos, int a, int b, int i = 0, int j = n - 1, int no = 1) {
    if(i > j || j < a || i > b) return INT_MAX;
    if(a <= i && j <= b) return seg[no][k];

    int m =  (i + j)/2;
    return min(query(k, pos, a, b, i, m, 2*no), query(k, pos, a, b, m + 1, j, 2*no + 1));
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    cin>>n>>q;
    for (int i = 0; i < n; i++)cin>>v[i];
    build();

    while(q--) {
        int op;cin>>op;
        if(op == 1) {
            int k, x;
            cin>>k>>x;k--;
            upd(k, x);
        }
        else {
            int k;cin>>k;k--;
            int ans = query(0, k, k, n - 1) - k;
            ans = min(ans, query(1, k, 0, k) - (n - 1 - k));
            cout<<ans<<"\n";
        }
    }
}
