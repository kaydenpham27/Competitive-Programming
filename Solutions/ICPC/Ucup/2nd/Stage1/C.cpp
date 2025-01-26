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

const int MAXN = 1e5 + 5;
const int MAXW = 1e6;

int N, V[MAXN], K[MAXN]; string OP[MAXN]; vector<int> G[MAXN]; bool f[MAXN][300];
void Solve(void) {
  cin >> N;
  for (int i = 1; i <= N + 1; i ++) {
    G[i].clear();
    for (int j = 0; j < 256; j ++) {
      f[i][j] = false;
    }
  }
  for (int i = 1; i <= N; i ++) {
    cin >> OP[i];
    if (OP[i] != "add") {
      cin >> V[i] >> K[i];
    } else {
      cin >> V[i];
    }
  } 

  // Add edges
  for (int i = 1; i <= N; i ++) {
    G[i].pb(i + 1);
    if (OP[i] != "add") {
      G[i].pb(K[i]);
    }
  }

  deque<pair<int, int>> pq; pq.push_back(mp(1, 0));
  f[1][0] = true;
  while (!pq.empty()) {
    auto [u, j] = pq.front();
    pq.pop_front();
    for (auto v : G[u]) {
      if (OP[u] == "add") {
        int nxtj = (j + V[u]) % 256;
        if (!f[v][nxtj]) {
          f[v][nxtj] = true;
          pq.pb(mp(v, nxtj));
        }
      } else if (OP[u] == "beq") {
        if (j == V[u] && !f[K[u]][j]) {
          f[K[u]][j] = true;
          pq.pb(mp(K[u], j));
        } else if (j != V[u] && !f[u + 1][j]) {
          f[u + 1][j] = true;
          pq.pb(mp(u + 1, j));          
        }
      } else if (OP[u] == "bne") {
        if (j != V[u] && !f[K[u]][j]) {
          f[K[u]][j] = true;
          pq.pb(mp(K[u], j));
        } else if (j == V[u] && !f[u + 1][j]) {
          f[u + 1][j] = true;
          pq.pb(mp(u + 1, j));          
        }
      } else if (OP[u] == "blt") {
        if (j < V[u] && !f[K[u]][j]) {
          f[K[u]][j] = true;
          pq.pb(mp(K[u], j));
        } else if (j >= V[u] && !f[u + 1][j]) {
          f[u + 1][j] = true;
          pq.pb(mp(u + 1, j));          
        }
      } else {
        if (j > V[u] && !f[K[u]][j]) {
          f[K[u]][j] = true;
          pq.pb(mp(K[u], j));
        } else if (j <= V[u] && !f[u + 1][j]) {
          f[u + 1][j] = true;
          pq.pb(mp(u + 1, j));          
        }
      }
    }
  }
  for (int j = 0; j < 256; j ++) {
    if (f[N + 1][j]) {
      cout << "Yes" << "\n";
      return;
    }
  }
  cout << "No" << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}