// FPTU UWR
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

const int MAXN = 3e5 + 5;
const int MAXW = 6e5 + 10;
const int INF = LLONG_MAX/2;

int N, M, K, f[2][MAXN]; double p[MAXN];
vector<pair<int, int>> G[MAXN];
void Dijk(int b, int st) {
  for (int i = 1; i <= N; i ++) f[b][i] = INF;
  f[b][st] = 0;

  priority_queue<pair<int, int>> pq; pq.push(mp(0, st)); while (!pq.empty()) {
    auto [D, u] = pq.top(); pq.pop();
    if (-D != f[b][u]) continue;

    for (auto [v, w] : G[u]) {
      if (f[b][v] > f[b][u] + w) {
        f[b][v] = f[b][u] + w;
        pq.push(mp(-f[b][v], v));
      }
    }
  }
}
void Solve(void) {
  cin >> N >> M >> K;
  for (int i = 1; i <= N; i ++) {
    int u, v, w; cin >> u >> v >> w;
    G[u].pb(mp(v, w));
    G[v].pb(mp(u, w));
  }

  Dijk(0, 1);
  Dijk(1, N);
  
  for (int i = 1; i <= K; i ++) {
    int u;
    cin >> u >> p[u];

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