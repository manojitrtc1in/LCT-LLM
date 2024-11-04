import math
from collections import defaultdict

eps = 0.0000001
pi = math.acos(-1)

def fastpower(b, p):
    ans = 1
    while p:
        if p % 2:
            ans *= b
        b *= b
        p //= 2
    return ans

def id0(b, p, m):
    ans = 1
    while p:
        if p % 2:
            ans = (ans % m * b % m) % m
        b = (b % m * b % m) % m
        p //= 2
    return ans % m

def id1(n):
    ans = ""
    ch = False
    if n < 0:
        n *= -1
        ch = True
    if n == 0:
        ans = "0"
    while n:
        mo = n % 10
        mo += 48
        m = chr(mo)
        ans = m + ans
        n //= 10
    if ch:
        ans = '-' + ans
    return ans

def compare(f, s):
    return abs(f - s) < eps

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

N = int(1e2 + 1)

powcnt = [0] * N
ans = 0

def preprocess(num):
    global powcnt
    for i in range(30, -1, -1):
        if num >= (1 << i):
            num -= (1 << i)
            powcnt[i] += 1

def solve(curp):
    global ans, powcnt
    for i in range(curp, 31):
        if powcnt[i] > 0:
            powcnt[i] -= 1
            ans += 1
            for j in range(curp, i):
                powcnt[j] += 1
            break

def main():
    global ans, powcnt
    n, m = map(int, input().split())
    v = []
    for _ in range(n):
        x = int(input())
        preprocess(x)
    for _ in range(m):
        x = int(input())
        v.append(x)
    v.sort()
    for value in v:
        solve(value)
    print(ans)

if __name__ == "__main__":
    main()
