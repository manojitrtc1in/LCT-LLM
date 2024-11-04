import sys
import time
from collections import defaultdict

Mod = 1000000007
INF = 1e9
LINF = 1e18
Pi = 3.141592653589793116
EPS = 1e-9
Gold = (1 + 5 ** 0.5) / 2
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

    print("OI-Mode: ON")
    print("Input file:", infile)
    print("Output file:", outfile)
    print("\n")

    print("OI-Mode: OFF")
    print("Input file: NULL")
    print("Output file: NULL")
    print("\n")

    print("MultiTest-Mode: ON")
    print("MultiTest-Mode: OFF")

    print("Interactive-Mode: ON\n")
    print("Interactive-Mode: OFF\n")

    if len(sys.argv) > 1:
        sys.stdin = open(sys.argv[1], 'r')
    if len(sys.argv) > 2:
        sys.stdout = open(sys.argv[2], 'w')

    sys.stdin = open(infile, 'r')
    sys.stdout = open(outfile, 'w')

def TimerStart():
    return time.time()

def TimerStop(start_time):
    elapsed_time = time.time() - start_time
    print("\n\nTime elapsed: {:.6f} seconds.\n".format(elapsed_time))

def Input():
    return input().strip()

def Solve(s):
    baseAnswer = 1
    Map = defaultdict(int)
    q = 0

    for x in s:
        if '0' <= x <= '9':
            continue
        if x == '?':
            q += 1
            continue
        Map[x] += 1

    for i in range(10, 10 - len(Map), -1):
        baseAnswer *= i

    if 'A' <= s[0] <= 'J':
        baseAnswer //= 10
        baseAnswer *= 9
    if s[0] == '?':
        baseAnswer *= 9
        q -= 1

    print(baseAnswer, end='')
    print('0' * q)

def main():
    ControlIO()
    start_time = TimerStart()

    s = Input()
    Solve(s)

    T = int(input())
    for _ in range(T):
        s = Input()
        Solve(s)

    TimerStop(start_time)

if __name__ == "__main__":
    main()
