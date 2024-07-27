/*
  Problem: https://codeforces.com/contest/375/problem/D
*/
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
int N, Q, counter = 0, pos[100005], sum[100005], ans[100005], cnt[100005], color[100005], sz[100005], tin[100005], tout[100005]; 
vector<int> G[100005];
vector<pair<int, int>> qe[100005];
void dfs(int u, int par = -1) {
  sz[u] = 1;
  tin[u] = tout[u] = ++counter;
  pos[counter] = u;
  for (auto v : G[u]) {
    if (v != par) {
      dfs(v, u);
      sz[u] += sz[v];
    }
  }
  tout[u] = counter;
}
void sack(int u, int par = -1, int keep = 0) {
  int bigChild = -1;
  for (auto v : G[u]) {
    if (v != par) {
      if (bigChild == -1 || sz[v] > sz[bigChild]) {
        bigChild = v;
      }
    }
  }
  for (auto v : G[u]) {
    if (v != par && v != bigChild) {
      sack(v, u, 0);
    }
  }
  if (bigChild != -1) sack(bigChild, u, 1);
  for (auto v : G[u]) {
    if (v != par && v != bigChild) {
      for (int t = tin[v]; t <= tout[v]; t ++) {
        int ver = pos[t];
        sum[++cnt[color[ver]]] ++;
      }
    }
  }
  sum[++cnt[color[u]]] ++;
  for (auto [x, id] : qe[u]) {
    ans[id] = sum[x];
  }

  if (keep == 0) {
    for (int t = tin[u]; t <= tout[u]; t ++) {
      int ver = pos[t];
      sum[cnt[color[ver]] --] --;
    }
  }
}
void Solve(void) {
  cin >> N >> Q;
  for (int i = 1; i <= N; i ++) cin >> color[i];
  for (int i = 1; i < N; i ++) {
    int u, v; cin >> u >> v;
    G[u].pb(v);
    G[v].pb(u);
  }
  for (int i = 1; i <= Q; i ++) {
    int v, k; cin >> v >> k;
    qe[v].pb(mp(k, i));
  } dfs(1); sack(1); // cout << "\n";
  for (int i = 1; i <= Q; i ++) cout << ans[i] << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests;
  while (Tests --) {
    Solve();
  }
}
