#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 3e5 + 5;
const int inf = 1e18;

int n, k, a[O], lazy[O * 4];

struct Node{
    int sum, l, r, w, pref, suf, lsuf, rpref;
} tree[O * 4], rtree[O * 4];

Node Merg(Node x, Node y){
    Node root; root.w = -inf;
    root.sum = x.sum + y.sum;

    root.pref = x.pref;
    root.rpref = x.rpref;
    if (x.sum + y.pref > root.pref){
        root.pref = x.sum + y.pref;
        root.rpref = y.rpref;
    }

    root.suf = y.suf;
    root.lsuf = y.lsuf;
    if (y.sum + x.suf > root.suf){
        root.suf = y.sum + x.suf;
        root.lsuf = x.lsuf;
    }

    if (x.w > root.w){
        root.w = x.w;
        root.l = x.l;
        root.r = x.r;
    }

    if (y.w > root.w){
        root.w = y.w;
        root.l = y.l;
        root.r = y.r;
    }

    if (x.suf + y.pref >= root.w){
        root.w = x.suf + y.pref;
        root.l = x.lsuf;
        root.r = y.rpref;
    }

    return root;
}

void Push(int id){
    int &x = lazy[id];
    if (x == 0) return;

    for (int i = 2 * id; i <= 2 * id + 1; ++ i){
        swap(tree[i], rtree[i]);
        lazy[i] ^= x;
    }

    x = 0; return;
}

void Build(int id, int l, int r){
    if (l == r){
        tree[id] = {a[l], r, l, a[r], a[l], a[r], l, r};
        rtree[id] = {-a[r], l, r, -a[l], -a[r], -a[l], r, l};
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    tree[id] = Merg(tree[id << 1], tree[id << 1 | 1]);
    rtree[id] = Merg(rtree[id << 1], rtree[id << 1 | 1]);
}

void Update(int id, int l, int r, int u, int v){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        swap(tree[id], rtree[id]);
        lazy[id] ^= 1;
        return;
    }
    int mid = (l + r) / 2; Push(id);
    Update(id << 1, l, mid, u, v);
    Update(id << 1 | 1, mid + 1, r, u, v);
    tree[id] = Merg(tree[id << 1], tree[id << 1 | 1]);
    rtree[id] = Merg(rtree[id << 1], rtree[id << 1 | 1]);
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i) cin >> a[i];

    Build(1, 1, n);

    int res = 0;
    for (int i = 1; i <= k; ++ i){
        if (tree[1].w <= 0) break;
        res += tree[1].w;
        Update(1, 1, n, tree[1].l, tree[1].r);
    }

    cout << res;
    return 0;
}