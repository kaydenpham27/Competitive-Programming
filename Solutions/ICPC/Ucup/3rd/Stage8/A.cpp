// FPTU UWR
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 4e5 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

string N; int M;
string Min(string S, string T) {
  if (S == "") return T;
  if ((int)S.size() < (int)T.size()) return S;
  if ((int)S.size() > (int)T.size()) return T;
  for (int i = 0; i < (int)S.size(); i ++) {
    if (S[i] < T[i]) return S;
    if (S[i] > T[i]) return T;
  }
  return S;
}
void Solve(void) {
  cin >> N >> M;
  int sz = (int)N.size();
  i64 ans = 0;
  for (int i = 0; i < sz; i ++) {
    ans = (ans * 10 + N[i] - '0') % M;
  }
  ans = M - ans;
  
  string NN = to_string(ans);
  string NNN = N;
  
  reverse(all(NNN));
  reverse(all(NN));

  int rem = 0;
  for (int i = 0; i < max((int)NNN.size(), (int)NN.size()); i ++) {
    int d = rem;
    if (i < (int)NNN.size()) d += NNN[i] - '0';
    if (i < (int)NN.size()) d += NN[i] - '0';

    rem = 0;
    if (d >= 10) {
      d %= 10;
      rem ++;
    }
    NNN[i] = char(d + '0');
  }

  if (rem) NNN += '1';
  /// First string
  reverse(all(NNN));

  string MS = to_string(M);
  int szz = (int)MS.size();

  if (szz > sz) {
    cout << M << "\n";
    return;
  }

  vector<int> suff(sz + 2, 0);
  for (int i = sz - 1; i >= 0; i --) {
    suff[i] = suff[i + 1] + (N[i] != '9');
  }

  string cur = "";
  bool findEq = false; int findLa = -1;
  for (int i = sz - szz; i >= 0; i --) {
    int eq = 0;
    for (int j = i; j < i + szz; j ++) {
      if (MS[j - i] > N[j]) {
        eq = 1;
        break;
      } if (MS[j - i] < N[j]) {
        eq = -1;
        break;
      }
    }
    // if (eq == 0) {
    // }
    if (eq > 0 && (findLa == -1 || i >= findLa - szz)) {
      if (findLa == -1) findLa = i;
      string prevN = N;
      for (int j = i; j < i + szz; j ++) {
        N[j] = MS[j - i];
      }
      for (int j = i + szz; j < sz; j ++) {
        N[j] = '0';
      } 
      cur = Min(cur, N);
      N = prevN;
    } if (eq == 0 && i + szz < sz && suff[i + szz] && !findEq) {
      findEq = true;
      string prevN = N;
      for (int j = i; j < i + szz; j ++) {
        N[j] = MS[j - i];
      }
      bool found = false;
      for (int j = i + szz; j < sz; j ++) {
        if (found) N[j] = '0';
        if (N[j] != '9' && !found && !suff[j + 1]) {
          found = true;
          N[j] = char(N[j] + 1);
        }
      } 
      // cout << N << "\n";
      cur = Min(cur, N);
      N = prevN;
      break;
    }
  }
  cout << Min(cur, NNN) << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}
