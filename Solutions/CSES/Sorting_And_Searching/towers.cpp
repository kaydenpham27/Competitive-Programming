#include <bits/stdc++.h>
#define int64_t long long
#define double long double
using namespace std;
using type = int64_t;
const long long mod = 1000000007, inf = 1e18;
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
void Minimize(int64_t &a, int64_t b) {if(b < a) a = b;}
void Maximize(int64_t &a, int64_t b) {if(b > a) a = b;}
void Add(int64_t& a, int64_t b) {a = a + b; a %= mod;}
void Dec(int64_t& a, int64_t b) {a = a - b + mod; a %= mod;}
 
int64_t Pow(int64_t x, int64_t e, int64_t M){
    int64_t ans = 1;
    while(e > 0){
        if(e & 1) ans = (ans * x) % M;
        x = (x * x) % M;
        e >>= 1LL;
    }
    return ans;
}
 
int64_t M;
struct Matrix{
    vector<vector<type>> data;
    int row() const {return data.size(); }
    int col() const {return data[0].size(); }
    auto & operator [] (int i) {return data[i]; }
    const auto & operator [] (int i) const {return data[i]; }
 
    Matrix() = default;
    Matrix(int r, int c): data(r, vector<type>(c)) {}
    Matrix(const vector<vector<type>> &d) : data(d){
 
    }
    friend ostream & operator << (ostream &out, const Matrix &d){
        for(auto x : d.data){
            for(auto y : x) out << y << ' ';
            out << '\n';
        }
        return out;
    }
 
    static Matrix identity(int64_t n){
        Matrix a = Matrix(n, n);
        while(n --) a[n][n] = 1;
        return a;
    }
 
    Matrix operator * (const Matrix &b){
        Matrix a = *this;
        assert(a.col() == b.row());
        Matrix c(a.row(), b.col());
        for(int i = 0; i < a.row(); i ++){
            for(int j = 0; j < b.col(); j ++){
                for(int k = 0; k < a.col(); k ++){
                    c[i][j] = (c[i][j] + (a[i][k] * b[k][j])%M)%M;
                }
            }
        }
        return c;
    }
 
    Matrix pow(int64_t e){
        assert(row() == col());
 
        Matrix base = *this, ans = identity(row());
        for(; e > 0; e >>= 1, base = base * base){
            if(e & 1) ans = ans * base;
        }
        return ans;
    }
};
 
struct Tree{
    int n;
    vector<int64_t>st;
    Tree(int _n, int64_t _v): n(_n), st(_n * 4, _v){};
 
    void update(int id, int l, int r, int pos, int64_t val){
        if(pos < l || pos > r) return;
        if(l == r){
            st[id] = val;
            return;
        }
        int mid = (l + r)/2;
        update(id * 2, l, mid, pos, val);
        update(id * 2 + 1, mid + 1, r, pos, val);
        st[id] = max(st[id * 2], st[id * 2 + 1]);
    }
    int64_t getSum(int id, int l, int r, int u, int v){
        if(v < l || u > r) return -inf;
        if(u <= l && r <= v){
            return st[id];
        }
        int mid = (l + r)/2;
        return max(getSum(id * 2, l, mid, u, v),
               getSum(id * 2 + 1, mid + 1, r, u, v));
    }
};
 
int64_t inv[500000], fact[500000];
int64_t C(int n, int k)
{
    return fact[n] * inv[n - k] % mod * inv[k] % mod;
}
 
int64_t Ways(int x, int y, int xe, int ye)
{
    return C(xe - x + ye - y, xe - x);
}
 
void Solve(void)
{
    int n; cin >> n;
    vector<int>a;
    for (int i = 1; i <= n; i ++) {
        int x; cin >> x;
        auto it = upper_bound(a.begin(), a.end(), x);
        if (it == a.end()) a.push_back(x);
        else (*it) = x;
    }
    cout << a.size();
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    if(fopen("palpath.in", "r")){
        freopen("palpath.in", "r", stdin);
        freopen("palpath.out", "w", stdout);
    }
    if(fopen("A.inp", "r")){
        freopen("A.inp", "r", stdin);
        freopen("A.out", "w", stdout);
    }
    int tc = 1;
    //cin >> tc;
    while(tc --){
        Solve();
    }
}