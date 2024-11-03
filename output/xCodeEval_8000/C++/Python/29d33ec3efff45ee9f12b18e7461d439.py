import sys
import time
import math
import heapq
import random
import bisect
import string
import itertools
import functools
import collections

sys.setrecursionlimit(10**7)
inf = float('inf')
eps = 1.0 / 10**10
mod = 10**9 + 7
dd = [(-1, 0), (0, 1), (1, 0), (0, -1)]
ddn = [(-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1)]

def LI(): return [int(x) for x in sys.stdin.readline().split()]
def LI_(): return [int(x)-1 for x in sys.stdin.readline().split()]
def LF(): return [float(x) for x in sys.stdin.readline().split()]
def LS(): return sys.stdin.readline().split()
def I(): return int(sys.stdin.readline())
def F(): return float(sys.stdin.readline())
def S(): return input()
def pf(s): return print(s, flush=True)


def main():
    s1, s2, virus = S().strip(), S().strip(), S().strip()
    n1, n2, nv = len(s1), len(s2), len(virus)
    NextCommonPrefix = [[0] * 26 for _ in range(nv)]

    for i in range(nv):
        for j in range(26):
            pref2 = virus[:i]
            pref2 += chr(65 + j)
            for x in range(i+1, -1, -1):
                if pref2[i+1-x:i+1] == virus[:x]:
                    NextCommonPrefix[i][j] = x
                    break

    List1 = [[] for _ in range(26)]
    List2 = [[] for _ in range(26)]
    for i in range(n1):
        List1[ord(s1[i]) - ord('A')].append(i)
    for i in range(n2):
        List2[ord(s2[i]) - ord('A')].append(i)

    dp = [[[False] * (min(n1, n2) + 1) for _ in range(n2)] for _ in range(n1)]
    Last = [[[[(-1, -1), (-1, -1)] for _ in range(nv+1)] for _ in range(min(n1, n2) + 1)] for _ in range(n2)]

    for i in range(n1):
        for j in range(n2):
            if s1[i] == s2[j]:
                dp[i][j][NextCommonPrefix[0][ord(s1[i]) - ord('A')]] = True
            else:
                dp[i][j][0] = True

    for x in range(1, min(n1, n2)):
        for i in range(n1-1):
            for j in range(n2-1):
                for y in range(nv):
                    if not dp[i][j][x][y]:
                        continue
                    for z in range(26):
                        if List1[z] and List2[z]:
                            i1 = bisect.bisect(List1[z], i)
                            j1 = bisect.bisect(List2[z], j)
                            dp[i1][j1][x+1][NextCommonPrefix[y][z]] = True
                            Last[i1][j1][x+1][NextCommonPrefix[y][z]] = ((i, j), (x, y))

    for x in range(min(n1, n2), 0, -1):
        for y in range(nv):
            for i in range(n1):
                for j in range(n2):
                    if dp[i][j][x][y]:
                        I, J, X, Y = i, j, x, y
                        s = ""
                        while I != -1:
                            s = s1[I] + s
                            Token = Last[I][J][X][Y]
                            I, J = Token[0]
                            X, Y = Token[1]
                        print(s)
                        return

    print("0")


if __name__ == '__main__':
    main()
