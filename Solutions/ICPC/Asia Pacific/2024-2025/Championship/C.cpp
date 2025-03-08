// FPTU UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 4e5 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

vector<pair<int, int>> G[MAXN]; int col[MAXN], ans = 0; 
bool used[MAXN];
void calc(int u) {
  col[u] = 0;
  queue<int> q; q.push(u); while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto [v, id] : G[u]) {
      if (col[v] == -1) {
        col[v] = 1 - col[u];
        ans ++;
        used[id] = true;
        q.push(v);
      } else if ((col[v] == 1 - col[u]) && !used[id]) {
        ans ++;
        used[id] = true;
      }
    }
  }
}
void Solve(void) {
  int N, M; cin >> N >> M;
  for (int i = 1; i <= M; i ++) {
    int u, v; cin >> u >> v;
    G[u].pb(mp(v, i));
    G[v].pb(mp(u, i));
  }

  for (int i = 1; i <= N; i ++) col[i] = -1;

  for (int i = 1; i <= N; i ++) {
    if (col[i] == -1) {
      calc(i);
    }
  }

  cout << ans + 1 << "\n";
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
