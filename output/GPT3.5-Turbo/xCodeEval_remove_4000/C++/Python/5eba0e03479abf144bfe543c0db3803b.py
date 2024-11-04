import random
import math

s = ""
n = 0

def read():
    global s, n
    try:
        s = input()
        n = len(s)
        return True
    except EOFError:
        return False

def gen(n):
    global ord
    if n == 1:
        ord.append(1)
        return
    gen(n // 2)
    gen((n + 1) // 2)
    ord.append(n)

def solve():
    global s, n
    for t in range(n + 1, 0, -1):
        ord = []
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
                    if cnt0 == x // 2 and cnt1 < (x + 1) // 2:
                        fl = True
                        break
                else:
                    cnt1 += 1
                    if cnt1 == (x + 1) // 2 and cnt0 < x // 2:
                        fl = True
                        break
                r += 1
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
                    if cnt0 == x // 2 and cnt1 < (x + 1) // 2:
                        fl = True
                        break
                else:
                    R[cnt1] = cnt0 + cnt1
                    cnt1 += 1
                    if cnt1 == (x + 1) // 2 and cnt0 < x // 2:
                        fl = True
                        break
                r += 1
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
            print(x + 1, end=" ")
        print()
        break

def main():
    global s, n
    tc = int(input())
    while tc > 0:
        read()
        solve()
        tc -= 1

if __name__ == "__main__":
    main()
