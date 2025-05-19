#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 6e5 + 5;
const int N = (1 << 20) + 5;
const int mod = 1e9 + 7; //998244353;
const int inf = 1e14;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};

int n, k, a[O], b[O], t[O], id[O], res[O], tree[O * 4], f[21][O];
vector <int> val, g[O], q[O];

bool how_sort(int x, int y){
    return max(a[x], b[x]) < max(a[y], b[y]);
}

void Build(int id, int l, int r){
    if (l == r){
        tree[id] = 1;
        return;
    }
    int mid = (l + r) / 2;
    Build(id << 1, l, mid);
    Build(id << 1 | 1, mid + 1, r);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

void Update(int id, int l, int r, int u, int x){
    if (l > u || r < u) return;
    if (l == r){
        tree[id] = x;
        return;
    }
    int mid = (l + r) / 2;
    Update(id << 1, l, mid, u, x);
    Update(id << 1 | 1, mid + 1, r, u, x);
    tree[id] = tree[id << 1] + tree[id << 1 | 1];
}

int Get(int id, int l, int r, int u, int v){
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    int mid = (l + r) / 2;
    return Get(id << 1, l, mid, u, v) + Get(id << 1 | 1, mid + 1, r, u, v);
}

int Get(int l, int r){
    int len = log2(r - l + 1);
    return max(f[len][l], f[len][r - (1 << len) + 1]);
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i] >> b[i];
        val.push_back(a[i]);
        val.push_back(b[i]);
        id[i] = i;
        if (a[i] == b[i]) res[i] = a[i];
    }

    for (int i = 1; i <= k; ++ i){
        cin >> t[i];
        val.push_back(t[i]);
    }

    sort(val.begin(), val.end());
    int m = unique(val.begin(), val.end()) - val.begin();
    val.resize(m);

    sort(id + 1, id + n + 1, how_sort);

    for (int i = 1; i <= n; ++ i){
        int j = id[i];
        if (a[j] == b[j]) continue;
        int d = upper_bound(val.begin(), val.end(), max(a[j], b[j])) - val.begin();
        q[d].push_back(j);
    }

    for (int i = 1; i <= k; ++ i){
        int d = upper_bound(val.begin(), val.end(), t[i]) - val.begin();
        g[d].push_back(i);
        f[0][d] = max(f[0][d], i);
    }

    for (int i = 1; i <= 20; ++ i){
        for (int j = 1; j - 1 + (1 << i) <= m; ++ j){
            f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
        }
    }

    Build(1, 1, k);

    int Max = 0;
    for (int i = 1; i <= m; ++ i){
        for (int j : q[i]){
            int idL = upper_bound(val.begin(), val.end(), min(a[j], b[j])) - val.begin();
            int idR = upper_bound(val.begin(), val.end(), max(a[j], b[j])) - val.begin() - 1;

            int x = Get(idL, idR);

            int cur = (a[j] < b[j]);
            if (x) cur = 0;

            cur ^= (Get(1, 1, k, x + 1, k) & 1);

            res[j] = (cur ? min(a[j], b[j]) : max(a[j], b[j]));
        }

        for (int j : g[i]){
            Update(1, 1, k, j, 0);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        ans += res[i];
    }

    cout << ans;
}
/**
**/