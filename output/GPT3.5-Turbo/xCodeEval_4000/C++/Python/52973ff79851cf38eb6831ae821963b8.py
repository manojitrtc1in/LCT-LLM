import sys
from typing import List, Tuple

def add(x: int, y: int) -> int:
    x += y
    if x >= mod:
        x -= mod
    return x

def powlog2(v: int) -> int:
    return 1 << (31 - v.bit_length())

def solve2(x: int, y: int, k: int, bonus: int = 0) -> int:
    if x <= 0 or y <= 0 or k <= 0:
        return 0
    if x < y:
        x, y = y, x
    if (x & (x - 1)) == 0:
        k = min(k, x)
        return k * y % mod * (k + 1 + bonus * 2) % mod
    ty = powlog2(y)
    tx = powlog2(x)
    res = 0
    txk = min(tx, k)
    if tx == ty:
        res = txk * ty % mod * (txk + 1 + bonus * 2) % mod
        res = add(res, solve2(x - tx, tx, k - tx, bonus + tx))
        res = add(res, solve2(y - tx, tx, k - tx, bonus + tx))
        res = add(res, solve2(x - tx, y - tx, k, bonus))
    else:
        res = txk * y % mod * (txk + 1 + bonus * 2) % mod
        res = add(res, solve2(x - tx, y, k - tx, bonus + tx))
    return res

def solve(q: int, queries: List[Tuple[int, int, int, int, int]]) -> List[int]:
    ans = []
    for i in range(q):
        x1, y1, x2, y2, k = queries[i]
        res = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k)
        res %= mod
        if res < 0:
            res += mod
        ans.append(int(res * powmod(2, mod - 2, mod) % mod))
    return ans

if __name__ == "__main__":
    q = int(input())
    queries = []
    for _ in range(q):
        x1, y1, x2, y2, k = map(int, input().split())
        queries.append((x1, y1, x2, y2, k))
    ans = solve(q, queries)
    for res in ans:
        print(res)
