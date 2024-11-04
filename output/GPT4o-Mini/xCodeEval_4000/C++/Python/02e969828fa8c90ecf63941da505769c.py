import sys
import time
from math import sqrt

Mod = 1000000007
INF = 1e9
LINF = 1e18
Pi = 3.141592653589793116
EPS = 1e-9
Gold = (1 + sqrt(5)) / 2
keymod = [1000000007, 1000000009, 1000000021, 1000000033]
keyCount = len(keymod)

def modPow(a, b, M):
    if b == 0:
        return 1
    tmp = modPow(a, b // 2, M)
    if b % 2 == 0:
        return (tmp * tmp) % M
    return ((tmp * tmp) % M * a) % M

def Input():
    global n, m
    n, m = map(int, input().split())

def Solve():
    A = (modPow(3, n, m) + m - 1) % m
    print(A)

def ControlIO():
    if len(sys.argv) > 1:
        sys.stdin = open(sys.argv[1], 'r')
    if len(sys.argv) > 2:
        sys.stdout = open(sys.argv[2], 'w')

def TimerStart():
    return time.time()

def TimerStop(start_time):
    elapsed_time = time.time() - start_time
    print(f"\n\nTime elapsed: {elapsed_time} seconds.")

if __name__ == "__main__":
    ControlIO()
    start_time = TimerStart()
    
    if 'MultiTest' not in globals():
        Input()
        Solve()
    else:
        T = int(input())
        for _ in range(T):
            Input()
            Solve()
    
    TimerStop(start_time)
