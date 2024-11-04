import sys
from collections import deque
from sortedcontainers import SortedSet

mod = 1000000007

class Scanner:
    def __init__(self, source):
        if isinstance(source, str):
            self.br = open(source, 'r')
        else:
            self.br = source
        self.st = None

    def next(self):
        while self.st is None or not self.st:
            self.st = self.br.readline().split()
        return self.st.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

def bfs(s, adj, dist, mulpath):
    dist[:] = [float('inf')] * len(dist)
    dist[s] = 0
    q = deque([s])

    while q:
        u = q.popleft()
        for v in adj[u]:
            if dist[v] == float('inf'):
                dist[v] = dist[u] + 1
                q.append(v)
            elif dist[v] == dist[u] + 1:
                mulpath[v] = True

def main():
    sc = Scanner(sys.stdin)
    n = sc.next_int()
    m = sc.next_int()
    adj = [[] for _ in range(n)]
    
    for _ in range(m):
        u = sc.next_int() - 1
        v = sc.next_int() - 1
        adj[v].append(u)

    dist = [0] * n
    mulpath = [False] * n
    k = sc.next_int()
    p = [sc.next_int() - 1 for _ in range(k)]

    bfs(p[k - 1], adj, dist, mulpath)

    min_count = 0
    max_count = 0
    for i in range(k - 1):
        if dist[p[i + 1]] + 1 == dist[p[i]]:
            if mulpath[p[i]]:
                max_count += 1
        else:
            min_count += 1
            max_count += 1

    print(min_count, max_count)

if __name__ == "__main__":
    main()
