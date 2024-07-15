int64_t C(int N, int K) {
    return fact[N] * inv[K] % MOD * inv[N - K] % MOD;
}
int64_t divcom(int N, int M) {
    if (M == 0) return 1;
    return C(N + M - 1, M - 1);
}
