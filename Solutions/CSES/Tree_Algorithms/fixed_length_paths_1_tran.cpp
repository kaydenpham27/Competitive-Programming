#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e6 + 50;
const int inf = 1e8;
 
int n, m, k, cnt, res, Time, c[O], p[O], in[O], out[O], dem[O], child[O];
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
            c[v] = c[u] + 1;
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
 
    res += dem[c[u] + k];
 
    Add(c[u]);
    for (int v : g[u]){
        if (v != BigChild && v != par){
            for (int i = in[v]; i <= out[v]; ++ i){
                int x = p[i];
                if (k - (c[x] - c[u]) >= 0){
                    res += (dem[c[u] + (k - (c[x] - c[u]))]);
                    //cout << "check " << u << " " << x << " " << c[u] << " " << c[u] + (k - (c[x] - c[u])) << endl;
                }
            }
 
            for (int i = in[v]; i <= out[v]; ++ i){
                int x = p[i];
                Add(c[x]);
            }
        }
    }
 
    //res[u] = cnt;
 
    if (!keep){
        for (int i = in[u]; i <= out[u]; ++ i){
            int x = p[i];
            Del(c[x]);
        }
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
 
    for (int i = 1; i < n; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    init(1); dfs(1);
 
    //for (int i = 1; i <= n; ++ i) cout << c[i] << endl;
 
    cout << res;
}
/**
**/
