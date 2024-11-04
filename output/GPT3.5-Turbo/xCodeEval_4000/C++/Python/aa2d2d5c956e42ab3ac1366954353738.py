import random
import math
from collections import defaultdict

def read():
    s = input()
    n = len(s)
    m = int(input())
    t = []
    for _ in range(m):
        tmp = input()
        x = 0
        for c in tmp:
            x |= (1 << (ord(c) - ord('a')))
        t.append(x)
    return s, n, m, t

def solve():
    AL = 26
    nxt = [[0] * AL for _ in range(N)]
    cnt = [0] * N
    mx = [-1] * N
    masks = defaultdict(int)
    
    for i in range(AL):
        nxt[n][i] = n
    for i in range(n - 1, -1, -1):
        for j in range(AL):
            nxt[i][j] = nxt[i + 1][j]
        nxt[i][ord(s[i]) - ord('a')] = i
    
    for i in range(m):
        if t[i] not in masks:
            k = len(masks)
            masks[t[i]] = k
    
    for i in range(n):
        lst = i
        cur = (1 << (ord(s[lst]) - ord('a')))
        while True:
            mn = n
            for j in range(AL):
                if not ((cur >> j) & 1):
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
        s, n, m, t = read()
        solve()
    except EOFError:
        break
