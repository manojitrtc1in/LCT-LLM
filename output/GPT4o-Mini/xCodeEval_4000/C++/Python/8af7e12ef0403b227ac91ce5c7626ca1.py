import sys
from collections import defaultdict
from itertools import combinations

input = sys.stdin.read
INF = 1011111111
F = 10001

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
        if not pr[i]:
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
            w.append(vec[i])
        vid[i] = id

    ws = len(w)
    for i in range(min(len(w), 7000)):
        cur = w[i]
        for j in range(len(cur)):
            t = cur[:]
            t[j] -= 1
            add_used(g[i], t)
            t[j] += 2
            add_used(g[i], t)
        cur.append(1)
        add_used(g[i], cur)
        g[i] = sorted(set(g[i]))
        dc[i] = calcd(w[i])

    for i in range(ws):
        vis = [False] * F
        q = [i]
        dp = [INF] * len(used)
        dp[i] = 0
        for cur in q:
            dcur = dp[cur]
            for to in g[cur]:
                if dp[to] == INF:
                    dp[to] = dcur + 1
                    q.append(to)
        for j in range(len(used)):
            if dc[j] < F:
                dist[i][dc[j]] = min(dist[i][dc[j]], dp[j])

    n = int(input())
    results = []
    for _ in range(n):
        a, b = map(int, input().split())
        a = vid[a]
        b = vid[b]
        if a < b:
            a, b = b, a
        ans = INF
        for i in range(1, 3000):
            ans = min(ans, dist[a][i] + dist[b][i])
        results.append(ans)
    print('\n'.join(map(str, results)))

vec = [[] for _ in range(1010101)]
vid = [0] * 1010101
pr = [0] * 1010101
primes = []
used = {}
maxh = 0
g = [[] for _ in range(F)]
w = []
dc = [0] * F
dist = [[INF] * F for _ in range(301)]

if __name__ == "__main__":
    solve()
