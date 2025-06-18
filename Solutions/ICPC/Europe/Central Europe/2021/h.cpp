#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 1e3 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

struct Point {
  double deg, cosa, x, y;
};

bool operator<(const Point &a, const Point &b) {
  return a.deg < b.deg;
}

void Solve(void) {
  int R, F, N; cin >> R >> F >> N;
  vector<double> rs(R + 2);
  for (int i = 1; i <= R; i ++) {
    cin >> rs[i];
  }

  vector<Point> ps;

  for (int i = 1; i <= F; i ++) {
    double x, y; cin >> x >> y;
    double cosa = x/(sqrt(x * x + y * y));
    // cout << cosa << "\n";
    // cout << acos(cosa) * 180 / M_PI << "\n";
    double deg = acos(cosa) * 180 / M_PI;
    if (y < 0) deg = 360 - deg;
    ps.pb({deg, cosa, x, y});
  }

  sort(all(ps), [&](Point &x, Point &y) {
    return x.deg < y.deg;
  });

  for (auto p : ps) {
    // cout << p.x << " " << p.y << " " << p.deg << " " << p.cosa << "\n";
  }

  auto d = [&](pair<double, double> a, pair<double, double> b) {
    double f1 = a.first - b.first;
    double f2 = a.second - b.second;
    return sqrt(f1 * f1 + f2 * f2);
  };

  auto solveFor = [&](auto it, Point target) {
    Point cur = (*it);
    cout << "P " << cur.x << " " << cur.y << "\n";
    int l = 1, h = R; while (l <= h) {
      int mid = (l + h)/2;
      double y = cur.cosa * rs[mid] * (cur.y < 0 ? -1 : 1);
      double x = sqrtl(rs[mid] * rs[mid] - x * x) * (cur.x < 0 ? -1 : 1);
      if (y <= target.y) l = mid + 1;
      else h = mid - 1;
    }

    double y = cur.cosa * rs[l] * (cur.y < 0 ? -1 : 1);
    double x = sqrtl(rs[l] * rs[l] - x * x) * (cur.x < 0 ? -1 : 1);
    cout << "CHECK " << x << " " << y << "\n";

    double ans = 1e9;
    for (int i = 0; i < 2; i ++) {
      if (l && l <= R) {
        double y = cur.cosa * rs[l] * (cur.y < 0 ? -1 : 1);
        double x = sqrtl(rs[l] * rs[l] - x * x) * (cur.x < 0 ? -1 : 1);
        cout << l << " " << target.x << " " << target.y << " " << x << " " << y << "\n";
        ans = min(ans, d(mp(target.x, target.y), mp(x, y)));
      }
      l --;
    }
    return ans;
  };

  for (int i = 1; i <= N; i ++) {
    double x, y; cin >> x >> y;
    double cosa = x/(sqrt(x * x + y * y));
    double deg = acos(cosa) * 180 / M_PI;
    if (y < 0) deg = 360 - deg;

    Point curp = {deg, cosa, x, y};
    auto it = lower_bound(all(ps), curp);

    // cout << (*it).x << " " << (*it).y << " " << (*it).deg << " " << deg << "\n";

    double ans = 1e9;
    if (it != ps.end()) ans = min(ans, solveFor(it, curp));
    if (--it != ps.begin()) ans = min(ans, solveFor(it, curp));
    
    cout << ans << "\n";
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
