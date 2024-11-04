from collections import defaultdict
import sys
input = sys.stdin.read

MOD = int(1e9 + 7)
MX = int(2e5 + 5)
INF = int(1e18)
PI = 3.141592653589793

def nod(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def nok(a, b):
    return a * b // nod(a, b)

def binpow(a, n):
    if n == 0:
        return 1
    if n % 2 == 1:
        return binpow(a, n - 1) * a
    else:
        b = binpow(a, n // 2)
        return b * b

def read():
    return list(map(int, input().split()))

def solve():
    m = defaultdict(int)
    n, s, k = read()
    ans = MOD
    cnt = 0
    a = read()
    
    for i in range(n):
        if i >= k:
            m[a[i - k]] -= 1
            if m[a[i - k]] == 0:
                cnt -= 1
        m[a[i]] += 1
        if m[a[i]] == 1:
            cnt += 1
        if i >= k - 1:
            ans = min(ans, cnt)

    print(ans)

def main():
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
