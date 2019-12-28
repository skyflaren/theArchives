#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

int n, q, a, b, cnt = 1, BIT[200005],  eul[2000005]; ll sal[100005];
vector <int> arr[100005], refe[100005];
char c;

void update(int idx, ll val){
    for(; idx < 200005; idx += idx&-idx) BIT[idx] += val;
}

ll query(int idx){
    ll sum = 0;
    for(; idx > 0; idx -= idx&-idx) sum += BIT[idx];
    return sum;
}

void dfs(int cur){
    eul[cnt] = cur;
    update(cnt, sal[cur]);
    refe[cur].pb(cnt);
    cnt++;
    for(int v: arr[cur]) dfs(v);

    eul[cnt] = cur;
    update(cnt, sal[cur]);
    refe[cur].pb(cnt);
    cnt++;
    return;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        arr[a].pb(i);
        sal[i] = b;
    }
    dfs(1);
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> c;
        if(c == 'q'){
            cin >> a;
            cout << (query(refe[a].at(1))-query(refe[a].at(0)-1))/2 << "\n";
        }
        else{
            cin >> a >> b;
            update(refe[a].at(0), b-sal[a]);
            update(refe[a].at(1), b-sal[a]);
            sal[a] = b;
        }
    }
}

//We can create a tour of the graph where we visit each node, and then use a BIT for handling the queries
