
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






struct montgomery
{
    using u64 = unsigned long long;
    using u32 = unsigned;
    u32 mod, inv, r, r2, r3;
    montgomery() {}
    montgomery(u32 mod) : mod(mod) { init(); }
    friend istream &operator>>(istream &in, montgomery &a) { return in >> a.mod, a.init(), in; }
    void init()
    {
        inv = 1;
        for (int i = 0; i < 5; i++)
            inv *= 2 - mod * inv;
        r = -mod % mod;
        r2 = ((u64)r * r) % mod;
        r3 = mul(r2, r2);
    }
    u32 add(u32 v) { return mul(v, r2); }
    u32 reduce(u64 v)
    {
        u32 l = ((u64)((u32)v * inv) * mod) >> 32;
        u32 h = v >> 32;
        if (h < l)
            return h + mod - l;
        return h - l;
    }
    u32 mul(u64 a, u32 b) { return reduce(a * b); }
} mod = 998244353;

struct mint
{
    unsigned v;
    mint() {}
    mint(unsigned v) : v(v) {}
    mint(int v) { this->v = mod.add(v < 0 ? v + mod.mod : v); }
    friend istream &operator>>(istream &in, mint &a)
    {
        int v;
        cin >> v;
        return a = mint(v), in;
    }
    template <typename V>
    friend V &operator<<(V &out, const mint &a) { return out << mod.reduce(a.v); }
    bool operator==(const mint &a) { return v == a.v; }
    bool operator!=(const mint &a) { return v != a.v; }
    mint &operator+=(const mint &a)
    {
        v += a.v;
        if (v >= mod.mod)
            v -= mod.mod;
        return *this;
    }
    mint &operator-=(const mint &a)
    {
        if (v < a.v)
            v += mod.mod - a.v;
        else
            v -= a.v;
        return *this;
    }
    mint operator*(const mint &a) const { return mod.mul(v, a.v); }
    mint operator/(const mint &a) const { return *this * a.inv(); }
    mint operator+(const mint &a) const { return mint(v) += a; }
    mint operator-(const mint &a) const { return mint(v) -= a; }
    mint &operator*=(const mint &a) { return *this = *this * a; }
    mint &operator/=(const mint &a) { return *this = *this / a; }
    mint inv() const
    {
        int a = v, b = mod.mod, x = 1, y = 0;
        while (a)
        {
            int q = b / a, r = b - q * a, z = y - q * x;
            b = a, a = r, y = x, x = z;
        }
        if (y < 0)
            y += mod.mod;
        return mod.mul(y, mod.r3);
    }
    mint pow(int n) const
    {
        mint ans(1);
        for (mint current(v); n; n >>= 1, current *= current)
            if (n & 1)
                ans *= current;
        return ans;
    }
};

mint num0 = 0, num1 = 1, num2 = num1 + num1, num3 = num2 + num1;

template <typename W, int dim>
struct matrix
{
    W v[dim][dim];
    matrix() {}
    matrix(W c)
    {
        memset(v, 0, sizeof(v));
        for (int i = 0; i < dim; i++)
            v[i][i] = c;
    }
    matrix operator+=(const matrix &a)
    {
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
                v[i][j] += a.v[i][j];
        return *this;
    }
    matrix operator*(const matrix &a) const
    {
        matrix ans(num0);
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
                for (int k = 0; k < dim; k++)
                    ans.v[i][j] += v[i][k] * a.v[k][j];
        return ans;
    }
    matrix pow(int n) const
    {
        matrix ans(W(1));
        for (matrix current(*this); n; n >>= 1, current = current * current)
            if (n & 1)
                ans = ans * current;
        return ans;
    }
};
matrix<mint, 2> mat1(num1);

template <typename W, int dim>
struct vector
{
    W v[dim];
    vector() {}
    vector(W c)
    {
        for (int i = 0; i < dim; i++)
            v[i] = c;
    }
    vector operator+(const vector &a) const
    {
        vector ans;
        for (int i = 0; i < dim; i++)
            ans.v[i] = v[i] + a.v[i];
        return ans;
    }
    friend vector operator*(const matrix<W, dim> &a, const vector &b)
    {
        vector ans(num0);
        for (int i = 0; i < dim; i++)
            for (int j = 0; j < dim; j++)
                ans.v[i] += a.v[i][j] * b.v[j];
        return ans;
    }
    template <typename V>
    friend V &operator<<(V &out, const vector &a)
    {
        out << '[';
        for (int i = 0; i < dim; i++)
        {
            if (i)
                out << ' ';
            out << a.v[i];
        }
        return out << ']';
    }
};
vector<mint, 2> vec0(num0);

struct cost
{
    matrix<mint, 2> l;
    vector<mint, 2> v;
    cost() {}
    cost(int v) : v(vec0), l(mat1) {}
    void update() {}
    void lazyUpdate(matrix<mint, 2> L)
    {
        l = L * l;
        v = L * v;
    }
    void lazyPush(cost &a, cost &b)
    {
        a.lazyUpdate(l);
        b.lazyUpdate(l);
        l = mat1;
    }
    friend cost merge(const cost &a, const cost &b)
    {
        cost ans;

        ans.v = a.v + b.v;
        ans.l = mat1;

        return ans;
    }
};

template <int maxN>
struct segtree
{
    static const int maxDepth = 32 - __builtin_clz(maxN - 1);

    cost tree[maxN << 1];
    int stacks[maxDepth], n = maxN, depth = maxDepth;
    void build(cost *values, int n)
    {
        this->n = n, this->depth = 32 - __builtin_clz(n - 1);
        memcpy(tree + n, values, sizeof(cost) * n);
        for (int i = n - 1; i; i--)
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
        tree[0] = cost(1);
    }
    cost find() { return tree[1]; }
    cost find(int i)
    {
        i += n;
        for (int d = depth; d; d--)
            tree[i >> d].lazyPush(tree[i >> d << 1], tree[i >> d << 1 | 1]);
        return tree[i];
    }
    cost find(int l, int r)
    {
        l += n, r += n;
        for (int d = depth; d; d--)
        {
            if (l >> d << d != l)
                tree[l >> d].lazyPush(tree[l >> d << 1], tree[l >> d << 1 | 1]);
            if (r >> d << d != r)
                tree[r >> d].lazyPush(tree[r >> d << 1], tree[r >> d << 1 | 1]);
        }

        cost L(1), R(1);
        while (l < r)
        {
            if (l & 1)
                L = merge(L, tree[l++]);
            if (r & 1)
                R = merge(tree[--r], R);
            l >>= 1, r >>= 1;
        }

        return merge(L, R);
    }
    template <typename... V>
    void update(int i, V... v)
    {
        i += n;
        for (int d = depth; d; d--)
            tree[i >> d].lazyPush(tree[i >> d << 1], tree[i >> d << 1 | 1]);

        tree[i].update(v...);

        for (int d = 1; d <= depth; d++)
            tree[i >> d] = merge(tree[i >> d << 1], tree[i >> d << 1 | 1]);
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
                tree[l >> d] = merge(tree[l >> d << 1], tree[l >> d << 1 | 1]);
            if (r >> d << d != r)
                tree[r >> d] = merge(tree[r >> d << 1], tree[r >> d << 1 | 1]);
        }
    }
    int findFirst(int l, int r, const std::function<int(cost &)> &f)
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

        cost t(1);
        while (l < r)
        {
            if (l & 1)
            {
                cost tt = merge(t, tree[l]);
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
            cost tt = merge(t, tree[*(--top)]);
            if (f(tt))
                return findFirst(*top, f, t);
            t = tt;
        }
        return ans;
    }
    int findFirst(int i, const std::function<int(cost &)> &f, cost &t)
    {
        while (i < n)
        {
            tree[i].lazyPush(tree[i << 1], tree[i << 1 | 1]);
            cost tt = merge(t, tree[i << 1]);
            if (f(tt))
                i = i << 1;
            else
                i = i << 1 | 1, t = tt;
        }
        return i - n;
    }
    int findLast(int l, int r, const std::function<int(cost &)> &f)
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

        cost t(1);
        while (l < r)
        {
            if (l & 1)
                *(top++) = l++;
            if (r & 1)
            {
                cost tt = merge(tree[--r], t);
                if (f(tt))
                    return findLast(r, f, t);
                t = tt;
            }
            l >>= 1, r >>= 1;
        }
        while (top > stacks)
        {
            cost tt = merge(tree[*(--top)], t);
            if (f(tt))
                return findLast(*top, f, t);
            t = tt;
        }
        return ans;
    }
    int findLast(int i, const std::function<int(cost &)> &f, cost &t)
    {
        while (i < n)
        {
            tree[i].lazyPush(tree[i << 1], tree[i << 1 | 1]);
            cost tt = merge(tree[i << 1 | 1], t);
            if (f(tt))
                i = i << 1 | 1;
            else
                i = i << 1, t = tt;
        }
        return i - n;
    }
};
segtree<300000> tree;

void testCase()
{
    int n;
    cin >> n;

    {
        n--;
        int l, r;
        cin >> l >> r;
        r++;

        cost dp[300001];
        for (int i = 0; i < 300001; i++)
        {
            dp[i].l = mat1;
            dp[i].v = vec0;
            if (l <= i && i < r)
                dp[i].v.v[0] = num1;
            else
                dp[i].v.v[1] = num1;
        }
        tree.build(dp, 300001);
    }

    matrix<mint, 2> m0, m1;
    m0.v[0][0] = num2, m0.v[0][1] = num0, m0.v[1][0] = num1, m0.v[1][1] = num3;
    m1.v[0][0] = num2, m1.v[0][1] = num2, m1.v[1][0] = num1, m1.v[1][1] = num1;

    while (n--)
    {
        int l, r;
        cin >> l >> r;
        r++;

        tree.updateRange(0, l, m0);
        tree.updateRange(l, r, m1);
        tree.updateRange(r, 300001, m0);
    }

    cout << tree.find().v.v[0] << '\n';
}

int main()
{
    testCase();
    return 0;
}