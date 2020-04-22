#include <bits/stdc++.h> //Segment Tree
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

struct node{ int l, r, v, g, f; } seg[3*MM];    //left, right, value, gcd, flag
int n, m, arr[MM], a; char op;

void push_up(int id){
    seg[id].v = min(seg[2*id].v, seg[2*id+1].v);
    seg[id].g = __gcd(seg[2*id].g, seg[2*id+1].g);
    seg[id].f = 0;
    if(seg[id].g == seg[2*id].g) seg[id].f += seg[2*id].f;
    if(seg[id].g == seg[2*id+1].g) seg[id].f += seg[2*id+1].f;
}

void build(int l, int r, int id){
    seg[id].l = l; seg[id].r = r;
    if(l == r){ 
        seg[id].v = seg[id].g = arr[l]; seg[id].f = 1; 
        return; 
    }
    int mid = (seg[id].l + seg[id].r)/2;
    build(l, mid, 2*id); build(mid+1, r, 2*id+1); 
    push_up(id);
}

void update(int pos, int val, int id){
    if(seg[id].l == pos && seg[id].r == pos){ //base
        seg[id].v = seg[id].g = val; return;
    }
    int mid = (seg[id].l + seg[id].r)/2;
    if(pos <= mid) update(pos, val, 2*id);
    else update(pos, val, 2*id+1);
    push_up(id); 
}

int qryMin(int l, int r, int id){
    if(seg[id].l == l && seg[id].r == r) return seg[id].v;
    int mid = (seg[id].l + seg[id].r)/2;
    if(r <= mid) return qryMin(l, r, 2*id);
    if(l > mid) return qryMin(l, r, 2*id+1);
    else return min(qryMin(l, mid, 2*id), qryMin(mid+1, r, 2*id+1));
}

int qryGcd(int l, int r, int id){
    if(seg[id].l == l && seg[id].r == r) return seg[id].g;
    int mid = (seg[id].l + seg[id].r)/2;
    if(r <= mid) return qryGcd(l, r, 2*id);
    if(l > mid) return qryGcd(l, r, 2*id+1);
    else return __gcd(qryGcd(l, mid, 2*id), qryGcd(mid+1, r, 2*id+1));
}

int qryCnt(int l, int r, int g, int id){
    if(seg[id].l == l && seg[id].r == r) return seg[id].g == g? seg[id].f: 0;
    int mid = (seg[id].l + seg[id].r)/2;
    if(r <= mid) return qryCnt(l, r, g, 2*id);
    if(l > mid) return qryCnt(l, r, g, 2*id+1);
    return qryCnt(l, mid, g, 2*id) + qryCnt(mid+1, r, g, 2*id+1);
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    build(1, n, 1);

    for(int i = 1, x, y; i <= m; i++){
        cin >> op >> x >> y;
        if(op == 'C') update(x, y, 1);
        else if(op == 'M') cout << qryMin(x, y, 1) << "\n";
        else if(op == 'G') cout << qryGcd(x, y, 1) << "\n";
        else cout << qryCnt(x, y, qryGcd(x,y, 1), 1) << "\n";
    }
}
