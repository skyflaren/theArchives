#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;

int n, q, l, r, amt = 0; ll sum = 0, a, mx = LONG_MIN, arr[100002][2], psa[100002], bpsa[100002]; string str;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q; arr[n+1][1] = 0; psa[0] = 0; psa[n+1] = 0; bpsa[n+1] = 0; bpsa[0] = 0; l = 0; r = n;
    for(int z = 1; z <= n; z++){ 
        cin >> arr[z][0]; arr[n-z][1] = arr[z][1] + arr[n-z+1][1]; 
        psa[z] = psa[z-1] + arr[z][0];
    }
    for(int z = n; z >= 1; z--) bpsa[z] = bpsa[z+1] + arr[z][0];

    for(int i = 1; i <= n; i++){
        sum = max(0LL, sum) + arr[i][amt];
        if(sum > mx) mx = sum;
    }

    for(int z = 0; z < q; z++){
        cin >> str;
        if(str.compare("MAX-SUM") == 0) cout << mx << "\n";
        else if(str.compare("GET-SUM") == 0){
            cin >> l >> r;
            if(amt == 0) cout << (psa[l+r-1] - psa[l-1]) << "\n";
            else cout << (bpsa[n-(l+r-2)]-bpsa[n-l+2]) << "\n";
        }
        else amt ^= 1;
    }
}

//We can create a prefix sum array for the array forwards and backwards, and then swap between them. For the MAX-SUM, we can use Kadane's for it in O(N)
