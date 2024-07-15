struct TrieBit {
    struct Node {
        Node* child[2];
        int exist, cnt;
        Node () {
            for (int i = 0; i < 2; i ++) child[i] = NULL;
            exist = cnt = 0;
        }
    };
    int cur;
    Node* root;
    TrieBit() : cur(0) {
        root = new Node();
    };
    void Add(int64_t v) {
        Node* p = root;
        for (int i = LG; i >= 0; i --) {
            int c = ((v >> i) & 1LL);
            if (p->child[c] == NULL) {
                p->child[c] = new Node();
            }
            p = p->child[c];
            p->cnt ++;
        }
        p->exist ++;
    }
    void Delete(int64_t v) {
        if (!find(v)) return;
        Node* p = root;
        for (int i = LG; i >= 0; i --) {
            int c = (v >> i & 1LL);
            p->child[c]->cnt--;
            if (p->child[c]->cnt == 0) {
                /// Can not delete(p->child[c]) directly
                p->child[c] = NULL;
                return;
            }
            p = p->child[c];
        }
        p->exist --;
    } 
    bool find(int64_t v) {
        Node* p = root;
        for (int i = LG; i >= 0; i --) {
            int c = ((v >> i) & 1LL);
            if (p->child[c] == NULL) return false;
            p = p->child[c];
        }
        return true;
    }  
};
