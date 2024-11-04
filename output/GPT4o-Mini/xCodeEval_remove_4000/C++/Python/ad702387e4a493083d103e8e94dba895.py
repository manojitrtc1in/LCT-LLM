mod = int(1e9 + 7)
gmod = 2
inf = 1039074182
eps = 1e-9
llinf = 1 * inf * inf

def chmin(x, b):
    if b < x:
        x = b
    return x

def chmax(x, b):
    if b > x:
        x = b
    return x

def chadd(x, b):
    x += b - mod
    x += (x >> 31) & mod
    return x

def chadd_mod(x, b):
    x += b
    if x >= mod:
        x -= mod
    return x

def chmul(x, b):
    return (1 * x * b) % mod

def chmod(x, b):
    x %= b
    x += b
    if x >= b:
        x -= b
    return x

def mabs(x):
    return -x if x < 0 else x

def print_vector(vec):
    return "{" + ",".join(map(str, vec)) + "}"

def operator_multiply(vec, k):
    return [x * k for x in vec]

def operator_subtract(a, b):
    assert len(a) == len(b)
    return [a[i] - b[i] for i in range(len(a))]

def operator_multiply_vec(vec, k):
    return operator_multiply(vec, k)

def operator_add(x, y):
    return (x[0] + y[0], x[1] + y[1])

def operator_add_inplace(x, y):
    x[0] += y[0]
    x[1] += y[1]

def operator_negate(x):
    return (-x[0], -x[1])

def operator_transpose(vec):
    return [[vec[j][i] for j in range(len(vec))] for i in range(len(vec[0]))]

def id0(x):
    vec = []
    while x:
        vec.append(x & 1)
        x >>= 1
    vec.reverse()
    print(' '.join(map(str, vec)), end=' ')

def id0_len(x, length):
    vec = []
    while x:
        vec.append(x & 1)
        x >>= 1
    vec.reverse()
    print('0' * (length - len(vec)), end='')
    print(' '.join(map(str, vec)), end=' ')

n, v, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
edges = [[] for _ in range(305)]
for _ in range(m):
    x, y = map(int, input().split())
    x -= 1
    y -= 1
    edges[x].append(y)
    edges[y].append(x)

visit = [0] * 305
cnt = 0
c = [0] * 305
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
    visit[:] = [0] * len(visit)
    visit[src] = 1
    dist[src] = 0
    que = [src]
    while que:
        x = que.pop(0)
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

def liu_recursive(i, flow, routes):
    if i == len(routes) - 1:
        return
    nxt = routes[i + 1]
    now = routes[i]
    if a[nxt] + flow <= v:
        liu(now, nxt, flow)
        liu_recursive(i + 1, flow, routes)
    else:
        id2 = a[now]
        moved = v - a[nxt]
        liu(now, nxt, v - a[nxt])
        liu_recursive(i + 1, flow, routes)
        liu(now, nxt, flow - moved)
        id1 = a[now]

def adjust(x, y):
    assert a[x] != b[x]
    assert a[y] != b[y]
    if a[x] < b[x]:
        x, y = y, x
    flow = min(mabs(a[x] - b[x]), mabs(a[y] - b[y]))
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
    notEq = sum(1 for x in routes if a[x] != b[x])
    liu_recursive(0, flow, routes)
    for x in routes:
        if a[x] != b[x]:
            notEq -= 1
    assert notEq >= 1

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
        print("NO")
        exit()

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
