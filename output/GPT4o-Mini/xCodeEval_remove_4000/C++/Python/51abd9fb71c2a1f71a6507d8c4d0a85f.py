from collections import defaultdict
import math
import time

Mod = 1000000007
INF = 1e9
LINF = 1e18
Pi = 3.141592653589793116
EPS = 1e-9
Gold = (1 + math.sqrt(5)) / 2
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

TimeStart = 0
TimeEnd = 0

def ControlIO(argc, argv):
    global infile, outfile
    infile = "FILE.IN"
    outfile = "FILE.OUT"
    
    if argc > 1:
        infile = argv[1]
    if argc > 2:
        outfile = argv[2]
    
    print(f"Input file: {infile}")
    print(f"Output file: {outfile}\n")

def TimerStart():
    global TimeStart
    TimeStart = time.time()

def TimerStop():
    global TimeEnd
    TimeEnd = time.time()
    elapsed_time = TimeEnd - TimeStart
    print(f"\n\nTime elapsed: {elapsed_time} seconds.\n")

def Exit():
    TimerStop()
    exit(0)

n = 0
Min = LINF
Max = -LINF
A = []

def Pow(a, b):
    if b == 0:
        return 1
    tmp = Pow(a, b // 2)
    if b % 2 == 0:
        return tmp * tmp
    return tmp * tmp * a

def Try(id, x1, x2, x3):
    global Min, Max
    if id == len(A):
        Min = min(Min, (x1 + 1) * (x2 + 2) * (x3 + 2))
        Min = min(Min, (x1 + 2) * (x2 + 1) * (x3 + 2))
        Min = min(Min, (x1 + 2) * (x2 + 2) * (x3 + 1))
        Max = max(Max, (x1 + 1) * (x2 + 2) * (x3 + 2))
        Max = max(Max, (x1 + 2) * (x2 + 1) * (x3 + 2))
        Max = max(Max, (x1 + 2) * (x2 + 2) * (x3 + 1))
        return
    
    key, v = A[id]
    for i in range(v + 1):
        for j in range(v + 1):
            for k in range(v + 1):
                if i + j + k != v:
                    continue
                Try(id + 1, x1 * Pow(key, i), x2 * Pow(key, j), x3 * Pow(key, k))

def Input():
    global n
    n = int(input())

def Solve():
    global Min, Max, A
    Map = defaultdict(int)
    N = n
    for i in range(2, int(math.sqrt(n)) + 1):
        while n % i == 0:
            Map[i] += 1
            n //= i
    if n > 1:
        Map[n] += 1
    A = [(k, v) for k, v in Map.items()]
    Try(0, 1, 1, 1)
    print(Min - N, Max - N)

if __name__ == "__main__":
    import sys
    ControlIO(len(sys.argv), sys.argv)
    
    TimerStart()
    Input()
    Solve()
    TimerStop()
    
    T = int(input())
    TimerStart()
    for _ in range(T):
        Input()
        Solve()
    TimerStop()
