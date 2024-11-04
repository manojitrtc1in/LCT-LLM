import random
import time

class Cerr:
    def __lshift__(self, other):
        return self

cerr = Cerr()

class Modular:
    def __init__(self, value):
        self.value = self.normalize(value)
    
    def normalize(self, x):
        v = x % self.mod()
        if v < 0:
            v += self.mod()
        return v
    
    def __call__(self):
        return self.value
    
    def __int__(self):
        return int(self.value)
    
    def __float__(self):
        return float(self.value)
    
    def __str__(self):
        return str(self.value)
    
    def __eq__(self, other):
        return self.value == other.value
    
    def __ne__(self, other):
        return self.value != other.value
    
    def __lt__(self, other):
        return self.value < other.value
    
    def __le__(self, other):
        return self.value <= other.value
    
    def __gt__(self, other):
        return self.value > other.value
    
    def __ge__(self, other):
        return self.value >= other.value
    
    def __add__(self, other):
        return Modular(self.value + other.value)
    
    def __sub__(self, other):
        return Modular(self.value - other.value)
    
    def __mul__(self, other):
        return Modular(self.value * other.value)
    
    def __truediv__(self, other):
        return Modular(self.value / other.value)
    
    def __pow__(self, other):
        return Modular(pow(self.value, other.value, self.mod()))
    
    def __iadd__(self, other):
        self.value = self.normalize(self.value + other.value)
        return self
    
    def __isub__(self, other):
        self.value = self.normalize(self.value - other.value)
        return self
    
    def __imul__(self, other):
        self.value = self.normalize(self.value * other.value)
        return self
    
    def __itruediv__(self, other):
        self.value = self.normalize(self.value / other.value)
        return self
    
    def __neg__(self):
        return Modular(-self.value)
    
    def __pos__(self):
        return Modular(self.value)
    
    def __abs__(self):
        return Modular(abs(self.value))
    
    def __invert__(self):
        return Modular(pow(self.value, -1, self.mod()))
    
    def __int__(self):
        return int(self.value)
    
    def __float__(self):
        return float(self.value)
    
    def __complex__(self):
        return complex(self.value)
    
    def __hash__(self):
        return hash(self.value)
    
    def mod(self):
        return 998244353

class Mint(Modular):
    def __init__(self, value):
        super().__init__(value)

class hasher:
    def __call__(self, x):
        return x[0] * 1234567 + x[1] * 7893215

def can(n):
    if n == 1:
        return True
    
    global it
    x = n // 2
    y = (n + 1) // 2
    if not can(x) or not can(y):
        return False
    p0 = nxt[it][0]
    p1 = nxt[it][1]
    if p0 == len(s) or ind[p0] + x - 1 >= len(o[0]):
        p0 = len(s)
    else:
        p0 = o[0][ind[p0] + x - 1]
    if p1 == len(s) or ind[p1] + y - 1 >= len(o[1]):
        p1 = len(s)
    else:
        p1 = o[1][ind[p1] + y - 1]
    p0 = min(p0, p1)
    if p0 == len(s):
        return False
    it = p0 + 1
    return True

def id_gen(l, r):
    if l == r:
        return
    m = (l + r - 1) // 2
    id_gen(l, m)
    id_gen(m + 1, r)
    a = l
    b = m + 1
    c = l
    while a <= m and b <= r:
        if s[it] == '0':
            mas[c] = id[a]
            a += 1
        else:
            mas[c] = id[b]
            b += 1
        c += 1
        it += 1
    while a <= m:
        mas[c] = id[a]
        a += 1
        c += 1
    while b <= r:
        mas[c] = id[b]
        b += 1
        c += 1
    for i in range(l, r + 1):
        id[i] = mas[i]

def go(n, cert):
    global it
    it = 0
    if not cert:
        return can(n)
    it = 0
    can(n)
    assert it == len(s)

    it = 0
    id = list(range(n))
    id_gen(0, n - 1)
    assert it == len(s)
    p = [0] * n
    for i in range(n):
        p[id[i]] = i
    print(n)
    print(' '.join(str(i + 1) for i in p))
    exit(0)

def solve():
    global s, o, ind, nxt, it
    o = [[], []]
    ind = []
    nxt = []
    it = 0
    for i in range(2, maxn):
        x = i // 2
        y = i - x
        len[i] = (len[x][0] + len[y][0] + x, len[x][1] + len[y][1] + x + y - 1)
        seg[i] = [seg[x][0] + seg[y][0], seg[x][1] + seg[y][1]]
        seg[i][0] += x
        seg[i][1] += y
    s = input()
    counter = [0, 0]
    nxt = [[0, 0] for _ in range(len(s) + 1)]
    ind = [0] * len(s)
    for i in range(len(s)):
        c = int(s[i])
        counter[c] += 1
        ind[i] = len(o[c])
        o[c].append(i)
    nxt[len(s)][0] = nxt[len(s)][1] = len(s)
    for i in range(len(s) - 1, -1, -1):
        nxt[i][0] = nxt[i + 1][0]
        nxt[i][1] = nxt[i + 1][1]
        nxt[i][int(s[i])] = i
    l = 0
    r = 1e5 + 10
    while r - l > 1:
        m = (l + r) // 2
        if go(m, False):
            l = m
        else:
            r = m
    go(l, True)

ts = 1

for its in range(1, ts + 1):
    solve()
