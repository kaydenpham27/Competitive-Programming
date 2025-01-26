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

const int MAXN = 4e6 + 1;
const int MOD = 998244353;
const i64 INF = INT_MAX/2;

int N, h[MAXN], root; vector<int> G[MAXN];
void dnc(int l, int r, int p) {
  if (l > r) return;
  int pos = l;
  for (int i = l; i <= r; i ++) {
    if (h[i] > h[pos]) {
      pos = i;
    }
  }
  if (p == -1) root = pos;
  if (p != -1) {
    G[p].pb(pos);
    G[pos].pb(p);
  }
  dnc(l, pos - 1, pos);
  dnc(pos + 1, r, pos);
}
int d[MAXN];
int bfs(int src) {
  for (int i = 1; i <= N; i ++) d[i] = -1;
  d[src] = 0;
  int bestv = src;
  queue<int> q; q.push(src); while (!q.empty()) {
    int u = q.front(); q.pop();
    for (auto v : G[u]) {
      if (d[v] == -1) {
        d[v] = d[u] + 1;
        if (d[v] > d[bestv]) {
          bestv = v;
        }
        q.push(v);
      }
    }
  }
  return bestv;
}
void Solve(void) {  
  cin >> N;
  for (int i = 1; i <= N; i ++) cin >> h[i];
  dnc(1, N, -1);
  int nroot = bfs(root);
  nroot = bfs(nroot);
  cout << d[nroot] << "\n";
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
