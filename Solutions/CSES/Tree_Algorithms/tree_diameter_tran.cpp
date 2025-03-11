#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vi vector<int>
 
using namespace std;
 
const int O = 2e5 + 5;
const int N = 4e5 + 5;
const int mod = 998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n, h[O];
vector <int> g[O];
 
void dfs(int u, int par = 0){
    for (int v : g[u]){
        if (v != par){
            h[v] = h[u] + 1;
            dfs(v, u);
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
    int Max = 1;
    for (int i = 1; i <= n; ++ i){
        if (h[Max] < h[i]) Max = i;
    }
 
    h[Max] = 0;
    dfs(Max);
    int res = 0;
    for (int i = 1; i <= n; ++ i) res = max(res, h[i]);
    cout << res;
}
/**
**/