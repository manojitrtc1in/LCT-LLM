import sys
from collections import defaultdict

def solve():
    primes = []
    pr = [0] * 1010101
    vec = [[] for _ in range(1010101)]
    vid = [0] * 1010101
    used = {}
    w = [[]]
    dc = [0] * (1001 * 2)
    g = [[] for _ in range(1001 * 2)]
    dist = [[0] * (1001 * 2) for _ in range(301)]
    vis = [False] * (1001 * 2)
    ans = [[0] * 303 for _ in range(303)]

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

    def addUsed(v, t):
        x = calc(t)
        if x not in used:
            sz = len(used)
            used[x] = sz
            w.append(t)
            dc[sz] = calcd(t)
        v.append(used[x])

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
        vec[i] = vec[x] + [cnt]
        h = calc(vec[i])
        id = used.get(h, None)
        if id is None:
            id = len(w)
            w.append(vec[i])
            used[h] = id
        vid[i] = id

    ws = len(w)
    for i in range(min(len(w), 1001)):
        cur = w[i]
        for j in range(len(cur)):
            t = cur[:]
            t[j] -= 1
            addUsed(g[i], t)
            t[j] += 2
            addUsed(g[i], t)
        cur.append(1)
        addUsed(g[i], cur)
        g[i].sort()
        g[i] = list(set(g[i]))
        dc[i] = calcd(w[i])

    for i in range(ws):
        vis = [False] * (1001 * 2)
        q = [i]
        dp = [float('inf')] * (1001 * 2)
        dp[i] = 0
        for j in range(len(q)):
            cur = q[j]
            dcur = dp[cur]
            for to in g[cur]:
                if dp[to] == float('inf'):
                    dp[to] = dcur + 1
                    q.append(to)
        for j in range(len(used)):
            if dc[j] < 1001:
                dist[i][dc[j]] = min(dist[i][dc[j]], dp[j])

    for i in range(ws):
        dist[i][0] = float('inf')
        for j in range(i + 1):
            res = float('inf')
            for k in range(1001):
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
    solve()
