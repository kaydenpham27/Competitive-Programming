#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 2e5 + 50;
const int inf = 1e8;
 
int n, m, cnt, Time, c[O], p[O], in[O], out[O], res[O], dem[O], child[O];
vector <int> val, g[O];
unordered_map <int, int> rval;
 
int ID(int x){
    return rval[x];
}
 
void Add(int x){
    dem[x] += 1;
    if (dem[x] == 1) cnt += 1;
}
 
void Del(int x){
    dem[x] -= 1;
    if (dem[x] == 0) cnt -= 1;
}
 
void init(int u, int par = 0){
    in[u] = ++ Time; p[Time] = u;
    child[u] = 1;
    for (int v : g[u]){
        if (v != par){
            init(v, u);
            child[u] += child[v];
        }
    }
    out[u] = Time;
}
 
void dfs(int u, int par = 0, int keep = 1){
    int Max = -1, BigChild = -1;
    for (int v : g[u]){
        if (v != par && child[v] > Max){
            Max = child[v];
            BigChild = v;
        }
    }
 
    for (int v : g[u]){
        if (v != par && v != BigChild) dfs(v, u, 0);
    }
 
    if (BigChild != -1) dfs(BigChild, u, 1);
 
    Add(c[u]);
    for (int v : g[u]){
        if (v != BigChild && v != par){
            for (int i = in[v]; i <= out[v]; ++ i){
                int x = p[i];
                Add(c[x]);
            }
        }
    }
 
    res[u] = cnt;
 
    if (!keep){
        for (int i = in[u]; i <= out[u]; ++ i){
            int x = p[i];
            Del(c[x]);
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
    m = unique(val.begin(), val.end()) - val.begin();
    val.resize(m);
 
    for (int i = 1; i <= m; ++ i) rval[val[i - 1]] = i;
    for (int i = 1; i <= n; ++ i) c[i] = ID(c[i]);
 
    for (int i = 1; i < n; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    init(1); dfs(1);
 
    for (int i = 1; i <= n; ++ i) cout << res[i] << " ";
}
/**
**/