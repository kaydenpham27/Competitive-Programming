/*
  Problem: https://csacademy.com/contest/archive/task/squared-ends/statement/
*/
#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define double long double
#define mp make_pair
#define all(x) (x).begin(), (x).end()
/**
 * Author: Simon Lindholm
 * Date: 2017-04-20
 * License: CC0
 * Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
 * Useful for dynamic programming (``convex hull trick'').
 * Time: O(\log N)
 */
struct Line {
	mutable i64 k, m, p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(i64 x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const i64 inf = 1e18;
	i64 div(i64 a, i64 b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(i64 k, i64 m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	i64 query(i64 x) {
		// assert(!empty());
    if (empty()) return -inf;
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N, K; cin >> N >> K;
  vector<i64> a(N + 2);
  for (int i = 1; i <= N; i ++) cin >> a[i];
  vector<LineContainer> f(K + 2);
  f[0].add(2 * a[1], -a[1] * a[1]);
  i64 best = 0, ans = 0;
  for (int i = 1; i <= N; i ++) {
    for (int j = K; j >= 1; j --) {
      best = f[j - 1].query(a[i]) - a[i] * a[i];
      if (i == N && j == K) ans = best;
      if (i < N) f[j].add(2 * a[i + 1], best - a[i + 1] * a[i + 1]);
    }
  }
  cout << -ans;

}

