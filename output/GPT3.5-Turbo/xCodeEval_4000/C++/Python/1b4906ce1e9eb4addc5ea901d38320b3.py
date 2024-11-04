from collections import defaultdict

N = 3005
pil = lambda a, b: (a, b)

class Edge:
    def __init__(self, v):
        self.v = v
        self.next = None

pool = [Edge(0) for _ in range(3 * N)]
h = [None] * N

n, m, top = 0, 0, 0
a = [0] * N
size = [0] * N
f = [[pil(0, -0x3f3f3f3f3f3f3f3f)] * N for _ in range(N)]
tmp_f = [pil(0, -0x3f3f3f3f3f3f3f3f)] * N
nil = pil(0, -0x3f3f3f3f3f3f3f3f)

def addedge(u, v):
    global top
    tmp = pool[top + 1]
    tmp.v = v
    tmp.next = h[u]
    h[u] = tmp
    top += 1

def dfs(u, pre):
    global size
    size[u] = 1
    f[u][1] = pil(0, a[u])
    tmp = h[u]
    while tmp:
        v = tmp.v
        if v == pre:
            tmp = tmp.next
            continue
        dfs(v, u)
        for i in range(1, size[u] + 1):
            tmp_f[i] = f[u][i]
            f[u][i] = pil(0, -0x3f3f3f3f3f3f3f3f)
        for i in range(1, size[u] + 1):
            for j in range(1, size[v] + 1):
                if i + j - 1 > m:
                    break
                f[u][i + j] = max(f[u][i + j], tmp_f[i] + f[v][j] + pil(f[v][j][1] > 0, -f[v][j][1]))
                f[u][i + j - 1] = max(f[u][i + j - 1], tmp_f[i] + f[v][j])
        size[u] += size[v]
        tmp = tmp.next

def init():
    global n, m, a, h, f, top
    x, y = 0, 0
    n, m = map(int, input().split())
    a = [0] + list(map(int, input().split()))
    a = [x - a[i] for i, x in enumerate(map(int, input().split()), start=1)]
    for _ in range(n - 1):
        x, y = map(int, input().split())
        addedge(x, y)
        addedge(y, x)
    for i in range(n + 1):
        for j in range(m + 1):
            f[i][j] = nil
    dfs(1, 0)
    print(f[1][m][0] + (f[1][m][1] > 0))
    top = -1
    h = [None] * (n + 2)

T = int(input())
for _ in range(T):
    init()
