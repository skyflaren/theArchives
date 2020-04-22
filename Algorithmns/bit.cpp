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
const int INF = 0x3F3F3F3F;
const int MM = 1e5 + 5;

int n, q; ll BIT[MM], arr[MM], a, b, c;

void upd(int x, ll v){  //2D
    for(int i = x; i < MM; i+=i&-i) BIT[i] += v;
}
ll quer(int x){
    ll sum = 0;
    for(int i = x; i > 0; i-=i&-i) sum += BIT[i];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){ cin >> arr[i]; upd(i, arr[i]);}
    for(int i = 0; i < q; i++){
        cin >> c;
        if(c == 1){ 
            cin >> a >> b; 
            upd(a, b-arr[a]);
        }
        else{ 
            cin >> a; 
            cout << quer(a)-quer(a-1) << ln;
        } 
    }
    for(int i = 1; i<= 5; i++) cout << quer(i)-quer(i-1) << " ";
}
