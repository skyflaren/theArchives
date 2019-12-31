#include <bits/stdc++.h>
#define pb push_back
using namespace std;
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;
#define FILL(a, b) memset(a, b, sizeof(a))
const int INF = 0x3F3F3F3F;
const int MAX = 1e3 + 5;

int k, r, c; char a;
stack <int> s;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> k;
    for(int z = 0; z < k; z++){
        cin >> r >> c; ll mx = 0;
        int arr[r+1][c+1], cur[c+1], left[c+1], right[c+1]; 

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                cin >> a; 
                arr[i][j] = a == 'F' ? 0 : 1;
            }
        }


        for(int i = 0; i < c+1; i++) cur[i] = -1;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++)
                if(arr[i][j] == 1) cur[j] = i;
            
            for(int j = 0; j < c; j++){
                while(!s.empty() && cur[s.top()] <= cur[j]) s.pop();
                if(!s.empty()) left[j] = s.top();
                else left[j] = -1;
                s.push(j);
            }
            while(!s.empty()) s.pop();


            for(int j = c-1; j >= 0; j--){
                while(!s.empty() && cur[s.top()] <= cur[j]) s.pop();
                if(!s.empty()) right[j] = s.top();
                else right[j] = c;
                s.push(j);
            } 
            while(!s.empty()) s.pop();


            for(int j = 0; j < c; j++){
                if((right[j]-left[j]-1) * (i-cur[j]) > mx) mx = (right[j]-left[j]-1) * (i-cur[j]);
            }
        }
        cout << mx*3 << "\n";
    }
}

//For each square as the bounding square, we use a stack to help find what the left and right bounds are
