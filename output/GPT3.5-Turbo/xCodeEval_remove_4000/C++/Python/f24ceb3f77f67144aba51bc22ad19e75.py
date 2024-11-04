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
    def __init__(self, n, special=False):
        if special:
            self.n = -1
            return
        if n >= 0 and n < mod:
            self.n = n
            return
        n %= mod
        if n < 0:
            n += mod
        self.n = n
    
    def __iadd__(self, other):
        if self.n == -1 or other.n == -1:
            raise Exception("Illegal state")
        self.n += other.n
        if self.n >= mod:
            self.n -= mod
        return self
    
    def __isub__(self, other):
        if self.n == -1 or other.n == -1:
            raise Exception("Illegal state")
        self.n -= other.n
        if self.n < 0:
            self.n += mod
        return self
    
    def __imul__(self, other):
        if self.n == -1 or other.n == -1:
            raise Exception("Illegal state")
        self.n = (self.n * other.n) % mod
        return self
    
    def __idiv__(self, other):
        if other.n == 0:
            raise Exception("Division by zero")
        if self.n == -1 or other.n == -1:
            raise Exception("Illegal state")
        return self.__imul__(other.inverse())
    
    def __neg__(self):
        if self.n == -1:
            raise Exception("Illegal state")
        if self.n == 0:
            return 0
        return modint(mod - self.n)
    
    def inverse(self):
        if self.n == -1:
            raise Exception("Illegal state")
        x, y = 0, 0
        g = gcd(self.n, mod, x, y)
        if g != 1:
            raise Exception("not inversable")
        return x
    
    def log(self, alpha):
        if self.n == -1 or alpha.n == -1:
            raise Exception("Illegal state")
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
        i = 1
        while True:
            if pow in base:
                return exp * i + base[pow]
            pow *= step
            i += 1

id5 = modint(-1, True)

def operator_add(a, b):
    return modint(a) + b

def operator_sub(a, b):
    return modint(a) - b

def operator_mul(a, b):
    return modint(a) * b

def operator_div(a, b):
    return modint(a) / b

def operator_eq(a, b):
    return a.n == b.n

def operator_ne(a, b):
    return a.n != b.n

class BVerkhnyayaYacheika:
    def solve(self):
        n = int(input())
        m = int(input())
        
        mod = m
        ft = [modint(0) for _ in range(n + 1)]
        ft[n] = modint(1)
        for i in range(n - 1, 0, -1):
            res = ft[i + 1]
            for z in range(2, n // i + 1):
                res += ft[z * i]
            ft[i] = res
        print(ft[1])

solver = BVerkhnyayaYacheika()
solver.solve()
