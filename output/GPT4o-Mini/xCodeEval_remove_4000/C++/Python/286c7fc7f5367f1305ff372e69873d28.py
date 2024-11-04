import sys
from collections import defaultdict
from itertools import combinations
from math import isqrt, inf

def read_int():
    return int(sys.stdin.readline().strip())

def read_long_array(n):
    return list(map(int, sys.stdin.readline().strip().split()))

def bit_count(x):
    return bin(x).count('1')

def is_set(mask, bit):
    return (mask >> bit) & 1

def minim(was, cand):
    return min(was, cand)

class EDerevoDelitelei:
    def solve(self):
        n = read_int()
        a = read_long_array(n)

        a.sort()
        d = [0] * n
        for i in range(n):
            c = a[i]
            for j in range(2, isqrt(c) + 1):
                while c % j == 0:
                    d[i] += 1
                    c //= j
            if c != 1:
                d[i] += 1

        reachable = [inf] * (1 << n)
        reachable[0] = 0

        for i in range(n):
            for j in range(1 << i):
                rem = a[i]
                good = True
                for k in range(i):
                    if is_set(j, k):
                        if rem % a[k] != 0:
                            good = False
                            break
                        rem //= a[k]
                qty = 0
                for c in range(2, isqrt(rem) + 1):
                    while rem % c == 0:
                        qty += 1
                        rem //= c
                if rem != 1:
                    qty += 1
                lim = 0 if i == 0 else 1 << (i - 1)
                if good:
                    for k in range(1 << i):
                        if (j & k) == 0 and reachable[j + k] != inf and j + k >= lim:
                            reachable[(1 << i) + k] = minim(reachable[(1 << i) + k], reachable[j + k] + qty + (0 if d[i] == 1 else 1))

        answer = inf
        for i in range(1 << (n - 1), 1 << n):
            if reachable[i] != inf:
                answer = minim(answer, reachable[i] + (0 if bit_count(i) == 1 else 1))

        print(answer)

def main():
    EDerevoDelitelei().solve()

if __name__ == "__main__":
    main()
