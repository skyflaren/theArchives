#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

int n, q, a, b, xi, yi, v, c; ll BIT[5005][5005];

void update(int xi, int yi, ll val){
    for(int y = yi; y < 5005; y += y&-y) 
        for(int x = xi; x < 5005; x += x&-x) BIT[x][y] += val;
}

ll query(int xi, int yi){
    ll sum = 0;
    for(int y = yi; y > 0; y -= y&-y) 
        for(int x = xi; x > 0; x -= x&-x) sum += BIT[x][y]; 
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;

    for(int i = 0; i < q; i++){
        cin >> c;
        if(c == 1){
            cin >> a >> b >> xi >> yi >> v;
            update(xi+1, yi+1, v); update(a, yi+1, -v); update(xi+1, b, -v); update(a, b, v); 
        }
        else{
            cin >> a >> b;
            cout << query(a, b) << '\n';
        }
    }
}

//We use a BIT for range uodate and queries in the same manner as a difference array
