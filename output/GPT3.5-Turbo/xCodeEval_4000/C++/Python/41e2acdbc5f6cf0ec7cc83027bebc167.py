import sys
from collections import deque
from heapq import heappop, heappush
from math import gcd, ceil, floor, isinf, sqrt, factorial, pi, sin, cos, tan, atan2, log2
from bisect import bisect_left, bisect_right
from itertools import permutations, combinations
from functools import cmp_to_key
from operator import itemgetter
from string import ascii_lowercase, ascii_uppercase, digits
from random import randint, randrange, sample, choice
from time import time
from copy import deepcopy
from decimal import Decimal, getcontext

# Set the precision of decimal numbers
getcontext().prec = 30

# Constants
MOD = int(1e9) + 7
INF = float('inf')
EPS = 1e-9

# Functions
def add(x, y):
    x += y
    if x >= MOD:
        x -= MOD
    return x

def sub(x, y):
    x -= y
    if x < 0:
        x += MOD
    return x

def powlog2(v):
    return 1 << (31 - v.bit_length())

def solve2(x, y, k, bonus=0):
    if x <= 0 or y <= 0 or k <= 0:
        return 0
    if x < y:
        x, y = y, x
    ty = powlog2(y)
    tx = powlog2(x)
    res = 0
    txk = min(tx, k)
    if tx == ty:
        res = txk * ty % MOD * (txk + 1 + bonus * 2) % MOD
        res = add(res, solve2(x - tx, tx, k - tx, bonus + tx))
        res = add(res, solve2(y - tx, tx, k - tx, bonus + tx))
        res = add(res, solve2(x - tx, y - tx, k, bonus))
    else:
        res = txk * y % MOD * (txk + 1 + bonus * 2) % MOD
        res = add(res, solve2(x - tx, y, k - tx, bonus + tx))
    return res

# Main function
def main():
    q = int(input())
    for _ in range(q):
        x1, y1, x2, y2, k = map(int, input().split())
        ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k)
        ans %= MOD
        if ans < 0:
            ans += MOD
        print(ans * powmod(2, MOD - 2, MOD) % MOD)

# Execute the main function
if __name__ == "__main__":
    main()
