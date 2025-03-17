#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 3e5 + 5;

int n, cnt, a[O], b[O], c[O], h[O], d[O], E[O], par[O], head[O], child[O], tree[O * 4];
vector <int> val, g[O];

deque <pair <int, int>> q[O];

void Update(int id, int l, int r, int u, int x){
    if (l > u || r < u) return;
    if (l == r){
        tree[id] += x;
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

void dfs(int u){
    child[u] = 1;
    for (int i : g[u]){
        int v = u ^ E[i];
        if (v != par[u]){
            par[v] = u;
            h[v] = h[u] + 1;
            dfs(v);
            child[u] += child[v];
        }
    }
}

void hld(int u){
    if (head[cnt] == 0) head[cnt] = u; d[u] = cnt;

    int Max = -1, BigChild = -1;

    for (int i : g[u]){
        int v = u ^ E[i];
        if (v != par[u] && child[v] > Max){
            Max = child[v];
            BigChild = v;
        }
    }

    if (BigChild != -1) hld(BigChild);

    for (int i : g[u]){
        int v = u ^ E[i];
        if (v != par[u] && v != BigChild){
            cnt += 1;
            hld(v);
        }
    }
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        cin >> c[i];
        val.push_back(c[i]);
    }

    sort(val.begin(), val.end());
    val.resize(unique(val.begin(), val.end()) - val.begin());
    int lim = val.size();

    for (int i = 1; i < n; ++ i){
        cin >> a[i] >> b[i];
        g[a[i]].push_back(i);
        E[i] = a[i] ^ b[i];
    }

    dfs(1); hld(1);

    q[d[1]].push_back({1, c[1]});
    for (int i = 1; i < n; ++ i){
        int u = a[i];

        vector <pair <int, int>> need;
        while (u){
            int parU = head[d[u]];
            int k = h[u] - h[parU] + 1;

            vector <pair <int, int>> sth;
            while (k){
                int cost = min(k, q[d[u]][0].first);
                k -= cost;

                sth.push_back({cost, q[d[u]][0].second});

                q[d[u]][0].first -= cost;
                if (q[d[u]][0].first == 0) q[d[u]].pop_front();
            }


            while (sth.size()){
                need.push_back(sth.back());
                sth.pop_back();
            }

            q[d[u]].push_front({h[u] - h[parU] + 1, c[b[i]]});
            u = par[parU];
        }

        u = b[i];
        if (q[d[u]].size() && q[d[u]].back().second == c[u]) q[d[u]].back().first += 1;
        else q[d[u]].push_back({1, c[u]});

        int res = 0;
        for (auto j : need){
            int id = upper_bound(val.begin(), val.end(), j.second) - val.begin();
            res += j.first * Get(1, 1, lim, 1, id - 1);
            Update(1, 1, lim, id, j.first);
        }

        for (auto j : need){
            int id = upper_bound(val.begin(), val.end(), j.second) - val.begin();
            Update(1, 1, lim, id, -j.first);
        }

        cout << res << "\n";
    }
}