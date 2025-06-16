#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 1e3 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

int N, R, M;

struct Dinic {
  // Complexity O(V^2 * E), strongly polynomial algo (independent from max flow value)
  // Template from: https://github.com/ShahjalalShohag/code-library/blob/main/Graph%20Theory/Dinics%20Algorithm.cpp
  const i64 inf = (1LL << 61);
  struct edge {
    int to, rev;
    long long flow, w;
    int id;
  };
  int n, s, t, mxid;
  vector<int> d, flow_through;
  vector<int> done;
  vector<vector<edge>> g;
  Dinic() {}
  Dinic(int _n) {
    n = _n + 10;
    mxid = 0;
    g.resize(n);
  }
  void add_edge(int u, int v, long long w, int id = -1) {
    edge a = {v, (int)g[v].size(), 0, w, id};
    edge b = {u, (int)g[u].size(), 0, 0, -2};//for bidirectional edges cap(b) = w
    g[u].emplace_back(a);
    g[v].emplace_back(b);
    mxid = max(mxid, id);
  }
  bool bfs() {
    d.assign(n, -1);
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &e : g[u]) {
        int v = e.to;
        if (d[v] == -1 && e.flow < e.w) d[v] = d[u] + 1, q.push(v);
      }
    }
    return d[t] != -1;
  }
  long long dfs(int u, long long flow) {
    if (u == t) return flow;
    for (int &i = done[u]; i < (int)g[u].size(); i++) {
      edge &e = g[u][i];
      if (e.w <= e.flow) continue;
      int v = e.to;
      if (d[v] == d[u] + 1) {
        long long nw = dfs(v, min(flow, e.w - e.flow));
        if (nw > 0) {
          e.flow += nw;
          g[v][e.rev].flow -= nw;
          return nw;
        }
      }
    }
    return 0;
  }
  long long max_flow(int _s, int _t) {
    s = _s;
    t = _t;
    long long flow = 0;
    while (bfs()) {
      done.assign(n, 0);
      while (long long nw = dfs(s, inf)) flow += nw;
    }
    flow_through.assign(mxid + 10, 0);
    for(int i = 0; i < n; i++) for(auto e : g[i]) if(e.id >= 0) flow_through[e.id] = e.flow;
    return flow;
  }
  void traceback(void) {
  }
};

void Solve(void) {
  cin >> N >> R >> M;
  Dinic graph(N + 2);
  vector<int> diff(N + 2, 0), w(R + 2, 0);
  for (int i = 1; i <= R; i ++) {
    int u, v; cin >> u >> v >> w[i];
    diff[u] -= w[i];
    diff[v] += w[i];
    graph.add_edge(u, v, 1, i);
  }

  int add = 0;
  for (int i = 1; i <= N; i ++) {
    if (diff[i] > 0) {
      add ++;
      graph.add_edge(i, N + 1, diff[i]/M, R + add);
    } else if (diff[i] < 0) {
      add ++;
      graph.add_edge(0, i, -diff[i]/M, R + add);
    }
  }

  graph.max_flow(0, N + 1);
  for (int i = 1; i <= R; i ++) {
    cout << -graph.flow_through[i] * M + w[i] << "\n";
  }
}

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}
