import sys
from collections import defaultdict

def main():
    ncr = [[0] * 40 for _ in range(40)]
    ans = [[0] * 30 for _ in range(30)]

    for a in range(40):
        for b in range(40):
            if b > a:
                ncr[a][b] = 0
                continue
            if b == 0 or b == a:
                ncr[a][b] = 1
                continue
            ncr[a][b] = ncr[a-1][b-1] + ncr[a-1][b]

    R, C = map(int, input().split())
    str = input()

    n = R + C
    blockarea = [[0] * n for _ in range(n)]
    totalarea = [[0] * (n+1) for _ in range(n+1)]

    for a in range(n):
        for b in range(n):
            blockarea[a][b] = ncr[a][R-1] * ncr[b][R-1]

    for a in range(n+1):
        for b in range(n+1):
            totalarea[a][b] = 0
            if a == 0 or b == 0:
                continue
            totalarea[a][b] = totalarea[a][b-1] + totalarea[a-1][b] - totalarea[a-1][b-1]
            totalarea[a][b] += blockarea[a-1][b-1]

    d = min(2*n-1, n+R-3)

    dp = [[defaultdict(int) for _ in range(n+1)] for _ in range(n+1)]
    bp = [[defaultdict(int) for _ in range(n+1)] for _ in range(n+1)]
    dp[0][0][0] = 1
    bp[0][0][0] = 1

    best = ans[R][C]
    m1 = (-best + totalarea[n][n]) // 2
    m2 = totalarea[n][n] - m1
    bestfreq = 0

    for x in range(n+1):
        for y in range(n):
            if x+y+1 <= d and str[x+y] != 'B':
                for c, freq in dp[x][y].items():
                    if c > m2:
                        continue
                    dp[x][y+1][c] += freq

            if x+y+1 <= 2*n-d and str[n-x+n-y-1] != 'B':
                for c, freq in bp[x][y].items():
                    if c > m2:
                        continue
                    bp[x][y+1][c] += freq

        if x == n:
            continue

        for y in range(n+1):
            if x+y+1 <= d and str[x+y] != 'A':
                newarea = totalarea[x+1][y] - totalarea[x][y]
                for c, freq in dp[x][y].items():
                    if c + newarea > m2:
                        continue
                    dp[x+1][y][c + newarea] += freq

            if x+y+1 <= 2*n-d and str[n-x+n-y-1] != 'A':
                id0 = totalarea[n-x][n-y] - totalarea[n-x-1][n-y]
                for c, freq in bp[x][y].items():
                    if c + id0 > m2:
                        continue
                    bp[x+1][y][c + id0] += freq

            if x+y+1 <= d:
                dp[x][y].clear()
            if x+y+1 <= 2*n-d:
                bp[x][y].clear()

    for x in range(n+1):
        y = d-x
        if y < 0 or y > n:
            continue

        for c, freq in dp[x][y].items():
            bestfreq += freq * bp[n-x][n-y][m1-c]
            if m1 != m2:
                bestfreq += freq * bp[n-x][n-y][m2-c]

    print(bestfreq)


if __name__ == "__main__":
    main()