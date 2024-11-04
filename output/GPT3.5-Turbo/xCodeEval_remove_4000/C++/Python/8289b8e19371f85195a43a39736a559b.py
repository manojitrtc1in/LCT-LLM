class modint:
    def __init__(self, val):
        self.mod = modint.get_mod()
        self.val = val % self.mod

    def __lt__(self, other):
        return self.val < other.val

    def __add__(self, other):
        return modint(self.val + other.val)

    def __sub__(self, other):
        return modint(self.val - other.val)

    def __mul__(self, other):
        return modint(self.val * other.val)

    def __truediv__(self, other):
        return self * other.inverse()

    def __neg__(self):
        return modint(self.mod - self.val)

    def __eq__(self, other):
        return self.val == other.val

    def __ne__(self, other):
        return self.val != other.val

    def inverse(self):
        a = self.val
        b = self.mod
        u = 1
        v = 0
        while b > 0:
            t = a // b
            a -= t * b
            u -= t * v
            a, b = b, a
            u, v = v, u
        return modint(u)

    def pow(self, n):
        ret = modint(1)
        mul = modint(self.val)
        while n > 0:
            if n & 1:
                ret *= mul
            mul *= mul
            n >>= 1
        return ret

    @staticmethod
    def get_mod():
        return 1000000007


class id4:
    def __init__(self, val):
        self.mod = id4.get_mod()
        self.val = val % self.mod

    def __lt__(self, other):
        return self.val < other.val

    def __add__(self, other):
        return id4(self.val + other.val)

    def __sub__(self, other):
        return id4(self.val - other.val)

    def __mul__(self, other):
        a = self.val
        b = other.val
        xh = (a >> 16) & 0xffff
        xl = a & 0xffff
        yh = (b >> 16) & 0xffff
        yl = b & 0xffff
        h = xh * yh
        m = xh * yl + xl * yh
        l = xl * yl
        ret = (h << 16) + l
        ret += (m & 0xffff) << 16
        ret += (m >> 16)
        ret %= self.mod
        return id4(ret)

    def __truediv__(self, other):
        return self * other.inverse()

    def __neg__(self):
        return id4(self.mod - self.val)

    def __eq__(self, other):
        return self.val == other.val

    def __ne__(self, other):
        return self.val != other.val

    def inverse(self):
        a = self.val
        b = self.mod
        u = 1
        v = 0
        while b > 0:
            t = a // b
            a -= t * b
            u -= t * v
            a, b = b, a
            u, v = v, u
        return id4(u)

    def pow(self, n):
        ret = id4(1)
        mul = id4(self.val)
        while n > 0:
            if n & 1:
                ret *= mul
            mul *= mul
            n >>= 1
        return ret

    @staticmethod
    def get_mod():
        return 0


class Group_Add:
    @staticmethod
    def op(x, y):
        return x + y

    @staticmethod
    def inverse(x):
        return -x

    @staticmethod
    def power(x, n):
        return n * x

    @staticmethod
    def unit():
        return 0

    commute = True


class id2:
    def __init__(self, n):
        self.n = n
        self.log = 1
        while (1 << self.log) < n:
            self.log += 1
        self.size = 1 << self.log
        self.laz = [Group_Add.unit()] * (self.size << 1)

    def reset(self):
        self.laz = [Group_Add.unit()] * (self.size << 1)

    def all_apply(self, k, a):
        self.laz[k] = Group_Add.op(self.laz[k], a)

    def get(self, p):
        assert 0 <= p < self.n
        p += self.size
        for i in range(self.log, 0, -1):
            self.push(p >> i)
        return self.laz[p]

    def get_all(self):
        for i in range(self.size):
            self.push(i)
        return self.laz[self.size : self.size + self.n]

    def apply(self, l, r, a):
        assert 0 <= l <= r <= self.n
        if l == r:
            return

        l += self.size
        r += self.size

        if not Group_Add.commute:
            for i in range(self.log, 0, -1):
                if (l >> i) << i != l:
                    self.push(l >> i)
                if ((r - 1) >> i) << i != r - 1:
                    self.push((r - 1) >> i)

        l2 = l
        r2 = r
        while l < r:
            if l & 1:
                self.all_apply(l, a)
                l += 1
            if r & 1:
                r -= 1
                self.all_apply(r, a)
            l >>= 1
            r >>= 1
        l = l2
        r = r2

    def debug(self):
        print("dualsegtree getall:", self.get_all())

def solve():
    N, mod = map(int, input().split())
    modint.get_mod = lambda: mod

    seg = id2(Group_Add)
    seg.apply(1, 2, modint(1))

    for n in range(1, N + 1):
        dp = seg.get(n)
        seg.apply(n + 1, N + 1, dp)
        z = 2
        while True:
            l = n * z
            r = (n + 1) * z
            if l > N:
                break
            z += 1
            r = min(r, N + 1)
            seg.apply(l, r, dp)
    print(seg.get(N))

T = 1

for _ in range(T):
    solve()
