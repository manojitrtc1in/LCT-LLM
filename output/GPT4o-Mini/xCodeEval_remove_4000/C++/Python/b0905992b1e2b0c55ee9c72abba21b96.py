from collections import deque
import sys
import time
import random
import math

INF = int(1e9)
INF64 = int(1e18)
MOD = int(1e9) + 7
EPS = 1e-9
PI = math.acos(-1.0)

N = 20 * 1000 * 1000 + 13

s = ""
n = 0

def read():
    global s, n
    buf = sys.stdin.readline().strip()
    if not buf:
        return False
    s = buf
    n = len(s)
    return True

ord = []

def gen(n):
    if n == 1:
        ord.append(1)
        return
    gen(n // 2)
    gen((n + 1) // 2)
    ord.append(n)

def get(t, ans=False):
    global ord
    ord.clear()
    gen(t)
    l = 0
    pr = 0
    for x in ord:
        if x == 1:
            pr += 1
            continue
        cnt0 = 0
        cnt1 = 0
        r = l
        fl = False
        while r < n:
            if s[r] == '0':
                cnt0 += 1
                r += 1
                if cnt0 == x // 2 and cnt1 < (x + 1) // 2:
                    fl = True
                    break
            else:
                cnt1 += 1
                r += 1
                if cnt1 == (x + 1) // 2 and cnt0 < x // 2:
                    fl = True
                    break
        if not fl:
            break
        l = r
        pr += 1

    if not ans:
        return len(ord) - pr
    assert l == n and pr == len(ord)
    res = []
    l = 0
    for x in ord:
        if x == 1:
            res.append([0])
            continue
        cnt0 = 0
        cnt1 = 0
        r = l
        fl = False
        L = [0] * (x // 2)
        R = [0] * ((x + 1) // 2)
        while r < n:
            if s[r] == '0':
                L[cnt0] = cnt0 + cnt1
                cnt0 += 1
                r += 1
                if cnt0 == x // 2 and cnt1 < (x + 1) // 2:
                    fl = True
                    break
            else:
                R[cnt1] = cnt0 + cnt1
                cnt1 += 1
                r += 1
                if cnt1 == (x + 1) // 2 and cnt0 < x // 2:
                    fl = True
                    break
        while cnt0 < x // 2:
            L[cnt0] = cnt0 + cnt1
            cnt0 += 1
        while cnt1 < (x + 1) // 2:
            R[cnt1] = cnt0 + cnt1
            cnt1 += 1
        nw = []
        for x in res[-2]:
            nw.append(L[x])
        for x in res[-1]:
            nw.append(R[x])
        res.pop()
        res.pop()
        res.append(nw)
        if not fl:
            break
        l = r
    print(t)
    for x in res[0]:
        print(x + 1, end=' ')
    print()
    return True

def solve():
    l = 1
    r = n + 1
    res = -1
    while l <= r:
        m = (l + r) // 2
        if get(m) == 0:
            res = m
            l = m + 1
        else:
            r = m - 1
    get(res, True)

def main():
    input_file = open("input.txt", "r")
    sys.stdin = input_file

    tt = time.clock()

    tc = int(sys.stdin.readline())
    for _ in range(tc):
        read()
        while read():
            solve()
            print("TIME =", time.clock() - tt)
            tt = time.clock()

if __name__ == "__main__":
    main()
