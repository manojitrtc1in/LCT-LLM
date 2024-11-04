from collections import defaultdict
import sys
from math import gcd

MOD = 10**9 + 7
MX = 200005
INF = 10**18
PI = 3.141592653589793

def adskiy_razgon():
    input = sys.stdin.read
    data = input().split()
    return data

def read():
    return map(int, input().split())

def solve():
    m = defaultdict(int)
    n, s, k = map(int, input().split())
    ans = MOD
    cnt = 0
    a = list(map(int, input().split()))
    
    for i in range(n):
        if i >= k:
            m[a[i - k]] -= 1
            if m[a[i - k]] == 0:
                cnt -= 1
            m[a[i]] += 1
            if m[a[i]] == 1:
                cnt += 1
            ans = min(ans, cnt)
        else:
            m[a[i]] += 1
            if m[a[i]] == 1:
                cnt += 1

    ans = min(ans, cnt)
    print(ans)

def main():
    adskiy_razgon()
    t = int(input())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
