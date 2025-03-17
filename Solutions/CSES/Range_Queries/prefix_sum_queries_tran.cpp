#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, q, a[O], sum[O], tree[O * 4], lazy[O * 4];
 
void Build(int id, int l, int r){
    if (l == r){
        tree[id] = sum[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}
 
void Push(int id, int l, int r){
    int &x = lazy[id];
    if (!x) return;
 
    int mid = (l + r) / 2;
 
    lazy[id << 1] += x;
    lazy[id << 1 | 1] += x;
 
    tree[id << 1] += x;
    tree[id << 1 | 1] += x;
 
    x = 0; return;
}
 
void Update(int id, int l, int r, int u, int v, int x){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        tree[id] += x;
        lazy[id] += x;
        return;
    }
    int mid = (l + r) / 2; Push(id, l, r);
    Update(id << 1, l, mid, u, v, x);
    Update(id << 1 | 1, mid + 1, r, u, v, x);
    tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}
 
int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return -1e18;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2; Push(id, l, r);
    return max(Get(id << 1, l, mid, u, v), Get(id << 1 | 1, mid + 1, r, u, v));
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> a[i], sum[i] = sum[i - 1] + a[i];
 
    Build(1, 1, n);
    for (int i = 1; i <= q; ++ i){
        int l, r, k, x; cin >> k >> l >> r;
        if (k == 1) Update(1, 1, n, l, n, -a[l]), Update(1, 1, n, l, n, r), a[l] = r;
        if (k == 2) cout << max(0ll, Get(1, 1, n, l, r) - (l - 1 > 0) * Get(1, 1, n, l - 1, l - 1)) << "\n";
    }
}