import math

def umax(a, b):
    if a < b:
        a = b

def umin(a, b):
    if a > b:
        a = b

def abs(a):
    if a > 0:
        return a
    else:
        return -a

def gcd(a, b):
    return math.gcd(a, b)

def lcm(a, b):
    return a // gcd(a, b) * b

def modpow(a, n, temp):
    res = 1
    y = a
    while n > 0:
        if n & 1:
            res = (res * y) % temp
        y = (y * y) % temp
        n //= 2
    return res % temp

def ison(mask, pos):
    return mask & (1 << pos)

def cbit(n):
    k = 0
    while n:
        n &= (n - 1)
        k += 1
    return k

def nbit(n):
    k = 0
    while n:
        n //= 2
        k += 1
    return k

mod = 10**9 + 7

def sgn(x):
    if x < 0:
        return -1
    else:
        return int(bool(x))

eps = 1e-7
pi = math.acos(-1.0)

def inc(x, y):
    x += y
    if x >= mod:
        x -= mod

def dec(x, y):
    x -= y
    if x < 0:
        x += mod

def chmax(x, y):
    if y > x:
        x = y

def mulm(x, y):
    x *= y
    if x >= mod:
        x -= mod

def xo(i):
    if (i & 3) == 0:
        return i
    if (i & 3) == 1:
        return 1
    if (i & 3) == 2:
        return i + 1
    return 0

data = []

n = int(input())
tot = 0
for _ in range(n):
    k, a, x, y, m = map(int, input().split())
    tot += k
    tmp = [a]
    for j in range(2, k + 1):
        tmp.append((tmp[-1] * x + y) % m)
    data.append(tmp)

q = set()
for i in range(n):
    q.add((data[i][0], (i, 0)))

ans = []
sol = []
p = 0
while len(ans) < tot:
    it = next((x for x in q if x[0] >= p), next(iter(q)))
    v = it[0]
    p = v
    o = it[1]
    ans.append(v)
    sol.append((v, o[0] + 1))
    q.remove(it)
    if o[1] + 1 < len(data[o[0]]):
        q.add((data[o[0]][o[1] + 1], (o[0], o[1] + 1)))

bad = 0
for i in range(1, len(ans)):
    if ans[i - 1] > ans[i]:
        bad += 1

print(bad)
if tot <= 200000:
    for i in range(len(sol)):
        print(sol[i][0], sol[i][1])
