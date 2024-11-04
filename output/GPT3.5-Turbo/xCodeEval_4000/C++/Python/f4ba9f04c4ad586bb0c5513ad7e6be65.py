import sys
import math
from collections import defaultdict, Counter
from itertools import combinations, permutations
from functools import lru_cache
from bisect import bisect_left, bisect_right
from heapq import heappush, heappop
from math import gcd, ceil, floor

# Constants
INF = int(1e9)
INF64 = int(1e18)
MOD = int(1e9) + 7
EPS = 1e-9
PI = math.acos(-1.0)

CR = 7
BITS = 15

# Fast I/O
input = sys.stdin.readline
print = sys.stdout.write

# Custom Functions
def read():
    return int(input().strip())

def precalc():
    dp = [[[0 for _ in range(CR)] for _ in range(BITS + 1)] for _ in range(CR)]
    cnt = [[[0 for _ in range(1 << BITS)] for _ in range(CR)] for _ in range(CR)]
    
    for i in range(CR):
        dp[i][0][i][0] = 1
    
    for cs in range(CR):
        for i in range(BITS):
            for ct in range(CR):
                for x in range(1 << BITS):
                    if dp[cs][i][ct][x] != 0:
                        for cc in range(CR + 1):
                            dp[cs][i + 1][(ct + cc) // 2][(((ct + cc) % 2) << i) | x] += dp[cs][i][ct][x]
    
    for i in range(CR):
        for j in range(CR):
            for x in range(1 << BITS):
                cnt[i][j][x] = dp[i][BITS][j][x]
    
    return cnt

def solve(n, cnt):
    dp2 = [[0 for _ in range(CR)] for _ in range(5)]
    dp2[0][0] = 1
    
    for i in range(4):
        x = (n & ((1 << BITS) - 1))
        n >>= BITS
        for j in range(CR):
            for k in range(CR):
                dp2[i + 1][k] += dp2[i][j] * cnt[j][k][x]
    
    return int(dp2[4][0])

# Main Function
def main():
    precalc()
    
    # Read the number of test cases
    tc = read()
    
    for _ in range(tc):
        n = read()
        result = solve(n, cnt)
        print(str(result) + '\n')

# Run the main function
if __name__ == "__main__":
    main()
