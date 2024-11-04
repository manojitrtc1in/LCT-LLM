mod = 1000000007

def add(x, y):
    x += y
    if x >= mod:
        x -= mod

def sub(x, y):
    x -= y
    if x < 0:
        x += mod

def solve2(x, y, k, bonus=0):
    if x <= 0 or y <= 0 or k <= 0:
        return 0
    if x < y:
        x, y = y, x
    ty = 1
    while ty * 2 <= y:
        ty *= 2
    tx = 1
    while tx * 2 <= x:
        tx *= 2
    res = 0
    txk = min(tx, k)
    if tx == ty:
        res = txk * (txk + 1) % mod * ty + bonus * txk * 2 % mod * ty
        res %= mod
        res += solve2(x - tx, tx, k - tx, bonus + tx)
        res += solve2(y - tx, tx, k - tx, bonus + tx)
        res += solve2(x - tx, y - tx, k, bonus)
    else:
        res = txk * (txk + 1) % mod * y + bonus * txk * 2 % mod * y
        res %= mod
        res += solve2(x - tx, y, k - tx, bonus + tx)
    return res

q = int(input())
for _ in range(q):
    x1, y1, x2, y2, k = map(int, input().split())
    ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k)
    ans %= mod
    if ans < 0:
        ans += mod
    ans = ans * pow(2, mod - 2, mod) % mod
    print(ans)
