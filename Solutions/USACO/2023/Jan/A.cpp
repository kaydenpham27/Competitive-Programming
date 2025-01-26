#include<bits/stdc++.h>
using namespace std;

#define int64_t long long
#define mp make_pair
#define all(x) (x).begin(), (x).end()

const int64_t INF = 1e18;
struct Node {
    char lab;
    int64_t sz;
    Node *l, *r;
    void print(int64_t start, int64_t end) {
        start = max(start, 1LL);
        end = min(end, sz);
        if (start > end) return;
        if (lab != '#') cout << lab;
        else {
            l->print(start, end);
            r->print(start - l->sz, end - l->sz);
        }
    }
};

Node* trie[26];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int64_t L, R; int N; cin >> L >> R >> N;
    vector<pair<char, string>> ops;
    for (int i = 0; i < N; i ++) {
        char c; string S; cin >> c >> S;
        ops.push_back(mp(c, S));
    }
    for (int c = 0; c < 26; c ++) {
        trie[c] = new Node{char(c + 'a'), 1};
    }
    for (int i = N - 1; i >= 0; i --) {
        Node* res = nullptr;
        for (auto c : ops[i].second) {
            if (res == nullptr) {
                res = trie[c - 'a'];
            } else {
                res = new Node {
                    '#', 
                    min(INF, res->sz + trie[c - 'a']->sz),
                    res,
                    trie[c - 'a']
                };
            }
        }
        trie[ops[i].first - 'a'] = res;
    }
    trie[0]->print(L, R);
    cout << "\n";
}  
