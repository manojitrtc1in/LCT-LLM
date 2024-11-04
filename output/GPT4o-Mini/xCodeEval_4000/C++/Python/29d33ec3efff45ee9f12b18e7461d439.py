import sys
import time
from collections import defaultdict

Mod = 1000000007
INF = int(1e9)
LINF = int(1e18)
Pi = 3.141592653589793116
EPS = 1e-9
Gold = (1 + 5 ** 0.5) / 2
keymod = [1000000007, 1000000009, 1000000021, 1000000033]

def getbit(s, i):
    return (s >> i) & 1

def onbit(s, i):
    return s | (1 << i)

def offbit(s, i):
    return s & (~(1 << i))

def cntbit(s):
    return bin(s).count('1')

def ControlIO():
    global cppstr_infile, cppstr_outfile
    cppstr_infile = "FILE.IN"
    cppstr_outfile = "FILE.OUT"
    
    if len(sys.argv) > 1:
        sys.stdin = open(sys.argv[1], 'r')
    if len(sys.argv) > 2:
        sys.stdout = open(sys.argv[2], 'w')

def TimerStart():
    return time.time()

def TimerStop(start_time):
    elapsed_time = time.time() - start_time
    print(f"\n\nTime elapsed: {elapsed_time} seconds.")

def ProceedVirus(virus, nv):
    NextCommonPrefix = [[0] * 26 for _ in range(nv)]
    for i in range(nv):
        for j in range(26):
            pref2 = virus[:i] + chr(65 + j)
            for x in range(i + 1):
                if pref2[i + 1 - x:i + 1] == virus[:x]:
                    NextCommonPrefix[i][j] = x
                    break
    return NextCommonPrefix

def Input():
    global s1, s2, virus, n1, n2, nv
    s1, s2, virus = input().split()
    nv = len(virus)
    n1 = len(s1)
    n2 = len(s2)

def Solve():
    global s1, s2, virus, n1, n2, nv
    List1 = [[] for _ in range(26)]
    List2 = [[] for _ in range(26)]
    
    for i in range(n1):
        List1[ord(s1[i]) - ord('A')].append(i)
    for i in range(n2):
        List2[ord(s2[i]) - ord('A')].append(i)
    
    NextCommonPrefix = ProceedVirus(virus, nv)
    Default = ((-1, -1), (-1, -1))
    
    dp = [[[[False] * (nv + 1) for _ in range(min(n1, n2) + 1)] for _ in range(n2)] for _ in range(n1)]
    Last = [[[[Default for _ in range(nv + 1)] for _ in range(min(n1, n2) + 1)] for _ in range(n2)] for _ in range(n1)]
    
    for i in range(n1):
        for j in range(n2):
            if s1[i] == s2[j]:
                dp[i][j][1][NextCommonPrefix[0][ord(s1[i]) - ord('A')]] = True
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
                        dp[i1][j1][x + 1][NextCommonPrefix[y][z]] = True
                        Last[i1][j1][x + 1][NextCommonPrefix[y][z]] = ((i, j), (x, y))
    
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
                    print(s[::-1])
                    return
    print("0")

def main():
    ControlIO()
    start_time = TimerStart()
    
    Input()
    Solve()
    
    TimerStop(start_time)

if __name__ == "__main__":
    main()
