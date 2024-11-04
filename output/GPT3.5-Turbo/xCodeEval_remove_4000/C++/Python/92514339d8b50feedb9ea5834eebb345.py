import sys
input = sys.stdin.readline

mod = 998244353

def add(x, y):
    x += y
    if x >= mod:
        x -= mod

def sub(x, y):
    x -= y
    if x < 0:
        x += mod

def pow2(v):
    return 1 << (63 - v.bit_length())

def solve2(x, y, k, bonus=0):
    if x <= 0 or y <= 0 or k <= 0:
        return 0
    if x < y:
        x, y = y, x
    ty = pow2(y)
    tx = pow2(x)
    res = 0
    txk = min(tx, k)
    if tx == ty:
        res = txk * ty % mod * (txk + 1 + bonus * 2) % mod
        add(res, solve2(x - tx, tx, k - tx, bonus + tx))
        add(res, solve2(y - tx, tx, k - tx, bonus + tx))
        add(res, solve2(x - tx, y - tx, k, bonus))
    else:
        res = txk * y % mod * (txk + 1 + bonus * 2) % mod
        add(res, solve2(x - tx, y, k - tx, bonus + tx))
    return res

q = int(input())
for _ in range(q):
    x1, y1, x2, y2, k = map(int, input().split())
    ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k)
    ans %= mod
    if ans < 0:
        ans += mod
    print(ans * pow(pow(2, mod - 2, mod), mod) % mod)
