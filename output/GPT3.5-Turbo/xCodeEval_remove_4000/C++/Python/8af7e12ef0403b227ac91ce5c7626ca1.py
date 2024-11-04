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
    return __builtin_readcyclecounter()

def readInt():
    def c():
        if __ir == __er:
            __bur = [0] * (__BS + 16)
            sys.stdin.readinto(__bur, __BS)
            __ir = __bur
    c()
    while __ir and (__ir < '0' or __ir > '9') and __ir != '-':
        __ir += 1
        c()
    m = False
    if __ir == '-':
        __ir += 1
        c()
        m = True
    r = 0
    while __ir >= '0' and __ir <= '9':
        r = r * 10 + __ir - '0'
        __ir += 1
        c()
    __ir += 1
    return -r if m else r

def readString():
    def c():
        if __ir == __er:
            __bur = [0] * (__BS + 16)
            sys.stdin.readinto(__bur, __BS)
            __ir = __bur
    r = ""
    c()
    while __ir and isspace(__ir):
        __ir += 1
        c()
    while not isspace(__ir):
        r += __ir
        __ir += 1
        c()
    __ir += 1
    return r

def readChar():
    def c():
        if __ir == __er:
            __bur = [0] * (__BS + 16)
            sys.stdin.readinto(__bur, __BS)
            __ir = __bur
    c()
    while __ir and isspace(__ir):
        __ir += 1
        c()
    return __ir

def writeInt(x, endc = '\n'):
    if x < 0:
        __iw += 1
        x = -x
    if x == 0:
        __iw += 1
        __iw = '0'
    s = __iw
    while x:
        t = x / 10
        c = x - 10 * t + '0'
        __iw += 1
        __iw = c
        x = t
    f = __iw - 1
    while s < f:
        swap(s, f)
        s += 1
        f -= 1
    if __iw > __ew:
        sys.stdout.write(__iw, __iw - __ew)
        __iw = __iw
    if endc:
        __iw += 1
        __iw = endc

def writeStr(str):
    i = 0
    while str[i]:
        __iw += 1
        __iw = str[i]
        i += 1
        if __iw > __ew:
            sys.stdout.write(__iw, __iw - __ew)
            __iw = __iw

class __FL__:
    def __del__(self):
        if __iw != id10:
            sys.stdout.write(__iw, __iw - id10)
__FL__ = __FL__()
id2 = __FL__

def solve():
    w = []
    used = {}
    primes = []
    vec = defaultdict(list)
    pr = [0] * 1010101
    vid = [0] * 1010101
    maxh = 0
    g = defaultdict(list)
    dc = [0] * F
    dist = [[0] * F for _ in range(301)]
    vis = [False] * F
    n = readInt()
    for i in range(2, 1010101):
        if not pr[i]:
            pr[i] = i
            primes.append(i)
        for p in primes:
            if p * i > 1010101 or p > pr[i]:
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
        if h not in used:
            id = len(w)
            used[h] = id
            w.append(vec[i])
        vid[i] = used[h]
    ws = len(w)
    for i in range(ws):
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
        vis = [False] * F
        q = [i]
        dp = [INF] * F
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
    for _ in range(n):
        a = readInt()
        b = readInt()
        a = vid[a]
        b = vid[b]
        if a < b:
            a, b = b, a
        ans = INF
        for i in range(1, 3000):
            ans = min(ans, dist[a][i] + dist[b][i])
        writeInt(ans, '\n')
    return 0

solve()
