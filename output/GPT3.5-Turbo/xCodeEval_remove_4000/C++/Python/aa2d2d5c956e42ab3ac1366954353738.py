import random
import math
from collections import defaultdict

INF = int(1e9)
INF64 = int(1e18)
MOD = INF + 7
EPS = 1e-9
PI = math.acos(-1.0)

N = 1000 * 1000 + 13
AL = 26

n = 0
s = ""
m = 0
t = []

def read():
    global n, s, m, t
    buf = input().strip()
    s = buf
    n = len(s)
    m = int(input())
    for _ in range(m):
        buf = input().strip()
        tmp = buf
        x = 0
        for j in range(len(tmp)):
            x |= (1 << (ord(tmp[j]) - ord('a')))
        t.append(x)

def solve():
    global n, s, m, t
    nxt = [[0] * AL for _ in range(N)]
    for i in range(AL):
        nxt[n][i] = n
    for i in range(n - 1, -1, -1):
        for j in range(AL):
            nxt[i][j] = nxt[i + 1][j]
        nxt[i][ord(s[i]) - ord('a')] = i
    
    masks = defaultdict(int)
    cnt = [0] * N
    mx = [-1] * N
    
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
        read()
        solve()
    except EOFError:
        break
