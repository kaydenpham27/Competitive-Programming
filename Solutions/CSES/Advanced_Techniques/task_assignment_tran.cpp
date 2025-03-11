#include <bits/stdc++.h>
//#define int long long
 
using namespace std;
 
const int INF = 1e9;
struct Dinitz {
    struct Edge { // u -> v
        int u, v, cost, cap, flow=0;
    };
 
    vector<Edge> edges;
    vector<vector<int>> g;
    vector<int> dist, ptr; // uses dist instead of level
    vector<int> flow_through;
 
    int n, src, sink;
    Dinitz(int nn, int s, int t){
        this->n = nn + 1;
        src = s;
        sink = t;
        g.resize(n);
    }
 
    void addEdge(int u, int v, int cost, int cap, bool trace = false, int rcap = 0) { // rcap = retrocapacity for bidiretional edges
        g[u].push_back( (int)edges.size() );
        if (trace) flow_through.push_back(edges.size());
        edges.push_back({u, v, cost, cap});
 
        g[v].push_back( (int)edges.size() );
        edges.push_back({v, u, -cost, rcap});
    }
 
    bool find_augment_path() {
        dist.assign(n, INF);
        vector<bool> inqueue(n, false);
 
        queue<int> q; q.push(src);
        dist[src] = 0;
        inqueue[src] = true;
 
        while (!q.empty()) {
            int u = q.front(); q.pop();
            inqueue[u] = false;
 
            for (auto eid : g[u]) {
                auto const& e = edges[eid];
                if (e.flow >= e.cap) continue;
                if (dist[e.u] + e.cost < dist[e.v]) {
                    dist[e.v] = dist[e.u] + e.cost;
                    if (!inqueue[e.v]) {
                        q.push(e.v);
                        inqueue[e.v] = true;
                    }
                }
            }
        }
        return dist[sink] != INF;
    }
 
    int min_cost = 0;
    int dfs(int u, int f) {
        if (f == 0 or u == sink) return f;
        for (int &i = ptr[u]; i < (int)g[u].size();) {
            int eid = g[u][i++];
            auto &e = edges[eid];
            if(e.flow >= e.cap or (dist[e.u] + e.cost) != dist[e.v]) continue;
            int newf = dfs(e.v, min(f, e.cap - e.flow));
            if (newf == 0) continue;
            e.flow += newf;
            edges[eid^1].flow -= newf;
            min_cost += e.cost * newf;
            return newf;
        }
        return 0;
    }
 
    int max_flow = 0;
    pair<int, int> getFlow(bool reset_flow_cost = true) {
        if (reset_flow_cost) {
            max_flow = 0;
            min_cost = 0;
            for(int u=0; u<n; u++) {
                for(auto eid : g[u]) {
                    auto &e = edges[eid];
                    e.flow = 0;
                }
            }
        }
        while (find_augment_path()) {
            ptr.assign(n, 0);
            while (int newf = dfs(src, INF))
                max_flow += newf;
        }
        return {min_cost, max_flow};
    }
};
 
 
const int O = 2e2 + 5;
 
int n, m, k, c[O][O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("input.in", "r")){
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
 
    cin >> n;
 
    int source = 2 * n + 1, sink = 2 * n + 2;
    Dinitz flow(sink + 2, source, sink);
 
    vector<pair<int, int>> p;
    for (int i = 1; i <= n; ++ i){
        flow.addEdge(source, i, 0, 1);
        flow.addEdge(n + i, sink, 0, 1);
        for (int j = 1; j <= n; ++ j){
            cin >> c[i][j];
            flow.addEdge(i, n + j, c[i][j], 1, 1);
            p.push_back({i, j});
        }
    }
 
    auto [cost, ans] = flow.getFlow();
 
    cout << cost << "\n";
    for (int i = 0; i < p.size(); ++ i){
        if (flow.edges[flow.flow_through[i]].flow) cout << p[i].first << " " << p[i].second << "\n";
    }
}