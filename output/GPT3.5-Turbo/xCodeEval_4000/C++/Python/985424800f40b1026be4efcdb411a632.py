import math

def grid_bfs(H, W, sx, sy, gx, gy):
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    dist = [[-1] * W for _ in range(H)]
    dist[sy][sx] = 0

    queue = [(sy, sx)]
    while queue:
        y, x = queue.pop(0)
        if y == gy and x == gx:
            break
        for t in range(4):
            nx = x + dx[t]
            ny = y + dy[t]
            if nx < 0 or ny < 0 or nx >= W or ny >= H or dist[ny][nx] != -1:
                continue
            if maze[ny][nx] == '#':
                continue
            dist[ny][nx] = dist[y][x] + 1
            queue.append((ny, nx))

    return dist[gy][gx]


def warshall_floyd(n, g, INF):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if g[i][k] == INF or g[k][j] == INF:
                    continue
                g[i][j] = min(g[i][j], g[i][k] + g[k][j])
    return g


class Dijkstra:
    def __init__(self, n):
        self.n = n
        self.Edges = [[] for _ in range(n)]
        self.Dist = [math.inf] * n
        self.Prev = [-1] * n
        self.PathNum = [0] * n

    def add_edge(self, a, b, c, directed=True):
        if directed:
            self.Edges[a].append((b, c))
        else:
            self.Edges[a].append((b, c))
            self.Edges[b].append((a, c))

    def build(self, start):
        queue = [(0, start)]
        self.Dist[start] = 0
        self.PathNum[start] = 1

        while queue:
            d, v = queue.pop(0)
            if self.Dist[v] < d:
                continue
            for to, cost in self.Edges[v]:
                if self.Dist[to] > self.Dist[v] + cost:
                    self.Dist[to] = self.Dist[v] + cost
                    queue.append((self.Dist[to], to))
                    self.Prev[to] = v
                    self.PathNum[to] = self.PathNum[v]
                elif self.Dist[to] == self.Dist[v] + cost:
                    self.PathNum[to] += self.PathNum[v]
                    self.PathNum[to] %= MOD

    def dist(self, t):
        return self.Dist[t]

    def get_path(self, t):
        path = []
        while t != -1:
            path.append(t)
            t = self.Prev[t]
        path.reverse()
        return path

    def get_path_num(self, t):
        return self.PathNum[t]


def solve():
    n, k = map(int, input().split())
    if k == 1:
        print(1)
        exit(0)
    a = [0] * 101010
    a[2] = 1
    for i in range(3, 11):
        a[i] = (i - 1) * (a[i - 1] + a[i - 2])

    ans = 1
    for i in range(k):
        ans += math.comb(n, k - i) * a[k - i]

    print(ans)


if __name__ == "__main__":
    solve()
