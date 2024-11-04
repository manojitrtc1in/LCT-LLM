import sys
import time
import math
import heapq
import random
from collections import defaultdict, deque
from itertools import permutations, combinations
from bisect import bisect_left, bisect_right
from functools import cmp_to_key
from decimal import Decimal

# Constants
MOD = int(1e9) + 7
INF = float('inf')
EPS = 1e-9
PI = math.pi

# Input/output
def read_int():
    return int(input().strip())

def read_int_list():
    return list(map(int, input().split()))

def read_float():
    return float(input().strip())

def read_float_list():
    return list(map(float, input().split()))

def read_str():
    return input().strip()

def read_str_list():
    return input().split()

def write(*args, end='\n'):
    print(*args, end=end)

def solve():
    s1, s2, virus = read_str(), read_str(), read_str()
    nv = len(virus)
    n1, n2 = len(s1), len(s2)

    def proceed_virus():
        nonlocal NextCommonPrefix
        NextCommonPrefix = [[0] * 26 for _ in range(nv)]
        for i in range(nv):
            for j in range(26):
                pref2 = virus[:i] + chr(65 + j)
                for x in range(i+1, -1, -1):
                    if pref2[i+1-x:i+1] == virus[:x]:
                        NextCommonPrefix[i][j] = x
                        break

    def solve():
        List1 = [[] for _ in range(26)]
        List2 = [[] for _ in range(26)]
        for i in range(n1):
            List1[ord(s1[i]) - ord('A')].append(i)
        for i in range(n2):
            List2[ord(s2[i]) - ord('A')].append(i)
        proceed_virus()
        Default = ((-1, -1), (-1, -1))
        dp = [[[[False] * (nv+1) for _ in range(min(n1, n2)+1)] for _ in range(n2)] for _ in range(n1)]
        Last = [[[[Default] * (nv+1) for _ in range(min(n1, n2)+1)] for _ in range(n2)] for _ in range(n1)]
        for i in range(n1):
            for j in range(n2):
                if s1[i] == s2[j]:
                    dp[i][j][1][NextCommonPrefix[0][ord(s1[i]) - ord('A')]] = True
                else:
                    dp[i][j][0][0] = True
        for x in range(1, min(n1, n2)):
            for i in range(n1-1):
                for j in range(n2-1):
                    for y in range(nv):
                        if not dp[i][j][x][y]:
                            continue
                        for z in range(26):
                            if List1[z] and List2[z]:
                                i1 = bisect_right(List1[z], i)
                                j1 = bisect_right(List2[z], j)
                                dp[i1][j1][x+1][NextCommonPrefix[y][z]] = True
                                Last[i1][j1][x+1][NextCommonPrefix[y][z]] = ((i, j), (x, y))
        for x in range(min(n1, n2), 0, -1):
            for y in range(nv):
                for i in range(n1):
                    for j in range(n2):
                        if not dp[i][j][x][y]:
                            continue
                        I, J, X, Y = i, j, x, y
                        s = ''
                        while I != -1:
                            s = s1[I] + s
                            Token = Last[I][J][X][Y]
                            I, J = Token[0]
                            X, Y = Token[1]
                        write(s)
                        return
        write(0)

    solve()

def main():
    # Control IO
    if len(sys.argv) > 1:
        sys.stdin = open(sys.argv[1], 'r')
    if len(sys.argv) > 2:
        sys.stdout = open(sys.argv[2], 'w')

    # Input/output
    # ControlIO()

    # Timing
    start_time = time.time()

    # Solve the problem
    solve()

    # Timing
    end_time = time.time()
    elapsed_time = end_time - start_time
    write(f"\nTime elapsed: {elapsed_time:.6f} seconds.")

    # Exit
    exit(0)

if __name__ == '__main__':
    main()
