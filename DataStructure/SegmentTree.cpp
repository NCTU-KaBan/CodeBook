struct SegmentTree {
    struct Node { int L, R; Node *l, *r;
        // data, eg. v
        // tag, eg. add
        Node (int L = 0, int R = 0) : L(L), R(R) { l = r = NULL; }
    }*rt, *buf, *ptr;
    SegmentTree (vector<int> arr) { rt = build(0, arr.size(), arr);
        buf = new Node[__lg(arr.size()) * 4 + 5];
    }
    Node* build(int L, int R, vector<int> &arr) {
        Node *u = new Node(L, R); int M = (L + R) >> 1;
        if (R - L == 1) return /*basic data,*/ u;
        return u->l = build(L, M, arr), u->r = build(M, R, arr), pull(u);
    }
    Node* pull(Node *u) { return pull(u, u->l, u->r); }
    Node* pull(Node *u, Node *l, Node *r) {
        push(l); push(r); if (!l || !r) return l ? l : r;
        // pull function
        return u;
    }
    void push(Node *u) {
        if (!u) return ;
        // push function
    }
    Node* query(int qL, int qR, Node *u = NULL) {
        if (!u) u = rt, ptr = buf;
        if (qR <= u->L || u->R <= qL) return (Node*)NULL;
        push(u); if (qL <= u->L && u->R <= qR) return u;
        return pull(ptr++, query(qL, qR, u->l), query(qL, qR, u->r));
    }
    void modify(int mL, int mR, int v, Node *u = NULL) {
        if (!u) u = rt; push(u); if (mR <= u->L || u->R <= mL) return ;
        if (mL <= u->L && u->R <= mR) 
            return /*basic modify,*/ void();
        modify(mL, mR, v, u->l); modify(mL, mR, v, u->r);
        return pull(u), void();
    }
    ~SegmentTree() { clear(rt); delete []buf; }
    void clear(Node *u) { if (u) clear(u->l), clear(u->r), delete u; }
};
