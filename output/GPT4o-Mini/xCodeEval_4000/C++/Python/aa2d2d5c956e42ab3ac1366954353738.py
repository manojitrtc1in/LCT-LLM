import sys
import random
from collections import defaultdict

INF = int(1e9)
INF64 = int(1e18)
MOD = INF + 7
EPS = 1e-9
PI = 3.141592653589793

N = 1000 * 1000 + 13
AL = 26

n = 0
s = ""
m = 0
t = [0] * N

def read():
    global n, s, m, t
    s = sys.stdin.readline().strip()
    n = len(s)
    m = int(sys.stdin.readline().strip())
    for i in range(m):
        tmp = sys.stdin.readline().strip()
        x = 0
        for char in tmp:
            x |= (1 << (ord(char) - ord('a')))
        t[i] = x
    return True

nxt = [[n] * AL for _ in range(N)]
cnt = [0] * N
mx = [-1] * N
masks = {}

def solve():
    global cnt, mx, masks
    for i in range(AL):
        nxt[n][i] = n
    for i in range(n - 1, -1, -1):
        for j in range(AL):
            nxt[i][j] = nxt[i + 1][j]
        nxt[i][ord(s[i]) - ord('a')] = i

    masks.clear()
    for i in range(m):
        if t[i] not in masks:
            k = len(masks)
            masks[t[i]] = k

    cnt = [0] * len(masks)
    mx = [-1] * len(masks)

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

def main():
    while read():
        solve()

if __name__ == "__main__":
    main()
