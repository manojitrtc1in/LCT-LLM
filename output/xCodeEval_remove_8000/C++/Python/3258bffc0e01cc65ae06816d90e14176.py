import sys
import time
import math

def getbit(s, i):
    return (s >> i) & 1

def onbit(s, i):
    return s | (1 << i)

def offbit(s, i):
    return s & (~(1 << i))

def cntbit(s):
    return bin(s).count('1')

TimeStart = time.time()
TimeEnd = time.time()

def ControlIO():
    infile = "FILE.IN"
    outfile = "FILE.OUT"

    t = time.localtime()
    print("Source code by ")
    print("Current time: ", t.tm_year + 1900, "-", str(t.tm_mon + 1).zfill(2), "-", str(t.tm_mday).zfill(2), " | ", str(t.tm_hour).zfill(2), ":", str(t.tm_min).zfill(2), ":", str(t.tm_sec).zfill(2), "\n\n")

    print("OI-Mode: ON")
    print("Input file: ", infile)
    print("Output file: ", outfile)
    print("\n")

    print("OI-Mode: OFF")
    print("Input file: NULL")
    print("Output file: NULL")
    print("\n")

    print("MultiTest-Mode: ON")

    print("MultiTest-Mode: OFF")

    print("Interactive-Mode: ON\n\n")

    print("Interactive-Mode: OFF\n\n")

    if len(sys.argv) > 1:
        sys.stdin = open(sys.argv[1], 'r')
    if len(sys.argv) > 2:
        sys.stdout = open(sys.argv[2], 'w')

    sys.stdin = open(infile, 'r')
    sys.stdout = open(outfile, 'w')

def TimerStart():
    global TimeStart
    TimeStart = time.time()

def TimerStop():
    global TimeEnd
    TimeEnd = time.time()
    ElapsedTime = TimeEnd - TimeStart
    print("\n\nTime elapsed: ", ElapsedTime, " seconds.\n")

def Exit():
    TimerStop()
    sys.exit(0)

def Input():
    global s
    s = input()

def Solve():
    global s, q
    baseAnswer = 1
    Map = {}
    q = 0
    for x in s:
        if x >= '0' and x <= '9':
            continue
        if x == '?':
            q += 1
            continue
        if x not in Map:
            Map[x] = 0
        Map[x] += 1
    for i in range(10, 10 - len(Map), -1):
        baseAnswer *= i
    if s[0] >= 'A' and s[0] <= 'J':
        baseAnswer //= 10
        baseAnswer *= 9
    if s[0] == '?':
        baseAnswer *= 9
        q -= 1
    print(baseAnswer, end='')
    for i in range(q):
        print('0', end='')

ControlIO()

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
