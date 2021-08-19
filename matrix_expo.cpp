#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
struct Matrix {
    int r, c;
    vector<vector<ll>> m;

    Matrix(int _r, int _c){
        r = _r;
        c = _c;
        m.resize(r, vector<ll> (c, 0));
    }

    Matrix operator*(Matrix other){
        int l = r;
        int n = c;
        int p = other.c;
        Matrix prod(l, p);

        for(int i = 0; i<l; i++){
            for(int j = 0; j<p; j++){
                for(int k = 0; k<n; k++){
                    prod.m[i][j] += m[i][k]*other.m[k][j];
                    prod.m[i][j] %= mod;
                }
            }
        }

        return prod;
    }


    Matrix pow(ll n){
        if(n == 0){
            Matrix I(r, c);
            for(int i = 0 ; i<r; i++)
                I.m[i][i] = 1;
            return I;
        }

        Matrix squared = (*this) * (*this);
        Matrix result = squared.pow(n/2);
        if(n % 2 == 1){
            result = result * (*this);
        }

        return result;
    }
};
ll n;
int main(){
    cin>>n;
    Matrix state(2, 1);
    state.m[0][0] = 1;
    state.m[1][0] = 0;

    Matrix transition_matrix(2, 2);
    transition_matrix.m[0][0] = 3;
    transition_matrix.m[0][1] = 1;
    transition_matrix.m[1][0] = 1;
    transition_matrix.m[1][1] = 3;
    Matrix res = transition_matrix.pow(n) * state;
    cout<<res.m[0][0];
}
