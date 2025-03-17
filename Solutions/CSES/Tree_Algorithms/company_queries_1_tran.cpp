#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vi vector<int>
//#define push_back emplace_back
 
using namespace std;
 
const int O = 3e5 + 5;
const int N = 4e5 + 5;
const int mod1 = /*1053818881; /*/998244353;
const int mod2 = 1045430273; //998244353;
const int inf = 2e9 + 5;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
 
int n, q, h[O], f[20][O];
vector <int> g[O];
 
void dfs(int u){
    for (int v : g[u]){
        h[v] = h[u] + 1;
        f[0][v] = u;
        dfs(v);
    }
}
 
int Lca(int u, int v){
    if (h[u] < h[v]) swap(u, v);
    for (int i = 19; i >= 0; -- i){
        if (h[u] - (1 << i) >= h[v]) u = f[i][u];
    }
 
    if (u == v) return u;
 
    for (int i = 19; i >= 0; -- i){
        if (f[i][u] != f[i][v]){
            u = f[i][u];
            v = f[i][v];
        }
    }
 
    return f[0][u];
}
 
int Jump(int u, int dist){
    for (int i = 19; i >= 0; -- i){
        if (u != -1 && (dist >> i & 1)) u = f[i][u];
    }
    return u;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);// srand(time(NULL));
    cin >> n >> q;
    for (int i = 2; i <= n; ++ i){
        int x; cin >> x;
        g[x].push_back(i);
    }
 
    memset(f, -1, sizeof(f));
    dfs(1);
    for (int i = 1; i < 20; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (f[i - 1][j] != -1) f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
 
    for (int i = 1; i <= q; ++ i){
        int u, v; cin >> u >> v;
        cout << Jump(u, v) << "\n";
        //cout << Lca(u, v) << "\n";
    }
}
/**
 
**/