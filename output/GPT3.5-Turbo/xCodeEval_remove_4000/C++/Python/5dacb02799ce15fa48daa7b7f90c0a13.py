n, m = map(int, input().split())
a = [0] * 55
b = [0] * 55
dp = [[[0] * 55 for _ in range(55)] for _ in range(55)]
Mod = 998244353
nii = [0] * 5555

def id0(a, b):
    if not b:
        return 1
    x = id0(a, b >> 1)
    x = (x * x) % Mod
    if b & 1:
        x = (x * a) % Mod
    return x

for i in range(1, 5555):
    nii[i] = id0(i, Mod - 2)

for i in range(1, n + 1):
    a[i] = int(input())

for i in range(1, n + 1):
    b[i] = int(input())

for i in range(1, n + 1):
    for j in range(m + 1):
        for l in range(j + 1):
            proba = 0
            probb = 0
            for k in range(1, n + 1):
                if not a[k]:
                    probb += b[k]
                else:
                    proba += b[k]
            dp[i][j][l] = (dp[i][j][l] + 1) % Mod
            for n in range(55):
                if a[i]:
                    dp[i][j + 1][l + 1][n + 1] = (dp[i][j + 1][l + 1][n + 1] + (dp[i][j][l][n] * (n + b[i]) % Mod * nii[proba + probb + l - m]) % Mod) % Mod
                    if dp[i][j + 1][l + 1][n + 1] >= Mod:
                        dp[i][j + 1][l + 1][n + 1] -= Mod
                else:
                    dp[i][j + 1][l][n + 1] = (dp[i][j + 1][l][n + 1] + (dp[i][j][l][n] * (b[i] - n) % Mod * nii[proba + probb + l - m]) % Mod) % Mod
                    if dp[i][j + 1][l][n + 1] >= Mod:
                        dp[i][j + 1][l][n + 1] -= Mod
                if a[i]:
                    dp[i][j + 1][l + 1][n] = (dp[i][j + 1][l + 1][n] + (dp[i][j][l][n] * (proba + l - n - b[i]) % Mod * nii[proba + probb + l - m]) % Mod) % Mod
                    if dp[i][j + 1][l + 1][n] >= Mod:
                        dp[i][j + 1][l + 1][n] -= Mod
                    dp[i][j + 1][l][n] = (dp[i][j + 1][l][n] + (dp[i][j][l][n] * (probb - m) % Mod * nii[proba + probb + l - m]) % Mod) % Mod
                    if dp[i][j + 1][l][n] >= Mod:
                        dp[i][j + 1][l][n] -= Mod
                else:
                    dp[i][j + 1][l + 1][n] = (dp[i][j + 1][l + 1][n] + (dp[i][j][l][n] * (proba + l) % Mod * nii[proba + probb + l - m]) % Mod) % Mod
                    if dp[i][j + 1][l + 1][n] >= Mod:
                        dp[i][j + 1][l + 1][n] -= Mod
                    dp[i][j + 1][l][n] = (dp[i][j + 1][l][n] + (dp[i][j][l][n] * (probb - m - b[i] + n) % Mod * nii[proba + probb + l - m]) % Mod) % Mod

all = 0
for j in range(52):
    for k in range(52):
        all = (all + (dp[n][m][j][k] * (b[n] + k) % Mod)) % Mod
        if all >= Mod:
            all -= Mod

print(all)
