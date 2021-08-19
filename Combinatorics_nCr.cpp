const ll mod = 1e9 + 7;
ll fac[1001];
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
   return (fac[n] * modInverse(fac[r]) % mod * modInverse(fac[n - r]) % mod) % mod;
}
void pre(){
   fac[0] = 1;
 
   for(int x=1;x<=1000;x++){
       fac[x] = fac[x-1]*x;
       fac[x] %= mod;
   }
}
