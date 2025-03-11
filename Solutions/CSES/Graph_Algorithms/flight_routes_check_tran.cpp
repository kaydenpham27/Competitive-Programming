#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 4e5 + 5;
 
int n, m, dd[O];
vector <int> g[O], gr[O], order;
 
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
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
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
            rdfs(i);
 
            if (cnt > 0){
                cout << "NO\n";
                cout << i << " " << cnt;
                return 0;
            }
 
            cnt = i;
        }
    }
 
    cout << "YES";
}
/**
10
1 1 1 1 1 1 1 1 1 1
**/