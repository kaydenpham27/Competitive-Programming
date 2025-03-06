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

int ask(int l, int r) {
  cout << "? " << l << " " << r << "\n";
  fflush(stdout);
  int x; cin >> x; return x;
}
int dnc(int l, int r, int p = -1) {
  if (l == r) return l;
  if (p == -1) p = ask(l, r);
  if (l == r - 1) return l + r - p;

  // Golden Ratio: (sqrt5 - 1)/2;
  int sz = max(2, 62 * (r - l + 1)/ 100);
  int l1, r1, l2, r2;
  if (p <= l + sz - 1) {
    l1 = l, r1 = l1 + sz - 1;
    l2 = l1 + sz, r2 = r;
  } else {
    l1 = r - sz + 1, r1 = r;
    l2 = l, r2 = l1 - 1;
  }
  int pp = ask(l1, r1);
  if (pp == p) return dnc(l1, r1, pp);
  return dnc(l2, r2, -1);
}
void Solve(void) {
  int N; cin >> N;
  int ans = dnc(1, N);
  cout << "! " << ans << "\n";
}
signed main() {
  // ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}
