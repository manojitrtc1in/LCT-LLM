import sys
import math
import time
from typing import List, Tuple
from collections import defaultdict
from functools import reduce

# Constants
Mod = 1000000007
INF = 1e9
LINF = 1e18
Pi = 3.141592653589793116
EPS = 1e-9
Gold = ((1+math.sqrt(5))/2)
keymod = [1000000007, 1000000009, 1000000021, 1000000033]
keyCount = len(keymod)

# Utility functions
def getbit(s: int, i: int) -> int:
    return (s >> i) & 1

def onbit(s: int, i: int) -> int:
    return s | (1 << i)

def offbit(s: int, i: int) -> int:
    return s & (~(1 << i))

def cntbit(s: int) -> int:
    return bin(s).count('1')

# Global variables
TimeStart = time.time()
TimeEnd = time.time()

# IO functions
def input() -> Tuple[int]:
    n = int(sys.stdin.readline())
    return n

def output(Min: int, Max: int) -> None:
    print(Min - N, Max - N)

# Main function
def solve(n: int) -> Tuple[int, int]:
    Min = LINF
    Max = -LINF
    A = []
    Map = defaultdict(int)
    N = n
    for i in range(2, int(math.sqrt(n))+1):
        while n % i == 0:
            Map[i] += 1
            n //= i
    if n > 1:
        Map[n] += 1
    for k, v in Map.items():
        A.append((k, v))
    
    def Pow(a: int, b: int) -> int:
        if b == 0:
            return 1
        tmp = Pow(a, b//2)
        if b % 2 == 0:
            return tmp * tmp
        return tmp * tmp * a
    
    def Try(id: int, x1: int, x2: int, x3: int) -> None:
        nonlocal Min, Max
        if id == len(A):
            Min = min(Min, (x1+1)*(x2+2)*(x3+2))
            Min = min(Min, (x1+2)*(x2+1)*(x3+2))
            Min = min(Min, (x1+2)*(x2+2)*(x3+1))
            Max = max(Max, (x1+1)*(x2+2)*(x3+2))
            Max = max(Max, (x1+2)*(x2+1)*(x3+2))
            Max = max(Max, (x1+2)*(x2+2)*(x3+1))
            return
        key, v = A[id]
        for i in range(v+1):
            for j in range(v+1):
                for k in range(v+1):
                    if i + j + k != v:
                        continue
                    Try(id+1, x1 * Pow(key, i), x2 * Pow(key, j), x3 * Pow(key, k))
    
    Try(0, 1, 1, 1)
    return Min - N, Max - N

if __name__ == "__main__":
    n = input()
    Min, Max = solve(n)
    output(Min, Max)
