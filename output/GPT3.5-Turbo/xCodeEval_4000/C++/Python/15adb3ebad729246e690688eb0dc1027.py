MOD = int(1e9 + 7)
dp = [[0] * 8 for _ in range(61)]

def solve():
    n = int(input())
    dp[0][0] = 1
    for i in range(60):
        bit = (1 << i) & n
        for j in range(1 << 3):
            if dp[i][j] == 0:
                continue
            for k in range((j % 2) ^ bit, 8, 2):
                lol = j + k
                dp[i + 1][lol // 2] += dp[i][j]
                if dp[i + 1][lol // 2] >= MOD:
                    dp[i + 1][lol // 2] -= MOD
    print(dp[60][0])

tests = int(input())
for _ in range(tests):
    solve()
