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

#define lc (2*id)
#define rc (2*id+1)

struct node{ int l, r, v, g, f; } seg[3*MM];    //left, right, value, gcd, flag
int n, m, arr[MM], a; char op;

void push_up(int id){
    seg[id].v = min(seg[lc].v, seg[rc].v);
    seg[id].g = __gcd(seg[lc].g, seg[rc].g);
    seg[id].f = 0;
    if(seg[id].g == seg[lc].g) seg[id].f += seg[lc].f;
    if(seg[id].g == seg[rc].g) seg[id].f += seg[rc].f;
}

void build(int l, int r, int id){
    seg[id].l = l; seg[id].r = r;
    if(l == r){ 
        seg[id].v = seg[id].g = arr[l]; seg[id].f = 1; 
        return; 
    }
    int mid = (seg[id].l + seg[id].r)/2;
    build(l, mid, lc); build(mid+1, r, rc); 
    push_up(id);
}

void update(int pos, int val, int id){
    if(seg[id].l == pos && seg[id].r == pos){ //base
        seg[id].v = seg[id].g = val; return;
    }
    int mid = (seg[id].l + seg[id].r)/2;
    if(pos <= mid) update(pos, val, lc);
    else update(pos, val, rc);
    push_up(id); 
}

int qryMin(int l, int r, int id){
    if(seg[id].l == l && seg[id].r == r) return seg[id].v;
    int mid = (seg[id].l + seg[id].r)/2;
    if(r <= mid) return qryMin(l, r, lc);
    if(l > mid) return qryMin(l, r, rc);
    else return min(qryMin(l, mid, lc), qryMin(mid+1, r, rc));
}

int qryGcd(int l, int r, int id){
    if(seg[id].l == l && seg[id].r == r) return seg[id].g;
    int mid = (seg[id].l + seg[id].r)/2;
    if(r <= mid) return qryGcd(l, r, lc);
    if(l > mid) return qryGcd(l, r, rc);
    else return __gcd(qryGcd(l, mid, lc), qryGcd(mid+1, r, rc));
}

int qryCnt(int l, int r, int g, int id){
    if(seg[id].l == l && seg[id].r == r) return seg[id].g == g? seg[id].f: 0;
    int mid = (seg[id].l + seg[id].r)/2;
    if(r <= mid) return qryCnt(l, r, g, lc);
    if(l > mid) return qryCnt(l, r, g, rc);
    return qryCnt(l, mid, g, lc) + qryCnt(mid+1, r, g, rc);
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    build(1, n, 1);

    for(int i = 1, x, y; i <= m; i++){
        cin >> op >> x >> y;
        if(op == 'C') update(x, y, 1);
        else if(op == 'M') cout << qryMin(x, y, 1) << ln;
        else if(op == 'G') cout << qryGcd(x, y, 1) << ln;
        else cout << qryCnt(x, y, qryGcd(x,y, 1), 1) << ln;
    }
}
