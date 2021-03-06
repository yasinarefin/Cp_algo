// max segment tree
int arr[200005];

int tree[800001];

void build(int node, int l, int r){
    if(l == r){
        tree[node] = arr[l];
    }else{
        int mid =(l+r)/2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        int maxa = max(tree[2*node], tree[2*node+1]);
        tree[node] = maxa;
    }
}


int query(int node, int l, int r, int ql, int qr){
    if(r < ql || l > qr){
        return -1e9;
    }
    if(l >= ql && r <= qr){
        return tree[node];
    }
    int mid = (l+r)/2;
    int q1 = query(node*2, l, mid, ql, qr);
    int q2 = query(node*2+1, mid+1, r, ql, qr);
    int maxa = max(q1, q2);
    return maxa;
}
// max segment tree end


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX = 10e10;

pair<int, int> tree[400001];
int arr[100001];
void build(int node, int l, int r){
    if(l == r){
        tree[node] = make_pair(arr[l], 1);
    }else{
        int mid =(l+r)/2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        int maxa = max(tree[2*node].first, tree[2*node+1].first);
        tree[node].first = maxa;
        if(tree[2*node].first == maxa) tree[node].second += tree[2*node].second;
        if(tree[2*node+1].first == maxa) tree[node].second += tree[2*node+1].second;
    }
}

void update(int node, int l, int r, int idx, int val){
    if(l==r){
        tree[node].first = val;
        tree[node].second = 1;
    }else{
        int mid = (l+r)/2;
        if(idx <= mid){
            update(2*node, l, mid, idx, val);
        }else{
            update(2*node+1, mid+1, r, idx, val);
        }
        int maxa = max(tree[node *2].first, tree[node*2+1].first);
        tree[node].first = maxa;
        tree[node].second = 0;
        if(tree[2*node].first == maxa) tree[node].second += tree[2*node].second;
        if(tree[2*node+1].first == maxa) tree[node].second += tree[2*node+1].second;
    }

}

pair<int, int> query(int node, int l, int r, int ql, int qr){
    if(r < ql || l > qr){
        return make_pair(-MAX, 0);
    }
    if(l >= ql && r <= qr){
        return tree[node];
    }
    int mid = (l+r)/2;
    pair<int, int> q1 = query(node*2, l, mid, ql, qr);
    pair<int, int> q2 = query(node*2+1, mid+1, r, ql, qr);
    int maxa = max(q1.first, q2.first);
    int ret = 0;
    if(q1.first == maxa) ret += q1.second;
    if(q2.first == maxa) ret += q2.second;
    return make_pair(maxa, ret);
}
int n, m;
int main(){
    cin>>n>>m;
    for(int x=1;x<=n;x++)
        cin>>arr[x];

    build(1, 1, n);

    while(m--){
        int l, r; cin>>l>>r;
        pair<int, int > qu = query(1, 1, n, l, r);
        cout<<qu.second<<endl;
    }
}

typedef long long ll;

const ll MAX = 10e10;

pair<int, int> tree[400001];
vector<int> arr;
void build(int node, int l, int r){
    if(l == r){
        tree[node] = make_pair(arr[l-1], l);
    }else{
        int mid =(l+r)/2;
        build(2*node, l, mid);
        build(2*node+1, mid+1, r);
        int mina = min(tree[2*node].first, tree[2*node+1].first);
        tree[node].first = mina;
        if(tree[2*node].first < tree[2*node+1].first){
            tree[node].second = tree[2*node].second;
        }else{
            tree[node].second = tree[2*node+1].second;
        }
    }
}


pair<int, int> query(int node, int l, int r, int ql, int qr){
    if(r < ql || l > qr){
        return make_pair(MAX, 0);
    }
    if(l >= ql && r <= qr){
        return tree[node];
    }
    int mid = (l+r)/2;
    pair<int, int> q1 = query(node*2, l, mid, ql, qr);
    pair<int, int> q2 = query(node*2+1, mid+1, r, ql, qr);
    int mina = min(q1.first, q2.first);
    int ret;
    if(q1.first < q2.first){
        ret = q1.second;
    }else{
        ret = q2.second;
    }
    return make_pair(mina, ret);
}
ll rec(int l, int r){
    if(l>r) return 0;
    if(r == l )return arr[l-1];
    pair<int, int> m = query(1, 1, arr.size(), l, r);
    ll op = m.first;
    int mina = m.second;
    
    return max({(ll)(r-l+1) *op, rec( l, mina-1), rec( mina+1, r)});
}
int Solution::largestRectangleArea(vector<int> &A) {
    arr=A;
    build(1, 1, A.size());
    return rec( 1, A.size());
}

