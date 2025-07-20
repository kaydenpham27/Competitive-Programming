#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 2e5 + 5;
const int MAXW = 1e6;

// Insert an element randomly in an array efficiently
// Treap/Splay Tree/Balanced BST/Reverse inserting into a Segment Tree

int sz[4 * MAXN], a[MAXN];
void insert(int id, int l, int r, int p, int v) {
  sz[id] ++;
  if (l == r) {
    // cout << l << " " << v << "\n";
    a[l] = v;
    return;
  }
  int mid = (l + r)/2;
  if (mid - l + 1 - sz[id * 2] > p) insert(id * 2, l, mid, p, v);
  else insert(id * 2 + 1, mid + 1, r, p - (mid - l + 1 - sz[id * 2]), v);
}

void Solve(void) {
  int N; cin >> N;
  vector<int> B(N);
  for (int i = 0; i < N; i ++) cin >> B[i];
  swap(B[0], B[B[N - 1] % (N - 1)]);

  int id = 0;
  for (int i = 0; i < N; i ++) {
    insert(1, 1, N, id, B[i]);
    if (i < N - 1) id = (id + B[i] - 1) % (N - i - 1);
    // find the id-th empty element
  }

  for (int i = 1; i <= N; i ++) cout << a[i] << "\n";

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