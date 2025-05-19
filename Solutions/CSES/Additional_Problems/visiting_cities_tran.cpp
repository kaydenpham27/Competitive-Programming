#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 50;
const int mod = 1e9 + 3;
const int inf = 1e16;
 
bool in[O];
int n, m, d[O], f[O], dn[O], fn[O];
vector <pair <int, int>> g[O], gr[O];
 
void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        gr[v].push_back({u, w});
    }
 
    for (int i = 1; i <= n; ++ i) d[i] = inf, f[i] = 1; d[1] = 0; //in[1] = true;
 
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> q; q.push({0, 1});
 
    while (q.size()){
        auto [du, u] = q.top();
        q.pop(); //in[u] = false;
 
        if (du != d[u]) continue;
 
        for (auto [v, w] : g[u]){
            if (d[v] > du + w){
                d[v] = du + w;
                f[v] = f[u];
                //if (!in[v]){
                    q.push({d[v], v});
                    //in[v] = true;
                //}
            }
            else{
                if (d[v] == du + w){
                    Add(f[v], f[u]);
                    //if (!in[v]){
                        //q.push({d[v], v});
                        //in[v] = true;
                    //}
                }
            }
        }
    }
 
    for (int i = 1; i <= n; ++ i) fn[i] = 1, dn[i] = inf; dn[n] = 0; q.push({0, n});
    //in[n] = true;
 
    while (q.size()){
        auto [du, u] = q.top();
        q.pop(); //in[u] = false;
 
        if (du != dn[u]) continue;
 
        for (auto [v, w] : gr[u]){
            if (dn[v] > du + w){
                dn[v] = du + w;
                fn[v] = fn[u];
                //if (!in[v]){
                    q.push({dn[v], v});
                    //in[v] = true;
                //}
            }
            else{
                if (dn[v] == du + w){
                    Add(fn[v], fn[u]);
                    //if (!in[v]){
                        //q.push({dn[v], v});
                        //in[v] = true;
                    //}
                }
            }
        }
    }
 
    vector <int> res;
    for (int i = 1; i <= n; ++ i){
        //cout << i << " " << d[i] << " " << dn[i] << " " << f[i] << " " << fn[i] << endl;
        if (d[i] + dn[i] == d[n]){
            int x = f[i];
            x = 1ll * x * fn[i] % mod;
            if (x == f[n]) res.push_back(i);
        }
    }
 
    cout << res.size() << "\n";
    for (int i : res) cout << i << " ";
}
/***
***/