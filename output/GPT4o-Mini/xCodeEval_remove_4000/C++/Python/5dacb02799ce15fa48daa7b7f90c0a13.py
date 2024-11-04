from sys import stdin, stdout
import numpy as np

Mod = 998244353
nii = [0] * 5555

def id0(a, b):
    if b == 0:
        return 1
    x = id0(a, b >> 1)
    x = x * x % Mod
    if b & 1:
        x = x * a % Mod
    return x

n, m = map(int, stdin.readline().split())
for i in range(1, 5555):
    nii[i] = id0(i, Mod - 2)

a = [0] * 55
b = [0] * 55
for i in range(1, n + 1):
    a[i] = int(stdin.readline())
for i in range(1, n + 1):
    b[i] = int(stdin.readline())

for i in range(1, n + 1):
    dp = np.zeros((55, 55, 55), dtype=np.int64)
    proba = 0
    probb = 0
    for j in range(1, n + 1):
        if a[j] == 0:
            probb += b[j]
        else:
            proba += b[j]
    
    dp[0][0][0] += 1
    for j in range(m):
        for l in range(j + 1):
            m_val = j - l
            for n in range(55):
                if a[i]:
                    dp[j + 1][l + 1][n + 1] += dp[j][l][n] * (n + b[i]) % Mod * nii[proba + probb + l - m_val] % Mod
                    dp[j + 1][l + 1][n + 1] %= Mod
                else:
                    dp[j + 1][l][n + 1] += dp[j][l][n] * (b[i] - n) % Mod * nii[proba + probb + l - m_val] % Mod
                    dp[j + 1][l][n + 1] %= Mod

                if a[i]:
                    dp[j + 1][l + 1][n] += dp[j][l][n] * (proba + l - n - b[i]) % Mod * nii[proba + probb + l - m_val] % Mod
                    dp[j + 1][l + 1][n] %= Mod
                    dp[j + 1][l][n] += dp[j][l][n] * (probb - m_val) % Mod * nii[proba + probb + l - m_val] % Mod
                    dp[j + 1][l][n] %= Mod
                else:
                    dp[j + 1][l + 1][n] += dp[j][l][n] * (proba + l) % Mod * nii[proba + probb + l - m_val] % Mod
                    dp[j + 1][l + 1][n] %= Mod
                    dp[j + 1][l][n] += dp[j][l][n] * (probb - m_val - b[i] + n) % Mod * nii[proba + probb + l - m_val] % Mod
                    dp[j + 1][l][n] %= Mod

    all_val = 0
    for j in range(52):
        for k in range(52):
            all_val += dp[m][j][k] * (b[i] + k if a[i] else b[i] - k) % Mod
            all_val %= Mod

    stdout.write(f"{all_val}\n")
