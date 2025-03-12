#include <bits/stdc++.h>

using namespace std;

const int O = 2e5 + 5;
const int lim = 17;

int n, q, cnt, Time, d[O], h[O], pos[O], child[O], head[O], f[18][O];
int tree[O * 4], lazy[O * 4];
vector <int> g[O];

void dfs(int u, int par = 0){
    child[u] = 1;
    for (int v : g[u]){
        if (v != par){
            h[v] = h[u] + 1;
            dfs(v, u);
            f[0][v] = u;
            child[u] += child[v];
        }
    }
}

void hld(int u, int par = 0){
    if (head[cnt] == 0) head[cnt] = u;
    pos[u] = ++ Time; d[u] = cnt;

    int m = 0;
    for (int v : g[u]){
        if (v != par){
            if (child[v] > child[m]) m = v;
        }
    }
    if (m != 0) hld(m, u);
    for (int v : g[u]){
        if (v != par && v != m){
            cnt += 1;
            hld(v, u);
        }
    }
}

int Lca(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    for (int i = lim; i >= 0; -- i){
        if (h[u] - (1 << i) >= h[v]) u = f[i][u];
    }

    if (u == v) return u;

    for (int i = lim; i >= 0; -- i){
        if (f[i][u] != f[i][v]){
            u = f[i][u];
            v = f[i][v];
        }
    }

    return f[0][u];
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

int Jump(int x, int d){
    for (int i = 0; i <= lim; ++ i){
        if (d >> i & 1) x = f[i][x];
    }
    return x;
}

void Update(int u, int v, int val){
    while (d[u] != d[v]){
        if (d[u] < d[v]) swap(u, v);
        int x = head[d[u]];
        Update(1, 1, n, pos[x], pos[u], val);
        u = f[0][x];
    }
    if (pos[u] < pos[v]) swap(u, v);
    Update(1, 1, n, pos[v], pos[u], val);
}

int Get(int u, int v){
    int ans = 0;
    while (d[u] != d[v]){
        if (d[u] < d[v]) swap(u, v);
        int x = head[d[u]];
        ans += Get(1, 1, n, pos[x], pos[u]);
        u = f[0][x];
    }
    if (pos[u] < pos[v]) swap(u, v);
    ans += Get(1, 1, n, pos[v], pos[u]);
    return ans;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(f, -1, sizeof(f));
    dfs(1);
    hld(1);

    for (int i = 1; i <= lim; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (f[i - 1][j] != -1) f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }

    //cout << Time << endl;
    //for (int i = 1; i <= Time; ++ i) cout << d[i] << " "; cout << endl;
    //for (int i = 1; i <= Time; ++ i) cout << head[d[i]] << " "; cout << endl;
    //for (int i = 1; i <= Time; ++ i) cout << pos[i] << " "; cout << endl;

    //cout << "here " << f[0][9] << endl;

    for (int _ = 1; _ <= q; ++ _){
        int A, B, C, D; cin >> A >> B >> C >> D;
        int E = Lca(A, B);
        int F = Lca(C, D);

        Update(E, A, 1); //cout << "dcm " << E << " " << A << endl;
        if (E != B){
            int nE = Jump(B, h[B] - h[E] - 1);
            Update(nE, B, 1);
            //cout << "DCM " << nE << " " << B << endl;
        }

        int res = Get(F, C);
        if (F != D){
            int nF = Jump(D, h[D] - h[F] - 1);
            res += Get(nF, D);
            //cout << "nF: " << nF << " " << Get(nF, 8) << endl;
        }

        cout << res << "\n";

        Update(E, A, -1);
        if (E != B){
            int nE = Jump(B, h[B] - h[E] - 1);
            Update(nE, B, -1);
        }
    }
}
/**
10 1
1 4
4 5
3 4
3 2
7 3
6 7
7 8
10 8
8 9
1 9 5 10
**/