#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;
const ll prime1 = 1e9+7;
const ll prime2 = 1e9+9;

const ll base1 = 1000003;
const ll base2 = 1e8;
struct Hash{
    vector<ll> power1;
    vector<ll> H1;
    Hash(){}
    Hash(string &s){
        power1.resize(s.length(), 0);
        H1.resize(s.length(), 0);
        power1[0]= 1;
        H1[0]= s[0];
        for(int x=1;x<(int)s.length(); x++){
            power1[x] = (power1[x-1] * base1) % prime1;
            H1[x] = (H1[x-1] * base1 + s[x]) % prime1;
        }

    }
    pii hashVal(int L, int R){
        ll ret1;
        if(L == 0) ret1 = H1[R];
        else ret1 = (H1[R] - H1[L-1] * power1[R-L+1]) % prime1;
        if(ret1 < 0) ret1 += prime1;
        ll ret2 = 0;


        return make_pair(ret1, ret2);
    }
};
const int nmax = 100001;
ll power[100001];


struct HashTree{

    vector<ll> arr, tree;
    int len;
    HashTree(string &s){
        arr.resize(s.length()+1);
        for(int x=1;x<=(int)s.length();x++){
            arr[x] = s[x-1];
        }
        len = s.length();
        tree.resize(4 * s.length()+1);
        build(1, 1, s.length());
    }

    void build(int id, int l, int r){

        if(l == r){
            tree[id] = arr[l];
            return;
        }

        int mid = (l+r)/2;

        build(2*id, l, mid);
        build(2*id+1, mid+1, r);
        int len = r- mid;
        tree[id] = tree[2*id] * power[len] + tree[2*id+1];
        tree[id] %= prime1;

    }


    void update(int id, int l, int r, int k, ll val){

        if(l == r){
            tree[id] = val;
            return;
        }

        int mid = (l+r)/2;
        if(k <= mid)
            update(2*id, l, mid, k, val);
        else
            update(2*id+1, mid+1, r, k, val);

        int len = r- mid;
        tree[id] = tree[2*id] * power[len] + tree[2*id+1];
        tree[id] %= prime1;
        return;
    }

    void update(int idx, int val){
        update(1, 1, len, idx, val);
    }

    pair<ll, int> query(int id, int l, int r, int a, int b){
        if(b < l || r < a){
            return make_pair(0, 0);
        }

        if(a <= l && r <= b){
            return make_pair(tree[id] % prime1, r-l+1);
        }
        int mid = (l+r)/2;
        pair<ll, int> p = query(2*id, l, mid, a, b);
        pair<ll, int> q = query(2*id+1, mid+1, r, a, b);
        int len = q.second;
        ll val = (p.first * power[len] + q.first) % prime1;
        return make_pair(val, p.second + q.second);
    }

    ll query(int l, int r){
        return query(1, 1, len, l, r).first;
    }
};
void pre(){
    power[0] = 1;
    for(int x=1;x<=100000;x++)
        power[x] = (power[x-1] * base1) % prime1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    pre();

    string s, rs;
    cin>>s;
    int len = s.length();
    rs = s;
    reverse(rs.begin(), rs.end());

    Hash h(s);
    HashTree ht(s);
    HashTree rht(rs);

    //cout<<h.hashVal(1, 3).first<<endl;
    //cout<<ht.query(1, 1, len, 2, 4).first<<endl;
//
//    cout<<ht.query(1, 2)<<endl;
//    ht.update(4, 'b');
//    rht.update(2, 'b');
//    cout<<rht.query(1, 2)<<endl;


    int q; cin>>q;

    while(q--){
        string ac; cin>>ac;
        if(ac == "palindrome?"){
            int l, r; cin>>l>>r;
            int len2 = (r-l+1) / 2;
            ll q1 = ht.query(l, l + len2 - 1);
           // cout<<"Fir "<<l <<" "<<l+len2-1<<endl;
            ll q2 = rht.query(len-r+1, len - r + len2);
          //  cout<<"Sec "<<len-r+1<<" "<<len-r+len2<<endl;
            if(len == 0 || q1 == q2) cout<<"Yes\n";
            else cout<<"No\n";
        }else{
            int l; char r; cin>>l>>r;
            ht.update(l, r);
            rht.update(len - l+1 , (int)r);
        }
    }


}
