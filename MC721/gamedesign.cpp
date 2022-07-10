#include <bits/stdc++.h>
using namespace std;
        
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define endl "\n"
    
typedef pair<int,int>ii;
typedef vector<int> vi;
    
vector<string> rep = {"LRL", "RLR", "UDU", "DUD"};
    
int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int n = sz(s);
    
    vector<ii> ans;
    ii pos = {0, 0};
    
    if(n >= 3) {
        for (int i = 0; i < 4; i++) {
            if(s.substr(n-3, 3) == rep[i]){
                cout<<"impossible\n";
                return 0;
            }
        }
    }
    
    int d = 1;
    set<ii> x, y;
    
    for (int i = 0; i < n; i++) {  
        if(s[i] == 'L'){
            auto it = y.lower_bound({pos.second, -2097152});
            if(it != y.end() && (*it).first == pos.second && (*it).second < pos.first) {
                pos.first = (*it).second + 1;
            }
            else {
                pos.first -= d;
                x.insert({pos.first - 1, pos.second});
                y.insert({pos.second, pos.first - 1});
                ans.pb({pos.first -1, pos.second});
            }
        }
        else if(s[i] == 'U') {
            auto it = x.lower_bound({pos.first, pos.second});
            if(it != x.end() && (*it).first == pos.first) {
                pos.second = (*it).second - 1;
            }
            else {
                pos.second += d;
                x.insert({pos.first, pos.second + 1});
                y.insert({pos.second + 1, pos.first});
                ans.pb({pos.first, pos.second + 1});
            }
        }
        else if(s[i] == 'R') {
            auto it = y.lower_bound({pos.second, pos.first});
            if (it != y.end() && (*it).first == pos.second) {
                pos.first = (*it).second - 1;
            }
            else {
                pos.first += d;
                x.insert({pos.first + 1, pos.second});
                y.insert({pos.second, pos.first + 1});
                ans.pb({pos.first + 1, pos.second});
            }
        }
        else {
            auto it = x.lower_bound({pos.first, -2097152});
            if(it != x.end() && (*it).first == pos.first && (*it).second < pos.second) {
                pos.second = (*it).second + 1;
            }
            else {
                pos.second -= d;
                x.insert({pos.first, pos.second - 1});
                        y.insert({pos.second - 1, pos.first});
                        ans.pb({pos.first, pos.second - 1});
            }
        }
    
        d *= 2;
    }
    
    cout<<-pos.first<<" "<<-pos.second<<"\n";
    cout<<sz(ans)<<"\n";
    
    for (ii p: ans) {
        p.first -= pos.first;
        p.second -= pos.second;
        cout<<p.first<<" "<<p.second<<"\n";
    }     
}   