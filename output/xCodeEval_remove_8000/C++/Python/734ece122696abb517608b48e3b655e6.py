def mod_mul(x, y, n):
    d = int(x * y / n)
    d = x * y - n * d
    while d < 0:
        d += n
    while d >= n:
        d -= n
    return d

def powmod(x, t, base):
    res = 1
    while t > 0:
        if t & 1:
            res = mod_mul(res, x, base)
        x = mod_mul(x, x, base)
        t >>= 1
    return res

def id0(n, base):
    n2 = n - 1
    s = 0
    while n2 & 1 == 0:
        n2 >>= 1
        s += 1
    res = powmod(base, n2, n)
    if res == 1 or res == n - 1:
        return 1
    s -= 1
    while s >= 0:
        res = mod_mul(res, res, n)
        if res == n - 1:
            return 1
        s -= 1
    return 0

def isPrime(n):
    if n < 2:
        return False
    if n < 4:
        return True
    if id0(n, 2) == 0:
        return False
    if id0(n, 3) == 0:
        return False
    if n < 1373653:
        return True
    if id0(n, 5) == 0:
        return False
    if n < 25326001:
        return True
    if id0(n, 7) == 0:
        return False
    if n == 3215031751:
        return False
    if n < 25000000000:
        return True
    if id0(n, 11) == 0:
        return False
    if n < 2152302898747:
        return True
    if id0(n, 13) == 0:
        return False
    if id0(n, 17) == 0:
        return False
    if n < 341550071728321:
        return True
    if id0(n, 19) == 0:
        return False
    if id0(n, 23) == 0:
        return False
    if id0(n, 29) == 0:
        return False
    if id0(n, 31) == 0:
        return False
    if id0(n, 37) == 0:
        return False
    return True

def solve(l, r):
    if l > r:
        return 0
    sum = 0
    for i in range(l, r + 1):
        if i % 2 == 0 or i % 3 == 0 or i % 7 == 0 or not isPrime(i):
            continue
        if i % 4 == 1:
            sum += 1
    return sum

l, r = map(int, input().split())
l -= 1
L = l // 100000
R = r // 100000
sum1 = 0
for i in range(L + 1):
    sum1 += ans[i]
sum1 += solve(L * 100000 + 1, l)
if l >= 2 and l < 100000:
    sum1 += 1
sum2 = 0
for i in range(R + 1):
    sum2 += ans[i]
sum2 += solve(R * 100000 + 1, r)
if r >= 2 and r < 100000:
    sum2 += 1
print(sum2 - sum1)
