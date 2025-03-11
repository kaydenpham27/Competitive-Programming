#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 5e5 + 5;

int n, q, l[O], r[O], a[O], res[O], tree[O * 4], init[O * 4], lazy[O * 4];
vector <int> qu[O], nxt[O];

void Push(int id){
    int &x = lazy[id];
    if (x == 0) return;

    for (int i = 2 * id; i <= 2 * id + 1; ++ i){
        tree[i] = max(tree[i], init[i] + x);
        lazy[i] = max(lazy[i], x);
    }

    x = 0; return;
}

void Build(int id, int l, int r){
    if (l == r){
        init[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    init[id] = max(init[id << 1], init[id << 1 | 1]);
}

void Update(int id, int l, int r, int u, int v, int x){
    if (l > v || r < u) return;
    if (u <= l && r <= v){
        tree[id] = max(tree[id], init[id] + x);
        lazy[id] = max(lazy[id], x);
        return;
    }
    int mid = (l + r) / 2; Push(id);
    Update(id << 1, l, mid, u, v, x);
    Update(id << 1 | 1, mid + 1, r, u, v, x);
    tree[id] = max(tree[id << 1], tree[id << 1 | 1]);
}

int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2; Push(id);
    return max(Get(id << 1, l, mid, u, v), Get(id << 1 | 1, mid + 1, r, u, v));
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i) cin >> a[i];

    Build(1, 1, n);

    cin >> q;
    for (int i = 1; i <= q; ++ i){
        cin >> l[i] >> r[i];
        qu[l[i]].push_back(i);
    }

    vector <int> Q;
    for (int i = 1; i <= n; ++ i){
        while (Q.size() && a[Q.back()] <= a[i]){
            nxt[Q.back()].push_back(i);
            Q.pop_back();
        }

        if (Q.size()) nxt[Q.back()].push_back(i);

        Q.push_back(i);
    }

    for (int i = n; i >= 1; -- i){
        for (int j : nxt[i]){
            Update(1, 1, n, 2 * j - i, n, a[i] + a[j]);
        }

        for (int j : qu[i]){
            res[j] = Get(1, 1, n, i, r[j]);
        }
    }

    for (int i = 1; i <= q; ++ i) cout << res[i] << "\n";
}