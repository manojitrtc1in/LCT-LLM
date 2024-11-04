class Modular:
    def __init__(self, value):
        self.value = value

    def __add__(self, other):
        return Modular((self.value + other.value) % self.mod())

    def __sub__(self, other):
        return Modular((self.value - other.value) % self.mod())

    def __mul__(self, other):
        return Modular((self.value * other.value) % self.mod())

    def __divmod__(self, other):
        return Modular((self.value * pow(other.value, self.mod() - 2, self.mod())) % self.mod())

    def __eq__(self, other):
        return self.value == other.value

    def __str__(self):
        return str(self.value)

    def mod(self):
        return 1000000007

class id0:
    class node:
        def __init__(self):
            self.w = 0
            self.Wp = 0
            self.fp = 0
            self.tp = 0

        def apply(self, l, r, v, id, rid, a):
            self.w = v
            self.Wp = Modular(v) * a
            self.fp = Modular(v) * id
            self.tp = Modular(v) * rid

    def __init__(self, n):
        self.n = n
        self.tree = [self.node() for _ in range(2 * n - 1)]
        self.build(0, 0, n - 1)

    def unite(self, a, b):
        res = self.node()
        res.w = a.w + b.w
        res.Wp = a.Wp + b.Wp
        res.fp = a.fp + b.fp
        res.tp = a.tp + b.tp
        return res

    def push(self, x, l, r):
        pass

    def pull(self, x, z):
        self.tree[x] = self.unite(self.tree[x + 1], self.tree[z])

    def build(self, x, l, r):
        if l == r:
            return
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        self.build(x + 1, l, y)
        self.build(z, y + 1, r)
        self.pull(x, z)

    def build(self, x, l, r, v, a):
        if l == r:
            self.tree[x].apply(l, r, v[l], l, self.n - 1 - r, a[l])
            return
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        self.build(x + 1, l, y, v, a)
        self.build(z, y + 1, r, v, a)
        self.pull(x, z)

    def get(self, x, l, r, ll, rr):
        if ll <= l and r <= rr:
            return self.tree[x]
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        self.push(x, l, r)
        res = self.node()
        if rr <= y:
            res = self.get(x + 1, l, y, ll, rr)
        else:
            if ll > y:
                res = self.get(z, y + 1, r, ll, rr)
            else:
                res = self.unite(self.get(x + 1, l, y, ll, rr), self.get(z, y + 1, r, ll, rr))
        self.pull(x, z)
        return res

    def modify(self, x, l, r, ll, rr, v, id, rid, a):
        if ll <= l and r <= rr:
            self.tree[x].apply(l, r, v, id, rid, a)
            return
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        self.push(x, l, r)
        if ll <= y:
            self.modify(x + 1, l, y, ll, rr, v, id, rid, a)
        if rr > y:
            self.modify(z, y + 1, r, ll, rr, v, id, rid, a)
        self.pull(x, z)

    def find_first_knowingly(self, x, l, r, f):
        if l == r:
            return l
        self.push(x, l, r)
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        res = 0
        if f(self.tree[x + 1]):
            res = self.find_first_knowingly(x + 1, l, y, f)
        else:
            res = self.find_first_knowingly(z, y + 1, r, f)
        self.pull(x, z)
        return res

    def find_first(self, x, l, r, ll, rr, f):
        if ll <= l and r <= rr:
            if not f(self.tree[x]):
                return -1
            return self.find_first_knowingly(x, l, r, f)
        self.push(x, l, r)
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        res = -1
        if ll <= y:
            res = self.find_first(x + 1, l, y, ll, rr, f)
        if rr > y and res == -1:
            res = self.find_first(z, y + 1, r, ll, rr, f)
        self.pull(x, z)
        return res

    def find_last_knowingly(self, x, l, r, f):
        if l == r:
            return l
        self.push(x, l, r)
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        res = 0
        if f(self.tree[z]):
            res = self.find_last_knowingly(z, y + 1, r, f)
        else:
            res = self.find_last_knowingly(x + 1, l, y, f)
        self.pull(x, z)
        return res

    def find_last(self, x, l, r, ll, rr, f):
        if ll <= l and r <= rr:
            if not f(self.tree[x]):
                return -1
            return self.find_last_knowingly(x, l, r, f)
        self.push(x, l, r)
        y = (l + r) // 2
        z = x + ((y - l + 1) << 1)
        res = -1
        if rr > y:
            res = self.find_last(z, y + 1, r, ll, rr, f)
        if ll <= y and res == -1:
            res = self.find_last(x + 1, l, y, ll, rr, f)
        self.pull(x, z)
        return res

    def get(self, ll, rr):
        assert 0 <= ll <= rr <= self.n - 1
        return self.get(0, 0, self.n - 1, ll, rr)

    def get(self, p):
        assert 0 <= p <= self.n - 1
        return self.get(0, 0, self.n - 1, p, p)

    def modify(self, ll, rr, v, id, rid, a):
        assert 0 <= ll <= rr <= self.n - 1
        self.modify(0, 0, self.n - 1, ll, rr, v, id, rid, a)

    def find_first(self, ll, rr, f):
        assert 0 <= ll <= rr <= self.n - 1
        return self.find_first(0, 0, self.n - 1, ll, rr, f)

    def find_last(self, ll, rr, f):
        assert 0 <= ll <= rr <= self.n - 1
        return self.find_last(0, 0, self.n - 1, ll, rr, f)

n, q = map(int, input().split())
a = list(map(int, input().split()))
w = list(map(int, input().split()))
st = id0(n)
for _ in range(q):
    x, y = map(int, input().split())
    if x < 0:
        x = -x
        x -= 1
        st.modify(x, x, y, x, n - 1 - x, a[x])
    else:
        x -= 1
        y -= 1
        v = 0
        sum = st.get(x, y).w
        pos = st.find_first(x, y, lambda a: (v + a.w) * 2 >= sum)
        l = st.get(x, pos)
        r = st.get(pos, y)
        res = 0
        res += r.Wp - r.fp - Modular(a[pos] - pos) * r.w
        res += Modular(a[pos] - pos) * l.w + l.fp - l.Wp
        print(res)
