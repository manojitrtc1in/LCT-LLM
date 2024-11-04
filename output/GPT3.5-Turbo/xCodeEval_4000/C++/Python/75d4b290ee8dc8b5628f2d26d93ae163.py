MOD7 = 1000000007
MOD9 = 1000000009
MODF = 998244353

mod = MOD7

def gcd(a, b, x, y):
    if a == 0:
        x = 0
        y = 1
        return b
    d = gcd(b % a, a, y, x)
    x -= (b // a) * y
    return d

class modint:
    def __init__(self, n):
        if n >= 0 and n < mod:
            self.n = n
            return
        n %= mod
        if n < 0:
            n += mod
        self.n = n

    def __iadd__(self, other):
        self.n += other.n
        if self.n >= mod:
            self.n -= mod
        return self

    def __isub__(self, other):
        self.n -= other.n
        if self.n < 0:
            self.n += mod
        return self

    def __imul__(self, other):
        self.n = (self.n * other.n) % mod
        return self

    def __idiv__(self, other):
        if other.n == 0:
            raise ZeroDivisionError("Division by zero")
        return self.__imul__(other.inverse())

    def __neg__(self):
        if self.n == 0:
            return 0
        return modint(mod - self.n)

    def inverse(self):
        x, y = 0, 0
        g = gcd(self.n, mod, x, y)
        if g != 1:
            raise Exception("not inversable")
        return x

    def __add__(self, other):
        return modint(self.n).__iadd__(other)

    def __sub__(self, other):
        return modint(self.n).__isub__(other)

    def __mul__(self, other):
        return modint(self.n).__imul__(other)

    def __div__(self, other):
        return modint(self.n).__idiv__(other)

    def __str__(self):
        return str(self.n)

    def __eq__(self, other):
        return self.n == other.n

    def __ne__(self, other):
        return self.n != other.n

    def __hash__(self):
        return hash(self.n)

    def log(self, alpha):
        base = {}
        exp = 0
        pow = 1
        inv = self
        alInv = alpha.inverse()
        while exp * exp < mod:
            if inv == 1:
                return exp
            base[inv] = exp
            exp += 1
            pow *= alpha
            inv *= alInv
        step = pow
        while True:
            if pow in base:
                return exp * i + base[pow]
            pow *= step
            i += 1

class TaskD:
    def solve(self, inp, outp):
        n = int(inp.readline())
        x, v, p = [], [], []
        for _ in range(n):
            xi, vi, pi = map(int, inp.readline().split())
            x.append(xi)
            v.append(vi)
            p.append(pi)
        mod = MODF
        pp = [[modint(0) for _ in range(4)] for _ in range(4 * n)]
        tmp = [[modint(0) for _ in range(4)] for _ in range(4 * n)]
        allowed = [[True for _ in range(4)] for _ in range(n)]
        join = lambda left, right, result, at: [result.__setitem__(i, sum([left[i][j] * right[j][k] for j in range(2) for k in range(2) if allowed[at][2 * j + k]])) for i in range(4)]
        def init(root, left, right):
            pp[root] = [modint(0) for _ in range(4)]
            tmp[root] = [modint(0) for _ in range(4)]
            if left + 1 == right:
                pp[root][0] = modint(100 - p[left]) / 100
                pp[root][3] = 1 - pp[root][0]
            else:
                mid = (left + right) // 2
                init(2 * root + 1, left, mid)
                init(2 * root + 2, mid, right)
                join(pp[2 * root + 1], pp[2 * root + 2], pp[root], mid)
        init(0, 0, n)
        events = []
        for i in range(1, n):
            events.append((2, i, x[i] - x[i - 1], v[i] + v[i - 1]))
            if v[i] > v[i - 1]:
                events.append((0, i, x[i] - x[i - 1], v[i] - v[i - 1]))
            elif v[i] < v[i - 1]:
                events.append((3, i, x[i] - x[i - 1], v[i - 1] - v[i]))
        events.sort(key=lambda e: e[2] * e[3])
        answer = modint(0)
        for e in events:
            left = [tmp[0][e[0] // 2], tmp[0][2 + e[0] // 2]]
            right = [tmp[0][e[0] % 2 * 2], tmp[0][e[0] % 2 * 2 + 1]]
            answer += modint(e[2]) / e[3] * sum(left) * sum(right)
            allowed[e[1]][e[0]] = False
            for i in range(e[1], n):
                join(pp[2 * root + 1], pp[2 * root + 2], pp[root], mid)
        outp.write(str(answer) + "\n")

solver = TaskD()
solver.solve(input, print)
