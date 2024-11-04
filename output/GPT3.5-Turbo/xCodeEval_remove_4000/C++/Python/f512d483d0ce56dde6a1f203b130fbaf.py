import sys
from collections import defaultdict

def undefinedBehaviour():
    pass

def countBits(v):
    v = v - ((v >> 1) & 0x55555555)
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333)
    return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24

def reverseBits(x):
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1))
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2))
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4))
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8))
    return ((x >> 16) | (x << 16))

def sign(x):
    return 1 if x > 0 else -1 if x < 0 else 0

def id4(x):
    return (x != 0 and (x & (x - 1)) == 0)

def power(x, p):
    return 1 if p == 0 else (x * power(x, p - 1))

def inRange(val, min, max):
    return min <= val and val <= max

def id7():
    return 0

def readInt():
    return int(sys.stdin.readline().strip())

def readString():
    return sys.stdin.readline().strip()

def readChar():
    return sys.stdin.read(1)

def writeInt(x, endc='\n'):
    sys.stdout.write(str(x) + endc)

def writeStr(str):
    sys.stdout.write(str)

def solve():
    w = [[]]
    used = {0: 0}
    maxh = 0
    g = defaultdict(list)
    dc = [0] * (F * 2)
    ans = [[0] * 303 for _ in range(303)]
    n = readInt()
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
        if h not in used:
            id = len(w)
            used[h] = id
            w.append(vec[i])
        vid[i] = used[h]
    ws = len(w)
    for i in range(min(len(w), F)):
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
        vis = [False] * (F * 2)
        q = [i]
        dp = [INF] * (F * 2)
        dp[i] = 0
        for j in range(len(q)):
            cur = q[j]
            dcur = dp[cur]
            for to in g[cur]:
                if dp[to] == INF:
                    dp[to] = dcur + 1
                    q.append(to)
        for j in range(used.size()):
            if dc[j] < F:
                dist[i][dc[j]] = min(dist[i][dc[j]], dp[j])
    for i in range(ws):
        dist[i][0] = INF
        for j in range(i + 1):
            res = INF
            for k in range(F):
                res = min(res, dist[i][k] + dist[j][k])
            ans[i][j] = res
    for _ in range(n):
        a = readInt()
        b = readInt()
        a = vid[a]
        b = vid[b]
        if a < b:
            a, b = b, a
        writeInt(ans[a][b])

if __name__ == "__main__":
    solve()
