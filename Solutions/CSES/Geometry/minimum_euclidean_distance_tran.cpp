#include <bits/stdc++.h>
#define int long long
#define double long double
 
using namespace std;
 
const int inf = 1e18;
 
double sqr(double x) {
  return x * x;
}
double d(pair<double, double> x, pair<double, double> y) {
  return sqrt(sqr(x.first - y.first) + sqr(x.second - y.second));
}
 
pair<int, int> Closest_pair(vector<pair<double, double>>& a) {
  int n = a.size() - 1;
  sort(a.begin(), a.end());
  set<pair<pair<double, double>, int>> s;
 
  int j = 0;
  double dist = inf;
  int resx = 0, resy = n;
  for (int i = 0; i <= n; ++i) {
    while (j < i && a[j].first + dist <= a[i].first) {
      auto z = s.find(make_pair(make_pair(a[j].second, a[j].first), j));
      if (z != s.end()) s.erase(z);
      j += 1;
    }
 
    auto cur = s.lower_bound(make_pair(make_pair(a[i].second - 1, 0), 0));
    auto l = s.upper_bound(make_pair(make_pair(a[i].second - dist - 1, 0), 0));
    auto r = s.upper_bound(make_pair(make_pair(a[i].second + dist + 1, 0), 0));
 
    for (auto z = cur;; --z) {
      if (l == s.end()) break;
      if (z == s.end()) continue;
      if ((*z).first.first + dist <= a[i].second) break;
      swap(a[i].first, a[i].second);
      if (dist >= d((*z).first, a[i])) {
        dist = d((*z).first, a[i]);
        resx = (*z).second;
        resy = i;
      }
      swap(a[i].first, a[i].second);
      if (z == s.begin() || z == l) break;
    }
 
    for (auto z = cur;; ++z) {
      if (z == s.end()) break;
      if ((*z).first.first - dist >= a[i].second) break;
      swap(a[i].first, a[i].second);
      if (dist >= d((*z).first, a[i])) {
        dist = d((*z).first, a[i]);
        resx = (*z).second;
        resy = i;
      }
      swap(a[i].first, a[i].second);
      if (z == r) break;
    }
 
    s.insert(make_pair(make_pair(a[i].second, a[i].first), i));
  }
 
    //cout << fixed << setprecision(2) << a[resx].first << " " << a[resx].second << " " << a[resy].first << " " << a[resy].second << "\n";
  return make_pair(resx, resy);
}
 
const int O = 2e5 + 5;
 
int n, x[O], y[O];
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    vector <pair <double, double>> a;
    for (int i = 0; i < n; ++ i){
        cin >> x[i] >> y[i];
        a.push_back({x[i], y[i]});
    }
 
    auto [u, v] = Closest_pair(a);
 
    cout << (int)sqr(a[u].first - a[v].first) + (int)sqr(a[u].second - a[v].second);
}