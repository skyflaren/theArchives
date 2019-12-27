#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, int> pii;

int n, arr[200001], lef[200001], ind[200001], q, type, a, b, ans;

int upd(int end, int amt, int cur){ 
    if(cur+arr[cur] >= end){  
        ind[cur] = cur+arr[cur]; 
        return 1; 
    }
    else{
        ind[cur] = ind[cur+arr[cur]];
        return lef[cur+arr[cur]]+1;
    }
}

void query(int cur, int amt){
    if(cur >= n){ ans = amt; return;}
    query(ind[cur], amt+lef[cur]);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){ cin >> arr[i]; lef[i] = 0; }
    cin >> q;

    int sq = ceil(sqrt(n));
    for(int z = sq; z >= 1; z--){
        int zq = z*sq, en = min(zq, n);
        for(int i = zq-1; i >= zq-sq; i--){
            lef[i] = upd(en, 0, i); 
        }   
    }
    for(int i = 0; i < q; i++){
        cin >> type;
        if(type == 1){
            cin >> a;
            query(a, 0);
            cout << ans << endl;
        }
        else{
            cin >> a >> b;
            arr[a] = b; int aq = (a/sq)*sq, en = min(aq+sq, n);
            for(int i = a; i >= aq; i--){
                lef[i] = upd(en, 0, i);
            }
        }
    }
}

//This uses logN queries and updates using square root decomp, by breaking the array into blocks that you calculate how many steps it takes to get out of, and what index you will land on. 
//For updates, simply loop back towards 1 starting at the index you updated.
