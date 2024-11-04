import random
import math
import sys
from collections import defaultdict

def read():
    s = input().strip()
    n = len(s)
    m = int(input())
    t = []
    for _ in range(m):
        tmp = input().strip()
        x = 0
        for c in tmp:
            x |= (1 << (ord(c) - ord('a')))
        t.append(x)
    return s, n, m, t

def solve():
    s, n, m, t = read()
    nxt = [[0] * 26 for _ in range(n + 1)]
    for i in range(n - 1, -1, -1):
        for j in range(26):
            nxt[i][j] = nxt[i + 1][j]
        nxt[i][ord(s[i]) - ord('a')] = i
    
    masks = {}
    cnt = [0] * (n + 1)
    mx = [-1] * (n + 1)
    
    for i in range(m):
        if t[i] not in masks:
            k = len(masks)
            masks[t[i]] = k
    
    for i in range(n):
        lst = i
        cur = (1 << (ord(s[lst]) - ord('a')))
        while True:
            mn = n
            for j in range(26):
                if not (cur >> j) & 1:
                    mn = min(mn, nxt[lst][j])
            if cur in masks:
                x = masks[cur]
                if mx[x] != mn - 1:
                    mx[x] = mn - 1
                    cnt[x] += 1
            if mn == n:
                break
            lst = mn
            cur |= (1 << (ord(s[lst]) - ord('a')))
    
    for i in range(m):
        print(cnt[masks[t[i]]])

while True:
    try:
        solve()
    except EOFError:
        break
