import sys
from collections import defaultdict
import itertools

class DijkstraHeap:
    def __init__(self, N):
        self.val = [float('inf')] * N
        self.visited = [False] * N
        self.hp = []
        self.place = [-1] * N
        self.size = 0

    def up(self, n):
        while n:
            m = (n - 1) // 2
            if self.val[self.hp[m]] <= self.val[self.hp[n]]:
                break
            self.hp[m], self.hp[n] = self.hp[n], self.hp[m]
            self.place[self.hp[m]], self.place[self.hp[n]] = self.place[self.hp[n]], self.place[self.hp[m]]
            n = m

    def down(self, n):
        while True:
            m = 2 * n + 1
            if m >= self.size:
                break
            if m + 1 < self.size and self.val[self.hp[m]] > self.val[self.hp[m + 1]]:
                m += 1
            if self.val[self.hp[m]] >= self.val[self.hp[n]]:
                break
            self.hp[m], self.hp[n] = self.hp[n], self.hp[m]
            self.place[self.hp[m]], self.place[self.hp[n]] = self.place[self.hp[n]], self.place[self.hp[m]]
            n = m

    def change(self, n, v):
        if self.visited[n] or (self.place[n] >= 0 and self.val[n] <= v):
            return
        self.val[n] = v
        if self.place[n] == -1:
            self.place[n] = self.size
            self.hp.append(n)
            self.size += 1
            self.up(self.place[n])
        else:
            self.up(self.place[n])

    def pop(self):
        res = self.hp[0]
        self.place[res] = -1
        self.size -= 1
        if self.size:
            self.hp[0] = self.hp[self.size]
            self.place[self.hp[0]] = 0
            self.down(0)
        self.visited[res] = True
        return res

class Graph:
    def __init__(self):
        self.N = 0
        self.edge = []
        self.es = []

    def set_edge(self, N__, M, A, B):
        self.N = N__
        self.es = [0] * N__
        self.edge = [[] for _ in range(N__)]
        for i in range(M):
            self.es[A[i]] += 1
            self.es[B[i]] += 1
        for i in range(N__):
            self.edge[i] = [0] * self.es[i]
        for i in range(M):
            self.edge[A[i]][self.es[A[i]] - 1] = B[i]
            self.edge[B[i]][self.es[B[i]] - 1] = A[i]
            self.es[A[i]] -= 1
            self.es[B[i]] -= 1

    def dfs(self, n, b):
        res = 1
        for k in self.edge[n]:
            if k == b:
                continue
            res += self.dfs(k, n)
        return res

    def get_dist(self, root, res):
        hp = DijkstraHeap(self.N)
        hp.change(root, 0)
        while hp.size:
            i = hp.pop()
            for j in range(len(self.edge[i])):
                hp.change(self.edge[i][j], hp.val[i] + 1)  # Assuming cost is 1 for simplicity
        for i in range(self.N):
            res[i] = hp.val[i] if hp.visited[i] else -1

def main():
    input = sys.stdin.read
    data = input().split()
    idx = 0
    N = int(data[idx])
    idx += 1
    A = [0] * (N - 1)
    B = [0] * (N - 1)
    for i in range(N - 1):
        A[i] = int(data[idx]) - 1
        idx += 1
        B[i] = int(data[idx]) - 1
        idx += 1

    g = Graph()
    g.set_edge(N, N - 1, A, B)

    for r in range(N):
        as_ = []
        for i in range(len(g.edge[r])):
            as_.append(g.dfs(g.edge[r][i], r))
        dp = [0] * (N + 1)
        dp[0] = 1
        for i in range(len(as_)):
            for j in range(N, as_[i] - 1, -1):
                if not dp[j] and dp[j - as_[i]]:
                    dp[j] = 1
        for p in range(N + 1):
            if dp[p] and (p + 1) * (N - p) - 1 >= 2 * N * N / 9:
                break
        if p == N + 1:
            continue

        cnt = 0
        for i in range(len(g.edge[r])):
            cnt += g.dfs(g.edge[r][i], r)

        for i in range(N):
            for j in range(len(g.edge[i])):
                k = g.edge[i][j]
                print(i + 1, k + 1, 1)  # Assuming cost is 1 for simplicity

if __name__ == "__main__":
    main()
