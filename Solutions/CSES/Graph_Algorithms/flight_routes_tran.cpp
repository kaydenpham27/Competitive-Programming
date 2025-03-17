#include <bits/stdc++.h>
#define ii pair <int, int>
#define fi first
#define se second
#define int long long
 
using namespace std;
 
const int O = 2e5 + 5;
const int mod = 998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};
 
int n, m, c, r, k;
vector <int> d[O];
vector <pair <int, int>> g[O];
 
priority_queue <ii, vector <ii>, greater <ii>> q;
 
bool check(vector <int> a, int x){
    if (a.size() == k){
        if (a.back() < x){
            return true;
        }
    }
 
    return false;
}
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++ i){
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        //g[v].push_back({u, w});
    }
 
    d[1].push_back(0);
    q.push(make_pair(0, 1));
 
    while (q.size()){
        auto [du, u] = q.top();
        q.pop();
 
        if (check(d[u], du)) continue;
 
        for (auto [v, w] : g[u]){
            if (d[v].size() < k){
                d[v].push_back(du + w);
                q.push({du + w, v});
                sort(d[v].begin(), d[v].end());
            }
            else{
                if (d[v].back() > du + w){
                    d[v].pop_back();
                    d[v].push_back(du + w);
                    q.push({du + w, v});
                    sort(d[v].begin(), d[v].end());
                }
            }
        }
    }
 
    for (int i = 0; i < k; ++ i){
        cout << d[n][i] << " ";
    }
 
}