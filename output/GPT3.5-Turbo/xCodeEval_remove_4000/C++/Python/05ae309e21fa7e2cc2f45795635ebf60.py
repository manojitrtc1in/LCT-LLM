N = int(input())
A = []
B = []
C = []
for _ in range(N-1):
    a, b = map(int, input().split())
    A.append(a-1)
    B.append(b-1)

class wgraph:
    def __init__(self, N):
        self.N = N
        self.edge = [[] for _ in range(N)]
        self.cost = [[] for _ in range(N)]
    
    def setEdge(self, A, B, C):
        for i in range(len(A)):
            self.edge[A[i]].append(B[i])
            self.edge[B[i]].append(A[i])
            self.cost[A[i]].append(C[i])
            self.cost[B[i]].append(C[i])

g = wgraph(N)
g.setEdge(A, B, C)

arr = [0] * (N+1)
as_ = 0
for i in range(len(g.edge[0])):
    arr[as_] = dfs2(g.edge[0][i], 0)
    as_ += 1

dp = [0] * (N+1)
dp[0] = 1
for i in range(as_):
    for j in range(N, arr[i]-1, -1):
        if not dp[j] and dp[j-arr[i]]:
            dp[j] = 1
            back[j] = i

for p in range(N+1):
    if dp[p] and (p+1) * (N-p) - 1 >= 2*N*N/9:
        break

if p != N+1:
    k = p
    while k:
        ok[back[k]] = 1
        k -= arr[back[k]]
    cnt = 0
    dfs(r, -1, 0, 1, 0)
    cnt = 0
    dfs(r, -1, 0, p+1, 1)

for i in range(N):
    for j in range(len(g.edge[i])):
        k = g.edge[i][j]
        r = g.cost[i][j]
        if r > 0:
            print(i+1, k+1, r)
