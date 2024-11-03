import sys
import math
import time
from collections import defaultdict
from itertools import permutations
from functools import reduce
from operator import add, mul
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush, heapify
from decimal import Decimal, getcontext
from copy import deepcopy
from random import randint, sample, choice
from string import ascii_lowercase, ascii_uppercase
from fractions import Fraction
from sys import stdin, stdout, setrecursionlimit
from typing import List, Tuple, Dict, Any, Union


def getbit(s: int, i: int) -> int:
    return (s >> i) & 1


def onbit(s: int, i: int) -> int:
    return s | (1 << i)


def offbit(s: int, i: int) -> int:
    return s & (~(1 << i))


def cntbit(s: int) -> int:
    return bin(s).count('1')


def proceed_virus() -> None:
    global id1
    id1 = [[0] * 26 for _ in range(nv)]
    for i in range(nv):
        for j in range(26):
            pref2 = virus[:i]
            pref2 += chr(65 + j)
            for x in range(i + 1, -1, -1):
                if pref2[i + 1 - x:i + 1] == virus[:x]:
                    id1[i][j] = x
                    break


def input_data() -> None:
    global s1, s2, virus, n1, n2, nv
    s1, s2, virus = input().split()
    nv = len(virus)
    n1 = len(s1)
    n2 = len(s2)


def solve() -> None:
    List1 = [[] for _ in range(26)]
    List2 = [[] for _ in range(26)]
    for i in range(n1):
        List1[ord(s1[i]) - ord('A')].append(i)
    for i in range(n2):
        List2[ord(s2[i]) - ord('A')].append(i)
    proceed_virus()
    Default = ((-1, -1), (-1, -1))
    dp = [[[False] * (min(n1, n2) + 1) for _ in range(n2)] for _ in range(n1)]
    Last = [[[[Default] * (nv + 1) for _ in range(min(n1, n2) + 1)] for _ in range(n2)] for _ in range(n1)]
    for i in range(n1):
        for j in range(n2):
            if s1[i] == s2[j]:
                dp[i][j][1][id1[0][ord(s1[i]) - ord('A')]] = True
            else:
                dp[i][j][0][0] = True
    for x in range(1, min(n1, n2)):
        for i in range(n1 - 1):
            for j in range(n2 - 1):
                for y in range(nv):
                    if not dp[i][j][x][y]:
                        continue
                    for z in range(26):
                        if List1[z] and List2[z]:
                            i1 = bisect_left(List1[z], i)
                            j1 = bisect_left(List2[z], j)
                            if i1 < len(List1[z]) and j1 < len(List2[z]):
                                i1 = List1[z][i1]
                                j1 = List2[z][j1]
                                dp[i1][j1][x + 1][id1[y][z]] = True
                                Last[i1][j1][x + 1][id1[y][z]] = ((i, j), (x, y))
    for x in range(min(n1, n2), 0, -1):
        for y in range(nv):
            for i in range(n1):
                for j in range(n2):
                    if not dp[i][j][x][y]:
                        continue
                    I = i
                    J = j
                    X = x
                    Y = y
                    s = ""
                    while I != -1:
                        s = s1[I] + s
                        Token = Last[I][J][X][Y]
                        I, J = Token[0]
                        X, Y = Token[1]
                    print(s)
                    return
    print("0")


def main() -> None:
    input_data()
    solve()


if __name__ == "__main__":
    main()
