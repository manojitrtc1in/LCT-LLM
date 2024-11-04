import sys
import time
from collections import defaultdict

INF = int(1e9)
INF64 = int(1e18)
MOD = int(1e9) + 7
EPS = 1e-9
PI = 3.141592653589793

N = 4 * 1000 * 1000 + 13

def read():
    return list(map(int, sys.stdin.readline().split()))

def add(a, b, mod):
    a += b
    if a >= mod:
        a -= mod
    if a < 0:
        a += mod
    return a

def mul(a, b, mod):
    return a * b % mod

def solve(n, mod):
    dp = [0] * N
    pr = [0] * N
    pr[1] = 1
    pr[2] = mod - 1
    
    for i in range(1, n + 1):
        dp[i] = pr[i]
        pr[i + 1] = add(pr[i + 1], dp[i], mod)
        for j in range(2, n // i + 1):
            pr[j * i] = add(pr[j * i], dp[i], mod)
            if j * (i + 1) < N:
                pr[j * (i + 1)] = add(pr[j * (i + 1)], -dp[i], mod)
        pr[i + 1] = add(pr[i + 1], pr[i], mod)
    
    print(dp[n])

def main():
    sys.stdin = open("input.txt", "r")
    
    tt = time.clock()
    
    tc = int(sys.stdin.readline())
    for _ in range(tc):
        n, mod = read()
        solve(n, mod)
        
        print("TIME =", time.clock() - tt)
        tt = time.clock()

if __name__ == "__main__":
    main()
