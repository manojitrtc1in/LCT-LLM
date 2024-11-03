import random
import math
import heapq
from collections import deque
from itertools import permutations, combinations
from functools import reduce
from operator import add, mul, sub, truediv
from copy import deepcopy
from sys import stdin, stdout, setrecursionlimit
from bisect import bisect_left, bisect_right
from decimal import Decimal, getcontext
from heapq import heappush, heappop, heapify
from collections import Counter, defaultdict
from math import gcd, ceil, floor, sqrt, log2, log10, factorial

# Constants
INF = float('inf')
MOD = int(1e9) + 7

# Functions
def lcm(a, b):
    return abs(a * b) // gcd(a, b)

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n % 2 == 0 or n % 3 == 0:
        return False
    i = 5
    while i * i <= n:
        if n % i == 0 or n % (i + 2) == 0:
            return False
        i += 6
    return True

def sieve_of_eratosthenes(n):
    prime = [True for _ in range(n + 1)]
    p = 2
    while p * p <= n:
        if prime[p]:
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1
    primes = []
    for p in range(2, n + 1):
        if prime[p]:
            primes.append(p)
    return primes

def power(x, y, p):
    res = 1
    x %= p
    while y > 0:
        if y & 1:
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res

def mod_inverse(a, p):
    return power(a, p - 2, p)

def ncr(n, r, p):
    if r == 0:
        return 1
    fact = [1] * (n + 1)
    for i in range(2, n + 1):
        fact[i] = (fact[i - 1] * i) % p
    return (fact[n] * mod_inverse(fact[r], p) * mod_inverse(fact[n - r], p)) % p

def solve():
    n, m, k = map(int, input().split())
    a = []
    for _ in range(n):
        s = input()
        a.append(list(map(int, input().split())))
    ans = 0
    for i in range(n):
        for j in range(n):
            if i != j:
                val = 0
                for l in range(m):
                    if a[i][l] < a[j][l]:
                        val += a[j][l] - a[i][l]
                if val <= k:
                    ans = max(ans, sum(a[j]) - sum(a[i]))
    print(ans)

# Main
if __name__ == "__main__":
    solve()
