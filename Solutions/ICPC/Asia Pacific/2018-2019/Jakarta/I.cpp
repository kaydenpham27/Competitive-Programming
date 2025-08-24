// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define i128 __int128
#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  
#define sz(x) (int)x.size()

const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;
const i64 INF = LLONG_MAX/2;
const int BLOCK_SIZE = 320;

void Solve(void) {
  int lie = 0;
  int N; cin >> N;
  for (int i = 1; i <= N; i ++) {
    string S; cin >> S;
    if (S == "LIE") lie = 1 - lie;
  }
  cout << (lie ? "LIE" : "TRUTH") << "\n";
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