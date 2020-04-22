#include <bits/stdc++.h>  //Sparse Table RMQ
using namespace std;
#define pb push_back
#define f first
#define s second
#define ln "\n"
#define pii pair <int, int>
typedef long long ll;
typedef unsigned long long ull;
#define FILL(a, b) memset(a, b, sizeof(a))
const int INF = 0x3F3F3F3F;
const int MM = 1e5 + 5, LOG = 17;
int n, m, st[LOG][MM], x, y;

int RMQ(int x, int y){
    int lvl = log2(y-x+1);
    return max(st[lvl][x], st[lvl][y-(1<<lvl)+1]);
}

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> st[0][i];
    
    for(int i = 1; i < LOG; i++)
        for(int j = 1; j+ (1<<i)-1 <= n; j++)
            st[i][j] = max( st[i-1][j], st[i-1][ j+(1<<(i-1)) ]);

    for(int i = 1, x, y; i <= m; i++){
        cin >> x >> y;
        cout << (RMQ(x,y)) << ln;
    }
}
