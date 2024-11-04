import math

eps = 0.0000001
pi = math.acos(-1)

def fastpower(b, p):
    ans = 1
    while p:
        if p % 2:
            ans = ans * b
        b = b * b
        p //= 2
    return ans

def fastpowermod(b, p, m):
    ans = 1
    while p:
        if p % 2:
            ans = (ans * b) % m
        b = (b * b) % m
        p //= 2
    return ans % m

def makeitstring(n):
    ans = ""
    ch = False
    if n < 0:
        n *= -1
        ch = True
    if n == 0:
        ans = "0"
    while n:
        mo = n % 10
        mo += 48
        m = chr(mo)
        ans = m + ans
        n //= 10
    if ch:
        ans = "-" + ans
    return ans

def compare(f, s):
    return abs(f - s) < eps

def gcd(a, b):
    while b != 0:
        a2 = a
        a = b
        b = a2 % b
    return a

N = int(1e2 + 1)

powcnt = [0] * N
ans = 0

def preprocess(num):
    global powcnt
    for i in range(30, -1, -1):
        if num >= (1 << i):
            num -= (1 << i)
            powcnt[i] += 1

def solve(curp):
    global powcnt, ans
    for i in range(curp, 31):
        if powcnt[i] > 0:
            powcnt[i] -= 1
            ans += 1
            for j in range(curp, i):
                powcnt[j] += 1
            break

n, m = map(int, input().split())
v = []
for i in range(n):
    x = int(input())
    preprocess(x)
for i in range(m):
    x = int(input())
    v.append(x)
v.sort()
for i in range(len(v)):
    solve(v[i])
print(ans)
