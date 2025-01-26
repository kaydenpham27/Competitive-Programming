#include<bits/stdc++.h>
using namespace std;

#define int long long
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

int N;
pair<int, int> p[304];
bitset<300> f[304][304];
int64_t cross(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
    // vector p12
    p2.first -= p1.first;
    p2.second -= p1.second;
    // vector p13
    p3.first -= p1.first;
    p3.second -= p1.second;
    // cross product of p12 and p13
    return p2.first * p3.second - p3.first * p2.second;
}
void Solve(void) {
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cin >> p[i].first >> p[i].second;
    }
    for (int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            for (int z = 0; z < N; z ++) {
                if (i != j && j != z && z != i) {
                    if (cross(p[i], p[j], p[z]) > 0) {
                        f[i][j][z] = 1;
                    }
                }
            }
        }
    }

    vector<int> ans(N, 0);
    for (int i = 0; i < N; i ++) {
        for (int j = i + 1; j < N; j ++) {
            for (int z = j + 1; z < N; z ++) {
                int a = i, b = j, c = z;
                if (cross(p[a], p[b], p[c]) < 0)  swap(b, c);
                auto currentset = (f[a][b] & f[b][c] & f[c][a]);
                ans[currentset.count()] ++;
            }
        }
    }
    for (int i = 0; i <= N - 3; i ++) cout << ans[i] << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
    int Tests = 1; // cin >> Tests; 
    while (Tests --) {
        Solve();    
    }
}