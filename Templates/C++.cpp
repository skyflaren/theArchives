#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"


#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;


#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define ln "\n"
#define pii pair <int, int>
typedef long long ll;
typedef unsigned long long ull;
#define FILL(a, b) memset(a, b, sizeof(a))
const int INF = 0x3F3F3F3F, MOD = 1e9+7;
const int MAX = 1e3 + 5;

int n;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    
}
