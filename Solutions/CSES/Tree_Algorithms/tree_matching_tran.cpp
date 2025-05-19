#include <bits/stdc++.h>
#define int long long
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
 
int n, f[2][O];
vector <int> g[O];
 
void dfs(int u, int par = 0){
    int m = g[u].size();
 
    int sum = 0;
    for (int v : g[u]){
        if (v != par){
            dfs(v, u);
            sum += max(f[1][v], f[0][v]);
        }
    }
 
    f[0][u] = sum;
    for (int i = 0; i < m; ++ i){
        int v = g[u][i];
        if (v == par) continue;
 
        if (f[0][v] > f[1][v]) f[1][u] = max(f[1][u], sum + 1);
        else f[1][u] = max(f[1][u], sum - f[1][v] + f[0][v] + 1);
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
 
    cout << max(f[0][1], f[1][1]);
 
}
/**
 
**/