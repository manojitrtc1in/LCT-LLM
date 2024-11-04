class Dinic:
    def __init__(self, n):
        self.n = n
        self.to = [[] for _ in range(n)]
        self.cap = [[] for _ in range(n)]
        self.rev = [[] for _ in range(n)]
        self.min_cost = [-1] * n
        self.iter = [0] * n

    def add_edge(self, from_, to, cap):
        self.rev[from_].append(len(self.to[to]))
        self.rev[to].append(len(self.to[from_]))
        self.to[from_].append(to)
        self.to[to].append(from_)
        self.cap[from_].append(cap)
        self.cap[to].append(0)

    def bfs(self, s, t):
        self.min_cost = [-1] * self.n
        q = [s]
        self.min_cost[s] = 0
        head = 0
        while head < len(q) and self.min_cost[t] == -1:
            p = q[head]
            head += 1
            for i, to in enumerate(self.to[p]):
                if self.cap[p][i] > 0 and self.min_cost[to] == -1:
                    cost = self.min_cost[p] + 1
                    self.min_cost[to] = cost
                    q.append(to)

        return self.min_cost[t] != -1

    def dfs(self, idx, t, flow):
        if idx == t:
            return flow

        for i in range(self.iter[idx], len(self.cap[idx])):
            self.iter[idx] = i
            cap = self.cap[idx][i]
            to = self.to[idx][i]
            if cap > 0 and self.min_cost[idx] < self.min_cost[to]:
                delta = self.dfs(to, t, min(flow, cap))
                if delta > 0:
                    self.cap[idx][i] -= delta
                    rev = self.rev[idx][i]
                    self.cap[to][rev] += delta
                    return delta

        return 0

    def max_flow(self, s, t):
        flow = 0
        while self.bfs(s, t):
            self.iter = [0] * self.n
            f = 0
            while (f := self.dfs(s, t, float('inf'))) > 0:
                flow += f

        return flow


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    ma = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0])
    d = Dinic(8)
    d.add_edge(6, 0, a[0])
    d.add_edge(6, 1, a[1])
    d.add_edge(6, 2, a[2])

    d.add_edge(0, 3, float('inf'))
    d.add_edge(0, 5, float('inf'))
    d.add_edge(1, 3, float('inf'))
    d.add_edge(1, 4, float('inf'))
    d.add_edge(2, 4, float('inf'))
    d.add_edge(2, 5, float('inf'))

    d.add_edge(3, 7, b[0])
    d.add_edge(4, 7, b[1])
    d.add_edge(5, 7, b[2])

    print(n - d.max_flow(6, 7), ma)


T = 1
for _ in range(T):
    solve()
