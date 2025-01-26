// FPT UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 2e3 + 10;
const int MOD = 998244353;
const i64 INF = INT_MAX/2;

struct DSU{
  int N, ccp;
  vector<int> lab, sz;
  vector<int64_t> sum;
  DSU(int _N) : N(_N), ccp(_N), sum(N + 5, 0), sz(_N + 5, 1), lab(_N + 5) {
    for (int i = 1; i <= N; i ++) {
      lab[i] = i;
    }
  }; 
  int findLab(int u) { return (u == lab[u] ? u : lab[u] = findLab(lab[u])); }
  bool unite(int u, int v, int64_t w) {
    int labu = findLab(u);
    int labv = findLab(v);
    if (labu == labv) return false;
    if (sz[labu] < sz[labv]) swap(labu, labv);
    sz[labu] += sz[labv];
    lab[labv] = labu;
    sum[labu] += sum[labv] + w;
    ccp --;
    return true;
  }
};
int N, K, to[MAXN], m[MAXN], c[MAXN], w[MAXN]; vector<int> compress;
int getPos(int v) {
  return lower_bound(all(compress), v) - compress.begin();
}
void Solve(void) {  
  cin >> N >> K;
  vector<vector<int>> b(N + 1);
  vector<pair<int, int>> edges;
  vector<pair<int, int>> assigned(K + 3, mp(0, 0));
  for (int i = 1; i <= N; i ++) {
    cin >> to[i] >> m[i];
    edges.pb(mp(i, to[i]));
    for (int j = 1; j <= m[i]; j ++) {
      int x; cin >> x; 
      b[i].pb(x);
      compress.pb(x);
    }
  }
  for (int i = 1; i <= K; i ++) {
    cin >> c[i];
    compress.pb(c[i]);
  }
  sort(all(compress)); compress.erase(unique(all(compress)), compress.end());
  int sz = compress.size();
  vector<vector<int>> workers(sz + 2), have(sz + 2);
  vector<int> cnt(sz + 2, 0);
  for (int i = 1; i <= K; i ++) {
    c[i] = getPos(c[i]);
    workers[c[i]].pb(i);
    cnt[c[i]] ++;
  }
  for (int i = 1; i <= N; i ++) {
    for (auto &x : b[i]) {
      x = getPos(x);
      w[i] += cnt[x];
      have[x].pb(i);
    }
  }
  DSU city(N);
  while (!edges.empty()) {
    sort(all(edges), [&](pair<int, int> &p, pair<int, int> &q) {
      return w[p.first] > w[q.first];
    });
    // for (auto [u, v] : edges) {
    //   if (city.findLab(u) == city.findLab(v)) continue;
    //   for (auto x : b[u]) {
    //     if (!workers[x].empty()) {
    //       city.unite(u, v, 0);
    //       // cout << workers[x].back() << "\n";
    //       assigned[workers[x].back()] = mp(u, v);
    //       workers[x].pop_back();
    //       break;
    //     }
    //   }
    // }
    // cout << edges.size() << "\n";
    while (!edges.empty() && city.findLab(edges.back().first) == city.findLab(edges.back().second)) {
      edges.pop_back();
    }
    bool works = true;
    if (!edges.empty()) {
      auto [u, v] = edges.back();
      sort(all(b[u]), [&](int x, int y) {
        return workers[x].size() > workers[y].size();
      });
      for (auto x : b[u]) {
        if (!workers[x].empty()) {
          city.unite(u, v, 0);
          assigned[workers[x].back()] = mp(u, v);
          for (auto id : have[x]) w[id] --;
          workers[x].pop_back();
          edges.pop_back();
          works = false;
          break;
        }
      }
    }
    if (works) break;
  }
  if (city.ccp != 1) {
    cout << -1 << "\n";
    return;
  }
  for (int i = 1; i <= K; i ++) {
    cout << assigned[i].first << " " << assigned[i].second << "\n";
  }
}
signed main() {
  // ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}
