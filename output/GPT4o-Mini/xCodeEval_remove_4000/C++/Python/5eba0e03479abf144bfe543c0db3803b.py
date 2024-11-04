import sys
import random
import time
from collections import deque

INF = int(1e9)
INF64 = int(1e18)
MOD = int(1e9) + 7
EPS = 1e-9
PI = 3.141592653589793

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

def solve():
    global s, n, ord
    for t in range(n + 1, 0, -1):
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
        if l != n or pr != len(ord):
            continue
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
            for val in res[-2]:
                nw.append(L[val])
            for val in res[-1]:
                nw.append(R[val])
            res.pop()
            res.pop()
            res.append(nw)
            if not fl:
                break
            l = r
        print(t)
        print(" ".join(str(x + 1) for x in res[0]))
        break

def main():
    input_file = open("input.txt", "r")
    sys.stdin = input_file

    tt = time.process_time()

    tc = int(sys.stdin.readline().strip())
    for _ in range(tc):
        read()
        while read():
            solve()
            print(f'TIME = {time.process_time() - tt}')
            tt = time.process_time()

if __name__ == "__main__":
    main()
