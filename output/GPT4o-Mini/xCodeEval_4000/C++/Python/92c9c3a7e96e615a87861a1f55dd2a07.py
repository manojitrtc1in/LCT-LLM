import sys
import heapq

def solve(ind):
    global c
    if ind == n:
        heapq.heappush(q, c)
        if len(q) > t:
            heapq.heappop(q)
        return
    solve(ind + 1)
    for i in range(len(adj[ind])):
        if vis[adj[ind][i][0]] == 0:
            vis[adj[ind][i][0]] = 1
            c += adj[ind][i][1]
            if len(q) < t or c < q[0]:
                solve(ind + 1)
            c -= adj[ind][i][1]
            vis[adj[ind][i][0]] = 0

input = sys.stdin.read
data = input().split()
n, m, t = map(int, data[:3])
data = data[3:]

adj = [[] for _ in range(200005)]
q = []
vis = [0] * 200005
c = 0

for i in range(m):
    x, y, w = map(int, data[i * 3:i * 3 + 3])
    x -= 1
    y -= 1
    adj[x].append((y, w))

solve(0)
print(q[0])
