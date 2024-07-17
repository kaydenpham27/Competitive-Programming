/*
  Problem: https://codeforces.com/contest/319/problem/C
*/
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define double long double
#define mp make_pair
#define all(x) (x).begin(), (x).end()
struct ConvexHullTrick {
  int pos = 0;
  vector<i64> slopes;
  vector<i64> y_intercepts;

  // Returns true if the intersection of L1 and L3 is better than the intersection of L1 and L2
  double intersection(int lf, int rg) {
    return ((double) y_intercepts[lf] - y_intercepts[rg]) / ((double) slopes[rg] - slopes[lf]);
  }
  bool bad(int l1, int l2, int l3) {
    /* 
      y = slope * x + yint
      intersection(L1, L2) = (yint1 - yint2) / (slope2 - slope1);
      intersection(L1, L3) = (yint1 - yint3) / (slope3 - slope1);
      return true if intersection(L1, L3) < intersection(L1, L2)
    */
    return intersection(l1, l3) < intersection(l1, l2);
  }
  // Adds a new line (with lowest slope) to the structure
  void add(i64 slope, i64 yint) {
    slopes.push_back(slope);
    y_intercepts.push_back(yint);
    while (slopes.size() >= 3 && bad(slopes.size() - 3, slopes.size() - 2, slopes.size() - 1)) {
      slopes.erase(slopes.end() - 2);
      y_intercepts.erase(y_intercepts.end() - 2);
    }
  }
  /* 
    Returns the minimum y-coordinate of any intersection between a given vertical
    line and the lower envelope 
  */
  i64 calcY(int pos, i64 x) {
    return slopes[pos] * x + y_intercepts[pos];
  }
  i64 query(i64 x) {
    // If we removed what was the best line for the previous query, then the
    // newly inserted line is now the best for that query
    if (pos >= (int)slopes.size()) pos = (int)slopes.size() - 1;
    // Any better line must be to the right, since query values are non-decreasing
    while (pos < (int)slopes.size() - 1 && calcY(pos + 1, x) < calcY(pos, x)) pos ++;
    return calcY(pos, x); 
  } 
};
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N; cin >> N;
  vector<i64> a(N + 1), b(N + 1);
  for (int i = 1; i <= N; i ++) cin >> a[i];
  for (int i = 1; i <= N; i ++) cin >> b[i];

  if (N == 1) {
    cout << 0 << "\n";
    return 0;
  }

  ConvexHullTrick C;
  C.add(b[1], 0);
  for (int i = 2; i <= N; i ++) {
    i64 best = C.query(a[i]);
    C.add(b[i], best);
    if (i == N) cout << best << "\n";
  }
}

