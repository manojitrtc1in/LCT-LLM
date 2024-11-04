import sys

R, C = map(int, input().split())
str = input()

n = R + C
blockarea = [[0] * n for _ in range(n)]
totalarea = [[0] * (n + 1) for _ in range(n + 1)]

for a in range(n):
    for b in range(n):
        if b > a:
            blockarea[a][b] = 0
            continue
        if b == 0 or b == a:
            blockarea[a][b] = 1
            continue
        blockarea[a][b] = blockarea[a - 1][b - 1] + blockarea[a - 1][b]

for a in range(n + 1):
    for b in range(n + 1):
        totalarea[a][b] = 0
        if a == 0 or b == 0:
            continue
        totalarea[a][b] = totalarea[a][b - 1] + totalarea[a - 1][b] - totalarea[a - 1][b - 1]
        totalarea[a][b] += blockarea[a - 1][b - 1]

revarea = [[0] * (n + 1) for _ in range(n + 1)]
for a in range(n + 1):
    for b in range(n + 1):
        revarea[a][b] = totalarea[n][n] - totalarea[n - a][n] - totalarea[n][n - b] + totalarea[n - a][n - b]

d = min(2 * n - 1, n + R - 4)

dp = [[{} for _ in range(n + 1)] for _ in range(n + 1)]
bp = [[{} for _ in range(n + 1)] for _ in range(n + 1)]

dp[0][0][0] = 1
bp[0][0][0] = 1

best = ans[R][C]
m1 = (-best + totalarea[n][n]) // 2
m2 = totalarea[n][n] - m1
bestfreq = 0

for x in range(n + 1):
    for y in range(n):
        if x + y + 1 <= d and str[x + y] != 'B':
            for c, freq in dp[x][y].items():
                area2 = c + totalarea[n][y + 1] - totalarea[x][y + 1]
                if area2 > m2:
                    continue
                dp[x][y + 1].setdefault(c, 0)
                dp[x][y + 1][c] += freq

        if x + y + 1 <= 2 * n - d and str[n - x + n - y - 1] != 'B':
            for c, freq in bp[x][y].items():
                area2 = totalarea[n][n] - c - totalarea[n - x][n - (y + 1)]
                if area2 > m2:
                    continue
                bp[x][y + 1].setdefault(c, 0)
                bp[x][y + 1][c] += freq

    if x == n:
        continue

    for y in range(n + 1):
        if x + y + 1 <= d and str[x + y] != 'A':
            newarea = totalarea[x + 1][y] - totalarea[x][y]
            for c, freq in dp[x][y].items():
                newc = c + newarea
                area2 = totalarea[x + 1][n] - newc
                if area2 > m2:
                    continue
                dp[x + 1][y].setdefault(newc, 0)
                dp[x + 1][y][newc] += freq

        if x + y + 1 <= 2 * n - d and str[n - x + n - y - 1] != 'A':
            newarea = totalarea[n - x][n - y] - totalarea[n - x - 1][n - y]
            for c, freq in bp[x][y].items():
                newc = c + newarea
                if newc > m2:
                    continue
                bp[x + 1][y].setdefault(newc, 0)
                bp[x + 1][y][newc] += freq

        if x + y + 1 <= d:
            dp[x][y].clear()
        if x + y + 1 <= 2 * n - d:
            bp[x][y].clear()

for x in range(n + 1):
    y = d - x
    if y < 0 or y > n:
        continue

    for c, freq in dp[x][y].items():
        bestfreq += freq * bp[n - x][n - y][m1 - c]
        if m1 != m2:
            bestfreq += freq * bp[n - x][n - y][m2 - c]

print(bestfreq)
