import sys
import random

MOD = 1000 * 1000 * 1000 + 7

def read_int():
    return int(sys.stdin.readline().strip())

def print_int(value):
    print(value)

def max_int(a, b):
    return a if a > b else b

def min_int(a, b):
    return a if a < b else b

def abs_int(a):
    return a if a > 0 else -a

def solve():
    n = read_int()
    a = read_int()
    b = read_int()
    moves_num = read_int()

    dp = [[0] * (n + 1) for _ in range(2)]

    for i in range(1, n + 1):
        dp[0][i] = 1 + dp[0][i - 1]
        if dp[0][i] >= MOD:
            dp[0][i] -= MOD

    for move in range(moves_num):
        for x in range(1, n + 1):
            length = abs_int(x - b)
            dp[(move & 1) ^ 1][x] = dp[(move & 1) ^ 1][x - 1]
            if length > 1:
                left = max_int(x - (length - 1), 1)
                right = min_int(x + (length - 1), n)
                add = dp[(move & 1)][right] - dp[(move & 1)][left - 1]
                if add < 0:
                    add += MOD
                sub = dp[(move & 1)][x] - dp[(move & 1)][x - 1]
                if sub < 0:
                    sub += MOD
                diff = add - sub
                if diff < 0:
                    diff += MOD
                dp[(move & 1) ^ 1][x] += diff
                if dp[(move & 1) ^ 1][x] >= MOD:
                    dp[(move & 1) ^ 1][x] -= MOD

    ans = dp[((moves_num - 1) & 1) ^ 1][a] - dp[((moves_num - 1) & 1) ^ 1][a - 1]
    if ans < 0:
        ans += MOD
    print_int(ans)

def main():
    random.seed()
    solve()

if __name__ == "__main__":
    main()
