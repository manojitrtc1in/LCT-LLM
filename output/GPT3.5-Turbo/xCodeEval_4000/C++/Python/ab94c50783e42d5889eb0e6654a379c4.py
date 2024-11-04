import sys

def solve(n, k, arrs):
    sums = [sum(arr) for arr in arrs]
    dp = [[0] * (k + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        dp[i] = dp[i - 1][:]
        for j in range(k, len(arrs[i - 1]) - 1, -1):
            dp[i][j] = max(dp[i][j], dp[i - 1][j - len(arrs[i - 1])] + sums[i - 1])
    return dp[n][k]

def main():
    n, k = map(int, input().split())
    arrs = []
    for _ in range(n):
        t = int(input())
        arr = list(map(int, input().split()))
        if t > k:
            arr = arr[:k]
        arrs.append(arr)
    ans = solve(n, k, arrs)
    print(ans)

if __name__ == "__main__":
    main()
