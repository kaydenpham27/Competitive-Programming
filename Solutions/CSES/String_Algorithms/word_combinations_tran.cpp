#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define vi vector<int>
 
using namespace std;
 
const int O = 5e3 + 5;
const int mod = 1e9 + 7;
const int inf = 998244353;
const int base = 301;
 
int n, f[O], len[O], sta[O];
bool sz[O * O];
map <int, bool> dd;
string s;
 
void Add(int &x, int y){
    x += y;
    if (x >= mod) x -= mod;
    if (x < 0) x += mod;
}
 
struct SuffixArray{
	vi sa, lcp, rsa;
	vector <vi> f;
	SuffixArray(string &s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
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
};
 
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    int m = s.size();
 
    cin >> n;
 
    if (n >= 5000){
        for (int i = 1; i <= n; ++ i){
            string t; cin >> t;
 
            sz[t.size()] = true;
            if (t.size() > m) continue;
 
            reverse(t.begin(), t.end());
 
            int cur = 0;
            for (char c : t){
                cur = (1ll * cur * base + c - 'a' + 1) % mod;
            }
 
            dd[cur] = true;
        }
 
        f[0] = 1;
 
        for (int i = 1; i <= m; ++ i){
            int cur = 0;
            for (int j = i - 1; j >= 0; -- j){
                cur = (1ll * cur * base + s[j] - 'a' + 1) % mod;
                if (!sz[i - j]) continue;
                if (dd[cur]) Add(f[i], f[j]);
            }
        }
 
        cout << f[m];
    }
    else{
        string nw = s;
        for (int i = 1; i <= n; ++ i){
            nw += "*";
            string t; cin >> t;
            sta[i] = nw.size();
            nw += t;
            len[i] = t.size();
            len[i] = t.size();
        }
 
        f[0] = 1;
 
        SuffixArray q(nw);
 
        for (int i = 1; i <= m; ++ i){
            for (int j = 1; j <= n; ++ j){
                if (i >= len[j]){
                    if (q.LCP(sta[j], i - len[j]) >= len[j]) Add(f[i], f[i - len[j]]);
                }
            }
        }
 
        cout << f[m];
    }
}