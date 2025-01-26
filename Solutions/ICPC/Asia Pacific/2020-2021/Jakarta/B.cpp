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

const int MAXN = 2e5 + 10;
const int MOD = 235813;
const i64 INF = INT_MAX/2;

int N; i64 a[MAXN], fact[MAXN], inv[MAXN];
int64_t Pow(int64_t x, int64_t e) {
  int64_t ans = 1;
  while (e) {
    if (e & 1) ans = (ans * x) % MOD;
    x = (x * x) % MOD;
    e >>= 1LL;
  }
  return ans % MOD;
}
int64_t C(int N, int K) {
    return fact[N] * inv[K] % MOD * inv[N - K] % MOD;
}
void Add(int &x, int y){
  x += y;
  if (x >= MOD) x -= MOD;
  if (x < 0) x += MOD;
}
void Solve(void) {  
  cin >> N;
  for (int i = 1; i <= N; i ++) cin >> a[i];
  fact[0] = inv[0] = 1;
  for (int i = 1; i <= N; i ++) {
    fact[i] = (fact[i - 1] * i) % MOD;
    inv[i] = Pow(fact[i], MOD - 2);
  }
  i64 sum = 0; int mul = 1;
  for (int i = N; i >= 1; i --) {
    // cout << C(N - 1, i - 1) << "\n";
    sum = (sum + C(N - 1, i - 1) * mul * a[i] % MOD) % MOD;
    mul = -mul;
  }
  mul = 1;
  int ans = 0;
  // cout << sum << "\n";
  for (int i = N; i >= 1; i --) {
    i64 coef = C(N - 1, i - 1);
    i64 curSum = (sum - coef * mul * a[i] % MOD) % MOD; 
    curSum = (-curSum + MOD) % MOD;
    i64 x = mul * coef % MOD;
    x = (x + MOD) % MOD;
    i64 v = curSum * Pow(x, MOD - 2) % MOD;
    bool works = false;
    for (int j = -1; j <= 1; j ++) {
      i64 nv = v + j * MOD;
      if (abs(nv) <= 100000 && nv != a[i]) {
        works = true;
      }
    }
    ans += works;
    mul = -mul;
  }
  cout << ans << "\n";
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