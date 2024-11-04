import math

SQ = 100 * 1000
N = 3e8 + SQ
l, r = map(int, input().split())

def prime(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return n > 1

def check(n):
    if n == 2:
        return True
    if n % 4 != 1:
        return False
    return prime(n)

def calc(l, r):
    pl = l // SQ
    pr = r // SQ
    ans = 0

    if pl == pr:
        for i in range(l, r + 1):
            if check(i):
                ans += 1
        return ans

    while l < (pl + 1) * SQ:
        if check(l):
            ans += 1
        l += 1
    while r >= pr * SQ:
        if check(r):
            ans += 1
        r -= 1

    for i in range(pl + 1, pr):
        ans += res[i]

    return ans

print(calc(l, r))
