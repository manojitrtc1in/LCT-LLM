import sys

sys.setrecursionlimit(10**6)

n, k = map(int, input().split())
m = [0] * (n+1)
a = [[0] * (k+1) for _ in range(n+1)]
sum = [0] * (n+1)
ans = 0

def insert(dp, a, b):
    for i in range(k, a-1, -1):
        dp[i] = max(dp[i], dp[i-a] + b)

def DFS(l, r, f):
    global ans
    if l == r:
        ans = max(ans, f[k])
        s = 0
        for i in range(1, min(m[l], k)+1):
            s += a[l][i]
            ans = max(ans, s + f[k-i])
        return
    g = f.copy()
    mid = (l + r) // 2
    for i in range(mid+1, r+1):
        insert(g, m[i], sum[i])
    DFS(l, mid, g)
    g = f.copy()
    for i in range(l, mid+1):
        insert(g, m[i], sum[i])
    DFS(mid+1, r, g)

for i in range(1, n+1):
    m[i] = int(input())
    for j in range(1, m[i]+1):
        a[i][j] = int(input())
        sum[i] += a[i][j]

DFS(1, n, [0] * (k+1))
print(ans)
