#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, q, N, a[O], ver[O];
map <int, int> last;
 
struct Node{
    int w, l, r;
} tree[O * 32];
 
void Build(int id, int l, int r){
    if (l == r) return;
    tree[id].l = ++ N; tree[id].r = ++ N;
    int mid = (l + r) / 2;
    Build(tree[id].l, l, mid);
    Build(tree[id].r, mid + 1, r);
}
 
int Update(int id, int l, int r, int u, int x){
    if (l == r){
        tree[++ N].w = x;
        return N;
    }
 
    int mid = (l + r) / 2;
    int cur = ++ N;
 
    if (u <= mid){
        tree[cur].r = tree[id].r;
        tree[cur].l = Update(tree[id].l, l, mid, u, x);
        tree[cur].w = tree[tree[cur].l].w + tree[tree[cur].r].w;
    }
    else{
        tree[cur].l = tree[id].l;
        tree[cur].r = Update(tree[id].r, mid + 1, r, u, x);
        tree[cur].w = tree[tree[cur].l].w + tree[tree[cur].r].w;
    }
 
    return cur;
}
 
int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id].w;
    int mid = (l + r) / 2;
    return Get(tree[id].l, l, mid, u, v) + Get(tree[id].r, mid + 1, r, u, v);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
 
    ver[0] = ++ N; Build(ver[0], 1, n);
    for (int i = 1; i <= n; ++ i){
        if (!last[a[i]]) ver[i] = ver[i - 1];
        else ver[i] = Update(ver[i - 1], 1, n, last[a[i]], 1);
        last[a[i]] = i;
    }
 
    for (int i = 1; i <= q; ++ i){
        int l, r; cin >> l >> r;
        cout << (r - l + 1) - Get(ver[r], 1, n, l, r) << "\n";
    }
}