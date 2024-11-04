import random
import time

class Cerr:
    def __init__(self):
        pass
    
    def write(self, *args, **kwargs):
        pass
    
    def flush(self):
        pass

cerr = Cerr()

class mt19937:
    def __init__(self, seed):
        self.seed = seed
    
    def rand(self):
        self.seed = (self.seed * 0x5DEECE66D + 0xB) & ((1 << 48) - 1)
        return self.seed >> 16 & ((1 << 32) - 1)
    
    def randint(self, a, b):
        return self.rand() % (b - a + 1) + a

class mt19937_64:
    def __init__(self, seed):
        self.seed = seed
    
    def rand(self):
        self.seed = (self.seed * 6364136223846793005 + 1442695040888963407) & ((1 << 64) - 1)
        return self.seed >> 32 & ((1 << 32) - 1)
    
    def randint(self, a, b):
        return self.rand() % (b - a + 1) + a

rnd = mt19937(int(time.time()))
rndll = mt19937_64(int(time.time()))

def setmin(x, y):
    x = min(x, y)

def setmax(x, y):
    x = max(x, y)

def inverse(a, m):
    u = 0
    v = 1
    while a != 0:
        t = m // a
        m -= t * a
        a, m = m, a
        u -= t * v
        u, v = v, u
    assert m == 1
    return u

class Modular:
    def __init__(self, value):
        self.value = self.normalize(value)
    
    @staticmethod
    def normalize(x):
        v = x % self.mod() if -self.mod() <= x < self.mod() else x % self.mod()
        if v < 0:
            v += self.mod()
        return v
    
    def __call__(self):
        return self.value
    
    def __int__(self):
        return int(self.value)
    
    def __float__(self):
        return float(self.value)
    
    @staticmethod
    def mod():
        return 998244353
    
    def __iadd__(self, other):
        self.value += other.value
        if self.value >= self.mod():
            self.value -= self.mod()
        return self
    
    def __isub__(self, other):
        self.value -= other.value
        if self.value < 0:
            self.value += self.mod()
        return self
    
    def __add__(self, other):
        return Modular(self.value + other.value)
    
    def __sub__(self, other):
        return Modular(self.value - other.value)
    
    def __mul__(self, other):
        return Modular(self.value * other.value)
    
    def __imul__(self, other):
        self.value = self.normalize(self.value * other.value)
        return self
    
    def __idiv__(self, other):
        self.value = self.normalize(self.value * inverse(other.value, self.mod()))
        return self
    
    def __div__(self, other):
        return Modular(self.value * inverse(other.value, self.mod()))
    
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
    
    def __str__(self):
        return str(self.value)
    
    def __repr__(self):
        return str(self.value)

class Mint(Modular):
    def __init__(self, value):
        super().__init__(value)

ld = float

llinf = 10**18 + 100

maxn = 10**3 + 100
maxw = (1 << 20) + 5
inf = 10**9 + 100
LG = 18

s = ""

it = 0

def can(n):
    global it
    if n == 1:
        return True
    x = n // 2
    y = (n + 1) // 2
    if not can(x) or not can(y):
        return False
    a = 0
    b = 0
    while it < len(s):
        if s[it] == '0':
            a += 1
        else:
            b += 1
        it += 1
        if a == x or b == y:
            break
    if a != x and b != y:
        return False
    return True

e = [[] for _ in range(maxn)]

id = [0] * maxn

mas = [0] * maxn

deg = [0] * maxn

def gen(l, r):
    if l == r:
        return
    m = (l + r - 1) // 2
    gen(l, m)
    gen(m + 1, r)
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
        if i > l:
            e[id[i - 1]].append(id[i])

def go(n):
    global it
    it = 0
    if not can(n) or it != len(s):
        return
    it = 0
    id = list(range(n))
    gen(0, n - 1)
    assert it == len(s)
    p = [0] * n
    for i in range(n):
        p[id[i]] = i
    print(n)
    print(" ".join(str(i + 1) for i in p))
    exit(0)

seg = [[0, 0] for _ in range(maxn)]

def solve():
    global s
    for i in range(2, maxn):
        x = (i + 1) // 2
        y = i - x
        for t in range(2):
            seg[i][t] = seg[x][t] + seg[y][t]
        seg[i][0] += x
        seg[i][1] += y
    s = input()
    counter = [0, 0]
    for c in s:
        counter[int(c)] += 1
    for n in range(maxn - 1, 0, -1):
        if seg[n][0] >= counter[0] and seg[n][1] >= counter[1]:
            go(n)

if __name__ == "__main__":
    if False:
        te = 0
        while True:
            te += 1
            solve()
    ts = 1
    for its in range(1, ts + 1):
        solve()
