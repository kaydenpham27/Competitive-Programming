mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
const int MAXN = 2e6 + 50;
const int INF = 1e9;
const int64_t MOD = (1LL << 61) - 1;
const int64_t BASE = uniform_int_distribution<int64_t>(0, MOD - 1)(rng);
 
__int128 mul(int64_t a, int64_t b) { return (__int128)a * b; }
int64_t mod_mul(int64_t a, int64_t b) { return mul(a, b) % MOD; }
 
int64_t Hash[MAXN], InvHash[MAXN], Pow[MAXN];
int64_t calc(int64_t l, int64_t r) { return (Hash[r] - mod_mul(Hash[l], Pow[r - l]) + MOD) % MOD; }
int64_t invcalc(int64_t l, int64_t r) { return (InvHash[r] - mod_mul(InvHash[l], Pow[r - l]) + MOD) % MOD; }
bool checkpal(int L, int R) {
    return calc(L - 1, R) == invcalc(N - R, N - L + 1);
}
