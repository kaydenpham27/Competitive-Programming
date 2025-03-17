#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 5e3 + 5;
const int inf = 1e18;
 
int n, m, q, d[O][O];
 
void Minimize(int &x, int y){
    if (x > y) x = y;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
 
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (i != j) d[i][j] = inf;
        }
    }
 
    for (int i = 1; i <= m; ++ i){
        int u, v, c; cin >> u >> v >> c;
        Minimize(d[u][v], c);
        Minimize(d[v][u], c);
    }
 
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            for (int z = 1; z <= n; ++ z){
                Minimize(d[j][z], d[j][i] + d[i][z]);
            }
        }
    }
 
    while (q --){
        int u, v; cin >> u >> v;
        int res = d[u][v];
        if (res >= inf) res = -1;
        cout << res << "\n";
    }
 
}
/**
**/