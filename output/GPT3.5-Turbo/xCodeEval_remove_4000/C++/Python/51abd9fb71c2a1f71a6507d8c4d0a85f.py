import sys
import math
import time
from typing import List, Tuple, Dict

# Constants
Mod = 1000000007
INF = 1e9
LINF = 1e18
Pi = 3.141592653589793116
EPS = 1e-9
Gold = ((1+math.sqrt(5))/2)
keymod = [1000000007, 1000000009, 1000000021, 1000000033]
keyCount = len(keymod)

# Typedefs
vi = List[int]
vd = List[float]
vs = List[str]
vc = List[str]
vb = List[bool]
pii = Tuple[int, int]
pip = Tuple[int, pii]
ppi = Tuple[pii, int]

# Global variables
TimeStart = time.time()
TimeEnd = time.time()

# Helper functions
def getbit(s: int, i: int) -> int:
    return (s >> i) & 1

def onbit(s: int, i: int) -> int:
    return s | (1 << i)

def offbit(s: int, i: int) -> int:
    return s & (~(1 << i))

def cntbit(s: int) -> int:
    return bin(s).count('1')

def Pow(a: int, b: int) -> int:
    if b == 0:
        return 1
    tmp = Pow(a, b // 2)
    if b % 2 == 0:
        return tmp * tmp
    return tmp * tmp * a

def Try(id: int, x1: int, x2: int, x3: int) -> None:
    global Min, Max, A
    if id == len(A):
        Min = min(Min, (x1+1)*(x2+2)*(x3+2))
        Min = min(Min, (x1+2)*(x2+1)*(x3+2))
        Min = min(Min, (x1+2)*(x2+2)*(x3+1))
        Max = max(Max, (x1+1)*(x2+2)*(x3+2))
        Max = max(Max, (x1+2)*(x2+1)*(x3+2))
        Max = max(Max, (x1+2)*(x2+2)*(x3+1))
        return
    key = A[id][0]
    v = A[id][1]
    for i in range(v+1):
        for j in range(v+1):
            for k in range(v+1):
                if i + j + k != v:
                    continue
                Try(id+1, x1 * Pow(key, i), x2 * Pow(key, j), x3 * Pow(key, k))

def Input() -> None:
    global n
    n = int(input())

def Solve() -> None:
    global n, Min, Max, A
    Map = {}
    N = n
    for i in range(2, int(math.sqrt(n))+1):
        while n % i == 0:
            if i not in Map:
                Map[i] = 0
            Map[i] += 1
            n //= i
    if n > 1:
        if n not in Map:
            Map[n] = 0
        Map[n] += 1
    A = list(Map.items())
    Try(0, 1, 1, 1)
    print(Min - N, Max - N)

def main() -> None:
    ControlIO(sys.argv)

    Input()
    TimerStart()
    Solve()
    TimerStop()

    T = int(input())
    TimerStart()
    for _ in range(T):
        Input()
        Solve()
    TimerStop()

def ControlIO(args: List[str]) -> None:
    infile = "FILE.IN"
    outfile = "FILE.OUT"

    t = time.time()
    now = time.localtime(t)
    print("Source code by")
    print("Current time:", now.tm_year + 1900, '-', str(now.tm_mon + 1).zfill(2), '-', str(now.tm_mday).zfill(2), '|', str(now.tm_hour).zfill(2), ':', str(now.tm_min).zfill(2), ':', str(now.tm_sec).zfill(2))
    print()

    print("OI-Mode: ON")
    print("Input file:", infile)
    print("Output file:", outfile)
    print()

    print("OI-Mode: OFF")
    print("Input file: NULL")
    print("Output file: NULL")
    print()

    print("MultiTest-Mode: ON")
    print()

    print("MultiTest-Mode: OFF")
    print()

    print("Interactive-Mode: ON")
    print()

    print("Interactive-Mode: OFF")
    print()

    if len(args) > 1:
        sys.stdin = open(args[1], 'r')
    if len(args) > 2:
        sys.stdout = open(args[2], 'w')

    sys.stdin = open(infile, 'r')
    sys.stdout = open(outfile, 'w')

def TimerStart() -> None:
    global TimeStart
    TimeStart = time.time()

def TimerStop() -> None:
    global TimeEnd
    TimeEnd = time.time()
    ElapsedTime = TimeEnd - TimeStart
    print("\n\nTime elapsed:", ElapsedTime, "seconds.")

def Exit() -> None:
    TimerStop()
    sys.exit(0)

if __name__ == "__main__":
    main()
