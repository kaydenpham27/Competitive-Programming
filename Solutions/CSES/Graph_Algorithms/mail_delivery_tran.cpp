#include <bits/stdc++.h>
using namespace std;
 
int n, m;
vector<vector<pair<int, int>>> g;
vector<int> path;
vector<bool> seen;
 
void dfs(int node) {
	while (!g[node].empty()) {
		auto [son, idx] = g[node].back();
		g[node].pop_back();
		if (seen[idx]) { continue; }
		seen[idx] = true;
		dfs(son);
	}
	path.push_back(node);
}
 
int main() {
	cin >> n >> m;
 
	vector<int> degree(n, 0);
	g.resize(n);
	degree.resize(n);
	seen.resize(m);
 
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		g[x].push_back({y, i});
		g[y].push_back({x, i});
		degree[x]++;
		degree[y]++;
	}
 
	for (int node = 0; node < n; node++) {
		if (degree[node] % 2) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	}
 
	dfs(0);
 
	if (path.size() != m + 1) {
		cout << "IMPOSSIBLE";
	} else {
		for (auto node : path) { cout << node + 1 << ' '; }
	}
}