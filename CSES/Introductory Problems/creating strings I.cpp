#include<bits/stdc++.h>
using namespace std;
int k=1;
string s1;
vector<string>resp;
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    s1=s;
    //cout<<s1<<"\n";
    resp.push_back(s);
    while(true){
        bool val=next_permutation(s.begin(),s.end());
        if(s==s1)break;
        k++;
        resp.push_back(s);
    }
    cout<<k<<"\n";
    for(int i=0;i<k;i++){
        cout<<resp[i]<<"\n";
    }
}
