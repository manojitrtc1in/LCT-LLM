MOD = 998244353

def solve(dp, l, r):
    if r - l == 1:
        ans = 0
        for i in range(len(a[l]) + 1):
            ans = max(ans, dp[k - i] + sum(a[l][:i]))
        return ans
    m = (l + r) // 2
    dp2 = dp.copy()
    for i in range(m, r):
        for j in range(k - 1, -1, -1):
            if len(a[i]) + j <= k:
                dp2[j + len(a[i])] = max(dp2[j + len(a[i])], dp2[j] + w[i])
    ans = solve(dp2, l, m)
    for i in range(l, m):
        for j in range(k - 1, -1, -1):
            if len(a[i]) + j <= k:
                dp[j + len(a[i])] = max(dp[j + len(a[i])], dp[j] + w[i])
    return max(ans, solve(dp, m, r))

n, k = map(int, input().split())
a = []
w = []
for _ in range(n):
    t = int(input())
    a.append(list(map(int, input().split())))
    w.append(sum(a[-1]))
dp = [0] * (k + 1)
print(solve(dp, 0, n))
