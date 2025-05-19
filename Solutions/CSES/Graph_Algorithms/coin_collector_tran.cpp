#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 4e5 + 5;
 
int n, m, Time, a[O], d[O], f[O], dd[O], cmp[O];
vector <int> g[O], gr[O], adj[O], comp, order;
 
void init(int u){
    dd[u] = 1;
    for (int v : g[u]){
        if (!dd[v]) init(v);
    }
    order.push_back(u);
}
 
void rdfs(int u){
    dd[u] = 1;
    for (int v : gr[u]){
        if (!dd[v]){
            rdfs(v);
        }
    }
    comp.push_back(u);
}
 
void dfs(int u){
    int Max = 0;
    dd[u] = 1;
    for (int v : adj[u]){
        if (!dd[v]){
            dfs(v);
        }
        Max = max(Max, f[v]);
    }
    f[u] += Max;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
 
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
 
    for (int i = 1; i <= n; ++ i){
        if (!dd[i]) init(i);
    }
 
    reverse(order.begin(), order.end());
 
    int cnt = 0;
    memset(dd, 0, sizeof(dd));
    for (int i : order){
        if (!dd[i]){
            comp.clear();
            rdfs(i);
            cnt += 1;
 
            int cur = 0;
            for (int j : comp){
                cmp[j] = cnt;
                cur += a[j];
            }
 
            f[cnt] = cur;
        }
    }
 
    for (int i = 1; i <= n; ++ i){
        for (int j : g[i]){
            if (cmp[i] != cmp[j]) adj[cmp[i]].push_back(cmp[j]);
        }
    }
 
    memset(dd, 0, sizeof(dd));
    for (int i : order){
        if (!dd[cmp[i]]){
            dfs(cmp[i]);
        }
    }
 
    int res = 0;
    for (int i = 1; i <= n; ++ i) res = max(res, f[cmp[i]]);
 
    cout << res;
}
/**
10
1 1 1 1 1 1 1 1 1 1
**/