
typedef long long ll;
const int BUFFER = 1 << 18;
struct ostream
{
    char buffer[BUFFER], *pos = buffer, *end = buffer + BUFFER;
    ~ostream() { flush(); }
    void flush() { fwrite(buffer, 1, pos - buffer, stdout), pos = buffer; }
    void put(char ch)
    {
        if (pos == end)
            flush();
        *(pos++) = ch;
    }
    template <typename V>
    void put(V num)
    {
        if (num)
            put(num / 10), put((char)(num % 10 + '0'));
    }
    ostream &operator<<(char s) { return put(s), *this; }
    ostream &operator<<(const char *s)
    {
        while (*s)
            put(*(s++));
        return *this;
    }
    template <typename V, std::enable_if_t<std::is_integral_v<V>, bool> = true>
    ostream &operator<<(V num)
    {
        if (num < 0)
            put('-'), put(-num);
        else if (num == 0)
            put('0');
        else
            put(num);
        return *this;
    }
    template <typename V, std::enable_if_t<std::is_floating_point_v<V>, bool> = true>
    ostream &operator<<(V num)
    {
        if (num < 0)
            num *= -1, put('-');
        ll whole = (ll)num;
        num -= whole;
        *this << whole << '.';
        for (int i = 0; i < 8; i++)
        {
            char ch = num *= 10;
            put((char)(ch + '0')), num -= ch;
        }
        return *this;
    }
} cout;
struct istream
{
    char buffer[BUFFER], *pos = buffer, *end = buffer;
    int get()
    {
        if (pos == end)
        {
            end = buffer + fread(buffer, 1, BUFFER, stdin), pos = buffer;
            if (pos == end)
                return 0;
        }
        return *(pos++);
    }
    istream &operator>>(char &ch)
    {
        while ((ch = get()) <= ' ')
            ;
        return *this;
    }
    template <typename V, std::enable_if_t<std::is_integral_v<V>, bool> = true>
    istream &operator>>(V &num)
    {
        char ch;
        while ((ch = get()) < '-')
            ;
        int sign = ch == '-';
        num = sign ? 0 : ch - '0';
        while ((ch = get()) > ' ')
            num = 10 * num + ch - '0';
        if (sign)
            num = -num;
        return *this;
    }
} cin;






template <
    typename T,
    int maxN,
    int maxDepth = 32 - __builtin_clz(maxN - 1)>
struct segtree
{
    T tree[maxN << 1];
    int stacks[maxDepth], n = maxN, depth = maxDepth;
    void build(T *values, int n)
    {
        this->n = n, this->depth = 32 - __builtin_clz(n - 1);
        memcpy(tree + n, values, sizeof(T) * n);
        for (int i = n - 1; i; i--)
            tree[i] = T(tree[i << 1], tree[i << 1 | 1]);
        tree[0] = T(1);
    }
    T find() { return tree[1]; }
    T find(int i)
    {
        i += n;
        for (int d = depth; d; d--)
            tree[i >> d].lazyPush(tree[i >> d << 1], tree[i >> d << 1 | 1]);
        return tree[i];
    }
    T find(int l, int r)
    {
        l += n, r += n;
        for (int d = depth; d; d--)
        {
            if (l >> d << d != l)
                tree[l >> d].lazyPush(tree[l >> d << 1], tree[l >> d << 1 | 1]);
            if (r >> d << d != r)
                tree[r >> d].lazyPush(tree[r >> d << 1], tree[r >> d << 1 | 1]);
        }

        T L(1), R(1);
        while (l < r)
        {
            if (l & 1)
                L = T(L, tree[l++]);
            if (r & 1)
                R = T(tree[--r], R);
            l >>= 1, r >>= 1;
        }

        return T(L, R);
    }
    template <typename... V>
    void update(int i, V... v)
    {
        i += n;
        for (int d = depth; d; d--)
            tree[i >> d].lazyPush(tree[i >> d << 1], tree[i >> d << 1 | 1]);

        tree[i].update(v...);

        for (int d = 1; d <= depth; d++)
            tree[i >> d] = T(tree[i >> d << 1], tree[i >> d << 1 | 1]);
    }
    template <typename... V>
    void updateRange(int l, int r, V... v)
    {
        l += n, r += n;
        for (int d = depth; d; d--)
        {
            if (l >> d << d != l)
                tree[l >> d].lazyPush(tree[l >> d << 1], tree[l >> d << 1 | 1]);
            if (r >> d << d != r)
                tree[r >> d].lazyPush(tree[r >> d << 1], tree[r >> d << 1 | 1]);
        }

        int L = l, R = r;
        while (l < r)
        {
            if (l & 1)
                tree[l++].lazyUpdate(v...);
            if (r & 1)
                tree[--r].lazyUpdate(v...);
            l >>= 1, r >>= 1;
        }
        l = L, r = R;

        for (int d = 1; d <= depth; d++)
        {
            if (l >> d << d != l)
                tree[l >> d] = T(tree[l >> d << 1], tree[l >> d << 1 | 1]);
            if (r >> d << d != r)
                tree[r >> d] = T(tree[r >> d << 1], tree[r >> d << 1 | 1]);
        }
    }
    int findFirst(int l, int r, const std::function<int(T &)> &f)
    {
        int *top = stacks, ans = r;

        l += n, r += n;
        for (int d = depth; d; d--)
        {
            if (l >> d << d != l)
                tree[l >> d].lazyPush(tree[l >> d << 1], tree[l >> d << 1 | 1]);
            if (r >> d << d != r)
                tree[r >> d].lazyPush(tree[r >> d << 1], tree[r >> d << 1 | 1]);
        }

        T t(1);
        while (l < r)
        {
            if (l & 1)
            {
                T tt = T(t, tree[l]);
                if (f(tt))
                    return findFirst(l, f, t);
                t = tt, l++;
            }
            if (r & 1)
                *(top++) = --r;
            l >>= 1, r >>= 1;
        }
        while (top > stacks)
        {
            T tt = T(t, tree[*(--top)]);
            if (f(tt))
                return findFirst(*top, f, t);
            t = tt;
        }
        return ans;
    }
    int findFirst(int i, const std::function<int(T &)> &f, T &t)
    {
        while (i < n)
        {
            tree[i].lazyPush(tree[i << 1], tree[i << 1 | 1]);
            T tt = T(t, tree[i << 1]);
            if (f(tt))
                i = i << 1;
            else
                i = i << 1 | 1, t = tt;
        }
        return i - n;
    }
    int findLast(int l, int r, const std::function<int(T &)> &f)
    {
        int *top = stacks, ans = l - 1;

        l += n, r += n;
        for (int d = depth; d; d--)
        {
            if (l >> d << d != l)
                tree[l >> d].lazyPush(tree[l >> d << 1], tree[l >> d << 1 | 1]);
            if (r >> d << d != r)
                tree[r >> d].lazyPush(tree[r >> d << 1], tree[r >> d << 1 | 1]);
        }

        T t(1);
        while (l < r)
        {
            if (l & 1)
                *(top++) = l++;
            if (r & 1)
            {
                T tt = T(tree[--r], t);
                if (f(tt))
                    return findLast(r, f, t);
                t = tt;
            }
            l >>= 1, r >>= 1;
        }
        while (top > stacks)
        {
            T tt = T(tree[*(--top)], t);
            if (f(tt))
                return findLast(*top, f, t);
            t = tt;
        }
        return ans;
    }
    int findLast(int i, const std::function<int(T &)> &f, T &t)
    {
        while (i < n)
        {
            tree[i].lazyPush(tree[i << 1], tree[i << 1 | 1]);
            T tt = T(tree[i << 1 | 1], t);
            if (f(tt))
                i = i << 1 | 1;
            else
                i = i << 1, t = tt;
        }
        return i - n;
    }
};

struct maxCost
{
    int v;
    maxCost() {}
    maxCost(int v) : v(-1) {}
    maxCost(const maxCost &a, const maxCost &b)
    {
        if (a.v < b.v)
            v = b.v;
        else
            v = a.v;
    }
    void update(int v) { this->v = v; }
    void lazyUpdate() {}
    void lazyPush(maxCost &a, maxCost &b)
    {
        a.lazyUpdate();
        b.lazyUpdate();
    }
};
segtree<maxCost, 500000> lTree;

struct minCost
{
    int v;
    minCost() {}
    minCost(int v) : v(0x77777777) {}
    minCost(const minCost &a, const minCost &b)
    {
        if (a.v < b.v)
            v = a.v;
        else
            v = b.v;
    }
    void update(int v) { this->v = v; }
    void lazyUpdate() {}
    void lazyPush(minCost &a, minCost &b)
    {
        a.lazyUpdate();
        b.lazyUpdate();
    }
};
segtree<minCost, 500000> rTree;

std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
struct treap
{
    treap *l, *r;
    int prior;
    int i, x, y, lx, ly;
    treap() {}
    treap(int i, int x, int y) : l(0), r(0), prior(rnd()), i(i), x(x), y(y), lx(0), ly(0) { pull(this); }

    int bestX, bestY;
    friend void id2(treap *current, int x, treap *&l, treap *&r)
    {
        if (current)
        {
            push(current);
            if (current->x < x)
                id2(current->r, x, current->r, r), l = current;
            else
                id2(current->l, x, l, current->l), r = current;
            pull(current);
        }
        else
            l = r = 0;
    }
    friend void id1(treap *current, int x, treap *&l, treap *&r)
    {
        if (current)
        {
            push(current);
            if (x < current->x)
                id1(current->l, x, l, current->l), r = current;
            else
                id1(current->r, x, current->r, r), l = current;
            pull(current);
        }
        else
            l = r = 0;
    }
    friend void id0(treap *current, int y, treap *&l, treap *&r)
    {
        if (current)
        {
            push(current);
            if (current->y < y)
                id0(current->r, y, current->r, r), l = current;
            else
                id0(current->l, y, l, current->l), r = current;
            pull(current);
        }
        else
            l = r = 0;
    }
    friend void id3(treap *current, int y, treap *&l, treap *&r)
    {
        if (current)
        {
            push(current);
            if (y < current->y)
                id3(current->l, y, l, current->l), r = current;
            else
                id3(current->r, y, current->r, r), l = current;
            pull(current);
        }
        else
            l = r = 0;
    }
    friend treap *merge(treap *l, treap *r)
    {
        if (!l)
            return r;
        else if (!r)
            return l;
        else if (l->prior < r->prior)
        {
            push(r);
            r->l = merge(l, r->l);
            return pull(r);
        }
        else
        {
            push(l);
            l->r = merge(l->r, r);
            return pull(l);
        }
    }
    friend treap *left(treap *current)
    {
        if (current)
        {
            while (current->l)
                current = current->l;
            return current;
        }
        return 0;
    }
    friend treap *right(treap *current)
    {
        if (current)
        {
            while (current->r)
                current = current->r;
            return current;
        }
        return 0;
    }
    friend void update(treap *current, int lx, int ly)
    {
        if (current)
        {
            current->x += lx;
            current->lx += lx;
            current->bestX += lx;

            current->y += ly;
            current->ly += ly;
            current->bestY += ly;
        }
    }
    friend treap *push(treap *current)
    {
        if (current)
        {
            update(current->l, current->lx, current->ly);
            update(current->r, current->lx, current->ly);
            current->lx = current->ly = 0;
        }
        return current;
    }
    friend treap *pull(treap *current)
    {
        if (current)
        {
            current->bestX = current->x;
            current->bestY = current->y;
            if (current->l)
                *current << *current->l;
            if (current->r)
                *current << *current->r;
        }
        return current;
    }
    void operator<<(treap &a)
    {
        if (std::abs(bestX - bestY) > std::abs(a.bestX - a.bestY))
        {
            bestX = a.bestX;
            bestY = a.bestY;
        }
    }
    template <typename V>
    friend V &operator<<(V &out, treap *a)
    {
        if (a)
        {
            push(a);
            out << a->l << '(' << a->x << ',' << a->y << ',' << a->i << ')' << a->r;
            pull(a);
        }
        return out;
    }
} nodes[1000000];

template <typename V, int maxN>
struct fenwick
{
    V nums[maxN];
    int n;
    void clear(int n) { this->n = n, memset(nums, 0, sizeof(V) * n); }
    void add(int i, V value)
    {
        for (; i < n; i |= i + 1)
            nums[i] += value;
    }
    V query(int i)
    {
        V ans = 0;
        for (; 0 <= i; i = (i & (i + 1)) - 1)
            ans += nums[i];
        return ans;
    }
};
fenwick<int, 500000> dx, dy;

template <typename V>
int amax(V &a, const V b)
{
    if (a < b)
        return a = b, 1;
    return 0;
}

void testCase()
{
    int n;
    cin >> n;

    int round = n;
    dx.clear(n);
    dy.clear(n);

    int as[n], lUsed[n], rUsed[n];
    maxCost ldp[n];
    minCost rdp[n];
    memset(lUsed, 0, sizeof(lUsed)), memset(ldp, -1, sizeof(ldp));
    memset(rUsed, 0, sizeof(rUsed)), memset(rdp, 0x77, sizeof(rdp));
    for (int i = 0; i < n; i++)
    {
        cin >> as[i], as[i]--;

        if (as[i] == i)
            round--, dx.add(i, 1), dy.add(i, 1);
        else if (as[i] < i)
            ldp[i].v = as[i];
        else
            rdp[i].v = as[i];
    }
    lTree.build(ldp, n);
    rTree.build(rdp, n);

    treap *lRoot = 0, *rRoot = 0, *topNode = nodes;
    for (int last = 0, i = -1;; last = as[i])
    {
        i = lTree.findFirst(
            i + 1, n, [last](const maxCost &a)
            { return a.v >= last; });
        if (i == n)
            break;
        lUsed[i] = 1;
        *topNode = treap(i, as[i] - dx.query(as[i]), i - dy.query(i));
        lRoot = merge(lRoot, topNode++);
    }
    for (int last = n, i = n;; last = as[i])
    {
        i = rTree.findLast(
            0, i, [last](const minCost &a)
            { return a.v <= last; });
        if (i == -1)
            break;
        rUsed[i] = 1;
        *topNode = treap(i, as[i] - dx.query(as[i]), i - dy.query(i));
        rRoot = merge(topNode++, rRoot);
    }

    int ans = 0;
    while (round--)
    {
        int bestX = 0, bestY = n;
        if (lRoot)
            if (std::abs(bestX - bestY) > std::abs(lRoot->bestX - lRoot->bestY))
                bestX = lRoot->bestX, bestY = lRoot->bestY;
        if (rRoot)
            if (std::abs(bestX - bestY) > std::abs(rRoot->bestX - rRoot->bestY))
                bestX = rRoot->bestX, bestY = rRoot->bestY;
        amax(ans, std::abs(bestX - bestY));

        int choose;
        treap *l, *m, *r;

        id2(lRoot, bestX, l, lRoot);
        id1(lRoot, bestX, m, r);
        if (m)
        {
            update(r, -1, -1);
            choose = m->i;
            m = 0;

            treap *current = right(l);
            int last = 0, i = -1;
            if (current)
                last = as[i = current->i];
            lTree.update(choose, -1);
            while (1)
            {
                i = lTree.findFirst(
                    i + 1, n, [last](const maxCost &a)
                    { return a.v >= last; });
                if (i == n || lUsed[i])
                    break;
                lUsed[i] = 1;
                *topNode = treap(i, as[i] - dx.query(as[i]), i - dy.query(i) - 1);
                m = merge(m, topNode++);
                last = as[i];
            }
            lRoot = merge(l, merge(m, r));
        }
        else
        {
            update(r, -1, 0);
            lRoot = merge(l, r);

            id0(lRoot, bestY, l, r);
            update(r, 0, -1);
            lRoot = merge(l, r);
        }

        id2(rRoot, bestX, l, rRoot);
        id1(rRoot, bestX, m, r);
        if (m)
        {
            update(r, -1, -1);
            choose = m->i;
            m = 0;

            treap *current = left(r);
            int last = n, i = n;
            if (current)
                last = as[i = current->i];
            rTree.update(choose, 0x77777777);
            while (1)
            {
                i = rTree.findLast(
                    0, i, [last](const minCost &a)
                    { return a.v <= last; });
                if (i == -1 || rUsed[i])
                    break;
                rUsed[i] = 1;
                *topNode = treap(i, as[i] - dx.query(as[i]) - 1, i - dy.query(i));
                m = merge(topNode++, m);
                last = as[i];
            }
            rRoot = merge(l, merge(m, r));
        }
        else
        {
            update(r, -1, 0);
            rRoot = merge(l, r);

            id0(rRoot, bestY, l, r);
            update(r, 0, -1);
            rRoot = merge(l, r);
        }

        dx.add(as[choose], 1), dy.add(choose, 1);
    }

    cout << ans << '\n';
}

int main()
{
    testCase();
    return 0;
}