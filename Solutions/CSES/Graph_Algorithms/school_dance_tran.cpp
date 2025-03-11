#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
const int O = 5e3 + 5;
 
int n, m, k, a[O], b[O];
 
struct DinicWS{
    const int inf = 1e18;
    const int MAXN = 5e3 + 5;
 
    struct edge {
        int a, b, f, c, id;
    };
 
    int n, m, s, t, lim;
    vector <edge> e;
    vector <int> d, pt, MinCut; // very important performance trick
    vector <vector <int>> g;
    long long flow = 0;
    queue <int> q;
 
    DinicWS(){}
    DinicWS(int _n, int source, int sink){
        n = _n + 10; s = source; t = sink;
        g.resize(n);
        d.resize(n);
        pt.resize(n);
        flow = 0;
    }
 
    void add_edge(int a, int b, int c, bool undirected = false, int id = 0) {
        edge ed;
 
        //keep edges in vector: e[ind] - direct edge, e[ind ^ 1] - back edge
 
        ed.a = a; ed.b = b; ed.f = 0; ed.c = c; ed.id = id;
        g[a].push_back(e.size());
        e.push_back(ed);
 
        ed.a = b; ed.b = a; ed.f = undirected ? 0 : c; ed.c = c; ed.id = 0;
        g[b].push_back(e.size());
        e.push_back(ed);
    }
 
    bool bfs() {
        for (int i = 1; i < n; i++)
            d[i] = inf;
        d[s] = 0;
        q.push(s);
        while (!q.empty() && d[t] == inf) {
            int cur = q.front(); q.pop();
            for (size_t i = 0; i < g[cur].size(); i++) {
                int id = g[cur][i];
                int to = e[id].b;
 
                //printf("cur = %d id = %d a = %d b = %d f = %d c = %d\n", cur, id, e[id].a, e[id].b, e[id].f, e[id].c);
 
                if (d[to] == inf && e[id].c - e[id].f >= lim) {
                    d[to] = d[cur] + 1;
                    q.push(to);
                }
            }
        }
        while (!q.empty())
            q.pop();
        return d[t] != inf;
    }
 
    bool dfs(int v, int flow) {
        if (flow == 0)
            return false;
        if (v == t) {
            //cout << v << endl;
            return true;
        }
        for (; pt[v] < g[v].size(); pt[v]++) {
            int id = g[v][pt[v]];
            int to = e[id].b;
 
            //printf("v = %d id = %d a = %d b = %d f = %d c = %d\n", v, id, e[id].a, e[id].b, e[id].f, e[id].c);
 
            if (d[to] == d[v] + 1 && e[id].c - e[id].f >= flow) {
                int pushed = dfs(to, flow);
                if (pushed) {
                    e[id].f += flow;
                    e[id ^ 1].f -= flow;
                    return true;
                }
            }
        }
        return false;
    }
 
    int dinic() {
        for (lim = (1 << 30); lim >= 1;) {
            if (!bfs()) {
                lim >>= 1;
                continue;
            }
 
            for (int i = 1; i < n; i++)
                pt[i] = 0;
 
            int pushed;
 
            while (pushed = dfs(s, lim)) {
                flow = flow + lim;
            }
 
            //cout << flow << endl;
        }
        return flow;
    }
 
    vector <pair <int, int>> MinimumCut(){
        vector <pair <int, int>> ans;
        /// after the dinic
 
        lim = 1;
        bfs();
 
        for (int i = 1; i < n; ++ i){
            if (d[i] != inf) MinCut.push_back(i);
        }
 
        for (int u : MinCut){
            for (int i : g[u]){
                int v = e[i].b;
 
                if (d[v] == inf) ans.push_back({u, v});
            }
        }
 
        return ans;
    }
};
 
main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    int source = n + m + 1;
    int sink = n + m + 2;
    DinicWS flow(n + m + 2, source, sink);
 
    for (int i = 1; i <= k; ++ i){
        int u, v; cin >> u >> v;
        flow.add_edge(u, n + v, 1);
    }
 
    for (int i = 1; i <= n; ++ i){
        flow.add_edge(source, i, 1);
    }
 
    for (int i = 1; i <= m; ++ i){
        flow.add_edge(n + i, sink, 1);
    }
 
    cout << flow.dinic() << "\n";
    for (auto i : flow.e){
        if (i.f && i.a <= n && i.b <= n + m) cout << i.a << " " << i.b - n << "\n";
    }
}