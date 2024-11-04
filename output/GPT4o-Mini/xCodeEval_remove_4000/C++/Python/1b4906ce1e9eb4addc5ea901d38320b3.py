from collections import defaultdict

N = int(3e3 + 5)

class Edge:
    def __init__(self, v):
        self.v = v
        self.next = None

h = [None] * N
pool = [Edge(0) for _ in range(3 * N)]
top = -1

n, m = 0, 0
a = [0] * N
size = [0] * N
nil = (0, -0x3f3f3f3f3f3f3f3f)

def addedge(u, v):
    global top
    top += 1
    tmp = pool[top]
    tmp.v = v
    tmp.next = h[u]
    h[u] = tmp

def operator_add(x, y):
    return (x[0] + y[0], x[1] + y[1])

def dfs(u, pre):
    global size
    size[u] = 1
    f[u] = [(0, 0)] * (N)
    f[u][1] = (0, 1 * a[u])
    
    for tmp in iter_edges(u):
        v = tmp.v
        if v == pre:
            continue
        dfs(v, u)
        tmp_f = f[u][:size[u]]
        f[u] = [(0, -0x3f3f3f3f3f3f3f3f)] * (N)
        
        for i in range(1, size[u] + 1):
            for j in range(1, size[v] + 1):
                if i + j - 1 > m:
                    break
                f[u][i + j] = max(f[u][i + j], operator_add(tmp_f[i], f[v][j]) + (f[v][j][1] > 0, -f[v][j][1]))
                f[u][i + j - 1] = max(f[u][i + j - 1], operator_add(tmp_f[i], f[v][j]))

        size[u] += size[v]

def iter_edges(u):
    tmp = h[u]
    while tmp:
        yield tmp
        tmp = tmp.next

def init():
    global n, m
    x, y = 0, 0
    n, m = map(int, input().split())
    for i in range(1, n + 1):
        a[i] = int(input())
    for i in range(1, n + 1):
        x = int(input())
        a[i] = x - a[i]
    for _ in range(1, n):
        x, y = map(int, input().split())
        addedge(x, y)
        addedge(y, x)
    
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            f[i][j] = nil
    dfs(1, 0)
    print(f[1][m][0] + (f[1][m][1] > 0))
    
    global top
    top = -1
    for i in range(1, n + 1):
        h[i] = None

if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        init()
