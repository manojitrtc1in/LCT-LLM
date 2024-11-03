class Matrix:
    def __init__(self):
        self.d = [[0, 0], [0, 0]]
    
    def init(self):
        self.d = [[0, 0], [0, 0]]
    
    def sum(self):
        res = 0
        for i in range(2):
            for j in range(2):
                res += self.d[i][j]
        return res

def multiply(a, b):
    c = Matrix()
    for i in range(2):
        for j in range(2):
            tmp = 0
            for k in range(2):
                tmp += a.d[i][k] * b.d[k][j]
            c.d[i][j] = tmp
    return c

def power(a, b):
    c = Matrix()
    c.d = [[1, 0], [0, 1]]
    while b:
        if b & 1:
            c = multiply(c, a)
        a = multiply(a, a)
        b //= 2
    return c

def solve():
    ch = input().strip()
    if ch == '0':
        return 1 << 0
    if ch == '1':
        return 1 << 15
    if ch == '?':
        return (1 << 3) | (1 << 12)
    
    x = solve()
    ch = input().strip()
    y = solve()
    
    res = 0
    for i in range(16):
        if not x & (1 << i):
            continue
        for j in range(16):
            if not y & (1 << j):
                continue
            if ch == '^':
                k = i ^ j
            elif ch == '&':
                k = i & j
            elif ch == '|':
                k = i | j
            res |= 1 << k
    return res

N = int(input())
print("YES" if ~0x8241 & solve() else "NO")
