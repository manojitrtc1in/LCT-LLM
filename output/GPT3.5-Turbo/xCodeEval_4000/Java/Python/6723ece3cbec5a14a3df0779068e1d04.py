import sys
from collections import deque

class Main:
    def __init__(self):
        self.adj = []
        self.dist = []
        self.mulpath = []
        self.k = 0
        self.p = []
        self.min = 0
        self.max = 0

    def bfs(self, s):
        self.dist = [float('inf')] * len(self.adj)
        self.dist[s] = 0
        queue = deque([s])

        while queue:
            u = queue.popleft()
            for v in self.adj[u]:
                if self.dist[v] == float('inf'):
                    self.dist[v] = self.dist[u] + 1
                    queue.append(v)
                elif self.dist[v] == self.dist[u] + 1:
                    self.mulpath[v] = True

    def solve(self):
        n, m = map(int, input().split())
        self.adj = [[] for _ in range(n)]
        for _ in range(m):
            u, v = map(int, input().split())
            self.adj[v-1].append(u-1)
        self.dist = [0] * n
        self.mulpath = [False] * n
        self.k = int(input())
        self.p = list(map(int, input().split()))
        self.bfs(self.p[self.k-1]-1)

        for i in range(len(self.p)-1):
            if self.dist[self.p[i+1]-1] + 1 == self.dist[self.p[i]-1]:
                if self.mulpath[self.p[i]-1]:
                    self.max += 1
            else:
                self.min += 1
                self.max += 1

        print(self.min, self.max)

if __name__ == "__main__":
    obj = Main()
    obj.solve()
