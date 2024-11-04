import sys

class Main:
    def __init__(self):
        self.adj = []
        self.out = sys.stdout
        self.mod = 1000000007
        self.notmemo = []
        self.k = 0
        self.a = []
        self.b = []
        self.m = 0
        self.c = []
        self.trace = []
        self.h = 0
        self.x = 0
        self.ans1 = 0
        self.ans2 = 0

    def main(self):
        n, m = map(int, input().split())
        self.adj = [[] for _ in range(n)]
        for _ in range(m):
            u, v = map(int, input().split())
            self.adj[v-1].append(u-1)
        self.dist = [float('inf')] * n
        self.mulpath = [False] * n
        k = int(input())
        p = list(map(int, input().split()))
        self.bfs(p[k-1])
        min_count = 0
        max_count = 0
        for i in range(len(p)-1):
            if self.dist[p[i+1]] + 1 == self.dist[p[i]]:
                if self.mulpath[p[i]]:
                    max_count += 1
            else:
                min_count += 1
                max_count += 1
        print(min_count, max_count)

    def bfs(self, s):
        self.dist = [float('inf')] * len(self.dist)
        self.dist[s] = 0
        q = [s]
        while q:
            u = q.pop(0)
            for v in self.adj[u]:
                if self.dist[v] == float('inf'):
                    self.dist[v] = self.dist[u] + 1
                    q.append(v)
                elif self.dist[v] == self.dist[u] + 1:
                    self.mulpath[v] = True

if __name__ == "__main__":
    obj = Main()
    obj.main()
