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
Hash h1, h2;
string s, rs;
int len;
int dp[5000001];
int  rec(int en){
    if(dp[en] != -1) return dp[en];
    if(en == 0) return 1;
    int si = (en+1) / 2;
    int ena = en/2;
    if(en % 2==0) ena--;
    if(h1.hashVal(0, ena) == h2.hashVal(len-en-1,len-en + si - 2)){
        return dp[en] = 1 + rec(ena);
    }
    return dp[en] = 0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof dp);
    cin>>s;
    rs = s;
    len = s.length();

    reverse(rs.begin(), rs.end());
    h1 = Hash(s);
    h2 = Hash(rs);

    int ans = 0;

    for(int x=0;x<len;x++){
        ans += rec(x);
    }
    cout<<ans;


}
