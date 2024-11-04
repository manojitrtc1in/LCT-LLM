import math

n = int(input())
s = []
for _ in range(n):
    s.append(input())

m = len(s[0])
val = [0] * n
dy = [0] * (1 << m)
dp = [0] * (1 << m)

for i in range(n):
    for j in range(i + 1, n):
        num = 0
        for k in range(m):
            num |= (s[i][k] == s[j][k]) << k
        dy[num] |= (1 << i) | (1 << j)

for i in range((1 << m) - 1, -1, -1):
    for j in range(i, 0, -1):
        lst = j & -j
        dy[i ^ lst] |= dy[i]

dp[0] = 1
ans = 0

for i in range(1 << m):
    v = dp[i] / (m - bin(i).count('1'))
    for j in range((1 << m) - 1, i, -1):
        if j & -j:
            dp[i | (j & -j)] += v
    ans += dp[i] * bin(dy[i]).count('1')

print(ans / n)
