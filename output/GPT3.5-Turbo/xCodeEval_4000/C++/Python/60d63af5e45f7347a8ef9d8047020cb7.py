import sys
from collections import defaultdict, deque
from heapq import heappop, heappush
from math import gcd, sqrt, ceil, log2, floor, factorial, atan2, degrees
from bisect import bisect_left, bisect_right
from itertools import permutations, combinations
from functools import cmp_to_key
from random import randint, shuffle
from decimal import Decimal
from operator import add, mul, itemgetter
from string import ascii_lowercase, ascii_uppercase, digits
from queue import Queue, PriorityQueue
from copy import deepcopy
from time import time
from typing import List, Tuple, Dict, Any, Union

sys.setrecursionlimit(10**6)
INF = float('inf')
MOD = 10**9 + 7
EPS = 1e-9
PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679

def solve2(x: int, y: int, k: int, bonus: int = 0) -> int:
    if x <= 0 or y <= 0 or k <= 0:
        return 0
    if x < y:
        x, y = y, x
    if (x & (x - 1)) == 0:
        k = min(k, x)
        return (k * y * (k + 1 + bonus * 2)) % MOD
    ty = 1 << (31 - x.bit_length())
    tx = 1 << (31 - y.bit_length())
    res = 0
    txk = min(tx, k)
    if tx == ty:
        res = (txk * y * (txk + 1 + bonus * 2) + solve2(x - tx, tx, k - tx, bonus + tx) +
               solve2(y - tx, tx, k - tx, bonus + tx) + solve2(x - tx, y - tx, k, bonus)) % MOD
    else:
        res = (txk * y * (txk + 1 + bonus * 2) + solve2(x - tx, y, k - tx, bonus + tx)) % MOD
    return res

def main() -> None:
    q = int(input())
    for _ in range(q):
        x1, y1, x2, y2, k = map(int, input().split())
        ans = (solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k)) % MOD
        if ans < 0:
            ans += MOD
        print(int(ans * pow(2, MOD - 2, MOD) % MOD))

if __name__ == "__main__":
    main()
