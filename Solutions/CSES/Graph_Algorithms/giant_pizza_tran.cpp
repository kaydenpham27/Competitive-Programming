#include <bits/stdc++.h>
 
using namespace std;
 
const int O = 3e5 + 5;
const int mod = 1e9 + 7;
 
int n, m, cnt, dd[O], res[O];
vector <int> g[O], group[O], gr[O], order, comp;
 
int neg(int x){
    return x + (x <= m ? m : -m);
}
 
void init(int u){
    dd[u] = 1;
    for (int v : g[u]){
        if (!dd[v]) init(v);
    }
    order.push_back(u);
}
 
void dfs(int u){
    dd[u] = cnt;
    for (int v : gr[u]){
        if (!dd[v]) dfs(v);
    }
    comp.push_back(u);
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i){
        char c, d; int u, v;
        cin >> c >> u >> d >> v;
        if (c == '-') u += m;
        if (d == '-') v += m;
 
        g[neg(u)].push_back(v);
        g[neg(v)].push_back(u);
 
        gr[v].push_back(neg(u));
        gr[u].push_back(neg(v));
    }
 
    for (int i = 1; i <= 2 * m; ++ i){
        if (!dd[i]) init(i);
    }
 
    memset(res, -1, sizeof(res));
    memset(dd, 0, sizeof(dd));
 
    //for (int i : order) cout << i << " "; cout << endl;
 
    reverse(order.begin(), order.end());
 
    for (int i : order){
        if (!dd[i]){
            cnt += 1;
            comp.clear();
            dfs(i);
            for (int j : comp){
                if (dd[j] == dd[neg(j)]) return cout << "IMPOSSIBLE", 0;
                /*int &x = res[(j > m ? neg(j) : j)];
                if (x == -1){
                    x = (j > m) ? 0 : 1;
                }*/
            }
 
            group[cnt] = comp;
        }
    }
 
    for (int i = cnt; i >= 1; -- i){
        for (int j : group[i]){
            int &x = res[(j > m ? neg(j) : j)];
            if (x == -1){
                x = (j > m) ? 0 : 1;
            }
        }
    }
 
    for (int i = 1; i <= m; ++ i){
        cout << (res[i] ? '+' : '-') << " ";
    }
}
/**
3 3
- 1 - 3
- 1 - 1
+ 1 + 3
**/