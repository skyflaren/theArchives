#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int n; ll BIT[100005], arr[100005], sorted[100005], amt; 
map <ll, ll> rk;

void update(ll idx, ll val) {
    for (; idx<=100004;idx+=idx&-idx) {
        BIT[idx] += val;
    }
}
ll query(ll idx) {
    ll res = 0;
    for (; idx>0;idx-=idx&-idx) {
        res+= BIT[idx];
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    
    for(int i = 0; i < n; i++){ cin >> arr[i]; sorted[i] = arr[i]; }
    sort(sorted, sorted+n);
    for(int i = 1; i <= n; i++) rk.insert({sorted[i-1], n-i+1});
    
    for(int i = 0; i < n; i++){
        amt += query(rk.at(arr[i])-1)+1;
        update(rk.at(arr[i]), 1);
    }
    printf("%.2f\n", amt*1.0/n);
}

//This solution uses a BIT to count inversions (rank)
