int LCA(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    int gap = h[u] - h[v];
    for (int j = 0; (1 << j) <= gap; j ++) {
        if (gap >> j & 1) {
            u = up[u][j];
        }
    }
    if (u == v) return u;
    for (int j = 20; j >= 0; j --) {
        if (up[u][j] != up[v][j]) {
            u = up[u][j];
            v = up[v][j];
        }
    }
    return up[u][0];
}
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[v] <= tout[u];
}
