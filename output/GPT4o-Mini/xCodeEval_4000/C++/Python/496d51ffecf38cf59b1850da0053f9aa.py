import sys
from collections import defaultdict

eps = 0.0000001
pi = 3.141592653589793

def fastpower(b, p):
    ans = 1
    while p:
        if p % 2:
            ans *= b
        b *= b
        p //= 2
    return ans

def fastpowermod(b, p, m):
    ans = 1
    while p:
        if p % 2:
            ans = (ans % m) * (b % m) % m
        b = (b % m) * (b % m) % m
        p //= 2
    return ans % m

def makeitstring(n):
    ans = ""
    ch = False
    if n < 0:
        n *= -1
        ch = True
    if n == 0:
        return "0"
    while n:
        mo = n % 10
        ans = chr(mo + 48) + ans
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
    global ans
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    m = int(data[1])
    index = 2
    
    for _ in range(n):
        x = int(data[index])
        preprocess(x)
        index += 1
    
    v = []
    for _ in range(m):
        x = int(data[index])
        v.append(x)
        index += 1
    
    v.sort()
    
    for value in v:
        solve(value)
    
    print(ans)

if __name__ == "__main__":
    main()
