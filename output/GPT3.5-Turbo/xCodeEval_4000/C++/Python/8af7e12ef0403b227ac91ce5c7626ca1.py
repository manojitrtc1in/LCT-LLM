import sys
from collections import defaultdict

def solve():
    vec = defaultdict(list)
    vid = {}
    pr = [0] * 1010101
    primes = []
    w = [[]]
    used = {0: 0}
    maxh = 0
    dc = [0] * 1010101
    g = [[] for _ in range(1010101)]
    dist = [[0] * 10001 for _ in range(301)]
    vis = [False] * 10001

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

    def addUsed(v, t):
        x = calc(t)
        if x not in used:
            sz = len(used)
            used[x] = sz
            assert len(w) == sz
            w.append(t)
            dc[sz] = calcd(t)
        v.append(used[x])

    for i in range(2, 1010101):
        if not pr[i]:
            pr[i] = i
            primes.append(i)
        for p in primes:
            if p * i >= 1010101 or p > pr[i]:
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
        maxh = max(maxh, h)
        id = used.get(h, 0)
        if not id:
            id = len(w)
            w.append(vec[i])
            used[h] = id
        vid[i] = id

    ws = len(w)
    for i in range(min(len(w), 7000)):
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

    for i in range(ws):
        vis = [False] * 10001
        q = [i]
        dp = [0] * 10001
        for j in range(len(used)):
            dp[j] = float('inf')
        dp[i] = 0
        for j in range(len(q)):
            cur = q[j]
            dcur = dp[cur]
            for to in g[cur]:
                if dp[to] == float('inf'):
                    dp[to] = dcur + 1
                    q.append(to)
        for j in range(len(used)):
            if dc[j] < 10001:
                dist[i][dc[j]] = min(dist[i][dc[j]], dp[j])

    n = int(input())
    for _ in range(n):
        a, b = map(int, input().split())
        a = vid[a]
        b = vid[b]
        if a < b:
            a, b = b, a
        ans = float('inf')
        for i in range(1, 3000):
            ans = min(ans, dist[a][i] + dist[b][i])
        print(ans)

if __name__ == "__main__":
    solve()
