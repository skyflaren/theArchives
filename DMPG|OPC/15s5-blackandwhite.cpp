#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n, q, a, b, c, d; ll ans = 0;
bool dif[10005][10005];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;

    for(int i = 0; i < q; i++){
        cin >> a >> b >> c >> d; a++; b++;
        dif[a][b] ^= 1; dif[a][b+d] ^= 1; dif[a+c][b] ^= 1; dif[a+c][b+d] ^= 1;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dif[j][i] ^= dif[j-1][i-1] ^ dif[j-1][i] ^ dif[j][i-1];
            if(dif[j][i] % 2 == 1) ans++;
        }
    }
    cout << ans << "\n";
}

//This solution uses a 2-D difference array, but uses booleans for a memory optimization.
