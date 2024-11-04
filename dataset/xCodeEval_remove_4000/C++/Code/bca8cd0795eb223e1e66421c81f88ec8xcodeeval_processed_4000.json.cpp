


























using namespace std;

namespace DynamicTree{
    unsigned int randxor()
    {
        static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        unsigned int t;
        t = (x ^ (x << 11)); x = y; y = z; z = w; return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
    }
    struct D_NODE{

        int id1;
        int dep;

        D_NODE* pr;

        D_NODE *id11;  


        int id4;

        int size;

        long long int id12;
        long long int dist;  


        long long int have_dist;

        D_NODE *lef;
        D_NODE *rig;

        int idx;


        

        int id5;
        D_NODE *MINT;

        int id13;
        D_NODE *MAXT;

        bool start_flag;
        int NUMBER_OF_START_FLAG;

        D_NODE(){
            NUMBER_OF_START_FLAG;
            start_flag = false;
            id1 = 0;
            dep = 0;
            id12 = 0;
            dist = 0;
            lef = rig = NULL;
            id4 = randxor();
            id11 = NULL;
            MINT = NULL;
            id5 = INT_MAX;
            MAXT = NULL;
            id13 = INT_MIN;
            pr = NULL;
            size = 0;
        }
    };
    const int id14 = 2000000;
    D_NODE dymmy[id14];
    int ord = 0;
    D_NODE *neww(){
        if (ord < id14){
            ord++;
            return &dymmy[ord - 1];
        }
        return new D_NODE();
    }
    const int VECTOR_SIZE = 1000000;
    D_NODE* VEC[VECTOR_SIZE];
    int id9 = 0;
    

    inline void see(D_NODE *f, bool B = false){
        if (f->lef){
            see(f->lef, true);
        }
        cout << f->idx << " ";
        if (f->rig){
            see(f->rig, true);
        }
        if (B == false){
            puts("");
        }
    }

    int get_size(D_NODE *b){
        if (b == NULL){
            return 0;
        }
        return b->size;
    }

    void update(D_NODE *B){
        if (B == NULL){
            return;
        }
        if (B->id1){
            B->dep += B->id1;
            if (B->lef){
                B->lef->id1 += B->id1;
            }
            if (B->rig){
                B->rig->id1 += B->id1;
            }
            B->id1 = 0;
        }
        if (B->id12){
            B->dist += B->id12;
            if (B->lef){
                B->lef->id12 += B->id12;
            }
            if (B->rig){
                B->rig->id12 += B->id12;
            }
            B->id12 = 0;
        }
        B->size = 1 + get_size(B->lef) + get_size(B->rig);
        if (B->lef){
            B->lef->pr = B;
        }
        if (B->rig){
            B->rig->pr = B;
        }
        B->MINT = B;
        B->id5 = B->dep;
        if (B->lef&&B->id5 > B->lef->id5 + B->lef->id1){
            B->id5 = B->lef->id5 + B->lef->id1;
            B->MINT = B->lef->MINT;
        }
        if (B->rig&&B->id5 > B->rig->id5 + B->rig->id1){
            B->id5 = B->rig->id5 + B->rig->id1;
            B->MINT = B->rig->MINT;
        }
        B->MAXT = B;
        B->id13 = B->dep;
        if (B->lef&&B->id13 < B->lef->id13 + B->lef->id1){
            B->id13 = B->lef->id13 + B->lef->id1;
            B->MAXT = B->lef->MAXT;
        }
        if (B->rig&&B->id13 < B->rig->id13 + B->rig->id1){
            B->id13 = B->rig->id13 + B->rig->id1;
            B->MAXT = B->rig->MAXT;
        }
        B->NUMBER_OF_START_FLAG = B->start_flag;
        if (B->lef){
            B->NUMBER_OF_START_FLAG += B->lef->NUMBER_OF_START_FLAG;
        }
        if (B->rig){
            B->NUMBER_OF_START_FLAG += B->rig->NUMBER_OF_START_FLAG;
        }
    }
    D_NODE *find_root(D_NODE *a){
        while (a->pr != NULL){
            update(a);
            a = a->pr;
        }
        return a;
    }
    void path_update(D_NODE *a, bool dep_only = false){
        id9 = 0;
        while (a != NULL){
            VEC[id9] = a;
            id9++;
            a = a->pr;
        }
        int k = id9 - 1;
        if (dep_only == false){
            for (int i = k; i >= 0; i--){
                update(VEC[i]);
            }
        }
        for (int i = 0; i <= k; i++){
            update(VEC[i]);
        }
    }
    inline D_NODE *merge(D_NODE *a, D_NODE *b){
        if (a != NULL)update(a);
        if (b != NULL)update(b);
        if (a == NULL){
            path_update(b);
            return b;
        }
        if (b == NULL){
            path_update(a);
            return a;
        }
        if (a->id4 > b->id4){
            a->rig = merge(a->rig, b);
            update(a);
            return a;
        }
        else{
            b->lef = merge(a, b->lef);
            update(b);
            return b;
        }
    }

    int id3(D_NODE *a){
        if (a == NULL){
            return 0;
        }
        path_update(a);
        int sum = 1 + get_size(a->lef);
        D_NODE *pre = a;
        a = a->pr;
        while (a != NULL){
            if (a->rig == pre){
                sum++;
                sum += get_size(a->lef);
            }
            pre = a;
            a = a->pr;
        }
        return sum;
    }

    inline void id8(D_NODE *b, D_NODE *&l, D_NODE *&r, int x){  

        if (b == NULL){
            D_NODE *L = NULL;
            if (l) L = l->pr;
            D_NODE *R = NULL;
            if (r)R = r->pr;
            l = r = NULL;
            path_update(L);
            path_update(R);
            return;
        }
        update(b);
        int id0 = get_size(b->lef);
        if (id0 >= x){
            r = b;
            update(b->lef);
            id8(b->lef, l, b->lef, x);
            return;
        }
        if (id0 + 1 == x){
            l = b;
            r = b->rig;
            l->rig = NULL;
            path_update(l);
            path_update(r);
            return;
        }
        l = b;
        update(b->rig);
        id8(b->rig, b->rig, r, x - 1 - id0);
    }

    D_NODE * cut(D_NODE *&tree, D_NODE *id7){
        if (id7 == NULL){
            

            cout << "error cut" << endl;
            exit(0);
            return NULL;
        }
        D_NODE *star = id7;
        D_NODE *en = id7->id11;
        int id2 = id3(star);
        int cur_dep = id7->dep;
        long long int cur_dist = id7->dist;
        D_NODE *l1 = NULL;
        D_NODE *l2 = NULL;
        D_NODE *l3 = NULL;
        id8(tree, l1, l2, id2 - 1);
        if (l1){
            l1->pr = NULL;
        }
        if (l2){
            l2->pr = NULL;
        }
        if (tree){
            tree->pr = NULL;
        }
        int id10 = id3(en);
        id8(l2, l2, l3, id10);
        update(l2);
        update(l3);
        if (l2){
            path_update(l2->pr, true);
            l2->pr = NULL;
        }
        if (l3){
            path_update(l3->pr, true);
            l3->pr = NULL;
        }
        tree = merge(l1, l3);
        if (l1){
            path_update(l1->pr);
        }
        if (l3){
            path_update(l3->pr);
        }
        update(tree);
        if (tree)tree->pr = NULL;
        if (l2)l2->pr = NULL;
        if (l2)l2->id1 += -cur_dep;
        if (l2)l2->id12 += -cur_dist;
        update(l2);
        update(tree);
        return l2;
    }

    void add_distance(D_NODE *&tree, D_NODE *ap, long long int add){  

        path_update(ap);  

        ap->have_dist += add;
        D_NODE *star = ap;
        D_NODE *en = star->id11;
        int id2 = id3(star);
        D_NODE *l1;
        D_NODE *l2;
        D_NODE *l3;
        id8(tree, l1, l2, id2 - 1);
        int id10 = id3(en);
        id8(tree, l2, l3, id10);
        l2->id12 += add;
        update(l2);
        tree = merge(l1, l2);
        tree = merge(tree, l3);
        tree->pr = NULL;
        return;
    }

    void link(D_NODE *&tree, D_NODE *nex_parent, D_NODE *linked, long long int id6 = 1){
        if (linked == NULL){
            return;
        }
        path_update(nex_parent);
        path_update(nex_parent->id11);
        D_NODE *ne = neww();
        (*ne) = (*nex_parent->id11);
        ne->pr = NULL;
        ne->lef = ne->rig = NULL;
        ne->size = 1;
        ne->id5 = ne->id13 = ne->dep;
        ne->MINT = ne->MAXT = ne;
        update(ne);
        update(linked);
        linked->id12 += nex_parent->dist + id6;
        linked->id1 += nex_parent->dep + 1;
        update(linked);
        linked = merge(ne, linked);
        linked->pr = NULL;
        int LEFT_SIZE = id3(nex_parent->id11);
        LEFT_SIZE--;
        D_NODE *l1 = NULL;
        D_NODE *l2 = NULL;
        id8(tree, l1, l2, LEFT_SIZE);
        if (l1)l1->pr = NULL;
        if (l2)l2->pr = NULL;
        tree = merge(l1, linked);
        if (tree){
            tree->pr = NULL;
        }
        D_NODE *cp_ = tree;
        tree = merge(tree, l2);
        tree->pr = NULL;
    }

    D_NODE *LCA(D_NODE *&tree, D_NODE *a, D_NODE *b){
        if (a == b)return a;
        tree->pr = NULL;
        int lef1 = id3(a);
        int rig1 = id3(a->id11);
        int lef2 = id3(b);
        int rig2 = id3(b->id11);
        if (lef1 <= lef2&&rig2 <= rig1){
            return a;
        }
        if (lef2 <= lef1&&lef1 <= rig2){
            return b;
        }
        int mint = lef1;
        if (lef1 > lef2){
            mint = lef2;
        }
        int maxt = rig1;
        if (rig1 < rig2){
            maxt = rig2;
        }
        D_NODE *L1;
        D_NODE *L2;
        D_NODE *L3;
        D_NODE *ANS;
        id8(tree, L1, L2, mint - 1);
        id8(L2, L2, L3, maxt - mint + 1);
        if (L1){
            L1->pr = NULL;
        }
        if (L2){
            L2->pr = NULL;
        }
        if (L3){
            L3->pr = NULL;
        }
        ANS = L2->MINT;
        tree = merge(L1, L2);
        tree = merge(tree, L3);
        if (tree) tree->pr = NULL;
        return ANS;
    }
    long long int distance(D_NODE *&tree, D_NODE *a, D_NODE *b){
        if (a == b){
            return 0;
        }
        tree->pr = NULL;
        D_NODE *LC = LCA(tree, a, b);
        path_update(LC);
        long long int ans = a->dist + b->dist - 2LL * LC->dist;
        return ans;
    }
    void push_back(D_NODE *&tree, D_NODE *a){
        tree = merge(tree, a);
        tree->pr = NULL;
    }

    D_NODE *go_up(D_NODE *tree, D_NODE* from, int x){
        if (x == 0){
            return from;
        }
        path_update(from);
        int want_dep = from->dep - x;
        update(from);
        update(from->lef);
        if (from->lef&&from->lef->id5 <= want_dep&&want_dep <= from->lef->id13){
            from = from->lef;
            while (1){
                update(from);
                update(from->rig);
                if (from->rig&&from->rig->id5 <= want_dep&&from->rig->id13 >= want_dep){
                    from = from->rig;
                    continue;
                }
                if (from->dep == want_dep){
                    return from;
                }
                from = from->lef;
                continue;
            }
        }
        D_NODE *pre = from;
        from = from->pr;
        while (1){
            update(from);
            update(from->lef);
            if (from->lef == pre){
                pre = from;
                from = from->pr;
                continue;
            }
            if (from->dep == want_dep){
                return from;
            }
            if (from->lef&&from->lef->id5 <= want_dep&&want_dep <= from->lef->id13){
                from = from->lef;
                while (1){
                    update(from);
                    update(from->rig);
                    if (from->rig&&from->rig->id5 <= want_dep&&from->rig->id13 >= want_dep){
                        from = from->rig;
                        continue;
                    }
                    if (from->dep == want_dep){
                        return from;
                    }
                    from = from->lef;
                    continue;
                }
            }
            else{
                pre = from;
                from = from->pr;
            }
        }
    }

    

    D_NODE *F(D_NODE *tree, int k){
        D_NODE *a = tree;
        update(a);
        while (1){
            update(a);
            if (a->rig){
                update(a->rig);
                if (a->rig->id13 >= k&&a->rig->id5 <= k){
                    a = a->rig;
                    continue;
                }
            }
            if (a->dep == k){
                return a;
            }
            a = a->lef;
        }
        return a;
    }
    inline void se(D_NODE *f, bool B = false){
        update(f);
        int MX = f->id13;
        int MN = f->id5;
        if (f->lef){
            se(f->lef, true);
        }
        if (f->rig){
            se(f->rig, true);
        }
        update(f);
    }
}

DynamicTree::D_NODE *root;


int n;
int m;

vector<int> v[MAX];
DynamicTree::D_NODE *linkk[MAX];

int dep[MAX];
int star[MAX];
int en[MAX];
bool use[MAX];
vector<int> vv;
int siz;
inline void dfs(int b, int h = 0){
    use[b] = true;
    dep[b] = h;
    star[b] = siz;
    siz++;
    vv.push_back(b);
    for (int i = 0; i < v[b].size(); i++){
        if (use[v[b][i]]){
            continue;
        }
        dfs(v[b][i], h + 1);
        en[b] = siz;
        siz++;
        vv.push_back(b);
    }
    if (siz - 1 == star[b]){
        vv.push_back(b);
        en[b] = siz;
        siz++;
    }
}

void make(){
    dfs(0);
    for (int i = 0; i < vv.size(); i++){
        DynamicTree::D_NODE *add = DynamicTree::neww();
        add->dep = dep[vv[i]];
        add->idx = vv[i];
        add->MINT = add;
        add->id5 = dep[vv[i]];
        add->id13 = dep[vv[i]];
        add->MAXT = add;
        add->dist = dep[vv[i]];
        add->have_dist = 1;
        add->size = 1;
        if (star[vv[i]] == i){
            add->start_flag = true;
            add->NUMBER_OF_START_FLAG = 1;
            linkk[vv[i]] = add;
            DynamicTree::push_back(root, add);
        }
        else{
            linkk[vv[i]]->id11 = add;
            DynamicTree::push_back(root, add);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++){
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++){
            int a;
            scanf("%d", &a);
            a--;
            v[i].push_back(a);
        }
    }
    make();
    int cc = 0;
    while (m--){
        int ty;
        scanf("%d", &ty);
        if (ty == 1){
            cc++;
            int a, b;
            scanf("%d%d", &a, &b);
            a--;
            b--;
            DynamicTree::path_update(linkk[a]);
            DynamicTree::path_update(linkk[b]);
            DynamicTree::id3(linkk[a]);
            DynamicTree::id3(linkk[b]);
            printf("%lld\n", DynamicTree::distance(root, linkk[a], linkk[b]));
            continue;
        }
        if (ty == 2){
            int a, b;
            scanf("%d%d", &a, &b);
            a--;
            b = DynamicTree::go_up(root, linkk[a], b)->idx;
            DynamicTree::D_NODE *nw = DynamicTree::cut(root, linkk[a]);
            int ne = linkk[b]->dep + 1;
            update(nw);
            update(root);
            if (root)root->pr = NULL;
            if (nw)nw->pr = NULL;
            DynamicTree::link(root, linkk[b], nw);
            DynamicTree::update(root);
            root->pr = NULL;
            DynamicTree::path_update(linkk[a]);
            continue;
        }
        int k;
        scanf("%d", &k);
        cc++;
        DynamicTree::D_NODE *ans = DynamicTree::F(root, k);
        printf("%d\n", ans->idx + 1);
    }
    return 0;
}