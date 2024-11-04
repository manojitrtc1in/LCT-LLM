import sys
import math
from collections import defaultdict
from time import time

def control_io():
    global infile, outfile
    infile = "FILE.IN"
    outfile = "FILE.OUT"
    if len(sys.argv) > 1:
        infile = sys.argv[1]
    if len(sys.argv) > 2:
        outfile = sys.argv[2]

def timer_start():
    return time()

def timer_stop(start_time):
    elapsed_time = time() - start_time
    print(f"\n\nTime elapsed: {elapsed_time} seconds.")

def pow(a, b):
    if b == 0:
        return 1
    tmp = pow(a, b // 2)
    if b % 2 == 0:
        return tmp * tmp
    return tmp * tmp * a

def try_combination(id, x1, x2, x3):
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
                try_combination(id + 1, x1 * pow(key, i), x2 * pow(key, j), x3 * pow(key, k))

def input_data():
    global n
    n = int(input())

def solve():
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
    Min = float('inf')
    Max = float('-inf')
    try_combination(0, 1, 1, 1)
    print(Min - N, Max - N)

def main():
    control_io()
    start_time = timer_start()
    input_data()
    solve()
    timer_stop(start_time)

if __name__ == "__main__":
    main()
