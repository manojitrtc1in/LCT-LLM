import sys
from collections import defaultdict
from math import gcd

def reset_dp(dp):
    for i in range(len(dp)):
        for j in range(len(dp[i])):
            dp[i][j] = 0

M = 1000000007

s = input().strip()
t = input().strip()

dp = [[0] * (len(t) + 1) for _ in range(len(s) + 1)]
reset_dp(dp)

for i in range(len(s)):
    for j in range(len(t)):
        if s[i] == t[j]:
            dp[i + 1][j + 1] = (dp[i + 1][j] + dp[i][j] + 1) % M
        else:
            dp[i + 1][j + 1] = dp[i + 1][j]

re = 0
sz = len(t)
for i in range(len(s)):
    re = (re + dp[i + 1][sz]) % M

print(re)
