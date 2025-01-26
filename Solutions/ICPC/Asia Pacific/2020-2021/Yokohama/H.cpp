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

const int MAXN = 2e5 + 5;
const int MAXW = 1e6;

int N, Q, a[MAXN]; bitset<100001> G[MAXW + 10];
vector<int> dosth(int i, int op) {
  vector<int> res;
  int x = a[i];
  for (int j = 2; j * j <= x; j ++) {
    int cnt = 0;
    while (x % j == 0) {
      cnt ++;
    }
    int jj = 1; 
    if (op == 1) G[jj].insert(i);
    else if (op == 2) G[jj].erase(i);
    else res.pb(jj);
    for (int c = 1; c <= cnt; c ++) {
      jj = jj * j;
      if (op == 1) G[jj].insert(i);
      else if (op == 2) G[jj].erase(i);
      else res.pb(jj);
    }
  }
  return res;
}

void Solve(void) {
  cin >> N >> Q;
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    dosth(i, 1);
  }
  while (Q --) {
    char op; int l, r, k; cin >> op;
    if (op == 'Q') {
      cin >> l >> r >> k;
      vector<int> vs;
      int lcm = 0;
      for (int i = l; i <= min(l + 3, r); i ++) {
        vector<int> cur = dosth(i);
        for (auto x : cur) {
          auto p
        }
      }
    } else {
      cin >> l >> k;
      dosth(l, 2);
      a[l] = k;
      dosth(l, 1);
    }
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
