#include <bits/stdc++.h>
//#define int long long
 
using namespace std;
 
//Works for both directed, undirected and with negative cost too
//doesn't work for negative cycles
//for undirected edges just make the directed flag false
//Complexity: O(min(E^2 *V log V, E logV * flow))
using T = int;
const T inf = 1LL << 30;
struct MCMF {
  struct edge {
    int u, v;
    T cap, cost;
    int id;
    edge(int _u, int _v, T _cap, T _cost, int _id) {
      u = _u;
      v = _v;
      cap = _cap;
      cost = _cost;
      id = _id;
    }
  };
  int n, s, t, mxid;
  T flow, cost;
  vector<vector<int>> g;
  vector<edge> e;
  vector<T> d, potential, flow_through;
  vector<int> par;
  bool neg;
  MCMF() {}
  MCMF(int _n) { // 0-based indexing
    n = _n + 10;
    g.assign(n, vector<int> ());
    neg = false;
    mxid = 0;
  }
  void add_edge(int u, int v, T cap, T cost, int id = -1, bool directed = true) {
    if(cost < 0) neg = true;
    g[u].push_back(e.size());
    e.push_back(edge(u, v, cap, cost, id));
    g[v].push_back(e.size());
    e.push_back(edge(v, u, 0, -cost, -1));
    mxid = max(mxid, id);
    if(!directed) add_edge(v, u, cap, cost, -1, true);
  }
  bool dijkstra() {
    par.assign(n, -1);
    d.assign(n, inf);
    priority_queue<pair<T, T>, vector<pair<T, T>>, greater<pair<T, T>> > q;
    d[s] = 0;
    q.push(pair<T, T>(0, s));
    while (!q.empty()) {
      int u = q.top().second;
      T nw = q.top().first;
      q.pop();
      if(nw != d[u]) continue;
      for (int i = 0; i < (int)g[u].size(); i++) {
        int id = g[u][i];
        int v = e[id].v;
        T cap = e[id].cap;
        T w = e[id].cost + potential[u] - potential[v];
        if (d[u] + w < d[v] && cap > 0) {
          d[v] = d[u] + w;
          par[v] = id;
          q.push(pair<T, T>(d[v], v));
        }
      }
    }
    for (int i = 0; i < n; i++) {
      if (d[i] < inf) d[i] += (potential[i] - potential[s]);
    }
    for (int i = 0; i < n; i++) {
      if (d[i] < inf) potential[i] = d[i];
    }
    return d[t] != inf; // for max flow min cost
    // return d[t] <= 0; // for min cost flow
  }
  T send_flow(int v, T cur) {
    if(par[v] == -1) return cur;
    int id = par[v];
    int u = e[id].u;
    T w = e[id].cost;
    T f = send_flow(u, min(cur, e[id].cap));
    cost += f * w;
    e[id].cap -= f;
    e[id ^ 1].cap += f;
    return f;
  }
  //returns {maxflow, mincost}
  pair<T, T> solve(int _s, int _t, T goal = inf) {
    s = _s;
    t = _t;
    flow = 0, cost = 0;
    potential.assign(n, 0);
    if (neg) {
      // Run Bellman-Ford to find starting potential on the starting graph
      // If the starting graph (before pushing flow in the residual graph) is a DAG,
      // then this can be calculated in O(V + E) using DP:
      // potential(v) = min({potential[u] + cost[u][v]}) for each u -> v and potential[s] = 0
      d.assign(n, inf);
      d[s] = 0;
      bool relax = true;
      for (int i = 0; i < n && relax; i++) {
        relax = false;
        for (int u = 0; u < n; u++) {
          for (int k = 0; k < (int)g[u].size(); k++) {
            int id = g[u][k];
            int v = e[id].v;
            T cap = e[id].cap, w = e[id].cost;
            if (d[v] > d[u] + w && cap > 0) {
              d[v] = d[u] + w;
              relax = true;
            }
          }
        }
      }
      for(int i = 0; i < n; i++) if(d[i] < inf) potential[i] = d[i];
    }
    while (flow < goal && dijkstra()) flow += send_flow(t, goal - flow);
    flow_through.assign(mxid + 10, 0);
    for (int u = 0; u < n; u++) {
      for (auto v : g[u]) {
        if (e[v].id >= 0) flow_through[e[v].id] = e[v ^ 1].cap;
      }
    }
    return make_pair(flow, cost);
  }
};
 
 
const int O = 2e5 + 5;
 
int n, m, k;
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    if (fopen("input.in", "r")){
        freopen("input.in", "r", stdin);
        freopen("output.out", "w", stdout);
    }
 
    cin >> n >> m >> k;
 
    int source = n + 1, sink = n + 2;
    MCMF flow(n + 3);
 
    flow.add_edge(source, 1, k, 0);
    for (int i = 1; i <= m; ++ i){
        int u, v, cost, cap; cin >> u >> v >> cap >> cost;
        flow.add_edge(u, v, cap, cost);
    }
    flow.add_edge(n, sink, k, 0);
 
    auto [ans, cost] = flow.solve(source, sink);
 
    if (ans != k) return cout << -1, 0;
    cout << cost;
}