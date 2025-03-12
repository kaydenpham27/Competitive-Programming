#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 3e6 + 5;
const int inf = 1e18;

int n, k, m, E[O], W[O], par[O];
vector <int> g[O];

priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> q;

vector <int> Dijktra(vector <int> S){
    vector <int> d(n);
    for (int i = 0; i < n; ++ i) d[i] = inf, par[i] = 0;

    for (int i : S){
        d[i] = 0;
        par[i] = i;
        q.push({0, i});
    }

    while (q.size()){
        int u = q.top().second;
        int dist = q.top().first;
        q.pop();

        if (dist != d[u]) continue;

        for (int i : g[u]){
            int v = u ^ E[i];
            int w = W[i];

            if (dist + w < d[v]){
                d[v] = dist + w;
                par[v] = par[u];
                q.push({dist + w, v});
            }
        }
    }

    return d;
}

array <int, 3> bestPair(vector <int> d){
    array <int, 3> res; res[2] = inf;
    for (int u = 0; u < n; ++ u){
        for (int i : g[u]){
            int v = u ^ E[i];
            int w = W[i];

            if (par[u] != par[v] && d[u] + d[v] + w < res[2]){
                res[0] = par[u];
                res[1] = par[v];
                res[2] = d[u] + d[v] + w;
            }
        }
    }
    return res;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; ++ i){
        int u, v, w; cin >> u >> v >> w;
        u -= 1; v -= 1;
        g[u].push_back(i);
        g[v].push_back(i);
        E[i] = u ^ v;
        W[i] = w;
    }

    vector <int> specials(k);
    for (auto &i : specials){
        cin >> i; i -= 1;
    }

    ///
    array <int, 3> P1 = bestPair(Dijktra(specials));

    vector <int> anoSpecials;
    for (int i : specials){
        if (i != P1[0] && i != P1[1]){
            anoSpecials.push_back(i);
        }
    }

    array <int, 3> P2 = bestPair(Dijktra(anoSpecials));
    ///
    int res = P1[2] + P2[2];

    vector <int> onlyP0 = {P1[0]};
    vector <int> onlyP1 = {P1[1]};
    vector <int> dist0 = Dijktra(onlyP0);
    vector <int> dist1 = Dijktra(onlyP1);

    set <pair <int, int>> Min;
    for (int i : specials){
        if (i != P1[0] && i != P1[1]){
            Min.insert({dist1[i], i});
        }
    }

    for (int i : specials){
        if (i != P1[0] && i != P1[1]){
            Min.erase({dist1[i], i});
            int minCost = (*Min.begin()).first;
            Min.insert({dist1[i], i});
            res = min(res, dist0[i] + minCost);
        }
    }

    cout << res;
}