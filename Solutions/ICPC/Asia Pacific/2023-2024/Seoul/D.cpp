#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 2e5 + 5;
const int MAXW = 1e6;

int N, to[200];
string S; 

pair<int, int> dnc(int l, int r) {
  int p = l;
  vector<pair<int, int>> a(3);
  for (int i = 0; i < 3; i ++) {
    if (p > r) {
      cout << -1 << "\n";
      exit(0);
    }
    if (S[p] == '(') {
      a[i] = dnc(p + 1, to[p] - 1);
      p = to[p] + 1;
    } else {
      a[i] = mp(S[p] - '0', 1);
      p ++;
    }
  }

  if (p != r + 1) {
    cout << -1 << "\n";
    exit(0);
  }
  
  i64 x = a[1].first * a[2].second;
  i64 y = a[1].second * a[2].first;
  i64 g = __gcd(x, y);
  x /= g;
  y /= g;

  x = x * a[0].second + a[0].first * y;
  y = y * a[0].second;

  g = __gcd(x, y);

  x /= g;
  y /= g;

  return mp(x, y);
}

void Solve(void) {
  cin >> N;
  cin.ignore();
  string NS;
  getline(cin, NS);
  
  for (auto x : NS) if (x != ' ') S += x;
  S = " " + S;

  int lst = -1;
  vector<int> closes;
  for (int i = N; i >= 1; i --) {
    if (S[i] == ')') closes.pb(i);
    if (S[i] == '(') {
      if (closes.empty()) {
        cout << -1 << "\n";
        return;
      }
      to[i] = closes.back();
      closes.pop_back();
    }
  }

  if (S[1] != '(' || S[N] != ')' || !closes.empty()) {
    cout << -1 << "\n";
    return;
  }

  auto p = dnc(2, N - 1);
  cout << p.first << " " << p.second << "\n";
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