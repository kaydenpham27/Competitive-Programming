#include <bits/stdc++.h>
#define int long long

using namespace std;

const int O = 1e6 + 5;

int n, s, k, a[O], d[O], w[O];
int f[21][O];

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> s >> k;
    for (int i = 1; i < n; ++ i) cin >> d[i];
    for (int i = 1; i <= n; ++ i){
        cin >> w[i]; w[i] += w[i - 1];
        if (i > 1) a[i] = a[i - 1] + d[i - 1];
    }
    w[n + 1] = w[n];

    for (int i = 1; i <= n; ++ i){
        int x = upper_bound(a + 1, a + n + 1, a[i] + k) - a - 1;
        x = upper_bound(a + 1, a + n + 1, a[x] + k) - a - 1;
        f[0][i] = x;
    }
    for (int i = 0; i <= 20; ++ i) f[i][n + 1] = n;

    for (int i = 1; i <= 20; ++ i){
        for (int j = 1; j <= n; ++ j){
            if (n - j + 1 <= (1 << i)) f[i][j] = n;
            else{
                f[i][j] = f[i - 1][f[i - 1][j] + 1];
            }
        }
    }

    int res = 0, sta = 0;
    for (int i = 1; i <= n; ++ i){
        if (s >= n - i + 1 && w[n] - w[i - 1] > res){
            res = w[n] - w[i - 1];
            sta = i;
        }
        else{
            int x = i;
            for (int j = 0; j <= 20; ++ j){
                if (s >> j & 1) x = f[j][x] + 1;
            }
            x -= 1;
            if (w[x] - w[i - 1] > res){
                res = w[x] - w[i - 1];
                sta = i;
            }
        }
    }

    //cout << res << endl;

    vector <int> ans;
    if (s >= n - sta + 1){
        for (int i = sta; i <= n; ++ i) ans.push_back(i);

        cout << ans.size() << "\n";
        for (int i : ans) cout << i << " ";
        return 0;
    }

    for (int i = 1; i <= s; ++ i){
        int x = upper_bound(a + 1, a + n + 1, a[sta] + k) - a - 1;
        ans.push_back(x);
        sta = f[0][sta] + 1;
    }

    cout << ans.size() << "\n";
    for (int i : ans) cout << i << " ";
}