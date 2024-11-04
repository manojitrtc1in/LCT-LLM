import random
import math

s = ""
n = 0

def read():
    global s, n
    s = input().strip()
    n = len(s)

def gen(n):
    if n == 1:
        return [1]
    left = gen(n // 2)
    right = gen((n + 1) // 2)
    return left + right + [n]

def get(t, ans=False):
    global s, n
    ord = gen(t)
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
    print("")
    return True

def solve():
    global n
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
    global s, n
    tc = int(input())
    while tc > 0:
        read()
        solve()
        tc -= 1

main()
