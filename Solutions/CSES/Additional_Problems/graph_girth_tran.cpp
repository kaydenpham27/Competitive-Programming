#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 5e3 + 5;
const int inf = 1e9;
 
int n, m, res, f[O], dd[O], E[O];
vector <int> g[O];
 
void Minimize(int &x, int y){
    if (x > y) x = y;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        E[i] = u ^ v;
        g[u].push_back(i);
        g[v].push_back(i);
        dd[i] = u;
    }
 
    res = inf;
    for (int i = 1; i <= m; ++ i){
        queue <int> q;
        for (int j = 1; j <= n; ++ j) f[j] = inf;
        int sta = dd[i]; f[sta] = 0;
 
        q.push(sta);
        while (q.size()){
            auto u = q.front();
            int du = f[u];
            q.pop();
 
            for (int j : g[u]){
                if (j != i){
                    int v = E[j] ^ u;
                    if (f[v] > du + 1){
                        f[v] = du + 1;
                        q.push(v);
                    }
                }
            }
        }
 
        //if (i == 1) for (int j = 1; j <= n; ++ j) cout << f[j] << " ";
 
        Minimize(res, f[sta ^ E[i]] + 1);
    }
 
    cout << (res >= inf ? -1 : res);
}
/**
9 1
9 9 8 2 4 4 3 5 3
**/