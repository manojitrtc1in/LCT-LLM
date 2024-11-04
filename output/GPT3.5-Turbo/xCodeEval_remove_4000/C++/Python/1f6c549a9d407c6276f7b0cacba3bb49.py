mod = 998244353
K = 18

class FastIO:
    def __init__(self):
        pass

n, k = map(int, input().split())
hs = list(map(int, input().split()))

cnt = 0
for i in range(n):
    if hs[i] == hs[(i+1)%n]:
        cnt += 1

if cnt == n:
    print(0)
    exit()

class Poly:
    def __init__(self, n):
        self.c = [0] * (n + 1)

A = Poly(2e5+1000)
A.c[0] = 1
A.c[1] = (k-2) % mod
A.c[2] = 1

def power(x, n):
    res = 1
    while n > 0:
        if n % 2 == 1:
            res = (res * x) % mod
        x = (x * x) % mod
        n //= 2
    return res

def inv(x):
    return power(x, mod-2)

def add(x, y):
    return (x + y) % mod

def sub(x, y):
    return (x - y + mod) % mod

def mul(x, y):
    return (x * y) % mod

def div(x, y):
    return (x * inv(y)) % mod

def log(p):
    n = len(p.c)
    res = Poly(n)
    for i in range(1, n):
        res.c[i-1] = mul(p.c[i], inv(i))
    return res

def exp(p):
    n = len(p.c)
    res = Poly(n)
    res.c[0] = 1
    for i in range(1, n):
        for j in range(1, i+1):
            res.c[i] = add(res.c[i], mul(p.c[j], res.c[i-j]))
        res.c[i] = div(res.c[i], i)
    return res

B = log(A)
for i in range(len(B.c)):
    B.c[i] = mul(B.c[i], n-cnt)

C = exp(B)

ans = power(k, n-cnt)
for i in range(len(C.c)):
    ans = sub(ans, C.c[i])

ans = mul(ans, power(k, cnt))
print(ans)
