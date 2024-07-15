int64_t Pow(int64_t x, int64_t e) {
    int64_t ans = 1;
    while (e) {
        if (e & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        e >>= 1LL;
    }
    return ans % MOD;
}
