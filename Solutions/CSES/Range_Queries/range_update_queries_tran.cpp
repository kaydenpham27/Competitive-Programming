#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, q, a[O], tree[O * 4], lazy[O * 4];
 
void Build(int id, int l, int r){
    if (l == r){
        tree[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
}
 
void Push(int id, int l, int r){
    int &x = lazy[id];
    if (!x) return;
 
    int mid = (l + r) / 2;
 
    lazy[id << 1] += x;
    lazy[id << 1 | 1] += x;
 
    tree[id << 1] += (mid - l + 1) * x;
    tree[id << 1 | 1] += (r - mid) * x;
 
    x = 0; return;
}
 
void Update(int id, int l, int r, int u, int v, int x){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        tree[id] += (r - l + 1) * x;
        lazy[id] += x;
        return;
    }
    int mid = (l + r) / 2; Push(id, l, r);
    Update(id << 1, l, mid, u, v, x);
    Update(id << 1 | 1, mid + 1, r, u, v, x);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
 
int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2; Push(id, l, r);
    return Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
 
    Build(1, 1, n);
    for (int i = 1; i <= q; ++ i){
        int l, r, k, x; cin >> k >> l;
        if (k == 1) cin >> r >> x, Update(1, 1, n, l, r, x);
        if (k == 2) cout << Get(1, 1, n, l, l) << "\n";
    }
}