mod = 998244353
class modint:
    def __init__(self, val):
        self.val = val % mod
    
    def __add__(self, other):
        if isinstance(other, modint):
            return modint(self.val + other.val)
        else:
            return modint(self.val + other)
    
    def __sub__(self, other):
        if isinstance(other, modint):
            return modint(self.val - other.val)
        else:
            return modint(self.val - other)
    
    def __mul__(self, other):
        if isinstance(other, modint):
            return modint(self.val * other.val)
        else:
            return modint(self.val * other)
    
    def __truediv__(self, other):
        if isinstance(other, modint):
            return self * other.inv()
        else:
            return self * modint(other).inv()
    
    def __pow__(self, n):
        res = modint(1)
        x = self
        while n > 0:
            if n & 1:
                res *= x
            x *= x
            n >>= 1
        return res
    
    def inv(self):
        return self.__pow__(mod - 2)
    
    def __str__(self):
        return str(self.val)
    
    def __repr__(self):
        return str(self.val)

def in_v(szs):
    if len(szs) == 0:
        return int(input())
    else:
        s = szs[0]
        return [in_v(szs[1:]) for _ in range(s)]

def out(v):
    if isinstance(v, list):
        for i in range(len(v)):
            if i > 0:
                print(' ', end='')
            out(v[i])
        print()
    else:
        print(v, end='')

def main():
    n, m = map(int, input().split())
    a = in_v([n])
    w = in_v([n])
    zw = 0
    ow = 0
    for i in range(n):
        if a[i]:
            ow += w[i]
        else:
            zw += w[i]
    s = zw + ow
    inv = [modint(0) for _ in range(2 * m + 1)]
    for d in range(-m, m + 1):
        if s + d > 0:
            inv[d + m] = modint(1) / (s + d)
    dp = [[modint(0) for _ in range(2)] for _ in range(m + 1)]
    dp[0] = [modint(1), modint(1)]
    for i in range(m):
        ndp = [[modint(0) for _ in range(2)] for _ in range(m + 1)]
        for z in range(i + 1):
            o = i - z
            wz = zw - z
            wo = ow + o
            if wz < 0:
                continue
            for dz in range(-1, 1):
                nwz = wz + dz
                nz = z + (-dz)
                if nwz < 0:
                    continue
                eps = inv[wz + wo - s + m]
                p = modint(dz == -1 and wz or wo) * eps
                ndp[nz][-dz] += dp[z][-dz] * p
                ndp[nz][1 + dz] += (p + (2 * dz + 1) * eps) * dp[z][1 + dz]
        dp = ndp
    cz = modint(0)
    co = modint(0)
    for i in range(m + 1):
        cz += dp[i][0]
        co += dp[i][1]
    for i in range(n):
        out(w[i] * (cz if a[i] == 0 else co))

main()
