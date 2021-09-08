const ll mod = 998244353;
const int MAX = 200000;
ll fac[MAX+1];
ll power(ll x, ll y){
   ll res = 1;
   x = x % mod;
   while (y > 0) {
       if (y & 1)
           res = (res * x) % mod;
       y = y >> 1;
       x = (x * x) % mod;
   }
   return res;
}

ll modInverse(ll n) {
   return power(n, mod - 2);
}

ll cal(ll n, ll r){
   if(r > n) return 0;
   return (fac[n] * modInverse(fac[r]) % mod * modInverse(fac[n - r]) % mod) % mod;
}
void pre(){
   fac[0] = 1;

   for(int x=1;x<=MAX;x++){
       fac[x] = fac[x-1]*x;
       fac[x] %= mod;
   }
}
