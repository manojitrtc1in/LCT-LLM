import sys
from typing import List, Tuple
from math import gcd
from collections import deque
from itertools import permutations, combinations
from functools import reduce
from operator import mul
from bisect import bisect_left, bisect_right
from heapq import heappop, heappush
from copy import deepcopy
from queue import Queue


def lcm(a: int, b: int) -> int:
    return a // gcd(a, b) * b


def is_prime(x: int) -> bool:
    if x == 1:
        return False
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return False
    return True


def divisor(n: int) -> List[int]:
    ret = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            ret.append(i)
            if i * i != n:
                ret.append(n // i)
    ret.sort()
    return ret


def modpow(a: int, n: int, mod: int) -> int:
    res = 1
    while n > 0:
        if n & 1:
            res = res * a % mod
        a = a * a % mod
        n >>= 1
    return res


def modinv(a: int, mod: int) -> int:
    return modpow(a, mod - 2, mod)


MAX = 510000
fac = [0] * MAX
finv = [0] * MAX
inv = [0] * MAX


def COMinit() -> None:
    fac[0] = fac[1] = 1
    finv[0] = finv[1] = 1
    inv[1] = 1
    for i in range(2, MAX):
        fac[i] = fac[i - 1] * i % MOD
        inv[i] = MOD - inv[MOD % i] * (MOD // i) % MOD
        finv[i] = finv[i - 1] * inv[i] % MOD


def COM(n: int, k: int) -> int:
    if n < k:
        return 0
    if n < 0 or k < 0:
        return 0
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD


class UnionFind:
    def __init__(self, n: int) -> None:
        self.par = [-1] * n

    def init(self, n: int) -> None:
        self.par = [-1] * n

    def root(self, x: int) -> int:
        if self.par[x] < 0:
            return x
        else:
            self.par[x] = self.root(self.par[x])
            return self.par[x]

    def issame(self, x: int, y: int) -> bool:
        return self.root(x) == self.root(y)

    def merge(self, x: int, y: int) -> bool:
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return False
        if self.par[x] > self.par[y]:
            x, y = y, x

        self.par[x] += self.par[y]
        self.par[y] = x
        return True

    def size(self, x: int) -> int:
        return -self.par[self.root(x)]


class BIT:
    def __init__(self, n: int) -> None:
        self.n = n
        self.bit = [0] * (n + 1)

    def sum(self, i: int) -> int:
        s = 0
        while i > 0:
            s += self.bit[i]
            i -= i & -i
        return s

    def sum_range(self, x: int, y: int) -> int:
        return self.sum(y) - self.sum(x - 1)

    def add(self, i: int, x: int) -> None:
        while i <= self.n:
            self.bit[i] += x
            i += i & -i

    def lower_bound(self, w: int) -> int:
        if w <= 0:
            return 0
        x = 0
        r = 1
        while r < self.n:
            r <<= 1
        for k in range(r, 0, -1):
            if x + k <= self.n and self.bit[x + k] < w:
                w -= self.bit[x + k]
                x += k
        return x + 1


class id0:
    def __init__(self, v: List[int]) -> None:
        sz = len(v)
        self.n = 1
        while self.n < sz:
            self.n *= 2
        self.node = [0] * (2 * self.n - 1)
        self.lazy = [0] * (2 * self.n - 1)

        for i in range(sz):
            self.node[i + self.n - 1] = v[i]
        for i in range(self.n - 2, -1, -1):
            self.node[i] = self.node[i * 2 + 1] + self.node[i * 2 + 2]

    def eval(self, k: int, l: int, r: int) -> None:
        if self.lazy[k] != 0:
            self.node[k] += self.lazy[k]
            if r - l > 1:
                self.lazy[2 * k + 1] += self.lazy[k] // 2
                self.lazy[2 * k + 2] += self.lazy[k] // 2
            self.lazy[k] = 0

    def add(self, a: int, b: int, x: int, k: int = 0, l: int = 0, r: int = -1) -> None:
        if r < 0:
            r = self.n
        self.eval(k, l, r)
        if b <= l or r <= a:
            return
        if a <= l and r <= b:
            self.lazy[k] += (r - l) * x
            self.eval(k, l, r)
        else:
            self.add(a, b, x, 2 * k + 1, l, (l + r) // 2)
            self.add(a, b, x, 2 * k + 2, (l + r) // 2, r)
            self.node[k] = self.node[2 * k + 1] + self.node[2 * k + 2]

    def getsum(self, a: int, b: int, k: int = 0, l: int = 0, r: int = -1) -> int:
        if r < 0:
            r = self.n
        self.eval(k, l, r)
        if b <= l or r <= a:
            return 0
        if a <= l and r <= b:
            return self.node[k]
        vl = self.getsum(a, b, 2 * k + 1, l, (l + r) // 2)
        vr = self.getsum(a, b, 2 * k + 2, (l + r) // 2, r)
        return vl + vr


def digit_sum(v: int) -> int:
    ret = 0
    while v:
        ret += (v % 10)
        v //= 10
    return ret


def id4(n: int, g: List[List[int]], INF: int) -> List[List[int]]:
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if g[i][k] == INF or g[k][j] == INF:
                    continue
                g[i][j] = min(g[i][j], g[i][k] + g[k][j])
    return g


class Dijkstra:
    def __init__(self, n: int) -> None:
        self.n = n
        self.Edges = [[] for _ in range(n)]
        self.Dist = [0] * n
        self.Prev = [-1] * n
        self.PathNum = [0] * n

    def add_edge(self, a: int, b: int, c: int, directed: bool = True) -> None:
        if directed:
            self.Edges[a].append((b, c))
        else:
            self.Edges[a].append((b, c))
            self.Edges[b].append((a, c))

    def build(self, start: int) -> None:
        queue = []
        self.Dist = [1e+18] * self.n
        self.Prev = [-1] * self.n
        self.Dist[start] = 0
        self.PathNum[start] = 1
        heappush(queue, (0, start))

        while queue:
            p, v = heappop(queue)
            if self.Dist[v] < p:
                continue

            for e in self.Edges[v]:
                if self.Dist[e[0]] > self.Dist[v] + e[1]:
                    self.Dist[e[0]] = self.Dist[v] + e[1]
                    heappush(queue, (self.Dist[e[0]], e[0]))

                    self.Prev[e[0]] = v

                    self.PathNum[e[0]] = self.PathNum[v]
                elif self.Dist[e[0]] == self.Dist[v] + e[1]:
                    self.PathNum[e[0]] += self.PathNum[v]
                    self.PathNum[e[0]] %= MOD

    def dist(self, t: int) -> int:
        return self.Dist[t]

    def get_path(self, t: int) -> List[int]:
        path = []
        while t != -1:
            path.append(t)
            t = self.Prev[t]
        path.reverse()
        return path

    def get_path_num(self, t: int) -> int:
        return self.PathNum[t]


def LIS(a: List[int], n: int) -> int:
    A = [0x3f3f3f3f] * n
    for i in range(n):
        A[bisect_left(A, a[i])] = a[i]
    return bisect_left(A, 0x3f3f3f3f)


def id2(H: int, W: int, sx: int, sy: int, gx: int, gy: int) -> int:
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    dist = [[-1] * W for _ in range(H)]
    dist[sy][sx] = 0

    q = deque([(sy, sx)])
    while q:
        y, x = q.popleft()
        if y == gy and x == gx:
            break
        for t in range(4):
            nx = x + dx[t]
            ny = y + dy[t]
            if nx < 0 or ny < 0 or nx >= W or ny >= H or dist[ny][nx] != -1 or maze[ny][nx] == '#':
                continue
            dist[ny][nx] = dist[y][x] + 1
            q.append((ny, nx))

    return dist[gy][gx]


def id3(n: int, g: List[List[int]], INF: int) -> List[List[int]]:
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if g[i][k] == INF or g[k][j] == INF:
                    continue
                g[i][j] = min(g[i][j], g[i][k] + g[k][j])
    return g


class id1:
    def __init__(self, H: int, W: int) -> None:
        self.H = H
        self.W = W
        self.data = [[0] * (W + 1) for _ in range(H + 1)]

    def add(self, x: int, y: int, z: int) -> None:
        self.data[x + 1][y + 1] += z

    def build(self) -> None:
        for i in range(1, self.H + 1):
            for j in range(1, self.W + 1):
                self.data[i][j] += self.data[i][j - 1] + self.data[i - 1][j] - self.data[i - 1][j - 1]

    def query(self, sx: int, sy: int, gx: int, gy: int) -> int:
        return self.data[gy][gx] - self.data[sy - 1][gx] - self.data[gy][sx - 1] + self.data[sy - 1][sx - 1]


def digit_sum(v: int) -> int:
    ret = 0
    while v:
        ret += (v % 10)
        v //= 10
    return ret


def solve() -> None:
    n, k = map(int, input().split())
    if k == 1:
        print(1)
        sys.exit(0)
    a = [0] * 101010
    a[2] = 1
    for i in range(3, 11):
        a[i] = (i - 1) * (a[i - 1] + a[i - 2])

    ans = 1
    for i in range(k):
        ans += cnk(n, k - i) * a[k - i]

    print(ans)


def main() -> None:
    solve()


if __name__ == "__main__":
    main()
