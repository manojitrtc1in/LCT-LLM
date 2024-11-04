import sys
import math
from collections import deque, defaultdict
from heapq import heappop, heappush

INF = 1000000007
MOD = 1000000007
INF_LONG = 1e18

class Dijkstra:
    def __init__(self, n):
        self.N = n
        self.E = [[] for _ in range(n + 1)]

    def insert(self, u, v, w):
        self.E[u].append((v, w))

    def dijkstra(self, start, end):
        dist = [INF] * (self.N + 1)
        dist[start] = 0
        pq = []
        heappush(pq, (0, start))
        while pq:
            w, u = heappop(pq)
            w = -w
            if u == end:
                return dist
            if dist[u] < w:
                continue
            for v, w2 in self.E[u]:
                if dist[v] > w + w2:
                    dist[v] = w + w2
                    heappush(pq, (-dist[v], v))
        return dist

    def g(self):
        n, e = map(int, sys.stdin.readline().split())
        dk = Dijkstra(n)
        s = int(sys.stdin.readline())
        for _ in range(e):
            u, v, w = map(int, sys.stdin.readline().split())
            dk.insert(u, v, w)
        ans = dk.dijkstra(s, self.N)
        for i in range(1, n + 1):
            print("INF" if ans[i] >= INF else ans[i])

class Prim:
    def __init__(self, n):
        self.N = n
        self.E = [[] for _ in range(n + 1)]

    def insert(self, u, v, w):
        self.E[u].append((v, w))

    def execute(self):
        cost = 0
        dist = [INF] * (self.N + 1)
        selected = [False] * (self.N + 1)
        dist[1] = 0
        pq = []
        heappush(pq, (0, 1))
        for _ in range(self.N):
            w, u = heappop(pq)
            w = -w
            if selected[u]:
                continue
            cost += w
            selected[u] = True
            for v, w2 in self.E[u]:
                if not selected[v] and dist[v] > w2:
                    dist[v] = w2
                    heappush(pq, (-w2, v))
        return dist, cost

    def g(self):
        n, e = map(int, sys.stdin.readline().split())
        pm = Prim(n)
        s = int(sys.stdin.readline())
        for _ in range(e):
            u, v, w = map(int, sys.stdin.readline().split())
            pm.insert(u, v, w)
        ans, cost = pm.execute()
        print(cost)

class Floyd:
    def __init__(self, n):
        self.N = n
        self.E = [[INF] * (n + 1) for _ in range(n + 1)]

    def setRC(self, r, c, w):
        self.E[r][c] = w

    def execute(self):
        for i in range(1, self.N + 1):
            self.E[i][i] = 0
        for k in range(1, self.N + 1):
            for i in range(1, self.N + 1):
                for j in range(1, self.N + 1):
                    self.E[i][j] = min(self.E[i][j], self.E[i][k] + self.E[k][j])

class DFS_Graph:
    def __init__(self, n):
        self.N = n
        self.E = [[] for _ in range(n + 1)]
        self.A = [0] * (n + 1)

    def insert(self, u, v, w):
        self.E[u].append((v, w))

    def dfsAll(self, start, end):
        visited = [False] * (self.N + 1)
        return self.dfs(start, end, visited)

    def dfs(self, start, end, visited):
        if start == end:
            return 1
        visited[start] = True
        for v, _ in self.E[start]:
            if not visited[v]:
                if self.dfs(v, end, visited):
                    return 1
        return 0

    def g(self):
        n, m = map(int, sys.stdin.readline().split())
        dg = DFS_Graph(n)
        for _ in range(m):
            a, b = map(int, sys.stdin.readline().split())
            dg.insert(a, b, 0)
        m = int(sys.stdin.readline())
        for _ in range(m):
            a, b = map(int, sys.stdin.readline().split())
            if dg.dfsAll(a, b):
                c = -1
            elif dg.dfsAll(b, a):
                c = 1
            else:
                c = 0
            print(c)

class BFS_Graph:
    def __init__(self, n):
        self.N = n
        self.E = [[] for _ in range(n + 1)]
        self.IN = [0] * (n + 1)

    def insert(self, u, v, w):
        self.E[u].append((v, w))
        self.IN[v] += 1

    def bfs(self, start, end, min_weight):
        visited = [False] * (self.N + 1)
        weight = [INF_LONG] * (self.N + 1)
        Q = deque()
        visited[start] = True
        weight[start] = 0
        Q.append(start)
        while Q:
            u = Q.popleft()
            if u == end:
                break
            for v, c in self.E[u]:
                if c >= min_weight and not visited[v]:
                    Q.append(v)
                    weight[v] = weight[u] + c
                    visited[v] = True
        return weight

    def topologicalSort(self):
        order = []
        Q = deque()
        for i in range(1, self.N + 1):
            if self.IN[i] == 0:
                Q.append(i)
        while Q:
            u = Q.popleft()
            order.append(u)
            for v, _ in self.E[u]:
                if self.IN[v] > 0:
                    self.IN[v] -= 1
                    if self.IN[v] == 0:
                        Q.append(v)
        return order

    def g(self):
        n, m = map(int, sys.stdin.readline().split())
        bg = BFS_Graph(n)
        for _ in range(m):
            a, b, c = map(int, sys.stdin.readline().split())
            bg.insert(a, b, c)
        start, end = map(int, sys.stdin.readline().split())
        order = bg.topologicalSort()
        print(order)

def main():
    n = int(sys.stdin.readline())
    V = list(map(int, sys.stdin.readline().split()))
    V.sort()
    print(V[n // 2])

if __name__ == "__main__":
    main()
