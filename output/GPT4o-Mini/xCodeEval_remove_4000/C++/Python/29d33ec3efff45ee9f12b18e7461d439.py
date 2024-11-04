from collections import defaultdict
import time
import sys

Mod = 1000000007
INF = 1e9
LINF = 1e18
Pi = 3.141592653589793116
EPS = 1e-9
Gold = (1 + (5 ** 0.5)) / 2
keymod = [1000000007, 1000000009, 1000000021, 1000000033]
keyCount = len(keymod)

def getbit(s, i):
    return (s >> i) & 1

def onbit(s, i):
    return s | (1 << i)

def offbit(s, i):
    return s & (~(1 << i))

def cntbit(s):
    return bin(s).count('1')

def ControlIO():
    infile = "FILE.IN"
    outfile = "FILE.OUT"

    print("Source code by")
    print("Current time: ", time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))

    print("\nOI-Mode: ON")
    print("Input file: ", infile)
    print("Output file: ", outfile)
    print("\n")

    print("OI-Mode: OFF")
    print("Input file: NULL")
    print("Output file: NULL")
    print("\n")

    print("MultiTest-Mode: ON")
    print("MultiTest-Mode: OFF")

    print("Interactive-Mode: ON\n")
    print("Interactive-Mode: OFF\n")

    sys.stdin = open(infile, 'r')
    sys.stdout = open(outfile, 'w')

s1, s2, virus = "", "", ""
n1, n2, nv = 0, 0, 0
id1 = []

def ProceedVirus():
    global id1
    id1 = [[0] * 26 for _ in range(nv)]
    for i in range(nv):
        for j in range(26):
            pref2 = virus[:i] + chr(65 + j)
            for x in range(i + 1)[::-1]:
                if pref2[i + 1 - x:i + 1] == virus[:x]:
                    id1[i][j] = x
                    break

def Input():
    global s1, s2, virus, n1, n2, nv
    s1, s2, virus = input().split()
    nv = len(virus)
    n1 = len(s1)
    n2 = len(s2)

def Solve():
    global id1
    List1 = [[] for _ in range(26)]
    List2 = [[] for _ in range(26)]
    
    for i in range(n1):
        List1[ord(s1[i]) - ord('A')].append(i)
    for i in range(n2):
        List2[ord(s2[i]) - ord('A')].append(i)

    ProceedVirus()
    Default = ((-1, -1), (-1, -1))
    dp = [[[ [False] * (nv + 1) for _ in range(min(n1, n2) + 1)] for _ in range(n2)] for _ in range(n1)]
    Last = [[[[Default for _ in range(nv + 1)] for _ in range(min(n1, n2) + 1)] for _ in range(n2)] for _ in range(n1)]

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
                        if not List1[z] or List1[z][-1] <= i:
                            continue
                        if not List2[z] or List2[z][-1] <= j:
                            continue
                        i1 = next(idx for idx in List1[z] if idx > i)
                        j1 = next(idx for idx in List2[z] if idx > j)
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
                        s = s + s1[I]
                        Token = Last[I][J][X][Y]
                        I, J = Token[0]
                        X, Y = Token[1]
                    print(s)
                    return
    print("0")

def TimerStart():
    return time.time()

def TimerStop(start_time):
    elapsed_time = time.time() - start_time
    print("\n\nTime elapsed: {:.6f} seconds.\n".format(elapsed_time))

def main():
    ControlIO()
    Input()
    start_time = TimerStart()
    Solve()
    TimerStop(start_time)

    T = int(input())
    start_time = TimerStart()
    for _ in range(T):
        Input()
        Solve()
    TimerStop(start_time)

if __name__ == "__main__":
    main()
