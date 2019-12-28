#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

int N; int p[24][24], dp[1 << 21];

ll rec(int man, int mask){
  if(dp[mask] >= 0) return dp[mask]; 
  if(man >= N) return 1;
  ll ret = 0;
  for(int w = 0; w < N; w++)
    if(!(mask & (1 << w))) ret = (ret+p[man][w] * rec(man+1, mask| (1<<w)))%1000000007;
  return dp[mask] = ret;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> N; fill(dp, dp+(1<<21), -1);
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> p[i][j];
    }
  }
  cout << (rec(0, 0)) << "\n";
}

//We can use an array of bitmasks to represent all possibilities
