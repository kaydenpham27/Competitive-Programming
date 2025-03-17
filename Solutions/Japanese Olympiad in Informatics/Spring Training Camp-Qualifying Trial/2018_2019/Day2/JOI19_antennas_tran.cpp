#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 1e6 + 5;
const int inf = 1e18;

int n, q, l[O], r[O], h[O], a[O], b[O], res[O], tree[O * 4], Min[O * 4], Max[O * 4];
vector <int> qu[O], in[O], out[O];

int Beauti(int x){
    return max(1ll, x);
}

void Push(int id){
    int &x = Min[id];
    if (x == inf) return;

    for (int i = 2 * id; i <= 2 * id + 1; ++ i){
        tree[i] = max(tree[i], Max[i] - x);
        Min[i] = min(Min[i], x);
    }

    x = inf; return;
}

void UpdateMax(int id, int l, int r, int u, int x){
    if (l > u || r < u) return;
    if (l == r){
        Max[id] = x;
        Min[id] = inf;
        tree[id] = max(tree[id], Max[id] - Min[id]);
        return;
    }
    int mid = (l + r) / 2; Push(id);
    UpdateMax(id << 1, l, mid, u, x);
    UpdateMax(id << 1 | 1, mid + 1, r, u, x);
    tree[id] = max({tree[id], tree[id << 1], tree[id << 1 | 1]});
    Max[id] = max(Max[id << 1], Max[id << 1 | 1]);
}

void UpdateMin(int id, int l, int r, int u, int v, int x){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        Min[id] = min(Min[id], x);
        tree[id] = max(tree[id], Max[id] - Min[id]);
        return;
    }
    int mid = (l + r) / 2; Push(id);
    UpdateMin(id << 1, l, mid, u, v, x);
    UpdateMin(id << 1 | 1, mid + 1, r, u, v, x);
    tree[id] = max({tree[id], tree[id << 1], tree[id << 1 | 1], Max[id] - Min[id]});
}

int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return -inf;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2; Push(id);
    return max(Get(id << 1, l, mid, u, v), Get(id << 1 | 1, mid + 1, r, u, v));
}

void solve(){
    for (int i = 1; i <= q; ++ i) qu[r[i]].push_back(i);

    for (int i = 1; i < O; ++ i){
        tree[i] = -inf;
        Max[i] = -inf;
        Min[i] = inf;
    }

    for (int i = 1; i <= n; ++ i){
        for (int j : in[i]){
            UpdateMax(1, 1, n, j, h[j]);
        }

        for (int j : out[i]){
            UpdateMax(1, 1, n, j, -inf);
        }

        if (i - a[i] >= 1) UpdateMin(1, 1, n, Beauti(i - b[i]), Beauti(i - a[i]), h[i]);

        for (int j : qu[i]){
            res[j] = max(res[j], Get(1, 1, n, l[j], i));
        }

        if (i + a[i] <= n) in[i + a[i]].push_back(i);
        if (i + b[i] + 1 <= n) out[i + b[i] + 1].push_back(i);
    }

    for (int i = 1; i <= n; ++ i){
        qu[i].clear();
        in[i].clear();
        out[i].clear();
    }

}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> h[i] >> a[i] >> b[i];

    cin >> q;
    for (int i = 1; i <= q; ++ i){
        cin >> l[i] >> r[i];
        res[i] = -1;
    }

    solve();

    reverse(h + 1, h + n + 1);
    reverse(a + 1, a + n + 1);
    reverse(b + 1, b + n + 1);

    for (int i = 1; i <= q; ++ i){
        l[i] = n - l[i] + 1;
        r[i] = n - r[i] + 1;
        swap(l[i], r[i]);
    }

    solve();

    for (int i = 1; i <= q; ++ i) cout << res[i] << "\n";
}