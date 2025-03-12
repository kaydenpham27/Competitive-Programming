#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vi vector<int>

using namespace std;

const int O = 2e5 + 5;
const int N = 4e5 + 5;
const int mod = 998244353;
const int inf = 1e9;
int pr[] = {167772161, 469762049, 754974721, 1045430273, 1051721729, 1053818881};

int n, m;

struct SuffixArray{
	vi sa, lcp, rsa;
	vector <vi> f;
	SA(basic_string<int>& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1ll, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);

        reverse(sa.begin(), sa.end()); sa.pop_back();
        reverse(sa.begin(), sa.end());
        reverse(lcp.begin(), lcp.end()); lcp.pop_back(); lcp.pop_back();
        reverse(lcp.begin(), lcp.end());

        n -= 1;
        rsa.resize(n);
        rep(i, 0, n) rsa[sa[i]] = i;

        int bit = log2(n) + 1;
        f.resize(bit);
        rep(i, 0, bit) f[i].resize(n - 1);

        rep(i, 0, n - 1) f[0][i] = lcp[i];


        rep(i, 1, bit){
            for (int j = 0; j + (1 << i) - 1 < n - 1; ++ j){
                f[i][j] = min(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
            }
        }
	}

	int LCP(int i, int j){
        int l = min(rsa[i], rsa[j]);
        int r = max(rsa[i], rsa[j]) - 1;
        if (l > r) return inf;

        int len = log2(r - l + 1);
        return min(f[len][l], f[len][r - (1 << len) + 1]);
	}
} q;

basic_string<int> s;
vi sa, lcp, rsa, last;

main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i){
        int x; cin >> x;
        s += x;
    }
    q.SA(s);

    sa = q.sa;
    lcp = q.lcp;
    rsa = q.rsa;

    vi L, R;
    L.resize(n - 1);
    R.resize(n - 1);

    stack <int> S;
    for (int i = 0; i < n - 1; ++ i){
        while (S.size() && lcp[S.top()] >= lcp[i]) S.pop();
        L[i] = S.size() ? S.top() : -1;
        S.push(i);
    }

    while (S.size()) S.pop();
    for (int i = n - 2; i >= 0; -- i){
        while (S.size() && lcp[S.top()] >= lcp[i]) S.pop();
        R[i] = S.size() ? S.top() : n - 1;
        S.push(i);
    }

    int Max = n, pos = 0, len = n;
    for (int i = 0; i < n - 1; ++ i){
        if (lcp[i] * (R[i] - L[i]) > Max){
            Max = lcp[i] * (R[i] - L[i]);
            len = lcp[i];
            pos = sa[i];
        }
    }

    //cout << pos << " " << len << endl;

    vector <int> res;
    for (int i = pos; i < pos + len; ++ i) res.push_back(s[i]);

    cout << Max << "\n";
    cout << res.size() << "\n";
    for (int i : res) cout << i << " ";
}
/**
fffefff
0 1 1 2 2 3
0 -1 6
1 0 6
2 0 6
3 2 6
4 2 6
5 4 6
debug 0 0
debug 1 15
debug 3 6
49
aaazaaa
**/
