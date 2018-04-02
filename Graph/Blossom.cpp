#include <bits/stdc++.h>
using namespace std;
const int MAXN = 250 + 5;
const int MAXM = MAXN * MAXN / 2;
#define PB push_back
struct Graph{
    struct Node; struct Edge;
    int V;
    struct Node : vector<Edge*>{
        Node *p, *s, *m;
        int S, v;
        Node(){
            clear(), S = v = -1, s = p = m = NULL;
        }
    }_memN[MAXN], *node[MAXN];
    struct Edge{
        Node *t;
        Edge(Node *_t = NULL) : t(_t){}
    }_memE[MAXM], *ptrE;
    Graph(int _V = 0) : V(_V){
        ptrE = _memE;
        for (int i = 0 ; i < V ; i++)
            *(node[i] = _memN + i) = Node();
    }
    void addEdge(int u, int v){
        node[u]->PB(new (ptrE++) Edge(node[v]));
        node[v]->PB(new (ptrE++) Edge(node[u]));
    }
    void Print(){
    for (int i = 0 ; i < V ; i++){
        if (!node[i]->m) continue;
        if (node[i]->m - node[0] >= i)
            cout << i + 1 << ' ' << node[i]->m - node[0] + 1 << '\n';
        }
    }
};
struct Blossom{
    Graph *G;
    typedef Graph::Node Node;
    Node **node;
    Blossom(Graph *_G) : G(_G) {
        node = &G->node[0];
    }
    inline int maxMatch(){
        int ans = 0;
        for (int i = 0 ; i < G->V ; i++)
            if (!node[i]->m && bfs(node[i]))
                ans++;
        return ans;
    }
#define qpush(u) q.push(u), u->S = 0;
    inline bool bfs(Node *u){
        for (int i = 0 ; i < G->V ; i++)
            node[i]->s = node[i], node[i]->S = -1;
        queue<Node*> q; qpush(u);
        while (q.size()){
            u = q.front(), q.pop();
            for (auto e : *u){
                Node *v = e->t;
                if (!~v->S){
                    v->p = u;
                    v->S = 1;
                    if (!v->m)
                        return augment(u, v);
                    qpush(v->m);
                }else if(!v->S && v->s != u->s){
                    Node *l = LCA(v->s, u->s);
                    flower(v, u, l, q);
                    flower(u, v, l, q);
                }
            }
        }
        return false;
    }
    inline bool augment(Node *u, Node *v){
        for (Node *l; u; v = l, u = v ? v->p : NULL){
            l = u->m;
            u->m = v;
            v->m = u;
        }
        return true;
    }
    inline Node* LCA(Node *u, Node *v){
        static int t = 0;
        for (++t;; swap(u, v)){
            if (!u) continue;
            if (u->v == t) return u;
            u->v = t;
            u = u->m; if (!u) continue;
            u = u->p; if (!u) continue;
            u = u->s;
        }
    }
    inline void flower(Node *u, Node *v, Node *l, queue<Node*> &q){
        while (u->s != l){
            u->p = v;
            v = u->m;
            if (v->S == 1) qpush(v);
            u->s = v->s = l;
            u = v->p;
        }
    }
};
int main(){

}

