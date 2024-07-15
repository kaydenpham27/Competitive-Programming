struct Edge {
  int target, id;
  Edge (int _target, int _id) : target(_target), id(_id) {}
};
bool used[1000016];
list<int> euler_walk (vector<vector<Edge>>& G, int u) {
  list<int> ans;
  ans.pb(u);
  while (!G[u].empty()) {
    int v = G[u].back().target;
    int eid = G[u].back().id;
    G[u].pop_back();
    if (used[eid]) continue;
    used[eid] = true;
    u = v;
    ans.pb(u);
  }
  for (auto it = ++ans.begin(); it != ans.end(); it ++) {
    auto t = euler_walk(G, (*it));
    t.pop_back();
    ans.splice(it, t);
  }
  return ans;
}
