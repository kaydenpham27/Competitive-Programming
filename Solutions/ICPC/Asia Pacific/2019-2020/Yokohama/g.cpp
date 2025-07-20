#include<bits/stdc++.h>
  
using namespace std;
  
#define i64 long long
#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()  

const int MAXN = 4e5 + 10;
const int MOD = 998244353;
const i64 INF = LLONG_MIN/2;

string S[2003];
void Solve(void) {
  int N; cin >> N;
  unordered_map<string, int> dict;
  for (int i = 1; i <= N; i ++) {
    cin >> S[i];
    dict[S[i]] ++;
    S[i] = " " + S[i];
  }

  int ans = INT_MAX;

  priority_queue<array<int, 3>> pq;
  vector<vector<int>> f(N + 2, vector<int> (20, INT_MAX));
  for (int i = 1; i <= N; i ++) {
    int en = S[i].size() - 1;
    for (int st = 1; st < en; st ++) {
      string Sst = S[i].substr(1, st);
      if (dict[Sst]) {
        f[i][en - st] = st;
        pq.push({-st, i, en - st});
        // cout << i << " " << en - st << "\n";
      }
    }
    pq.push({0, i, en});
  }


  while (!pq.empty()) {
    array<int, 3> cur = pq.top(); pq.pop();
    int D = -cur[0];
    int i = cur[1];
    int need = cur[2];
    if (need == 0) {
      // cout << i << " " << D << "\n";
      ans = min(ans, D);
      // continue;
    }
    if (D > f[i][need]) continue;

    // cout << "ST " << i << " " << need << " " << D << "\n";

    int sz = (int)S[i].size() - 1;
    int st = sz - need + 1;
    for (int en = st; en <= sz; en ++) {
      string Smid = S[i].substr(st, en - st + 1);
      if (dict[Smid]) {
        int l = (int)Smid.size();
        if (f[i][sz - en] > f[i][need] + l) {
          f[i][sz - en] = f[i][need] + l;
          pq.push({-f[i][sz - en], i, sz - en});
        } 
      }
    }

    for (int j = 1; j <= N; j ++) {
      int szz = (int)S[j].size() - 1;

      for (int stt = 1; stt <= szz; stt ++) {
        string Smid = S[i].substr(st, need) + S[j].substr(1, stt);
        // cout << Smid << "\n";
        if (dict[Smid]) {
          int l = (int)Smid.size();
          // cout << f[j][szz - st] << " " << f[i][need] << " " << l << "\n";
          if (f[j][szz - stt] > f[i][need] + l) {
            f[j][szz - stt] = f[i][need] + l;
            pq.push({-f[j][szz - stt], j, szz - stt});
          }
        }
      }
    }
  }

  if (ans == INT_MAX) ans = 0;
  cout << ans << "\n";
}
signed main() {
  // ios_base::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(10);
  int Tests = 1; // cin >> Tests;    
  for (int i = 1; i <= Tests; i ++) {
    // cout << "Case " << i << ": ";
    Solve();    
  }
}