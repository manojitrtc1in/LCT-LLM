import sys
from typing import List, Tuple

MOD = 10**9 + 7

def gcd(a: int, b: int) -> int:
    if a < b:
        a, b = b, a
    while b > 0:
        a, b = b, a % b
    return a

def solve(n: int) -> int:
    primeFactors = [[] for _ in range(n+1)]
    for i in range(2, n+1):
        if not primeFactors[i]:
            primeFactors[i].append(i)
            if n // i >= i:
                for j in range(i*i, n+1, i):
                    if not primeFactors[j]:
                        primeFactors[j].append(i)
        else:
            prime = primeFactors[i][0]
            rest = i // prime
            while rest % prime == 0:
                rest //= prime
            if rest > 1:
                for factor in primeFactors[rest]:
                    primeFactors[i].append(factor)
    
    ans = 0
    check = [0] * (n+1)
    for g in range(1, n+1):
        if g*2 + 1 > n:
            break
        cnt = 0
        sm = 0
        for ap in range(2, n+1):
