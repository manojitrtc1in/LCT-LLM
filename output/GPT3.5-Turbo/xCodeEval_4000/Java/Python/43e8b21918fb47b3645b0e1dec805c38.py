import sys
from typing import List, Tuple, Dict, Any

def main() -> None:
    t = 1
    epsilon = 0.00000001
    isPrime = []
    smallestFactorOf = []

    for _ in range(t):
        n = int(input())
        mod = int(input())

        dp = [0] * (n + 1)
        dp[n] = 1

        for i in range(n - 1, 0, -1):
            dp[i] += dp[i + 1]
            dp[i] %= mod

            for div in range(1, n // i + 1):
                lb = div * i
                ub = min(div * (i + 1) - 1, n)
                segSum = dp[lb]
                if ub + 1 <= n:
                    segSum -= dp[ub + 1]
                dp[i] += segSum
                dp[i] %= mod

            dp[i] += dp[i + 1]
            dp[i] %= mod

        print((dp[1] - dp[2] + mod) % mod)

if __name__ == "__main__":
    main()
