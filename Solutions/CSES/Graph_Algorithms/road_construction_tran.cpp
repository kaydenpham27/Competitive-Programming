#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 1e5 + 5;
 
int n, m, res, cnt, sz[O], lab[O];
vector <tuple <int, int, int>> Edges;
 
int Find(int u){
    return lab[u] == 0 ? u : lab[u] = Find(lab[u]);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m; cnt = n;
    for (int i = 1; i <= n; ++ i) sz[i] = 1;
 
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        u = Find(u);
        v = Find(v);
 
        if (u != v){
            lab[u] = v;
            sz[v] += sz[u];
            cnt -= 1;
            res = max(res, sz[v]);
        }
 
        cout << cnt << " " << res << "\n";
    }
}
/**
10
1 1 1 1 1 1 1 1 1 1
**/