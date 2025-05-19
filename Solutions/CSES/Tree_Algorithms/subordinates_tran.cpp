#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
 
int n, E[O], child[O];
vector <int> g[O];
 
void dfs(int u){
    child[u] = 1;
    for (int i : g[u]){
        int v = E[i] ^ u;
        dfs(v);
        child[u] += child[v];
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; ++ i){
        int x; cin >> x;
        g[x].push_back(i);
        E[i] = x ^ i;
    }
    dfs(1);
    for (int i = 1; i <= n; ++ i) cout << child[i] - 1 << " ";
}