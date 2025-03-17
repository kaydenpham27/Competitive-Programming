#include <bits/stdc++.h>

using namespace std;

const int O = 2e3 + 5;
const int N = 2e5 + 5;
const int inf = 1e9;

int n, s, maxK, f[O], dp[O], cnt[O];
vector <pair <int, int>> val[O];

struct triple{
    int v, w, k;
} a[N];

bool how_sort(triple x, triple y){
    if (x.w != y.w) return x.w < y.w;
    return x.v > y.v;
}

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(0));
    cin >> s >> n;
    /*s = rand() % 2000 + 1;
    n = rand() % 100 + 1;
    //cout << s << " " << n << endl;*/
    for (int i = 1; i <= n; ++ i){
        cin >> a[i].v >> a[i].w >> a[i].k;
        /*a[i].k = rand() % 10 + 1;
        a[i].v = rand() % O + 5;
        a[i].w = rand() % s + 1;
        //cout << a[i].v << " " << a[i].w << " " << a[i].k << endl;*/
        maxK = max(maxK, a[i].k);
    }

    sort(a + 1, a + n + 1, how_sort);

    /// sub 1, 2, 3
    if (n <= 100 && maxK <= 10){
        vector <pair <int, int>> b;
        for (int i = 1; i <= n; ++ i){
            for (int j = 1; j <= a[i].k; ++ j) b.push_back({a[i].v, a[i].w});
        }

        for (auto x : b){
            for (int i = 0; i <= s; ++ i) dp[i] = f[i];
            for (int i = 0; i <= s; ++ i){
                if (i >= x.second){
                    f[i] = max(f[i], dp[i - x.second] + x.first);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i <= s; ++ i) ans = max(ans, f[i]);
        cout << ans;// << " " << endl;
        return 0;
    }

    vector <pair <int, int>> b;
    for (int i = 1; i <= n; ++ i){
        int x = a[i].w;
        if (cnt[x] * a[i].w >= s) continue;

        int add = min(s / x, a[i].k);
        cnt[x] += add;

        for (int j = 1; j <= add; ++ j) b.push_back({a[i].v, x});
    }

    memset(f, 0, sizeof(f));
    for (auto x : b){
        for (int i = 0; i <= s; ++ i) dp[i] = f[i];
        for (int i = 0; i <= s; ++ i){
            if (i >= x.second) f[i] = max(f[i], dp[i - x.second] + x.first);
        }
    }

    int res = 0;
    for (int i = 0; i <= s; ++ i) res = max(res, f[i]);

    cout << res;
}
/***
10 5
12 4 6
9 8 3
16 4 9
10 1 2
13 3 8

***/