import sys
from typing import List, Tuple

def add(x: int, y: int) -> int:
    x += y
    if x >= mod:
        x -= mod
    return x

def sub(x: int, y: int) -> int:
    x -= y
    if x < 0:
        x += mod
    return x

def solve2(x: int, y: int, k: int, bonus: int = 0) -> int:
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
        res = add(res, solve2(x - tx, tx, k - tx, bonus + tx))
        res = add(res, solve2(y - tx, tx, k - tx, bonus + tx))
        res = add(res, solve2(x - tx, y - tx, k, bonus))
    else:
        res = txk * (txk + 1) % mod * y + bonus * txk * 2 % mod * y
        res %= mod
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
        ans.append(res * powmod(2, mod - 2, mod) % mod)
    return ans

def main() -> None:
    q = int(input())
    queries = []
    for _ in range(q):
        x1, y1, x2, y2, k = map(int, input().split())
        queries.append((x1, y1, x2, y2, k))
    ans = solve(q, queries)
    for res in ans:
        print(res)

if __name__ == "__main__":
    main()
