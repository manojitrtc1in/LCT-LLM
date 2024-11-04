MOD = 998244353

def chmax(a, b):
    if a < b:
        a = b
        return True
    return False

def solve(solve, dp, l, r, a, w, k):
    if r - l == 1:
        sum = 0
        for i in range(len(a[l]) + 1):
            chmax(ans, dp[k - i] + sum)
            if i != len(a[l]):
                sum += a[l][i]
        return
    m = (r + l) // 2
    dp2 = dp.copy()
    for i in range(m, r):
        for j in range(k - 1, -1, -1):
            if len(a[i]) + j <= k:
                chmax(dp2[j + len(a[i])], dp2[j] + w[i])
    solve(solve, dp2, l, m, a, w, k)
    for i in range(l, m):
        for j in range(k - 1, -1, -1):
            if len(a[i]) + j <= k:
                chmax(dp[j + len(a[i])], dp[j] + w[i])
    solve(solve, dp, m, r, a, w, k)

n, k = map(int, input().split())
a = []
w = []
for _ in range(n):
    t = int(input())
    arr = list(map(int, input().split()))
    if len(arr) < k:
        a.append(arr)
    w.append(sum(arr))
ans = 0
dp = [0] * (k + 1)
solve(solve, dp, 0, n, a, w, k)
print(ans)
