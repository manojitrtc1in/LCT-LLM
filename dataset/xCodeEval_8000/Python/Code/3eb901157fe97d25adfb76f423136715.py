import sys
import re

import random
import math
import copy
from heapq import heappush, heappop, heapify
from functools import cmp_to_key
from bisect import bisect_left, bisect_right
from collections import defaultdict, deque, Counter



input = sys.stdin.readline
getS = lambda: input().strip()
getN = lambda: int(input())
getList = lambda: list(map(int, input().split()))
getZList = lambda: [int(x) - 1 for x in input().split()]

INF = float("inf")
d = defaultdict(list)







def listen(t, i, j, x):
    print('?', t, i, j, x)
    
    
    

    sys.stdout.flush()
    res = getN()

    return res

def triple(a, b, c, li, n):
    res1 = listen(2, a, b, 1)
    if res1 == 2:
        res11 = listen(2, b, a, 1)
        if res11 == 1:
            li[b] = 1
            return -1
    res2 = listen(2, c, b, 1)
    if res2 == 2:
        res11 = listen(2, b, c, 1)
        if res11 == 1:
            li[b] = 1
            return -1
    

    if res1 == res2:
        mn, o1, o2 = b, c, a
        resmin = res1
    elif res1 > res2:
        mn, o1, o2 = c, a, b
        resmin = res2
    else:
        mn, o1, o2 = a, c, b
        resmin = res1

    res3 = listen(1, mn, o1, n - 1)
    res4 = listen(1, mn, o2, n - 1)

    li[mn] = resmin
    li[o1] = res3
    li[o2] = res4

    return 0

def solve():
    
    
    
    n = getN()

    li = [-1 for i in range(n+1)]

    a, b, c = 1, 2, 3
    flag = True
    while flag:
        
        res = triple(a, b, c, li, n)
        if res == 0:
            a, b, c = sorted([a, b, c])
            a, b, c = a+3, b+3, c+3
        else:
            a, b, c = a, c, b

        if c > n:
            break
        

    triple(n-2, n-1, n, li, n)
    triple(n-2, n, n-1, li, n)

    li = ["!"] + li[1:]
    print(*li)
    sys.stdout.flush()

    
    
    
    
    

def ran():
    n = random.randint(1, 100)
    li = [random.choice(["B", "R", "W"]) for i in range(n)]

    return n, li

def qu(t, i, j, x):
    
    ans = [1,2,3,4]
    if t == 1:
        return max(min(ans[i-1], x), min(ans[j-1], x+1))
    else:
        return min(max(ans[i - 1], x), max(ans[j - 1], x + 1))

def main():
    n = getN()
    for i in range(n):
        solve()
        

    return
if __name__ == "__main__":
    main()
    # solve()