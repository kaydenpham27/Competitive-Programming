tuple<int64_t, int64_t, int64_t> eucl(int64_t a, int64_t b) {
    /// ax + by = gcd(a, b)
    if (b == 0) {
        return {a, 1, 0};
    }
    int64_t k = a/b;
    auto [gcd, x, y] = eucl(b, a - k * b);
    return {gcd, y, x - k * y};
}
