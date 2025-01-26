#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
void Solve(void) {
  int N, K = 1; cin >> N >> K;
  ordered_set circle;
  for (int i = 1; i <= N; i ++) {
    circle.insert(i);
  }
  int pos = 0;
  while ((int)circle.size() > 0) {
    pos = (pos + K) % (int)circle.size();
    cout << (*circle.find_by_order(pos)) << " ";
    circle.erase((*circle.find_by_order(pos)));
    if ((int)circle.size() != 0) pos %= (int)circle.size();
  }
} 
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int Tests = 1; // cin >> Tests; 
  while (Tests --) {
    Solve();    
  }
}