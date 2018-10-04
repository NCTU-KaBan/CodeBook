#include <bits/stdc++.h>
using namespace std;
const double alpha = 0.8;
struct ScapeGoatTree {
    struct Node {
        Node *ch[2];
        int v, sz;
        bool r;
        Node (int v) : v(v) {
            sz = r = 1; 
            ch[0] = ch[1] = 0;
        }
    }*rt;
    vector<Node*> seq;
    ScapeGoatTree() : rt(NULL) {}
    void flatten(Node *t) {
        if (!t) return ;
        flatten(t->ch[0]);
        if (t->r) seq.push_back(t);
        flatten(t->ch[1]);
        if (!t->r) delete t;
    }
    Node* rebuild(int L, int R) {
        if (L == R) return NULL;
        int M = L + R >> 1;
        Node *t = seq[M];
        t->sz = R - L;
        t->ch[0] = rebuild(L    , M);
        t->ch[1] = rebuild(M + 1, R);
        return t;
    }
    Node* insert(Node *t, int v) {
        if (!t) return new Node(v); t->sz++;
        t->ch[v > t->v] = insert(t->ch[v > t->v], v);
        if (t->ch[v > t->v]->sz > alpha * t->sz) {
            seq.clear(); flatten(t);
            t = rebuild(0, seq.size());
        }
        return t;
    }
    bool remove(Node *t, int v) {
        if (!t) return false; bool ret;
        if (t->v == v) ret = t->r, t->r = false;
        else ret = remove(t->ch[v > t->v], v);
        return t->sz -= ret, ret;
    }
    void insert(int v) { rt = insert(rt, v); }
    bool remove(int v) { return remove(rt, v); }
};
int main() { ios_base::sync_with_stdio(false); cin.tie(0);
    ScapeGoatTree *sol = new ScapeGoatTree();
    int n; while (cin >> n) sol->insert(n);
    delete sol;
}
