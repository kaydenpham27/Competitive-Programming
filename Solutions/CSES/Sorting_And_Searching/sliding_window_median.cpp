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
  for (int i = 1; i <= N; i ++) {
    if (i > K) {
      if (smaller.find(a[i - K]) != smaller.end()) {
        smaller.erase(smaller.find(a[i - K]));
      } else {
        greater.erase(greater.find(a[i - K]));
      }
    }
    cin >> a[i];
    smaller.insert(a[i]);
    int tp = (*smaller.rbegin());
    smaller.erase(smaller.find(tp));
    greater.insert(tp);
 
    while ((int)greater.size() < (int)smaller.size()) {
      tp = (*smaller.begin());
      greater.insert(tp);
      smaller.erase(smaller.find(tp));
    }
 
    while ((int)greater.size() > (int)smaller.size()) {
      tp = (*greater.begin());
      smaller.insert(tp);
      greater.erase(greater.find(tp));
    }
 
    if (i >= K) {
      cout << (*smaller.rbegin()) << " ";
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