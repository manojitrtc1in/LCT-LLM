import sys
import math
import time

def control_io():
    global infile, outfile
    infile = "FILE.IN"
    outfile = "FILE.OUT"
    
    if len(sys.argv) > 1:
        infile = sys.argv[1]
    if len(sys.argv) > 2:
        outfile = sys.argv[2]

    if infile != "NULL":
        sys.stdin = open(infile, 'r')
    if outfile != "NULL":
        sys.stdout = open(outfile, 'w')

def timer_start():
    global time_start
    time_start = time.time()

def timer_stop():
    elapsed_time = time.time() - time_start
    print(f"\n\nTime elapsed: {elapsed_time} seconds.")

def func(m, n, s):
    if m == 0:
        return (n, s)
    k = int(round(m ** (1/3)))
    x = k * k * k
    y = (k - 1) * (k - 1) * (k - 1)
    return max(func(m - x, n + 1, s + x), func(x - y - 1, n + 1, s + y))

def input_data():
    global x
    x = int(input())

def solve():
    token = func(x, 0, 0)
    print(token[0], token[1])

if __name__ == "__main__":
    control_io()
    
    timer_start()
    
    if 'MultiTest' in globals():
        T = int(input())
        for _ in range(T):
            input_data()
            solve()
    else:
        input_data()
        solve()
    
    timer_stop()
