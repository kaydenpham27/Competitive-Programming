#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vi vector<int>
//#define push_back emplace_back
 
using namespace std;
 
const int O = 2e5 + 5;
const int N = 4e5 + 5;
const int mod = 998244353;
const int inf = 2e9 + 5;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n, dp[O];
vector <int> g[O];
pair <int, int> f[2][O];
 
void dfs(int u, int par = 0){
    for (int v : g[u]){
        if (v != par){
            dfs(v, u);
            if (f[0][v].first + 1 >= f[0][u].first){
                f[1][u] = f[0][u];
                f[0][u] = {f[0][v].first + 1, v};
            }
            else{
                if (f[0][v].first + 1 > f[1][u].first){
                    f[1][u] = {f[0][v].first + 1, v};
                }
            }
        }
    }
}
 
void dfs2(int u, int par){
    dp[u] = dp[par] + 1;
    dp[u] = max(dp[u], 1 + (u == f[0][par].second ? f[1][par].first : f[0][par].first));
    for (int v : g[u]){
        if (v != par){
            dfs2(v, u);
        }
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    dfs(1);
    for (int v : g[1]) dfs2(v, 1);
 
    for (int i = 1; i <= n; ++ i) cout << max(dp[i], f[0][i].first) << " ";
}
/**
 
**/