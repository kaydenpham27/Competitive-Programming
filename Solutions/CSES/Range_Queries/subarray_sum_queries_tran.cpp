#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, q, x[O], sum[O], lazy[O * 4];
 
struct Node{
    int res, mn, mx;
} tree[O * 4];
 
void Build(int id, int l, int r){
    if (l == r){
        tree[id].mn = sum[l];
        tree[id].mx = sum[r];
        tree[id].res = max(0ll, x[l]);
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    tree[id].mx = max(tree[id << 1].mx, tree[id << 1 | 1].mx);
    tree[id].mn = min(tree[id << 1].mn, tree[id << 1 | 1].mn);
    tree[id].res = max({0ll, tree[id << 1].res, tree[id << 1 | 1].res, tree[id << 1 | 1].mx - tree[id << 1].mn});
}
 
void Push(int id){
    int &x = lazy[id];
    if (!x) return;
 
    for (int i = id * 2; i <= id * 2 + 1; ++ i){
        tree[i].mn += x;
        tree[i].mx += x;
        lazy[i] += x;
    }
 
    x = 0; return;
}
 
void Update(int id, int l, int r, int u, int v, int z){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        tree[id].mn += z;
        tree[id].mx += z;
        lazy[id] += z;
        if (z == 0) tree[id].res = max(0ll, x[r]);
        return;
    }
    int mid = (l + r) / 2; Push(id);
    Update(id << 1, l, mid, u, v, z);
    Update(id << 1 | 1, mid + 1, r, u, v, z);
    tree[id].mx = max(tree[id << 1].mx, tree[id << 1 | 1].mx);
    tree[id].mn = min(tree[id << 1].mn, tree[id << 1 | 1].mn);
    tree[id].res = max({0ll, tree[id << 1].res, tree[id << 1 | 1].res, tree[id << 1 | 1].mx - tree[id << 1].mn});
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> x[i], sum[i] = sum[i - 1] + x[i];
 
    Build(1, 0, n);
    for (int i = 1; i <= q; ++ i){
        int k, z; cin >> k >> z;
        Update(1, 0, n, k, n, z - x[k]); x[k] = z;
        Update(1, 0, n, k, k, 0);
        cout << tree[1].res << "\n";
    }
}