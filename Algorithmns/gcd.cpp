ll gcd(ll m, ll n){
    if(n == 0)  return m;
    return gcd(n, m%n);
}
