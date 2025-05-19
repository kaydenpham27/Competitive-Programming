// FPTU UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define int long long
#define double long double
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 3e5 + 5;
const int MAXW = 6e5 + 10;
const int INF = LLONG_MAX/2;

int N, M, a[MAXN]; bool c[3][3], d[MAXN]; int c0 = 0, c1 = 0, d0 = 0, d1 = 0;
void Solve(void) {
  cin >> N >> M;

  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    if (a[i] == 0) c0 ++;
    else c1 ++;
  }
  for (int i = 1; i <= M; i ++) {
    int u, v; cin >> u >> v;
    c[a[u]][a[v]] = c[a[v]][a[u]] = true;
    if (a[u] != a[v]) {
      d[u] = true;
      d[v] = true;
    }
  }

  if (!c0 || !c1) {
    cout << 1 << "\n";
    return;
  }
  if (!c[0][0] || !c[1][1]) {
    cout << 2 << "\n";
    return;
  }

  for (int i = 1; i <= N; i ++) {
    if (d[i]) {
      if (a[i] == 1) d1 ++;
      else d0 ++;
    }
  }

  if (d1 == 1 || d0 == 1) {
    cout << 4 << "\n";
    return;
  }

  cout << "infinity" << "\n";
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