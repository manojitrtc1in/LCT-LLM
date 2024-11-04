import sys
import random
import time
from collections import deque
from itertools import combinations

def IOSS0():
    sys.stdin = open('in.txt', 'r')
    sys.stdout = open('out.txt', 'w')
    sys.stderr = open('err.txt', 'w')

def OUT(*args):
    print(*args)

def IN():
    return list(map(float, sys.stdin.readline().strip().split()))

def solve(id, n, k, p):
    if p[id] <= 1e-9:
        OUT('0')
        return
    
    subret = [0] * 22
    dp = [0] * (1 << 20)
    subret[0] = dp[0] = p[id]
    
    for i in range(1, 1 << n):
        dp[i] = 0
        if (i >> id) & 1:
            continue
        
        sum_p = 0
        for j in range(n):
            if (i >> j) & 1:
                sum_p += p[j]
                dp[i] += dp[i ^ (1 << j)] * p[j]
        
        dp[i] /= (1 - sum_p)
        subret[bin(i).count('1')] += dp[i]
    
    ret = sum(subret[:k])
    OUT(f"{ret:.10f}")

def main():
    IOSS0()
    n, k = map(int, sys.stdin.readline().strip().split())
    p = list(map(float, sys.stdin.readline().strip().split()))
    
    for i in range(n):
        solve(i, n, k, p)
    
    OUT()

def generate_test_case():
    n = 1000
    # Additional test case generation logic can be added here
    exit(0)

if __name__ == "__main__":
    # Uncomment the following line to generate test cases
    # generate_test_case()
    main()
