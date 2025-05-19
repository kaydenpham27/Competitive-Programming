#include <bits/stdc++.h>

using namespace std;

const int O = 4e2 + 5;
const int mod = 998244353;
const int inf = 1e9;

int n, pre[3][O], f[3][O][O][O];
vector <int> pos[3];
string s;

void Maximize(int &x, int y){
    if (x < y) x = y;
}

void Minimize(int &x, int y){
    if (x > y) x = y;
}

void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s; s = " " + s;
    for (int i = 1; i <= n; ++ i){
        if (s[i] == 'R') pos[0].push_back(i);
        if (s[i] == 'G') pos[1].push_back(i);
        if (s[i] == 'Y') pos[2].push_back(i);
    }

    if (max({pos[0].size(), pos[1].size(), pos[2].size()}) > (n + 1) / 2) return cout << -1, 0;

    for (int i = 0; i <= n; ++ i){
        for (int j = 0; j <= n; ++ j){
            for (int z = 0; z <= n; ++ z)
                for (int l = 0; l < 3; ++ l) f[l][i][j][z] = inf;
        }
    }

    for (int i = 0; i < 3; ++ i){
        for (int j = 1; j <= n; ++ j)
            pre[i][j] = upper_bound(pos[i].begin(), pos[i].end(), j) - pos[i].begin() + 1;
    }

    int Rsize = pos[0].size();
    int Gsize = pos[1].size();
    int Wsize = pos[2].size();

    /// f[c][i][j][z] : - j is nums of green
    ///                 - z is nums of white
    ///

    for (int i = 0; i < 3; ++ i) f[i][0][0][0] = 0;

    for (int i = 1; i <= n; ++ i){
        for (int j = 0; j <= i && j <= (i + 1) / 2 && j <= Gsize; ++ j){
            for (int z = 0; z <= i - j && z <= (i + 1) / 2 && z <= Wsize; ++ z){
                int l = i - j - z;

                if (l > (i + 1) / 2 || l > Rsize) continue;

                int posR = pos[0][l - 1];
                int posG = pos[1][j - 1];
                int posW = pos[2][z - 1];

                /// Red
                if (j + z < i){
                    int x = pos[0][l - 1];

                    int G = pre[1][x];
                    int W = pre[2][x];

    //if (i == 1) cout << "vcl luon " << x << " " << G << " " << W << endl;

                    int val = max(0, max(0, j - G + 1) + max(0, z - W + 1) + x - i);

                    Minimize(f[0][i][j][z], min(f[1][i - 1][j][z], f[2][i - 1][j][z]) + val);
                }

                /// Green
                if (j){
                    int x = pos[1][j - 1];

                    int R = pre[0][x];
                    int W = pre[2][x];

                    int val = max(0, max(0, l - R + 1) + max(0, z - W + 1) + x - i);

                    Minimize(f[1][i][j][z], min(f[0][i - 1][j - 1][z], f[2][i - 1][j - 1][z]) + val);
                }

                /// White
                if (z){
                    int x = pos[2][z - 1];

                    int R = pre[0][x];
                    int G = pre[1][x];

                    int val = max(0, max(0, l - R + 1) + max(0, j - G + 1) + x - i);

                    Minimize(f[2][i][j][z], min(f[0][i - 1][j][z - 1], f[1][i - 1][j][z - 1]) + val);
                }

//cout << "debug " << i << " " << j << " " << z << " " << f[0][i][j][z] << " " << f[1][i][j][z] << " " << f[2][i][j][z] << endl;
            }
        }
    }

    int G = pos[1].size();
    int W = pos[2].size();
    cout << min({f[0][n][G][W], f[1][n][G][W], f[2][n][G][W]});
}