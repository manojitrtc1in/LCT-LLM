import sys

MOD = int(1e9 + 7)

def read():
    return sys.stdin.readline().strip()

def writeln(value):
    sys.stdout.write(str(value) + '\n')

def solve(n):
    dp = [[0] * 8 for _ in range(61)]
    dp[0][0] = 1

    for i in range(60):
        bit = (1 << i) & n

        for j in range(8):
            if dp[i][j] == 0:
                continue

            for k in range((j % 2) ^ bit, 8, 2):
                lol = j + k
                dp[i + 1][lol // 2] += dp[i][j]
                if dp[i + 1][lol // 2] >= MOD:
                    dp[i + 1][lol // 2] -= MOD

    writeln(dp[60][0])

def main():
    tests = int(read())
    for _ in range(tests):
        n = int(read())
        solve(n)

if __name__ == "__main__":
    main()
