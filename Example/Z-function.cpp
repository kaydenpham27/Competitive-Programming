/*
  Problem: https://codeforces.com/contest/1968/problem/G2
  Category: Z-function (Strings)
  Description: Using Z-function got AC, while using Hashing got TLE
*/
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
vector<int> z_function(string S) {
  int N = S.size();
  vector<int> z(N);
  int l = 0, r = 0;
  for (int i = 1; i < N; i ++) {
    if (i < r) {
      z[i] = min(r - i, z[i - l]);
    }
    while (i + z[i] < N && S[z[i]] == S[i + z[i]]) {
      z[i] ++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}
void Solve(void) {
  int N, L, R; cin >> N >> L >> R;
  string S; cin >> S;
  vector<int> z = z_function(S);
  vector<int> ans(N + 1, 0);
  
  int mx = 0;
  auto check = [&](int l, int grp) {
    if (l == 0) {
      mx = 0;
      return true;
    }
    int cnt = 1;
    for (int i = l; i < N; i ++) {
      if (z[i] >= l) {
        cnt ++;
        i += l - 1;
      }
    }
    mx = cnt;
    return (cnt >= grp);
  }; 
  
  for (int grp = 1; grp * grp <= N; grp ++) {
    int l = 1, h = N;
    while (l <= h) {
      int mid = (l + h)/2;
      if (check(mid, grp)) l = mid + 1;
      else h = mid - 1;
    }
    ans[grp] = h;
  }
  for (int l = 1; l * l <= N; l ++) {
    check(l, L);
    ans[mx] = max(ans[mx], l);
  }
  for (int i = N - 1; i >= 1; i --) {
    ans[i] = max(ans[i], ans[i + 1]);
  }
  for (int i = L; i <= R; i ++) cout << ans[i] << " \n"[i == R];
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; cin >> Tests;
  while (Tests --) {
    Solve();
  }
}
