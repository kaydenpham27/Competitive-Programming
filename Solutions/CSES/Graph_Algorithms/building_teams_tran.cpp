#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 5e5 + 5;
 
int n, m, dd[O];
vector <int> g[O];
 
void dfs(int u, int c = 0){
    dd[u] = c;
    for (int v : g[u]){
        if (dd[v] == -1){
            dfs(v, c ^ 1);
        }
        else{
            if (dd[v] == dd[u]){
                cout << "IMPOSSIBLE";
                exit(0);
            }
        }
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    memset(dd, -1, sizeof(dd));
 
    for (int i = 1; i <= n; ++ i){
        if (dd[i] == -1) dfs(i);
    }
 
    for (int i = 1; i <= n; ++ i) cout << dd[i] + 1 << " ";
}
/**
7 6
1 2 1
2 3 2
3 4 3
4 5 3
5 6 2
6 7 1
**/