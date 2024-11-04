import sys
from collections import defaultdict

N = 3000 + 10
n, k = 0, 0
m = [0] * N
a = [[0] * N for _ in range(N)]
ans = 0
sum_arr = [0] * N

def insert(dp, a, b):
    for i in range(k, a - 1, -1):
        dp[i] = max(dp[i], dp[i - a] + b)

def DFS(l, r, f):
    global ans
    if l == r:
        ans = max(ans, f[k])
        s = 0
        for i in range(1, min(m[l], k) + 1):
            s += a[l][i]
            ans = max(ans, s + f[k - i])
        return
    
    mid = (l + r) // 2
    g = f[:]
    
    for i in range(mid + 1, r + 1):
        insert(g, m[i], sum_arr[i])
    
    DFS(l, mid, g)
    
    g = f[:]
    
    for i in range(l, mid + 1):
        insert(g, m[i], sum_arr[i])
    
    DFS(mid + 1, r, g)

def read():
    return list(map(int, sys.stdin.readline().split()))

def main():
    global n, k
    input_file = "1.in"
    with open(input_file, 'r') as f:
        n, k = map(int, f.readline().split())
        for i in range(1, n + 1):
            m[i] = int(f.readline())
            for j in range(1, m[i] + 1):
                a[i][j] = int(f.readline())
                sum_arr[i] += a[i][j]
    
    DFS(1, n, [0] * (k + 1))
    print(ans)

if __name__ == "__main__":
    main()
