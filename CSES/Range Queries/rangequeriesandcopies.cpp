#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sz(x) (int)x.size()
#define int long long
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<vi> vii;
const int mxN=2e5+5,M=1e9+7,mxM=3.6e6;
//did u check when n=1?
//is mxN correct?
int n,q,arr[mxN],cnt;
struct node{
    int val;
    node* left,*right;
    node(){}
    node(node* l,node* r,int v){
        left=l;
        right =r;
        val=v;        
    }
};
node* ver[mxN];
void build(node* n,int i,int j){
    if(i==j){
        n->val=arr[i];
        return;
    }
    int m=(i+j)/2;
    n->left=new node(NULL,NULL,0);
    n->right=new node(NULL,NULL,0);
    build(n->left,i,m);
    build(n->right,m+1,j);
    n->val=n->left->val+n->right->val;
}
void upd(node* prev,node* cur,int i,int j,int idx,int value){
    if(idx<i || idx>j || i>j)return;
    if(i==j){
        cur->val=value;
        return;
    }
    int m=(i+j)/2;
    if(idx<=m){
        cur->right=prev->right;
        cur->left= new node(NULL,NULL,0);
        upd(prev->left,cur->left,i,m,idx,value);
    }
    else{
        cur->left=prev->left;
        cur->right=new node(NULL,NULL,0);
        upd(prev->right,cur->right,m+1,j,idx,value);
    }
    cur->val=cur->left->val+cur->right->val;
}
int query(node* no,int i,int j,int A,int B){
    if(i>B || j<A || i>j)return 0;
    if(A<=i && j<=B)return no->val;
    int m=(i+j)/2;
    return query(no->left,i,m,A,B)+query(no->right,m+1,j,A,B);
}
int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for(int i=0;i<n;i++)cin>>arr[i];
    node* root=new node(NULL,NULL,0);
    build(root,0,n-1);
    ver[0]=root;
    while(q--){
        int op;cin>>op;
        if(op==3){
            int x;cin>>x;x--;
            ver[++cnt]=new node(NULL,NULL,0);
            ver[cnt]=ver[x];
        }
        else if(op==2){
            int x,l,r;cin>>x>>l>>r;x--;l--;r--;
            cout<<query(ver[x],0,n-1,l,r)<<"\n";
        }
        else{
            int x,pos,v;cin>>x>>pos>>v;x--;pos--;
            ver[++cnt]=new node(NULL,NULL,0);
            upd(ver[x],ver[cnt],0,n-1,pos,v);
            ver[x]=ver[cnt];    
            cnt--;
        }
    }
}
