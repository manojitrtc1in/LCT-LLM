#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define MAX 100002
namespace DynamicTree{
    unsigned int randxor()
    {
        static unsigned int x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        unsigned int t;
        t = (x ^ (x << 11)); x = y; y = z; z = w; return(w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
    }
    struct D_NODE{

        int lazy_for_dep;
        int dep;

        D_NODE* pr;

        D_NODE *pair_of_end;  


        int __PRIORITY;

        int size;

        long long int lazy_for_dist;
        long long int dist;  


        long long int have_dist;

        D_NODE *lef;
        D_NODE *rig;

        int idx;


        

        int MINT_DEP;
        D_NODE *MINT;

        int MAXT_DEP;
        D_NODE *MAXT;

        bool start_flag;
        int NUMBER_OF_START_FLAG;

        D_NODE(){
            NUMBER_OF_START_FLAG;
            start_flag = false;
            lazy_for_dep = 0;
            dep = 0;
            lazy_for_dist = 0;
            dist = 0;
            lef = rig = NULL;
            __PRIORITY = randxor();
            pair_of_end = NULL;
            MINT = NULL;
            MINT_DEP = INT_MAX;
            MAXT = NULL;
            MAXT_DEP = INT_MIN;
            pr = NULL;
            size = 0;
        }
    };
    const int MEMORY_SIZE = 2000000;
    D_NODE dymmy[MEMORY_SIZE];
    int ord = 0;
    D_NODE *neww(){
        if (ord < MEMORY_SIZE){
            ord++;
            return &dymmy[ord - 1];
        }
        return new D_NODE();
    }
    const int VECTOR_SIZE = 1000000;
    D_NODE* VEC[VECTOR_SIZE];
    int VECTOR_CUR_INDEX = 0;
    

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
        if (B->lazy_for_dep){
            B->dep += B->lazy_for_dep;
            if (B->lef){
                B->lef->lazy_for_dep += B->lazy_for_dep;
            }
            if (B->rig){
                B->rig->lazy_for_dep += B->lazy_for_dep;
            }
            B->lazy_for_dep = 0;
        }
        if (B->lazy_for_dist){
            B->dist += B->lazy_for_dist;
            if (B->lef){
                B->lef->lazy_for_dist += B->lazy_for_dist;
            }
            if (B->rig){
                B->rig->lazy_for_dist += B->lazy_for_dist;
            }
            B->lazy_for_dist = 0;
        }
        B->size = 1 + get_size(B->lef) + get_size(B->rig);
        if (B->lef){
            B->lef->pr = B;
        }
        if (B->rig){
            B->rig->pr = B;
        }
        B->MINT = B;
        B->MINT_DEP = B->dep;
        if (B->lef&&B->MINT_DEP > B->lef->MINT_DEP + B->lef->lazy_for_dep){
            B->MINT_DEP = B->lef->MINT_DEP + B->lef->lazy_for_dep;
            B->MINT = B->lef->MINT;
        }
        if (B->rig&&B->MINT_DEP > B->rig->MINT_DEP + B->rig->lazy_for_dep){
            B->MINT_DEP = B->rig->MINT_DEP + B->rig->lazy_for_dep;
            B->MINT = B->rig->MINT;
        }
        B->MAXT = B;
        B->MAXT_DEP = B->dep;
        if (B->lef&&B->MAXT_DEP < B->lef->MAXT_DEP + B->lef->lazy_for_dep){
            B->MAXT_DEP = B->lef->MAXT_DEP + B->lef->lazy_for_dep;
            B->MAXT = B->lef->MAXT;
        }
        if (B->rig&&B->MAXT_DEP < B->rig->MAXT_DEP + B->rig->lazy_for_dep){
            B->MAXT_DEP = B->rig->MAXT_DEP + B->rig->lazy_for_dep;
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
        VECTOR_CUR_INDEX = 0;
        while (a != NULL){
            VEC[VECTOR_CUR_INDEX] = a;
            VECTOR_CUR_INDEX++;
            a = a->pr;
        }
        int k = VECTOR_CUR_INDEX - 1;
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
        if (a->__PRIORITY > b->__PRIORITY){
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

    int calc_left_size(D_NODE *a){
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

    inline void split_base_cnt(D_NODE *b, D_NODE *&l, D_NODE *&r, int x){  

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
        int __get_size = get_size(b->lef);
        if (__get_size >= x){
            r = b;
            update(b->lef);
            split_base_cnt(b->lef, l, b->lef, x);
            return;
        }
        if (__get_size + 1 == x){
            l = b;
            r = b->rig;
            l->rig = NULL;
            path_update(l);
        

            return;
        }
        l = b;
        update(b->rig);
        split_base_cnt(b->rig, b->rig, r, x - 1 - __get_size);
    }

    D_NODE * cut(D_NODE *&tree, D_NODE *root_of_new_subtree){
        if (root_of_new_subtree == NULL){
            

            cout << "error cut" << endl;
            exit(0);
            return NULL;
        }
        D_NODE *star = root_of_new_subtree;
        D_NODE *en = root_of_new_subtree->pair_of_end;
        int __LEFT_SIZE = calc_left_size(star);
        int cur_dep = root_of_new_subtree->dep;
        long long int cur_dist = root_of_new_subtree->dist;
        D_NODE *l1 = NULL;
        D_NODE *l2 = NULL;
        D_NODE *l3 = NULL;
        split_base_cnt(tree, l1, l2, __LEFT_SIZE - 1);
        if (l1){
            l1->pr = NULL;
        }
        if (l2){
            l2->pr = NULL;
        }
        if (tree){
            tree->pr = NULL;
        }
        int __RIGHT_SIZE = calc_left_size(en);
        split_base_cnt(l2, l2, l3, __RIGHT_SIZE);
        if (l2){
            l2->pr = NULL;
        }
        if (l3){
            l3->pr = NULL;
        }
        tree = merge(l1, l3);
        if (tree)tree->pr = NULL;
        if (l2)l2->pr = NULL;
        if (l2)l2->lazy_for_dep += -cur_dep;
        if (l2)l2->lazy_for_dist += -cur_dist;
        update(l2);
        return l2;
    }

    void add_distance(D_NODE *&tree, D_NODE *ap, long long int add){  

        path_update(ap);  

        ap->have_dist += add;
        D_NODE *star = ap;
        D_NODE *en = star->pair_of_end;
        int __LEFT_SIZE = calc_left_size(star);
        D_NODE *l1;
        D_NODE *l2;
        D_NODE *l3;
        split_base_cnt(tree, l1, l2, __LEFT_SIZE - 1);
        int __RIGHT_SIZE = calc_left_size(en);
        split_base_cnt(tree, l2, l3, __RIGHT_SIZE);
        l2->lazy_for_dist += add;
        update(l2);
        tree = merge(l1, l2);
        tree = merge(tree, l3);
        tree->pr = NULL;
        return;
    }

    void link(D_NODE *&tree, D_NODE *nex_parent, D_NODE *linked, long long int subtree_add_dist = 1){
        if (linked == NULL){
            return;
        }
        path_update(nex_parent);
        path_update(nex_parent->pair_of_end);
        D_NODE *ne = neww();
        (*ne) = (*nex_parent->pair_of_end);
        ne->pr = NULL;
        ne->lef = ne->rig = NULL;
        ne->size = 1;
        ne->MINT_DEP = ne->MAXT_DEP = ne->dep;
        ne->MINT = ne->MAXT = ne;
        update(ne);
        update(linked);
        linked->lazy_for_dist += nex_parent->dist + subtree_add_dist;
        linked->lazy_for_dep += nex_parent->dep + 1;
        update(linked);
        linked = merge(ne, linked);
        linked->pr = NULL;
        int LEFT_SIZE = calc_left_size(nex_parent->pair_of_end);
        LEFT_SIZE--;
        D_NODE *l1 = NULL;
        D_NODE *l2 = NULL;
        split_base_cnt(tree, l1, l2, LEFT_SIZE);
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
        int lef1 = calc_left_size(a);
        int rig1 = calc_left_size(a->pair_of_end);
        int lef2 = calc_left_size(b);
        int rig2 = calc_left_size(b->pair_of_end);
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
        split_base_cnt(tree, L1, L2, mint - 1);
        split_base_cnt(L2, L2, L3, maxt - mint + 1);
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
        if (from->lef&&from->lef->MINT_DEP <= want_dep&&want_dep <= from->lef->MAXT_DEP){
            from = from->lef;
            while (1){
                update(from);
                update(from->rig);
                if (from->rig&&from->rig->MINT_DEP <= want_dep&&from->rig->MAXT_DEP >= want_dep){
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
            if (from->lef&&from->lef->MINT_DEP <= want_dep&&want_dep <= from->lef->MAXT_DEP){
                from = from->lef;
                while (1){
                    update(from);
                    update(from->rig);
                    if (from->rig&&from->rig->MINT_DEP <= want_dep&&from->rig->MAXT_DEP >= want_dep){
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
                if (a->rig->MAXT_DEP >= k&&a->rig->MINT_DEP <= k){
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
        int MX = f->MAXT_DEP;
        int MN = f->MINT_DEP;
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
        add->MINT_DEP = dep[vv[i]];
        add->MAXT_DEP = dep[vv[i]];
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
            linkk[vv[i]]->pair_of_end = add;
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
            printf("%lld\n", DynamicTree::distance(root, linkk[a], linkk[b]));
            continue;
        }
        if (ty == 2){
            int a, b;
            scanf("%d%d", &a, &b);
            a--;
            b = DynamicTree::go_up(root, linkk[a], b)->idx;
            DynamicTree::D_NODE *nw = DynamicTree::cut(root, linkk[a]);
            DynamicTree::link(root, linkk[b], nw);
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