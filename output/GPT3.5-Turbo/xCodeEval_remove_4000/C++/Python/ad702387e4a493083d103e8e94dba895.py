mod = 0

mod = int(1e9 + 7)

gmod = 2
inf = 1039074182
eps = 1e-9
llinf = 1 * inf * inf


def chmin(x, b):
    if b < x:
        x = b


def chmax(x, b):
    if b > x:
        x = b


def chadd(x, b):
    x += b - mod
    x += (x >> 31 & mod)


def chadd(x, b):
    x += b
    if x >= mod:
        x -= mod


def chmul(x, b):
    x = 1 * x * b % mod


def chmod(x, b):
    x %= b
    x += b
    if x >= b:
        x -= b


def mabs(x):
    return -x if x < 0 else x


using namespace std


def operator<<(cout, vec):
    cout << "{"
    for i in range(len(vec)):
        cout << vec[i]
        if i != len(vec) - 1:
            cout << ","
    cout << "}"
    return cout


def operator*=(vec, k):
    for i in range(len(vec)):
        vec[i] *= k


def operator-=(a, b):
    assert len(a) == len(b)
    for i in range(len(a)):
        a[i] -= b[i]


def operator*(vec, k):
    res = vec.copy()
    res *= k
    return res


def operator<<(cout, p):
    cout << "(" << p.first << "," << p.second << ")"
    return cout


def operator<<(cout, s):
    t = []
    for x in s:
        t.append(x)
    cout << t
    return cout


def operator<<(cout, s):
    t = []
    for x in s:
        t.append(x)
    cout << t
    return cout


def operator<<(cout, q):
    t = []
    while len(q) > 0:
        t.append(q.front())
        q.pop()
    cout << t
    return cout


def operator<<(cout, m):
    for x in m:
        cout << "Key: " << x.first << " " << "Value: " << x.second << endl
    return cout


def operator*(v1, v2):
    assert len(v1) == len(v2)
    n = len(v1)
    res = 0
    for i in range(n):
        res += v1[i] * v2[i]
    return res


def operator+(x, y):
    return make_pair(x.first + y.first, x.second + y.second)


def operator+=(x, y):
    x.first += y.first
    x.second += y.second


def operator-(x):
    return make_pair(-x.first, -x.second)


def operator~(vec):
    v = []
    n = len(vec)
    m = len(vec[0])
    v.resize(m)
    for i in range(m):
        v[i].resize(n)
    for i in range(m):
        for j in range(n):
            v[i][j] = vec[j][i]
    return v


def id0(x):
    vec = []
    while x:
        vec.append(x & 1)
        x >>= 1
    vec.reverse()
    for i in range(len(vec)):
        std::cout << vec[i]
    std::cout << ' '


def id0(x, len):
    vec = []
    while x:
        vec.append(x & 1)
        x >>= 1
    vec.reverse()
    for i in range(len(vec), len):
        putchar('0')
    for i in range(len(vec)):
        std::cout << vec[i]
    std::cout << ' '


using namespace std
n = 0
v = 0
m = 0
a = [0] * 305
b = [0] * 305
edges = [[] for _ in range(305)]
c = [0] * 305
visit = [0] * 305
cnt = 0
s = [0] * 305
res = []
dist = [0] * 305


def dfs(x):
    visit[x] = 1
    c[x] = cnt
    for u in edges[x]:
        if visit[u]:
            continue
        dfs(u)


def bfs(src):
    visit = [0] * 305
    visit[src] = 1
    dist[src] = 0
    que = []
    que.append(src)
    while len(que) > 0:
        x = que[0]
        que.pop(0)
        for u in edges[x]:
            if visit[u]:
                continue
            dist[u] = dist[x] + 1
            visit[u] = 1
            que.append(u)


def liu(x, y, flow):
    assert flow >= 0
    a[x] -= flow
    assert a[x] >= 0
    a[y] += flow
    assert a[y] <= v
    res.append(((x, y), flow))


def liu(i, flow, routes):
    if i == len(routes) - 1:
        return
    nxt = routes[i + 1]
    now = routes[i]
    if a[nxt] + flow <= v:
        liu(now, nxt, flow)
        liu(i + 1, flow, routes)
    else:
        id2 = a[now]
        moved = v - a[nxt]
        liu(now, nxt, v - a[nxt])
        liu(i + 1, flow, routes)
        liu(now, nxt, flow - moved)
        id1 = a[now]


def adjust(x, y):
    assert a[x] != b[x]
    assert a[y] != b[y]
    if a[x] < b[x]:
        x, y = y, x
    flow = min(abs(a[x] - b[x]), abs(a[y] - b[y]))
    bfs(x)
    routes = [y]
    while y != x:
        step = dist[y]
        nxt = -1
        for ny in edges[y]:
            if dist[ny] != step - 1:
                continue
            nxt = ny
            break
        y = nxt
        routes.append(y)
    routes.reverse()
    notEq = 0
    for x in routes:
        if a[x] != b[x]:
            notEq += 1
    ans = []
    liu(0, flow, routes)
    for x in routes:
        if a[x] != b[x]:
            notEq -= 1
    assert notEq >= 1


n, v, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
for _ in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    edges[x].append(y)
    edges[y].append(x)
for i in range(n):
    if visit[i]:
        continue
    dfs(i)
    cnt += 1
for i in range(n):
    s[c[i]] += a[i]
    s[c[i]] -= b[i]
for i in range(n):
    if s[i]:
        over("NO")
prev = 0
cur = 0
for i in range(n):
    if a[i] == b[i]:
        continue
    for j in range(i + 1, n):
        if c[i] != c[j]:
            continue
        if a[j] == b[j]:
            continue
        if a[i] < b[i] and a[j] < b[j]:
            continue
        if a[i] > b[i] and a[j] > b[j]:
            continue
        adjust(i, j)
        break
    if a[i] != b[i]:
        i -= 1
print(len(res))
for e in res:
    print(e[0][0] + 1, e[0][1] + 1, e[1])
