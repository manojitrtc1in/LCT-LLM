import sys
import math
import time
from collections import defaultdict

def getbit(s, i):
    return (s >> i) & 1

def onbit(s, i):
    return s | (1 << i)

def offbit(s, i):
    return s & (~(1 << i))

def cntbit(s):
    return bin(s).count('1')

def proceed_virus():
    global id1
    id1 = [[0] * 26 for _ in range(nv)]
    for i in range(nv):
        for j in range(26):
            pref2 = virus[:i]
            pref2 += chr(65 + j)
            for x in range(i+1, -1, -1):
                if pref2[i+1-x:i+1] == virus[:x]:
                    id1[i][j] = x
                    break

def input_data():
    global s1, s2, virus, n1, n2, nv
    s1, s2, virus = input().split()
    nv = len(virus)
    n1 = len(s1)
    n2 = len(s2)

def solve():
    global s1, s2, virus, n1, n2, nv, id1
    List1 = defaultdict(list)
    List2 = defaultdict(list)
    for i in range(n1):
        List1[s1[i]].append(i)
    for i in range(n2):
        List2[s2[i]].append(i)
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
                        if List1[chr(z + ord('A'))] and List2[chr(z + ord('A'))]:
                            i1 = next((x for x in List1[chr(z + ord('A'))] if x > i), None)
                            j1 = next((x for x in List2[chr(z + ord('A'))] if x > j), None)
                            if i1 is not None and j1 is not None:
                                dp[i1][j1][x + 1][id1[y][z]] = True
                                Last[i1][j1][x + 1][id1[y][z]] = ((i, j), (x, y))
    for x in range(min(n1, n2), 0, -1):
        for y in range(nv):
            for i in range(n1):
                for j in range(n2):
                    if not dp[i][j][x][y]:
                        continue
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

input_data()
solve()
