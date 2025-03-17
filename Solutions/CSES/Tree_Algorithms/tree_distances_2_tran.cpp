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
 
int n, child[O], f[O], dp[O];
vector <int> g[O];
 
void dfs(int u, int par = 0){
    child[u] = 1;
    for (int v : g[u]){
        if (v != par){
            dfs(v, u);
            child[u] += child[v];
            f[u] += f[v] + child[v];
        }
    }
}
 
void dfs1(int u, int par){
    dp[u] = dp[par] + f[par] - f[u] - child[u] + n - child[u];
    for (int v : g[u]){
        if (v != par){
            dfs1(v, u);
        }
    }
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);// srand(time(NULL));
    cin >> n;
    for (int i = 1; i < n; ++ i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
 
    dfs(1);
    for (int v : g[1]) dfs1(v, 1);
 
    for (int i = 1; i <= n; ++ i) cout << f[i] + dp[i] << " ";
}
/**
 
**/