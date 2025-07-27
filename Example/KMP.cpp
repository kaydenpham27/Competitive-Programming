/**
 * Problem: https://codeforces.com/problemset/problem/1721/E
 * Tag: KMP + String Automation 
 */
#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define i128 __int128
// #define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 2e6 + 10;
const int LG = 20;
const i64 INF = LLONG_MAX/2;

int prefl[MAXN], aut[MAXN][30];

void kmp(string S, int st) {
  for (int i = st; i < (int)S.size(); i ++) {
    int j = prefl[i - 1];
    while (j > 0 && S[i] != S[j]) {
      j = prefl[j - 1];
    }
    if (S[i] == S[j]) j ++;
    prefl[i] = j;
  }
}

void Solve(void) {
  string S; cin >> S;
  int N = (int)S.size();
  kmp(S, 1);

  // Automation to avoid amortised property of while loop in KMP
  // Similar to a finate state machine, where aut(i, c) indicates that number of characters 
  // has been matched from the start of the string (similar to prefl of KMP)
  for (int i = 0; i < N; i ++) {
    for (int c = 0; c < 26; c ++) {
      if (i > 0 && S[i] - 'a' != c) {
        aut[i][c] = aut[prefl[i - 1]][c];
      } else {
        aut[i][c] = i + (S[i] - 'a' == c);
      }
    }
  }

  int Q; cin >> Q; while (Q --) {
    string T; cin >> T;
    int M = (int)T.size();
    S += T;
    
    for (int i = N; i < N + M; i ++) {
      for (int c = 0; c < 26; c ++) {
        if (S[i] - 'a' != c) {
          aut[i][c] = aut[prefl[i - 1]][c];
        } else {
          aut[i][c] = i + (S[i] - 'a' == c);
        }
      }
      prefl[i] = aut[prefl[i - 1]][S[i] - 'a'];
      cout << prefl[i] << " ";
    } cout << "\n";
    
    for (int i = 0; i < M; i ++) S.pop_back();
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
