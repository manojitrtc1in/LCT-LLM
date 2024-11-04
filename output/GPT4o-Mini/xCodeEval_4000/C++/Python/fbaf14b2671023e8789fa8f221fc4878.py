from collections import defaultdict
import sys
import math

def reset_dp(dp):
    for i in range(len(dp)):
        for j in range(len(dp[i])):
            dp[i][j] = 0

def main():
    s = input().strip()
    t = input().strip()
    
    sz1 = len(s)
    sz2 = len(t)
    
    dp = [[0] * (sz2 + 1) for _ in range(sz1 + 1)]
    reset_dp(dp)
    
    M = 1000000007
    
    for i in range(sz1):
        for j in range(sz2):
            if s[i] == t[j]:
                dp[i + 1][j + 1] = (dp[i + 1][j] + (dp[i][j] + 1)) % M
            else:
                dp[i + 1][j + 1] = dp[i + 1][j]
    
    re = 0
    for i in range(sz1):
        re = (re + dp[i + 1][sz2]) % M
    
    print(re)

if __name__ == "__main__":
    main()
