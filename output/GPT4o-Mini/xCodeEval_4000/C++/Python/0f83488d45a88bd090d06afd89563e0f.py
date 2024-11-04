import sys
from collections import defaultdict
from itertools import combinations

input = sys.stdin.read
INF = 1011111111
F = 1001

def calc(v):
    v.sort()
    res = 0
    for x in v:
        res = res * 24 + x
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
        w.append(t)
        dc[sz] = calcd(t)
    v.append(used[x])

def solve():
    global used, w, dc, vid
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
        id = used.get(h, None)
        if id is None:
            id = len(w)
            w.append(vec[i])
        vid[i] = id

    ws = len(w)
    for i in range(min(len(w), F)):
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
        vis[:] = [0] * (F * 2)
        q = [i]
        dp = [INF] * len(used)
        dp[i] = 0
        for j in range(len(q)):
            cur = q[j]
            dcur = dp[cur]
            for to in g[cur]:
                if dp[to] == INF:
                    dp[to] = dcur + 1
                    q.append(to)

        for j in range(len(used)):
            if dc[j] < F:
                dist[i][dc[j]] = min(dist[i][dc[j]], dp[j])

    for i in range(ws):
        dist[i][0] = INF
        for j in range(i + 1):
            res = INF
            for k in range(F):
                res = min(res, dist[i][k] + dist[j][k])
            ans[i][j] = res

    n = int(input())
    for _ in range(n):
        a, b = map(int, input().split())
        a = vid[a]
        b = vid[b]
        if a < b:
            a, b = b, a
        print(ans[a][b])

if __name__ == "__main__":
    input_data = input().splitlines()
    used = {}
    w = []
    primes = []
    vec = [[] for _ in range(1010101)]
    vid = [0] * 1010101
    pr = [0] * 1010101
    dist = [[INF] * (F * 2) for _ in range(303)]
    vis = [0] * (F * 2)
    dc = [0] * (F * 2)
    g = [[] for _ in range(F * 2)]
    ans = [[0] * 303 for _ in range(303)]
    
    solve()
