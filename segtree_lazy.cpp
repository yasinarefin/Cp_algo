#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const  int MAX = 100001;
ll arr[MAX];
ll tree[4 * MAX];
ll lazy[4 * MAX];
void build(int node, int l, int r){
    lazy[node] = 0;
    if(l == r){
        tree[node] = arr[l];
    }else{
        int mid = (l + r) / 2;
        build(node * 2, l, mid);
        build(node * 2+ 1, mid +1, r);
        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void propagate(int id, int l, int r){
    if(l != r){
        lazy[2*id] += lazy[id];     /// pass lazy to left child
        lazy[2*id+1] += lazy[id];   /// pass lazy to right child
    }
    tree[id] += lazy[id] * (r-l+1);     /// apply lazy to itself
    lazy[id] = 0;               /// erase own lazy

}
void update(int node, int l, int r, int ul, int ur, ll c){
    propagate(node, l, r);
    if(l > ur || r < ul){ ///disjoint
        return;
    }
    if(l >= ul && r <= ur){
        lazy[node] += c;
        propagate(node, l, r);
        return;
    }

    int mid = (l+r)/2;
    update(2*node, l, mid, ul, ur, c);
    update(2*node+1, mid+1, r, ul, ur, c);

    tree[node] = tree[2*node] + tree[2*node+1];
}


ll query(int node, int l, int r, int ql, int qr){
    propagate(node, l, r);
    if(l > qr || r < ql){
        return 0;
    }
    if(l >= ql && r<= qr){
        return tree[node];
    }
    int mid = (l + r) / 2;
    ll q1 = query(node * 2, l, mid, ql, qr);
    ll q2 = query(node * 2 + 1, mid +1, r, ql, qr);
    return q1 + q2;
}
int n, c;
void solve(){
    cin>>n>>c;
    build(1, 1, n);
    while(c--){
        int com; cin>>com;
        if(com == 0){
            ll a, b, val; cin>>a>>b>>val;
            update(1, 1, n, a, b, val);
        }else{
            int l, r; cin>>l>>r;
            cout<<query(1, 1, n, l, r)<<endl;
        }
    }
}
int t;
int main(){
    cin>>t;
    while(t--)
        solve();
}
