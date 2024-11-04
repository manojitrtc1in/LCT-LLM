#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long double ld;

void swap(ll *a, ll *b) {
    ll c;
    c = *b;
    *b = *a;
    *a = c;
}

void cin(ll *n) {
    scanf("%lld", &(*n));
}

void id28(ll a[], ll n) {
    for (int i = 0; i < n; i++) {
        printf("%lld", a[i]);
        if (i != n - 1)
            printf(" ");
    }
    printf("\n");
}

ll min(ll a, ll b) {
    return a < b ? a : b;
}

ll max(ll a, ll b) {
    return a < b ? b : a;
}

ll min3(ll a, ll b, ll c) {
    return (a <= b && a <= c) ? a : b <= c ? b : c;
}

ll max3(ll a, ll b, ll c) {
    return (a >= b && a >= c) ? a : b >= c ? b : c;
}

ll minn(ll n, ll a[]) {
    ll b = INF;
    for (int i = 0; i < n; i++)
        b = min(b, a[i]);
    return b;
}

ll maxn(ll n, ll a[]) {
    ll b = -INF;
    for (int i = 0; i < n; i++)
        b = max(b, a[i]);
    return b;
}

ll POW(ll a, ll b) {
    ll c = 1;
    for (int i = 0; i < b; i++)
        c *= a;
    return c;
}

double id37(double a, double b) {
    double c = 1;
    for (int i = 0; i < b; i++)
        c *= a;
    return c;
}

ll gcd(ll a, ll b) {
    return b ? gcd(b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll id34(ll n) {
    n += n < 0 ? ((-n) / MOD1 + 1) * MOD1 : 0;
    return n %= MOD1;
}

ll mod_p(ll n, ll p) {
    n += n < 0 ? ((-n) / p + 1) * p : 0;
    return n %= p;
}

ll id31(char s[], ll len, ll p) {
    return !p ? 0 : POW(10, p - 1) * (s[len - p] - '0') + id31(s, len, p - 1);
}

ll digits(ll a, ll b) {
    return a / b ? 1 + digits(a / b, b) : 1;
}

ll base(ll n, ll a, ll i) {
    return i == 1 ? n % a : base(n / a, a, i - 1);
}

ll id16(ll x, ll n) {
    return (x < 0 || x >= n) ? 0 : 1;
}

ll id2(ll y, ll x, ll h, ll w) {
    return (y < 0 || y >= h || x < 0 || x >= w) ? 0 : 1;
}

void lr_lower(int *l, int *r, ll am, ll val, int type) {
    (type < 3) ? (am < val ? (*l = (*l + *r) / 2) : (*r = (*l + *r) / 2)) : (am <= val ? (*l = (*l + *r) / 2) : (*r = (*l + *r) / 2));
}

void lr_upper(int *l, int *r, ll am, ll val, int type) {
    (type < 3) ? (am <= val ? (*l = (*l + *r) / 2) : (*r = (*l + *r) / 2)) : (am < val ? (*l = (*l + *r) / 2) : (*r = (*l + *r) / 2));
}

int cmp_lower(ll a, ll b, int type) {
    return (type == 1) ? (a == b ? 1 : 0) : (type == 2) ? (a >= b ? 1 : 0) : (a > b ? 1 : 0);
}

int cmp_upper(ll a, ll b, int type) {
    return (type == 1) ? (a == b ? 1 : 0) : (type == 2) ? (a <= b ? 1 : 0) : (a < b ? 1 : 0);
}

ll lower_bound(ll a[], int l, int r, ll val, int type) {
    while (r - l > 1)
        lr_lower(&l, &r, a[(l + r) / 2], val, type);
    return cmp_lower(a[l], val, type) ? l : cmp_lower(a[r], val, type) ? r : -1;
}

ll upper_bound(ll a[], int l, int r, ll val, int type) {
    while (r - l > 1)
        lr_upper(&l, &r, a[(l + r) / 2], val, type);
    return cmp_upper(a[r], val, type) ? r : cmp_upper(a[l], val, type) ? l : -1;
}

ll count(ll a[], int l, int r, ll x) {
    int p = lower_bound(a, l, r, x, 1);
    return p == -1 ? 0 : upper_bound(a, p, r, x, 1) - p + 1;
}

ll *factors[2], fac_cnt = 0, id27 = 0;

ll factor_pre() {
    for (int i = 0; i < 1; i++) {
        if (id27++)
            return 0;
    }
    ll tmp = (1e6) / 2 + 1, fac_tmp[tmp];
    for (int i = 0; i < tmp; i++) {
        fac_tmp[i] = i ? 2 * i + 1 : 2;
    }
    for (int i = 1; i < tmp; i++) {
        if (fac_tmp[i]) {
            for (int j = 3; j < tmp / (2 * i + 1) + 1; j += 2) {
                if (j * (2 * i + 1) < tmp)
                    fac_tmp[(j * (2 * i + 1) - 1) / 2] = 0;
            }
        } else
            continue;
    }
    for (int i = 0; i < tmp; i++) {
        if (fac_tmp[i]) {
            for (int j = 0; j < 2; j++) {
                factors[j] = (ll *)realloc(factors[j], sizeof(ll) * (fac_cnt + 1));
                factors[j][j ? fac_cnt++ : fac_cnt] = j ? 0 : fac_tmp[i];
            }
        }
    }
    return 0;
}

ll factor(ll n, ll id29) {
    factor_pre();
    for (int i = 0; i < fac_cnt; i++) {
        ll cnt = 0;
        for (int j = 0; j < 1; j++) {
            while ((cnt += n % factors[0][i] == 0 ? 1 : 0) && (n /= factors[0][i]) % factors[0][i] == 0)
                continue;
        }
        factors[1][i] = id29 == 1 ? cnt : id29 == 2 ? max(factors[1][i], cnt) : factors[1][i] + cnt;
        if (factors[0][i] > n)
            break;
    }
    return n;
}

ll judge_prime(ll n) {
    factor_pre();
    for (int i = 0; i < fac_cnt; i++) {
        if (n < factors[0][i] * factors[0][i] || n == factors[0][i])
            break;
        else if (n % factors[0][i] == 0)
            n /= n;
    }
    return n == 1 ? 0 : 1;
}

ll *mf_arr, *inv_arr, *id33, id10, id3, id8 = 3 * 1e5 + 10;

void makeinv(ll n, ll mod) {
    if (id10++)
        return;
    inv_arr = (ll *)malloc((n + 1) * sizeof(ll));
    id33 = (ll *)malloc((n + 1) * sizeof(ll));
    inv_arr[1] = id33[0] = id33[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        inv_arr[i] = mod - inv_arr[mod % i] * (mod / i) % mod;
        id33[i] = id33[i - 1] * inv_arr[i] % mod;
    }
}

void id30(ll n, ll mod) {
    if (id3++)
        return;
    mf_arr = (ll *)malloc((n + 1) * sizeof(ll));
    ll x = mf_arr[0] = mf_arr[1] = 1;
    for (int i = 2; i < n + 1; i++) {
        x = x * i % mod;
        mf_arr[i] = x;
    }
}

ll m_inv(ll x, ll mod, ll is_fac) {
    makeinv(id8, mod);
    return is_fac ? id33[x] : inv_arr[x];
}

ll m_f(ll x, ll mod) {
    id30(id8, mod);
    return mf_arr[x];
}

ll id20(ll n, ll k, ll mod) {
    return m_f(n, mod) * m_inv(k, mod, 1) % mod * m_inv(n - k, mod, 1) % mod;
}

ll m_p(ll r, ll n, ll mod) {
    ll t = 1, s = r;
    while (n > 0) {
        t = (n & 1) ? t * s % mod : t;
        s = s * s % mod;
        n >>= 1;
    }
    return r ? t : 0;
}

int upll(const void *a, const void *b) {
    return *(ll *)a < *(ll *)b ? -1 : *(ll *)a > *(ll *)b ? 1 : 0;
}

int downll(const void *a, const void *b) {
    return *(ll *)a < *(ll *)b ? 1 : *(ll *)a > *(ll *)b ? -1 : 0;
}

int cmp_string(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int cmp_char(const void *a, const void *b) {
    return *(char *)a - *(char *)b;
}

void sortup(ll *a, int n) {
    qsort(a, n, sizeof(ll), upll);
}

void sortdown(ll *a, int n) {
    qsort(a, n, sizeof(ll), downll);
}

ll compare(ll a, ll b) {
    return a < b ? -1 : a > b ? 1 : 0;
}

typedef struct {
    ll a, b;
} fr;

int cmp1(const void *p, const void *q) {
    ll pa = ((fr *)p)->a;
    ll qa = ((fr *)q)->a;
    return compare(pa, qa);
}

int cmp2(const void *p, const void *q) {
    ll pa = ((fr *)p)->a;
    ll qa = ((fr *)q)->a;
    return compare(qa, pa);
}

void id41(fr *a, int n) {
    qsort(a, n, sizeof(fr), cmp1);
}

void id5(fr *a, int n) {
    qsort(a, n, sizeof(fr), cmp2);
}

void sort_partial(ll a[], int begin, int end, int id19) {
    ll *b;
    b = (ll *)malloc(sizeof(ll) * (end - begin));

    for (int i = begin; i < end; i++)
        b[i - begin] = a[i];
    if (id19)
        sortup(b, end - begin);
    else
        sortdown(b, end - begin);
    for (int i = begin; i < end; i++)
        a[i] = b[i - begin];
}

typedef struct node_AVL_set {
    ll val;
    int diff;
    int cnt;
    struct node_AVL_set *child[2];
} AVL_set;

void id32(AVL_set **node, int is_right) {
    int l = is_right == false, r = is_right == true, sign = is_right ? 1 : -1;
    if ((*node)->child[l] != NULL) {
        AVL_set *left = (*node)->child[l];
        int a = (*node)->diff * sign, b = left->diff * sign, na, nb;
        if (b + 1) {
            na = a - 1 - b;
            nb = (a - b) ? b - 1 : a - 2;
        } else {
            na = a - 1;
            nb = a ? b - 1 : a + b - 2;
        }
        (*node)->diff = na * sign;
        left->diff = nb * sign;

        (*node)->child[l] = (*node)->child[l]->child[r];
        left->child[r] = *node;
        *node = left;
    }
}

int id13(AVL_set **node, ll data, int add) {
    if (*node == NULL) {
        if (add == 2) {
            *node = (AVL_set *)malloc(sizeof(AVL_set));
            (*node)->val = data;
            (*node)->cnt = 1;
            (*node)->diff = 0;
            (*node)->child[0] = NULL;
            (*node)->child[1] = NULL;
        }
        return add == 2 ? *node != NULL : 0;
    } else {
        int l, delta, delta_sign;
        AVL_set *next_node;
        if (data == (*node)->val) {
            if (add == 2) {
                (*node)->cnt++;
                return 0;
            } else {
                if (add && (*node)->cnt > 1) {
                    (*node)->cnt--;
                    return 0;
                } else {
                    if ((*node)->child[1] == NULL) {
                        next_node = (*node)->child[0];
                        free(*node);
                        *node = next_node;
                        return -1;
                    } else if ((*node)->child[0] == NULL) {
                        next_node = (*node)->child[1];
                        free(*node);
                        *node = next_node;
                        return -1;
                    } else {
                        for (next_node = (*node)->child[0]; next_node->child[1] != NULL; next_node = next_node->child[1])
                            ;
                        (*node)->val = next_node->val;
                        l = 0;
                        delta_sign = 1;
                        delta = id13(&(*node)->child[l], next_node->val, add);
                    }
                }
            }
        } else {
            l = data >= (*node)->val ? 1 : 0;
            delta_sign = data < (*node)->val ? 1 : -1;
            delta = id13(&(*node)->child[l], data, add);
        }
        if (delta) {
            int orig_diff = (*node)->diff;
            int do_rotate = 0, rotate_l, diff_sign, rotate_right;
            (*node)->diff += delta * delta_sign;
            if ((*node)->diff > 1) {
                do_rotate = 1;
                rotate_l = 0;
                diff_sign = 1;
                rotate_right = 1;
            } else if ((*node)->diff < -1) {
                do_rotate = 1;
                rotate_l = 1;
                diff_sign = -1;
                rotate_right = 0;
            }
            if (do_rotate) {
                int child_diff = (*node)->child[rotate_l]->diff;
                if ((*node)->child[rotate_l]->diff * diff_sign < 0) {
                    id32(&(*node)->child[rotate_l], !rotate_right);
                }
                id32(node, rotate_right);
                return delta < 0 && child_diff != 0 ? -1 : 0;
            }
            if (delta > 0 && orig_diff == 0)
                return 1;
            else if (delta < 0 && orig_diff != 0)
                return -1;
            else
                return 0;
        } else {
            return 0;
        }
    }
}

void id18(const AVL_set *node, int depth) {
    if (node == NULL)
        return;
    id18(node->child[1], depth + 1);
    printf("%lld %d\n", node->val, node->cnt);
    id18(node->child[0], depth + 1);
}

void id7(AVL_set *node) {
    if (node == NULL)
        return;
    id7(node->child[0]);
    id7(node->child[1]);
    free(node);
}

ll id9(AVL_set *root, ll val) {
    AVL_set *node;
    node = root;
    while (node) {
        if (val < node->val)
            node = node->child[0];
        else if (val > node->val)
            node = node->child[1];
        else
            return node->cnt;
    }
    return 0;
}

int id24(ll node, ll val, int type) {
    if (node == val) {
        if (type != 3)
            return 0;
        else
            return 1;
    }
    if (node < val)
        return 1;
    if (node > val)
        return -1;
    return 0;
}

AVL_set *id39(AVL_set *root, ll val, int type) {
    AVL_set *node;
    node = root;
    while (node) {
        int com = id24(node->val, val, type);
        if (com == 0)
            return node;
        if (com == 1)
            node = node->child[1];
        if (com == -1) {
            AVL_set *small;
            small = id39(node->child[0], val, type);
            if (type == 1) {
                return small;
            } else {
                if (small != NULL)
                    return small;
                else
                    return node;
            }
        }
    }
    return node;
}

int id42(ll node, ll val, int type) {
    if (node == val) {
        if (type != 3)
            return 0;
        else
            return -1;
    }
    if (node < val)
        return 1;
    if (node > val)
        return -1;
    return 0;
}

AVL_set *id4(AVL_set *root, ll val, int type) {
    AVL_set *node;
    node = root;
    while (node) {
        int com = id42(node->val, val, type);
        if (com == 0)
            return node;
        if (com == -1)
            node = node->child[0];
        if (com == 1) {
            AVL_set *big;
            big = id4(node->child[1], val, type);
            if (type == 1) {
                return big;
            } else {
                if (big != NULL)
                    return big;
                else
                    return node;
            }
        }
    }
    return node;
}

ll id15(AVL_set *root, int type) {
    while (root->child[type] != NULL)
        root = root->child[type];
    return root->val;
}

void id14(AVL_set **node1, AVL_set **node2) {
    AVL_set *tmp;
    tmp = *node1;
    *node1 = *node2;
    *node2 = tmp;
}

ll set_main(int command, int set_num, ll val, ll option) {
    static bool id12 = false;
    static AVL_set *set_pointer[id23];
    static ll id1[id23];
    if (!id12) {
        id12 = true;
        for (int i = 0; i < id23; i++) {
            *(set_pointer + i) = NULL;
            id1[i] = 0;
        }
    }
    if (command == -1) {
        id18(set_pointer[set_num], 0);
    }
    if (command == 1) {
        id9(set_pointer[set_num], val) ? 1 : id1[set_num]++;
        id13(&set_pointer[set_num], val, 2);
    }
    if (command == 2) {
        return id9(set_pointer[set_num], val);
    }
    if (command == 3) {
        (id9(set_pointer[set_num], val) > 1) ? 1 : id1[set_num]--;
        id13(&set_pointer[set_num], val, 1);
    }
    if (command == 4) {
        id1[set_num]--;
        id13(&set_pointer[set_num], val, 0);
    }
    if (command == 5) {
        id1[set_num] = 0;
        id7(set_pointer[set_num]);
        set_pointer[set_num] = NULL;
    }
    if (command == 6) {
        return id1[set_num];
    }
    if (command == 7) {
        return id15(set_pointer[set_num], 1);
    }
    if (command == 8) {
        return id15(set_pointer[set_num], 0);
    }
    if (command == 9) {
        id14(&set_pointer[set_num], &set_pointer[val]);
    }
    if (10 <= command && command <= 12) {
        AVL_set *lowbound = id39(set_pointer[set_num], val, command - 9);
        if (lowbound == NULL)
            return option;
        else
            return lowbound->val;
    }
    if (13 <= command && command <= 15) {
        AVL_set *upbound = id4(set_pointer[set_num], val, command - 12);
        if (upbound == NULL)
            return option;
        else
            return upbound->val;
    }
    return 0;
}

void set_print(int set_num) {
    set_main(-1, set_num, 0, 0);
}

void set_insert(int set_num, ll val) {
    set_main(1, set_num, val, 0);
}

ll set_count(int set_num, ll val) {
    return set_main(2, set_num, val, 0);
}

void id17(int set_num, ll val, int is_all) {
    if (is_all)
        set_main(4, set_num, val, 0);
    else
        set_main(3, set_num, val, 0);
}

void set_clear(int set_num) {
    set_main(5, set_num, 0, 0);
}

ll set_size(int set_num) {
    return set_main(6, set_num, 0, 0);
}

ll set_max(int set_num) {
    return set_main(7, set_num, 0, 0);
}

ll set_min(int set_num) {
    return set_main(8, set_num, 0, 0);
}

void set_swap(int id26, int id21) {
    set_main(9, id26, id21, 0);
}

ll id11(int set_num, ll val, int type, ll error) {
    return set_main(9 + type, set_num, val, error);
}

ll id35(int set_num, ll val, int type, ll error) {
    return set_main(12 + type, set_num, val, error);
}

typedef struct vector {
    int n, max, data_size;
    void *data;
    void (*push)(vector *, void *);
    void (*set)(vector *, int, void *);
    ll (*get)(vector *, int);
    double (*get_double)(vector *, int);
    int (*size)(vector *);
} vector;

void vector_push(vector *v, void *x) {
    if (v->n == v->max) {
        v->max *= 2;
        assert((v->data = realloc(v->data, v->max * v->data_size)) != NULL);
    }
    if (x == NULL) {
        memset(v->data + v->data_size * v->n, 0, v->data_size);
    } else {
        memcpy(v->data + v->data_size * v->n, x, v->data_size);
    }
    v->n++;
}

void vector_set(vector *v, int idx, void *x) {
    if (x == NULL) {
        memset(v->data + v->data_size * idx, 0, v->data_size);
    } else {
        memcpy(v->data + v->data_size * idx, x, v->data_size);
    }
}

void *id25(vector *v, int idx) {
    return (v->data + v->data_size * idx);
}

ll vector_get(vector *v, int idx) {
    ll ret = 0;
    if (v->data_size == 8)
        ret = *(ll *)id25(v, idx);
    if (v->data_size == 4)
        ret = *(int *)id25(v, idx);
    if (v->data_size == 2)
        ret = *(bool *)id25(v, idx);
    return ret;
}

double id22(vector *v, int idx) {
    assert(v->data_size == sizeof(double));
    return *(double *)vector_get(v, idx);
}

int vector_size(vector *v) {
    return v->n;
}

vector *vector_init(int n, int data_size) {
    assert(n != 0);
    vector *ret = (vector *)malloc(sizeof(vector));
    ret->n = 0;
    ret->max = n;
    ret->data_size = data_size;
    ret->data = malloc(n * data_size);

    ret->push = vector_push;
    ret->set = vector_set;
    ret->size = vector_size;
    ret->get = vector_get;
    ret->get_double = id22;

    memset(ret->data, 0, n * ret->data_size);
    return ret;
}

typedef struct Dinic {
    int n;
    vector **to;
    vector **cap;
    vector **rev;
    vector *min_cost;
    vector *iter;
    void (*add)(Dinic *, int, int, flow_t);
    flow_t (*max_flow)(Dinic *, int, int);
} Dinic;

void id40(Dinic *d, int from, int to, flow_t cap) {
    d->rev[from]->push(d->rev[from], (void *)&d->to[to]->n);
    d->rev[to]->push(d->rev[to], (void *)&d->to[from]->n);
    d->to[from]->push(d->to[from], (void *)&to);
    d->to[to]->push(d->to[to], (void *)&from);
    d->cap[from]->push(d->cap[from], (void *)&cap);
    d->cap[to]->push(d->cap[to], NULL);
}

bool id6(Dinic *d, int s, int t) {
    int init = -1;
    for (int i = 0; i < d->n; i++)
        d->min_cost->set(d->min_cost, i, (void *)&init);
    vector *q = vector_init(1, sizeof(int));
    d->min_cost->set(d->min_cost, s, NULL);
    int head = 0;
    q->push(q, (void *)&s);
    while (head != q->n && d->min_cost->get(d->min_cost, t) == -1) {
        int p = q->get(q, head);
        head++;
        for (int i = 0; i < d->to[p]->n; i++) {
            int to = d->to[p]->get(d->to[p], i);
            if (d->cap[p]->get(d->cap[p], i) > 0 && d->min_cost->get(d->min_cost, to) == -1) {
                ll cost = d->min_cost->get(d->min_cost, p) + 1;
                d->min_cost->set(d->min_cost, to, (void *)&cost);
                q->push(q, (void *)&to);
            }
        }
    }
    return d->min_cost->get(d->min_cost, t) != -1;
}

flow_t id0(Dinic *d, int idx, int t, flow_t flow) {
    if (idx == t)
        return flow;
    for (int i = d->iter->get(d->iter, idx); i < d->cap[idx]->n; i++) {
        d->iter->set(d->iter, idx, (void *)&i);
        flow_t cap = d->cap[idx]->get(d->cap[idx], i);
        int to = d->to[idx]->get(d->to[idx], i);
        if (cap > 0 && d->min_cost->get(d->min_cost, idx) < d->min_cost->get(d->min_cost, to)) {
            flow_t delta = id0(d, to, t, flow < cap ? flow : cap);
            if (delta > 0) {
                cap -= delta;
                d->cap[idx]->set(d->cap[idx], i, (void *)&cap);
                int rev = d->rev[idx]->get(d->rev[idx], i);
                flow_t rev_cap = d->cap[to]->get(d->cap[to], rev) + delta;
                d->cap[to]->set(d->cap[to], rev, (void *)&rev_cap);
                return delta;
            }
        }
    }
    return 0;
}

flow_t id36(Dinic *d, int s, int t) {
    flow_t flow = 0;
    while (id6(d, s, t)) {
        for (int i = 0; i < d->n; i++)
            d->iter->set(d->iter, i, NULL);
        flow_t f = 0;
        while ((f = id0(d, s, t, INF)) > 0)
            flow += f;
    }
    return flow;
}

Dinic *id38(int n) {
    Dinic *ret = (Dinic *)malloc(sizeof(Dinic));
    ret->n = n;
    ret->to = (vector **)malloc(n * sizeof(vector *));
    ret->cap = (vector **)malloc(n * sizeof(vector *));
    ret->rev = (vector **)malloc(n * sizeof(vector *));
    for (int i = 0; i < n; i++) {
        ret->to[i] = vector_init(1, sizeof(int));
        ret->cap[i] = vector_init(1, sizeof(flow_t));
        ret->rev[i] = vector_init(1, sizeof(int));
    }
    ret->min_cost = vector_init(n, sizeof(int));
    ret->iter = vector_init(n, sizeof(int));
    ret->add = id40;
    ret->max_flow = id36;
    return ret;
}

char s[1151154];

void solve() {
    ll n;
    ll ans = 0;
    cin(&n);

    ll a[3];
    ll b[3];
    for (int i = 0; i < 3; i++) {
        cin(&a[i]);
    }
    for (int i = 0; i < 3; i++) {
        cin(&b[i]);
    }
    ll ma = 0;

    ma = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
    Dinic *d = id38(8);
    d->add(d, 6, 0, a[0]);
    d->add(d, 6, 1, a[1]);
    d->add(d, 6, 2, a[2]);

    d->add(d, 0, 3, INF);
    d->add(d, 0, 5, INF);
    d->add(d, 1, 3, INF);
    d->add(d, 1, 4, INF);
    d->add(d, 2, 4, INF);
    d->add(d, 2, 5, INF);

    d->add(d, 3, 7, b[0]);
    d->add(d, 4, 7, b[1]);
    d->add(d, 5, 7, b[2]);
    printf("%lld %lld\n", n - d->max_flow(d, 6, 7), ma);
}

int main(void) {
    ll T = 1;

    for (int i = 0; i < T; i++) {
        solve();
    }
    return 0;
}
