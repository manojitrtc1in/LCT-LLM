import sys
from collections import defaultdict
from itertools import combinations

def read_int():
    return int(sys.stdin.readline().strip())

def read_string():
    return sys.stdin.readline().strip()

def calc(v):
    v.sort()
    res = 0
    for x in v:
        res = res * 30 + x
    return res

def calcd(v):
    res = 1
    for x in v:
        res *= x + 1
    return res

used = {}
maxh = 0
F = 30001
dist = [[float('inf')] * F for _ in range(300)]
vis = [False] * F
dc = [0] * F
g = [[] for _ in range(F)]
w = []
vec = [[] for _ in range(1010101)]
vid = [0] * 1010101
pr = [0] * 1010101
primes = []

def add_used(v, t):
    x = calc(t)
    if x not in used:
        sz = len(used)
        used[x] = sz
        assert len(w) == sz
        w.append(t)
        dc[sz] = calcd(t)
    v.append(used[x])

def solve():
    global maxh
    w.append([])
    used[0] = 0
    N = 1000010
    for i in range(2, N):
        if pr[i] == 0:
            pr[i] = i
            primes.append(i)
        for p in primes:
            if p * i > N or p > pr[i]:
                break
            pr[p * i] = p
        cnt = 1
        x = i
        while pr[x] == pr[x // pr[x]]:
            cnt += 1
            x //= pr[x]
        x //= pr[x]
        vec[i].extend(vec[x])
        vec[i].append(cnt)
        h = calc(vec[i])
        maxh = max(maxh, h)
        id = used.get(h, None)
        if id is None:
            id = len(w)
            used[h] = id
            w.append(vec[i])
        vid[i] = id

    ws = len(w)
    for i in range(min(len(w), 20000)):
        cur = w[i]
        for j in range(len(cur)):
            t = cur[:]
            t[j] -= 1
            add_used(g[i], t)
            t[j] += 2
            add_used(g[i], t)
        cur.append(1)
        add_used(g[i], cur)
        g[i].sort()
        g[i] = list(dict.fromkeys(g[i]))  # Remove duplicates
        dc[i] = calcd(w[i])

    for i in range(ws):
        vis[:] = [False] * F
        q = [i]
        dp = [float('inf')] * used.size()
        dp[i] = 0
        for j in range(len(q)):
            cur = q[j]
            dcur = dp[cur]
            for to in g[cur]:
                if dp[to] == float('inf'):
                    dp[to] = dcur + 1
                    q.append(to)
        for j in range(used.size()):
            if dc[j] < F:
                dist[i][dc[j]] = min(dist[i][dc[j]], dp[j])

    ans = [[0] * 300 for _ in range(300)]
    for i in range(ws):
        dist[i][0] = float('inf')
        for j in range(i + 1):
            res = float('inf')
            for k in range(F):
                res = min(res, dist[i][k] + dist[j][k])
            ans[i][j] = res

    n = read_int()
    for _ in range(n):
        a, b = map(int, read_string().split())
        a = vid[a]
        b = vid[b]
        if a < b:
            a, b = b, a
        print(ans[a][b])

if __name__ == "__main__":
    sys.stdin = open("input.txt", "r")
    solve()
