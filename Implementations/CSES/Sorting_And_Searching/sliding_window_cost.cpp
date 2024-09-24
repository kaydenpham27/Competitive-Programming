#include<bits/stdc++.h>
using namespace std;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
void Solve(void) {
  multiset<int> smaller, greater;
  int N, K; cin >> N >> K;
  vector<int> a(N + 1);
  i64 sumlf = 0, sumrg = 0;
  for (int i = 1; i <= N; i ++) {
    if (i > K) {
      if (smaller.find(a[i - K]) != smaller.end()) {
        smaller.erase(smaller.find(a[i - K]));
        sumlf -= a[i - K];
      } else {
        greater.erase(greater.find(a[i - K]));
        sumrg -= a[i - K];
      }
    }
    cin >> a[i];
    sumlf += a[i];
    smaller.insert(a[i]);
    int tp = (*smaller.rbegin());
    smaller.erase(smaller.find(tp));
    sumlf -= tp;
    greater.insert(tp);
    sumrg += tp;
 
    while ((int)greater.size() < (int)smaller.size()) {
      tp = (*smaller.begin());
      greater.insert(tp);
      sumrg += tp;
      smaller.erase(smaller.find(tp));
      sumlf -= tp;
    }
 
    while ((int)greater.size() > (int)smaller.size()) {
      tp = (*greater.begin());
      smaller.insert(tp);
      sumlf += tp;
      greater.erase(greater.find(tp));
      sumrg -= tp;
    }
 
    if (i >= K) {
      int med = (*smaller.rbegin());
      i64 tot = 0;
      tot = tot + 1LL * (int)smaller.size() * med - sumlf;
      tot = tot + sumrg - 1LL * (int)greater.size() * med;
      cout << tot << " ";
    }
   }
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}