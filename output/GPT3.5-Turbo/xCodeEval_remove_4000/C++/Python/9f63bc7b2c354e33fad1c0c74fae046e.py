class modint_base:
    pass

class static_modint_base(modint_base):
    pass

class id0(static_modint_base):
    def __init__(self, v):
        self.v = v % self.umod()
    
    def __add__(self, other):
        return id0(self.v + other.v)
    
    def __sub__(self, other):
        return id0(self.v - other.v)
    
    def __mul__(self, other):
        return id0(self.v * other.v)
    
    def __truediv__(self, other):
        return id0(self.v * other.inv())
    
    def __pow__(self, n):
        x = self
        r = id0(1)
        while n:
            if n & 1:
                r *= x
            x *= x
            n >>= 1
        return r
    
    def inv(self):
        return self.pow(self.umod() - 2)
    
    @staticmethod
    def mod():
        return 998244353
    
    @staticmethod
    def raw(v):
        return id0(v)
    
    @staticmethod
    def umod():
        return 998244353

class id5(modint_base):
    def __init__(self, v):
        self.v = v % self.mod()
    
    def __add__(self, other):
        return id5(self.v + other.v)
    
    def __sub__(self, other):
        return id5(self.v - other.v)
    
    def __mul__(self, other):
        return id5(self.v * other.v)
    
    def __truediv__(self, other):
        return id5(self.v * other.inv())
    
    def __pow__(self, n):
        x = self
        r = id5(1)
        while n:
            if n & 1:
                r *= x
            x *= x
            n >>= 1
        return r
    
    def inv(self):
        eg = self.id2(self.v, self.mod())
        return eg[1]
    
    @staticmethod
    def mod():
        return id5.bt.umod()
    
    @staticmethod
    def set_mod(m):
        id5.bt = barrett(m)
    
    @staticmethod
    def raw(v):
        return id5(v)
    
    @staticmethod
    def umod():
        return id5.bt.umod()

class barrett:
    def __init__(self, m):
        self.m = m
        self.im = (1 << 64) // m + 1
    
    def umod(self):
        return self.m
    
    def mul(self, a, b):
        z = a
        z *= b
        x = ((z * self.im) >> 64)
        v = z - x * self.m
        if self.m <= v:
            v += self.m
        return v

class mint(id0):
    pass

def get(i, z):
    l1 = 1 * i * z
    r1 = 1 * (i + i) * z
    ans = l1
    while l1 <= r1:
        m = (l1 + r1) // 2
        if m // z > i:
            r1 = m - 1
        else:
            ans = max(ans, m)
            l1 = m + 1
    return ans

def solve():
    n, m = map(int, input().split())
    mint.set_mod(m)
    dp = [mint(0)] * (n + 1)
    p = [mint(0)] * (n + 1)
    dp[n] = mint(1)
    p[n] = mint(1)
    for i in range(n - 1, 0, -1):
        dp[i] += p[i + 1]
        for z in range(2, n // i + 1):
            r = get(i, z) + 1
            l = z * i
            dp[i] += p[l]
            if r <= n:
                dp[i] -= p[r]
        p[i] = p[i + 1] + dp[i]
    print(dp[1].val())

solve()
