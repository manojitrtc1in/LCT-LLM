import sys
import math
import time

sys.setrecursionlimit(10**6)
MOD = 1000000007
INF = 10**9
LINF = 10**18
PI = 3.141592653589793116
EPS = 1e-9
GOLD = (1 + math.sqrt(5)) / 2

def modPow(a, b, M):
    if b == 0:
        return 1
    tmp = modPow(a, b // 2, M)
    if b % 2 == 0:
        return (tmp * tmp) % M
    return (((tmp * tmp) % M) * a) % M

def solve():
    n, m = map(int, input().split())
    A = (modPow(3, n, m) + m - 1) % m
    print(A)

def main():
    n, m = map(int, input().split())
    solve()

if __name__ == "__main__":
    main()
