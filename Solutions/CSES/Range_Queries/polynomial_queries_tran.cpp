#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, q, a[O];
 
struct Segtree_Lazy{
    int N;
    vector <int> tree, lazy;
 
    void init(int n){
        N = n + 5;
        tree.assign(4 * N, 0);
        lazy.assign(4 * N, 0);
    }
 
    void Build(int id, int l, int r){
        lazy[id] = 0;
        if (l == r){
            tree[id] = 0;
            return;
        }
        int mid = (l + r) / 2;
        Build(id << 1, l, mid);
        Build(id << 1 | 1, mid + 1, r);
        tree[id] = 0;
    }
 
    void Push(int id, int l, int r){
        int &x = lazy[id];
        if (x == 0) return;
 
        int mid = (l + r) / 2;
 
        tree[id << 1] += x * (mid - l + 1);
        lazy[id << 1] += x;
 
        tree[id << 1 | 1] += x * (r - mid);
        lazy[id << 1 | 1] += x;
        x = 0;
        return;
    }
 
    void Update(int id, int l, int r, int u, int v, int val){
        if (l > v || r < u) return;
        if (u <= l && r <= v){
            tree[id] += val * (r - l + 1);
            lazy[id] += val;
            return;
        }
        int mid = (l + r) / 2; Push(id, l, r);
        Update(id << 1, l, mid, u, v, val);
        Update(id << 1 | 1, mid + 1, r, u, v, val);
        tree[id] = tree[id << 1] + tree[id << 1 | 1];
    }
 
    int Get(int id, int l, int r, int u, int v){
        if (l > v || r < u) return 0;
        if (u <= l && r <= v) return tree[id];
        int mid = (l + r) / 2; Push(id, l, r);
        return Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v);
    }
} del;
 
int tree[O * 4], lazy[O * 4], sum[O * 4];
 
void Build(int id, int l, int r){
    lazy[id] = 0;
    if (l == r){
        tree[id] = a[r];
        sum[id] = l;
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
    sum[id] = sum[id << 1] + sum[id << 1 | 1];
}
 
void Push(int id){
    int &x = lazy[id];
    if (x == 0) return;
    tree[id << 1] += x * sum[id << 1];
    lazy[id << 1] += x;
    tree[id << 1 | 1] += x * sum[id << 1 | 1];
    lazy[id << 1 | 1] += x;
    x = 0;
    return;
}
 
void Update(int id, int l, int r, int u, int v, int val){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        tree[id] += val * sum[id];
        lazy[id] += val;
        return;
    }
    int mid = (l + r) / 2; Push(id);
    Update(id << 1, l, mid, u, v, val);
    Update(id << 1 | 1, mid + 1, r, u, v, val);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
 
int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2; Push(id);
    return Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
 
    Build(1, 1, n);
    del.init(n);
 
    while (q --){
        int t, u, v; cin >> t >> u >> v;
 
        if (t == 1){
            del.Update(1, 1, n, u, v, u - 1);
            Update(1, 1, n, u, v, 1);
        }
 
        if (t == 2){
            cout << Get(1, 1, n, u, v) - del.Get(1, 1, n, u, v) << "\n";
        }
    }
}
/**
5 4
4 2 3 1 7
2 1 5
1 1 3
1 3 5
2 1 3
**/