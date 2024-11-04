N = 3 * 10**3 + 5

class Edge:
    def __init__(self, v):
        self.v = v
        self.next = None

h = [None] * N

n = 0
m = 0
top = 0
a = [0] * N
size = [0] * N
f = [[(0, -0x3f3f3f3f3f3f3f3f)] * N for _ in range(N)]
tmp_f = [(0, -0x3f3f3f3f3f3f3f3f)] * N
nil = (0, -0x3f3f3f3f3f3f3f3f)

def addedge(u, v):
    global top
    tmp = Edge(v)
    tmp.next = h[u]
    h[u] = tmp
    top += 1

def dfs(u, pre):
    global size
    global f
    size[u] = 1
    f[u][1] = (0, 1 * a[u])
    tmp = h[u]
    while tmp:
        v = tmp.v
        if v == pre:
            tmp = tmp.next
            continue
        dfs(v, u)
        for i in range(1, size[u] + 1):
            tmp_f[i] = f[u][i]
            f[u][i] = (0, -0x3f3f3f3f3f3f3f3f)
        for i in range(1, size[u] + 1):
            for j in range(1, size[v] + 1):
                if i + j - 1 > m:
                    break
                f[u][i + j] = max(f[u][i + j], (tmp_f[i][0] + f[v][j][0], tmp_f[i][1] + f[v][j][1] + (f[v][j][1] > 0, -f[v][j][1])))
                f[u][i + j - 1] = max(f[u][i + j - 1], (tmp_f[i][0] + f[v][j][0], tmp_f[i][1] + f[v][j][1]))
        size[u] += size[v]
        tmp = tmp.next

def init():
    global n
    global m
    global a
    global h
    global f
    global top
    x = 0
    y = 0
    n, m = map(int, input().split())
    a = [0] * (n + 1)
    for i in range(1, n + 1):
        a[i] = int(input())
    for i in range(1, n + 1):
        x = int(input())
        a[i] = x - a[i]
    for i in range(1, n):
        x, y = map(int, input().split())
        addedge(x, y)
        addedge(y, x)
    for i in range(1, n + 2):
        for j in range(1, m + 2):
            f[i][j] = nil
    dfs(1, 0)
    print(f[1][m][0] + (f[1][m][1] > 0))
    top = -1
    h = [None] * (n + 2)

T = int(input())
for i in range(1, T + 1):
    init()
