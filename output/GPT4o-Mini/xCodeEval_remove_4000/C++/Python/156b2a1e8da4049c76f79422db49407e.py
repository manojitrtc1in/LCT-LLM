import sys
import random
from collections import deque
from itertools import combinations

eps = 1e-9
pi = 3.14159265358979323846264338327950288419716939937510
inf = 0x3f3f3f3f
mod = 1000000007
mod2 = 1000000006
infll = 0x3f3f3f3f3f3f3f3f

dx = [0, 1, 0, -1, -1, 1, 1, -1]
dy = [1, 0, -1, 0, 1, 1, -1, -1]

def read_int():
    return int(sys.stdin.readline().strip())

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def write(value):
    sys.stdout.write(f"{value}\n")

def solve(id, n, k, p):
    if p[id] <= eps:
        write(0)
        return
    
    subret = [0] * (n + 1)
    dp = [0] * (1 << n)
    subret[0] = dp[0] = p[id]
    
    for i in range(1, 1 << n):
        dp[i] = 0
        if (i & (1 << id)) != 0:
            continue
        sum_p = 0
        for j in range(n):
            if (i & (1 << j)) != 0:
                sum_p += p[j]
                dp[i] += dp[i ^ (1 << j)] * p[j]
        dp[i] /= (1 - sum_p)
        subret[bin(i).count('1')] += dp[i]
    
    ret = sum(subret[:k])
    write(f"{ret:.10f}")

def main():
    n, k = read_ints()
    p = read_ints()
    
    for i in range(n):
        solve(i, n, k, p)

def id3():
    random.seed()
    n = 1000
    # Additional logic can be added here if needed

if __name__ == "__main__":
    sys.stdin = open("in.txt", "r")
    sys.stdout = open("out.txt", "w")
    sys.stderr = open("err.txt", "w")
    
    main()
    id3()
    
    # Time elapsed and other logging can be added here if needed
