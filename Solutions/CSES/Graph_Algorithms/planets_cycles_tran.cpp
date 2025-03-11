#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 4e5 + 5;
 
int n, m, Time, d[O], f[O], dd[O], cmp[O];
vector <int> g[O], gr[O], comp, order;
 
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
    dd[cmp[u]] = 1;
    for (int v : g[u]){
        if (!dd[cmp[v]]){
            dfs(v);
        }
        if (cmp[u] != cmp[v]) f[cmp[u]] += f[cmp[v]];
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++ i){
        int v; cin >> v;
        g[i].push_back(v);
        gr[v].push_back(i);
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
 
            for (int j : comp) cmp[j] = cnt;
 
            f[cnt] = comp.size();
        }
    }
 
    memset(dd, 0, sizeof(dd));
    for (int i : order){
        if (!dd[cmp[i]]) dfs(i);
        //cout << "check " << i << " " << cmp[i] << endl;
    }
 
    for (int i = 1; i <= n; ++ i) cout << f[cmp[i]] << " ";
}
/**
10
1 1 1 1 1 1 1 1 1 1
**/