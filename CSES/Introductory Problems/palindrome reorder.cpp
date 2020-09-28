#include<bits/stdc++.h>
using namespace std;
 
string s;
map<char,string>m;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    for(auto c:s){
        if(!m.count(c))m[c]=c;
        else m[c]+=c;        
    }
    string imp="",ini="";
    for(auto c:m){
        if((int)c.second.size()%2==1 && imp!=""){
            cout<<"NO SOLUTION";
            return 0;
        }
        else if((int)c.second.size()%2==1 ){
            imp=c.second;
        }
        else{
            ini+=c.second.substr(0,(int)c.second.size()/2);
        }
 
    }
    cout<<ini<<imp;
    reverse(ini.begin(),ini.end());
    cout<<ini;
}
Test
