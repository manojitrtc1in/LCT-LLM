



using namespace std;

struct Node {
    static Node *null;
    int x, y, sz;
    Node *l, *r;
    Node() {x = y = 0;sz = 0;l = r = this;}
    Node(const int &x_) {x = x_;y = rand();sz = 1;l = r = null;}
    void recount() {if(this == null) return; sz = l->sz + 1 + r->sz;};
};

Node *Node::null = new Node();
int n, a[1000000];
long long ans = 0;
Node *ls = Node::null, *rs;

Node *merge(Node *l, Node *r) {
    if(l == Node::null) return r;
    if(r == Node::null) return l;
    if(l->y > r->y) {
        l->r = merge(l->r, r);
        l->recount();
        return l;
    } else {
        r->l = merge(l, r->l);
        r->recount();
        return r;
    }
}

void split(Node *&t, Node *&l, Node *&r, const int &x0) {
    if(t == Node::null) {
        l = r = t;
        return;
    }
    if(t->x < x0) {
        l = t;
        split(l->r, l->r, r, x0);
    } else {
        r = t;
        split(r->l, l, r->l, x0);
    }
    l->recount();
    r->recount();
}

Node *build(const int &i, const int &j) {
    if(j == i + 1)
        return new Node(a[i]);
    return merge(build(i, (i + j) / 2), build((i + j) / 2, j));
}

void solve() {
    srand(time(nullptr));
    scanf("%d", &n);
    rs = Node::null;
    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
        a[i] = -a[i];
        Node *l, *r, *m = new Node(a[i]);
        split(rs, l, r, a[i]);
        rs = merge(merge(l, m), r);
    }


    for(int i = 0;i < n;i++) {
        Node *l, *m, *r;
        split(rs, l, m, a[i]);
        split(m, m, r, a[i] + 1);
        long long szr = r->sz;
        rs = merge(l, r);
        split(ls, l, r, a[i]);
        long long szl = l->sz;
        ans += szl * szr;
        ls = merge(merge(l, m), r);
    }
    printf("%I64d", ans);
}

int main() {
    if(!ONLINE_JUDGE) { 





    } else
        freopen("input.txt", "r", stdin);
    solve();
    return 0;
}
