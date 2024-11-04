from collections import defaultdict
import sys
import math

INF = float('inf')

class Vector:
    def __init__(self, n, data_size):
        self.n = 0
        self.max = n
        self.data_size = data_size
        self.data = [0] * (n * data_size)

    def push(self, x):
        if self.n == self.max:
            self.max *= 2
            self.data.extend([0] * (self.max * self.data_size - len(self.data)))
        if x is None:
            self.data[self.n * self.data_size:self.n * self.data_size + self.data_size] = [0] * self.data_size
        else:
            self.data[self.n * self.data_size:self.n * self.data_size + self.data_size] = x
        self.n += 1

    def set(self, idx, x):
        if x is None:
            self.data[idx * self.data_size:idx * self.data_size + self.data_size] = [0] * self.data_size
        else:
            self.data[idx * self.data_size:idx * self.data_size + self.data_size] = x

    def get(self, idx):
        if self.data_size == 8:
            return int.from_bytes(self.data[idx * self.data_size:idx * self.data_size + 8], 'little')
        elif self.data_size == 4:
            return int.from_bytes(self.data[idx * self.data_size:idx * self.data_size + 4], 'little')
        elif self.data_size == 2:
            return bool.from_bytes(self.data[idx * self.data_size:idx * self.data_size + 2], 'little')

    def size(self):
        return self.n

class Dinic:
    def __init__(self, n):
        self.n = n
        self.to = [Vector(1, 4) for _ in range(n)]
        self.cap = [Vector(1, 8) for _ in range(n)]
        self.rev = [Vector(1, 4) for _ in range(n)]
        self.min_cost = Vector(n, 4)
        self.iter = Vector(n, 4)

    def add(self, from_node, to_node, cap):
        self.rev[from_node].push(self.to[to_node].n)
        self.rev[to_node].push(self.to[from_node].n)
        self.to[from_node].push(to_node)
        self.to[to_node].push(from_node)
        self.cap[from_node].push(cap)
        self.cap[to_node].push(None)

    def bfs(self, s, t):
        init = -1
        for i in range(self.n):
            self.min_cost.set(i, init)
        q = Vector(1, 4)
        self.min_cost.set(s, None)
        head = 0
        q.push(s)
        while head != q.n and self.min_cost.get(t) == -1:
            p = q.get(head)
            head += 1
            for i in range(self.to[p].n):
                to = self.to[p].get(i)
                if self.cap[p].get(i) > 0 and self.min_cost.get(to) == -1:
                    cost = self.min_cost.get(p) + 1
                    self.min_cost.set(to, cost)
                    q.push(to)
        return self.min_cost.get(t) != -1

    def dfs(self, idx, t, flow):
        if idx == t:
            return flow
        for i in range(self.iter.get(idx), self.cap[idx].n):
            self.iter.set(idx, i)
            cap = self.cap[idx].get(i)
            to = self.to[idx].get(i)
            if cap > 0 and self.min_cost.get(idx) < self.min_cost.get(to):
                delta = self.dfs(to, t, min(flow, cap))
                if delta > 0:
                    cap -= delta
                    self.cap[idx].set(i, cap)
                    rev = self.rev[idx].get(i)
                    rev_cap = self.cap[to].get(rev) + delta
                    self.cap[to].set(rev, rev_cap)
                    return delta
        return 0

    def max_flow(self, s, t):
        flow = 0
        while self.bfs(s, t):
            for i in range(self.n):
                self.iter.set(i, 0)
            f = 0
            while (f := self.dfs(s, t, INF)) > 0:
                flow += f
        return flow

def solve():
    n = int(sys.stdin.readline().strip())
    a = [int(sys.stdin.readline().strip()) for _ in range(3)]
    b = [int(sys.stdin.readline().strip()) for _ in range(3)]
    ma = min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0])
    
    d = Dinic(8)
    d.add(6, 0, a[0])
    d.add(6, 1, a[1])
    d.add(6, 2, a[2])

    d.add(0, 3, INF)
    d.add(0, 5, INF)
    d.add(1, 3, INF)
    d.add(1, 4, INF)
    d.add(2, 4, INF)
    d.add(2, 5, INF)

    d.add(3, 7, b[0])
    d.add(4, 7, b[1])
    d.add(5, 7, b[2])
    
    print(n - d.max_flow(6, 7), ma)

if __name__ == "__main__":
    T = 1
    for _ in range(T):
        solve()
