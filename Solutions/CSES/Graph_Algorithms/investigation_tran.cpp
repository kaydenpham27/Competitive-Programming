#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector <int> g[n + 1], w[n + 1], d, f, Min, Max, par;
    for (int i = 1; i <= m; ++ i){
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back(v);
        w[u].push_back(c);
    }
    par.assign(n + 1, 0);
    d.assign(n + 1, 1e18);
    f.assign(n + 1, 0);
    Min.assign(n + 1, 1e18);
    Max.assign(n + 1, 0);
    d[1] = 0; f[1] = 1; Min[1] = 1; Max[1] = 1;
    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> q;
    q.push({0, 1});
    while (q.size()){
        int u = q.top().second;
        int du = q.top().first;
        q.pop();
        if (du != d[u]) continue;
        for (int i = 0; i < g[u].size(); ++ i){
            int v = g[u][i];
            int c = w[u][i];
            if (d[v] > du + c){
                d[v] = du + c;
                Min[v] = Min[u] + 1;
                Max[v] = Max[u] + 1;
                f[v] = f[u];
                q.push({d[v], v});
            }
            else{
                if (d[v] == du + c){
                    Min[v] = min(Min[v], Min[u] + 1);
                    Max[v] = max(Max[v], Max[u] + 1);
                    f[v] = (f[v] + f[u]) % 1000000007;
                }
            }
        }
    }
    cout << d[n] << " " << f[n] << " " << Min[n] - 1 << " " << Max[n] - 1;
}