from collections import defaultdict
import sys

input = sys.stdin.read
nil = (0, -float('inf'))

class Edge:
    def __init__(self, v):
        self.v = v
        self.next = None

N = 3005
top = -1
h = [None] * N
a = [0] * N
size = [0] * N
f = [[nil] * (N) for _ in range(N)]
tmp_f = [nil] * N

def addedge(u, v):
    global top
    top += 1
    tmp = Edge(v)
    tmp.next = h[u]
    h[u] = tmp

def dfs(u, pre):
    global size, f, tmp_f
    size[u] = 1
    f[u][1] = (0, a[u])
    
    tmp = h[u]
    while tmp:
        v = tmp.v
        if v == pre:
            tmp = tmp.next
            continue
        dfs(v, u)
        
        for i in range(1, size[u] + 1):
            tmp_f[i] = f[u][i]
            f[u][i] = nil
        
        for i in range(1, size[u] + 1):
            for j in range(1, size[v] + 1):
                if i + j - 1 > m:
                    break
                f[u][i + j] = max(f[u][i + j], 
                                  (tmp_f[i][0] + f[v][j][0], 
                                   tmp_f[i][1] + f[v][j][1] + (f[v][j][1] > 0, -f[v][j][1])))
                f[u][i + j - 1] = max(f[u][i + j - 1], 
                                      (tmp_f[i][0] + f[v][j][0], 
                                       tmp_f[i][1] + f[v][j][1]))
        
        size[u] += size[v]
        tmp = tmp.next

def init():
    global n, m, a, f, top, h
    n, m = map(int, input().split())
    
    for i in range(1, n + 1):
        a[i] = int(input().strip())
    
    for i in range(1, n + 1):
        x = int(input().strip())
        a[i] = x - a[i]
    
    for _ in range(1, n):
        x, y = map(int, input().split())
        addedge(x, y)
        addedge(y, x)
    
    for i in range(1, n + 2):
        for j in range(1, m + 2):
            f[i][j] = nil
    
    dfs(1, 0)
    print(f[1][m][0] + (f[1][m][1] > 0))
    
    top = -1
    for i in range(1, n + 2):
        h[i] = None

def main():
    T = int(input().strip())
    for _ in range(T):
        init()

if __name__ == "__main__":
    main()
