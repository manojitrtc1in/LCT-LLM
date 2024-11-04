import sys
from collections import defaultdict
from heapq import *
from math import *
from bisect import *
from io import BytesIO, IOBase
from itertools import *
from operator import *
from typing import *


def solve2(x: int, y: int, k: int, bonus: int = 0) -> int:
    if x <= 0 or y <= 0 or k <= 0:
        return 0
    if x < y:
        x, y = y, x
    ty = 1 << (63 - __builtin_clzll(y))
    tx = 1 << (63 - __builtin_clzll(x))
    res = 0
    txk = min(tx, k)
    if tx == ty:
        res = txk * ty % mod * (txk + 1 + bonus * 2) % mod
        res += solve2(x - tx, tx, k - tx, bonus + tx)
        res += solve2(y - tx, tx, k - tx, bonus + tx)
        res += solve2(x - tx, y - tx, k, bonus)
    else:
        res = txk * y % mod * (txk + 1 + bonus * 2) % mod
        res += solve2(x - tx, y, k - tx, bonus + tx)
    return res


def main():
    q = int(input())
    for _ in range(q):
        x1, y1, x2, y2, k = map(int, input().split())
        ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k)
        ans %= mod
        if ans < 0:
            ans += mod
        print(ans * powmod(2, mod - 2, mod) % mod)


if __name__ == "__main__":
    main()
