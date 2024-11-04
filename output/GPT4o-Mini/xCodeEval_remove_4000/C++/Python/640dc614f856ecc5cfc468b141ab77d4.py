import sys
import time
import math

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

def func(m, n, s):
    if m == 0:
        return (n, s)
    k = int(round(m ** (1/3)))
    x = k * k * k
    y = (k - 1) * (k - 1) * (k - 1)
    return max(func(m - x, n + 1, s + x), func(x - y - 1, n + 1, s + y))

def input_data():
    return int(sys.stdin.readline().strip())

def solve(x):
    Token = func(x, 0, 0)
    print(Token[0], Token[1])

def control_io():
    infile = "FILE.IN"
    outfile = "FILE.OUT"
    
    print("Source code by")
    print("Current time: ", time.strftime("%Y-%m-%d | %H:%M:%S", time.localtime()))
    print("\n")
    
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
    
    print("Interactive-Mode: ON\n")
    print("Interactive-Mode: OFF\n")
    
    sys.stdin = open(infile, 'r')
    sys.stdout = open(outfile, 'w')

def timer_start():
    return time.time()

def timer_stop(start_time):
    elapsed_time = time.time() - start_time
    print("\n\nTime elapsed: {:.6f} seconds.\n".format(elapsed_time))

def main():
    control_io()
    
    x = input_data()
    start_time = timer_start()
    solve(x)
    timer_stop(start_time)
    
    T = input_data()
    start_time = timer_start()
    for _ in range(T):
        x = input_data()
        solve(x)
    timer_stop(start_time)

if __name__ == "__main__":
    main()
