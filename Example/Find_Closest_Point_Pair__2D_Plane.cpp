/**
 * Algo: https://cp-algorithms.com/geometry/nearest_points.html
 * Prob: https://codeforces.com/contest/429/problem/D
 */
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define i128 __int128
#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  
 
const int MAXN = 4e5 + 10;
const i64 INF = LLONG_MIN/2;

int N, a[MAXN]; pair<int, int> p[MAXN], t[MAXN]; int best = LLONG_MAX;
bool cmp_y(pair<int, int> &x, pair<int, int> &y) {
  return x.second < y.second;
};
void calc(pair<int, int> p, pair<int, int> q) {
  int x = p.first - q.first;
  int y = p.second - q.second;
  best = min(best, x * x + y * y);
}
void dnc(int l, int r) {
  if (r - l + 1 <= 3) {
    for (int i = l; i < r; i ++) {
      for (int j = i + 1; j <= r; j ++) {
        calc(p[i], p[j]);
      }
    }
    sort(p + l, p + r + 1, cmp_y);
    return;
  }

  int mid = (l + r)/2;
  int midx = p[mid].first;
  dnc(l, mid);
  dnc(mid + 1, r);

  // Only consider set B of (midx - h, midx + h), then sort B based on y-coord
  // This is classic merge step of Merge Sort
  // [a + l, a + m), [a + m, a + r)
  merge(p + l, p + mid + 1, p + mid + 1, p + r + 1, t + 1, cmp_y);
  copy(t + 1, t + (r - l + 1) + 1, p + l);

  int post = 0;
  for (int i = l; i <= r; i ++) {
    // Check pi from B only
    if ((p[i].first - midx) * (p[i].first - midx) < best) {
      for (int j = post; j >= 1 && (p[i].second - t[j].second) * (p[i].second - t[j].second) < best; j --) {
        calc(p[i], t[j]);
      }
      t[++post] = p[i];
    }
  }
}
void Solve(void) {
  cin >> N;
  for (int i = 1; i <= N; i ++) {
    cin >> a[i];
    p[i].first = i;
    p[i].second = p[i - 1].second + a[i];
  }

  sort(p + 1, p + N + 1, [&](pair<int, int> &x, pair<int, int> &y) {
    if (x.first != y.first) return x.first < y.first;
    return x.second < y.second;
  });
  dnc(1, N);  
  
  cout << best << "\n";
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
