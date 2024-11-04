maxn = 1e5+5
mod = 1e9+7

def qpow(a, b):
    res = 1
    while b:
        if b & 1:
            res = res * a % mod
        a = a * a % mod
        b >>= 1
    return res

class graph:
    def __init__(self):
        self.head = [-1] * maxn
        self.nxt = [0] * (maxn << 1)
        self.to = [0] * (maxn << 1)
        self.w = [0] * (maxn << 1)
        self.sz = 0
    
    def init(self):
        self.head = [-1] * maxn
    
    def push(self, a, b, c):
        self.nxt[self.sz] = self.head[a]
        self.to[self.sz] = b
        self.w[self.sz] = c
        self.head[a] = self.sz
        self.sz += 1
    
    def __getitem__(self, a):
        return self.to[a]

num = [
    0,4,7,44,47,74,77,444,447,474,477,
    744,747,774,777,4444,4447,4474,4477,4744,4747,
    4774,4777,7444,7447,7474,7477,7744,7747,7774,7777,
    44444,44447,44474,44477,44744,44747,44774,44777,47444,47447,
    47474,47477,47744,47747,47774,47777,74444,74447,74474,74477,
