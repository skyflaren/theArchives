public static long gcd(long m, long n){
    if(n == 0)  return m;
    return gcd(n, m%n);
}
