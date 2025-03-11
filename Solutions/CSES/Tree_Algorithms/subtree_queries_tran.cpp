#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 4e5 + 5;
 
int n, m, k, Time, h[O], in[O], out[O];
vector <int> g[O];
/// euler tour?
int tree[O * 4];
 
void dfs(int u, int par = 0){
    in[u] = ++ Time;
    for (int v : g[u]){
        if (v != par){
            dfs(v, u);
        }
    }
    out[u] = Time;
}
 
void Update(int id, int l, int r, int u, int val){
    if (l > u || r < u) return;
    if (l == r){
        tree[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    Update(id << 1, l, mid, u, val);
    Update(id << 1 | 1, mid + 1, r, u, val);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}
 
int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2;
    return Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i){
        cin >> h[i];
    }
    for (int i = 1; i < n; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    dfs(1);
 
    for (int i = 1; i <= n; ++ i){
        Update(1, 1, Time, in[i], h[i]);
    }
 
    for (int i = 1; i <= m; ++ i){
        int c, u, x; cin >> c;
        if (c == 1){
            cin >> u >> x;
            Update(1, 1, Time, in[u], x);
        }
 
        if (c == 2){
            cin >> u;
            cout << Get(1, 1, Time, in[u], out[u]) << "\n";
        }
    }
}