/**
 * Problem: https://codeforces.com/problemset/problem/420/D
 * Data Structure: Implicit Treap 
 */
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define i128 __int128
#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 1e6 + 10;
const i64 INF = LLONG_MAX/2;

struct ImplicitTreap {
  struct Node {
    int v, sz, prior;
    Node *l, *r;
    Node () {}
    Node (int _v) {
      v = _v, sz = 1, prior = rand(), l = r = nullptr;
    }
  };

  Node* root;
  Node* tl;
  Node* tr;
  ImplicitTreap() {
    root = tl = tr = nullptr;
  }

  int sz(Node* p) { 
    return p ? p->sz : 0; 
  }

  void upd_sz(Node* &p) {
    if (p) p->sz = sz(p->l) + sz(p->r) + 1;
  }

  void split(Node* p, int k, Node* &l, Node* &r) {
    if (!p) l = r = nullptr;
    else if (sz(p->l) + 1 <= k) split(p->r, k - sz(p->l) - 1, p->r, r), l = p;
    else split(p->l, k, l, p->l), r = p;
    upd_sz(p);
  }

  // Assuming that all key(l) <= all key(r)
  void merge(Node* &p, Node* l, Node* r) {
    if (!l || !r) p = l ? l : r;
    else if (l->prior >= r->prior) merge(l->r, l->r, r), p = l;
    else merge(r->l, l, r->l), p = r;
    upd_sz(p);
  }
};

void Solve(void) {
  int N, M; cin >> N >> M;
  ImplicitTreap T;

  for (int i = 1; i <= N; i ++) {
    T.merge(T.root, T.root, new ImplicitTreap::Node(i));
  }

  vector<int> lab(N + 2, -1), have(N + 2, 0);

  for (int i = 1; i <= M; i ++) {
    int x, y; cin >> x >> y;

    T.split(T.root, y, T.tl, T.root);
    T.split(T.tl, y - 1, T.tl, T.tr);

    if (lab[T.tr->v] == x) {
      
    } else if (lab[T.tr->v] == -1 && !have[x]) {
      lab[T.tr->v] = x;
    } else {
      cout << -1 << "\n";
      return;
    }
    have[x] ++;
    T.merge(T.tl, T.tr, T.tl);
    T.merge(T.root, T.tl, T.root);
  }

  int a = 1;
  for (int i = 1; i <= N; i ++) {
    while (have[a]) a ++;
    if (lab[i] != -1) cout << lab[i] << " ";
    else cout << a++ << " ";
  } cout << "\n";
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
