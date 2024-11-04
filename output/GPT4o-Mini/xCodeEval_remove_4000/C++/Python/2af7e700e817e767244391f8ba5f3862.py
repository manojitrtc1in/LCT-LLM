from collections import deque
from itertools import combinations
import math
import sys

eps = 1e-9

def dot(a, b):
    return a.real * b.real + a.imag * b.imag

def cross(a, b):
    return a.real * b.imag - a.imag * b.real

def id3(a, b):
    if dot(a[1] - a[0], b - a[0]) < eps:
        return abs(b - a[0])
    if dot(a[0] - a[1], b - a[1]) < eps:
        return abs(b - a[1])
    return abs(cross(a[1] - a[0], b - a[0])) / abs(a[1] - a[0])

def id0(a, b):
    return (cross(a[1] - a[0], b[0] - a[0]) * cross(a[1] - a[0], b[1] - a[0]) < eps) and \
           (cross(b[1] - b[0], a[0] - b[0]) * cross(b[1] - b[0], a[1] - b[0]) < eps)

def intersection_l(a, b):
    da = a[1] - a[0]
    db = b[1] - b[0]
    return a[0] + da * cross(db, b[0] - a[0]) / cross(db, da)

def id8(a, b):
    if id0(a, b):
        return 0
    return min(id3(a, b[0]), id3(a, b[1]), id3(b, a[0]), id3(b, a[1]))

def id9(a, b):
    dist = abs(a['center'] - b['center'])
    assert dist <= eps + a['r'] + b['r']
    assert dist + eps >= abs(a['r'] - b['r'])
    target = b['center'] - a['center']
    pointer = target.real ** 2 + target.imag ** 2
    aa = (pointer + a['r'] ** 2 - b['r'] ** 2) / 2.0
    l = complex((aa * target.real + target.imag * math.sqrt(pointer * a['r'] ** 2 - aa ** 2)) / pointer,
                (aa * target.imag - target.real * math.sqrt(pointer * a['r'] ** 2 - aa ** 2)) / pointer)
    r = complex((aa * target.real - target.imag * math.sqrt(pointer * a['r'] ** 2 - aa ** 2)) / pointer,
                (aa * target.imag + target.real * math.sqrt(pointer * a['r'] ** 2 - aa ** 2)) / pointer)
    r += a['center']
    l += a['center']
    return (l, r)

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

class Compressor:
    def __init__(self):
        self.id6 = False
        self.zipper = {}
        self.unzipper = {}
        self.fetcher = deque()

    def add(self, now):
        assert not self.id6
        self.zipper[now] = 1
        self.fetcher.append(now)

    def exec(self):
        assert not self.id6
        cnt = 0
        for key in sorted(self.zipper.keys()):
            self.zipper[key] = cnt
            self.unzipper[cnt] = key
            cnt += 1
        self.id6 = True

    def fetch(self):
        assert self.id6
        hoge = self.fetcher.popleft()
        return self.zipper[hoge]

    def zip(self, now):
        assert self.id6
        assert now in self.zipper
        return self.zipper[now]

    def unzip(self, a):
        assert self.id6
        assert a < len(self.unzipper)
        return self.unzipper[a]

    def next(self, now):
        x = next((k for k in sorted(self.zipper.keys()) if k > now), None)
        if x is None:
            return len(self.zipper)
        return self.zipper[x]

    def back(self, now):
        x = next((k for k in sorted(self.zipper.keys()) if k < now), None)
        if x is None:
            return -1
        return self.zipper[x]

class Matrix:
    def __init__(self, a):
        self.data = a

    def __add__(self, obj):
        assert len(obj.data) == len(self.data)
        assert len(obj.data[0]) == len(self.data[0])
        ans = []
        for i in range(len(obj.data)):
            ans.append([obj.data[i][j] + self.data[i][j] for j in range(len(obj.data[i]))])
        return Matrix(ans)

    def __sub__(self, obj):
        assert len(obj.data) == len(self.data)
        assert len(obj.data[0]) == len(self.data[0])
        ans = []
        for i in range(len(obj.data)):
            ans.append([self.data[i][j] - obj.data[i][j] for j in range(len(obj.data[i]))])
        return Matrix(ans)

    def __mul__(self, obj):
        assert len(obj.data) == len(self.data[0])
        ans = []
        for i in range(len(self.data)):
            ans.append([])
            for j in range(len(obj.data[0])):
                hoge = self.data[i][0] * obj.data[0][j]
                for t in range(1, len(obj.data)):
                    hoge += self.data[i][t] * obj.data[t][j]
                ans[-1].append(hoge)
        return Matrix(ans)

    def __imul__(self, obj):
        self.data = (self * obj).data
        return self

    def __iadd__(self, obj):
        self.data = (self + obj).data
        return self

    def __isub__(self, obj):
        self.data = (self - obj).data
        return self

class Fraction:
    def __init__(self, c=0, d=1):
        self.a = c
        self.b = d
        if d < 0:
            self.a *= -1
            self.b *= -1
        g = gcd(abs(c), abs(d))
        if g != 0:
            self.a //= g
            self.b //= g

    def __lt__(self, rhs):
        if self.a < 0 and rhs.a > 0:
            return True
        if self.a > 0 and rhs.a < 0:
            return False
        return self.a * rhs.b < rhs.a * self.b

    def __eq__(self, rhs):
        return self.a == rhs.a and self.b == rhs.b

class modint:
    def __init__(self, a=0, mod=1):
        self.value = a % mod
        self.mod = mod

    def __add__(self, rhs):
        return modint(self.value + rhs.value, self.mod)

    def __sub__(self, rhs):
        return modint(self.value - rhs.value, self.mod)

    def __mul__(self, rhs):
        return modint(self.value * rhs.value, self.mod)

    def __truediv__(self, rhs):
        return modint(self.value * pow(rhs.value, self.mod - 2, self.mod), self.mod)

    def __iadd__(self, rhs):
        self.value += rhs.value
        if self.value >= self.mod:
            self.value -= self.mod
        return self

    def __isub__(self, rhs):
        if self.value < rhs.value:
            self.value += self.mod
        self.value -= rhs.value
        return self

    def __imul__(self, rhs):
        self.value = (self.value * rhs.value) % self.mod
        return self

    def __lt__(self, rhs):
        return self.value < rhs.value

    def __str__(self):
        return str(self.value)

class Dice:
    def __init__(self, init):
        self.vertexs = init

    def RtoL(self):
        for q in range(1, 4):
            self.vertexs[q], self.vertexs[q + 1] = self.vertexs[q + 1], self.vertexs[q]

    def LtoR(self):
        for q in range(3, 0, -1):
            self.vertexs[q], self.vertexs[q + 1] = self.vertexs[q + 1], self.vertexs[q]

    def UtoD(self):
        self.vertexs[5], self.vertexs[4] = self.vertexs[4], self.vertexs[5]
        self.vertexs[2], self.vertexs[5] = self.vertexs[5], self.vertexs[2]
        self.vertexs[0], self.vertexs[2] = self.vertexs[2], self.vertexs[0]

    def DtoU(self):
        self.vertexs[0], self.vertexs[2] = self.vertexs[2], self.vertexs[0]
        self.vertexs[2], self.vertexs[5] = self.vertexs[5], self.vertexs[2]
        self.vertexs[5], self.vertexs[4] = self.vertexs[4], self.vertexs[5]

    def ReachAble(self, now):
        hoge = set()
        next_queue = deque([now])
        hoge.add(tuple(now.vertexs))
        while next_queue:
            seeing = next_queue.popleft()
            if seeing == self:
                return True
            seeing.RtoL()
            if tuple(seeing.vertexs) not in hoge:
                hoge.add(tuple(seeing.vertexs))
                next_queue.append(seeing)
            seeing.LtoR()
            seeing.LtoR()
            if tuple(seeing.vertexs) not in hoge:
                hoge.add(tuple(seeing.vertexs))
                next_queue.append(seeing)
            seeing.RtoL()
            seeing.UtoD()
            if tuple(seeing.vertexs) not in hoge:
                hoge.add(tuple(seeing.vertexs))
                next_queue.append(seeing)
            seeing.DtoU()
            seeing.DtoU()
            if tuple(seeing.vertexs) not in hoge:
                hoge.add(tuple(seeing.vertexs))
                next_queue.append(seeing)
        return False

    def __eq__(self, a):
        return self.vertexs == a.vertexs

    def __lt__(self, a):
        return self.vertexs < a.vertexs

def id1(center, up):
    target = 1
    while True:
        if center != target and 7 - center != target and up != target and 7 - up != target:
            break
        target += 1
    return (Dice([up, target, center, 7 - target, 7 - center, 7 - up]), 
            Dice([up, 7 - target, center, target, 7 - center, 7 - up]))

def id2(center):
    bo = min(center, 7 - center)
    if bo == 1:
        goa = (2, 3)
    elif bo == 2:
        goa = (1, 3)
    elif bo == 3:
        goa = (1, 2)
    return (Dice([goa[0], goa[1], center, 7 - goa[1], 7 - center, 7 - goa[0]]),
            Dice([goa[0], 7 - goa[1], center, goa[1], 7 - center, 7 - goa[0]]),
            Dice([7 - goa[0], goa[1], center, 7 - goa[1], 7 - center, goa[0]]),
            Dice([7 - goa[0], 7 - goa[1], center, goa[1], 7 - center, goa[0]]))

class Dijkstra:
    def __init__(self, n, cost):
        self.vertexs = [[] for _ in range(n)]
        self.Cost_Function = cost

    def add_edge(self, a, b, c):
        self.vertexs[a].append((b, c))

    def build_result(self, StartPoint):
        dist = [2e18] * len(self.vertexs)
        dist[StartPoint] = 0
        next_queue = deque([(0, StartPoint)])
        while next_queue:
            now = next_queue.popleft()
            if dist[now[1]] != now[0]:
                continue
            for x in self.vertexs[now[1]]:
                now_cost = now[0] + self.Cost_Function(x[1])
                if dist[x[0]] > now_cost:
                    dist[x[0]] = now_cost
                    next_queue.append((now_cost, x[0]))
        return dist

class Dinic:
    class edge:
        def __init__(self, to, cap, rev):
            self.to = to
            self.cap = cap
            self.rev = rev

    def __init__(self, n):
        self.Graph = [[] for _ in range(n)]

    def add_edge(self, a, b, cap):
        self.Graph[a].append(self.edge(b, cap, len(self.Graph[b])))
        self.Graph[b].append(self.edge(a, 0, len(self.Graph[a]) - 1))

    def bfs(self, s):
        self.level = [-1] * len(self.Graph)
        self.level[s] = 0
        next_queue = deque([s])
        while next_queue:
            now = next_queue.popleft()
            for x in self.Graph[now]:
                if x.cap == 0:
                    continue
                if self.level[x.to] == -1:
                    self.level[x.to] = self.level[now] + 1
                    next_queue.append(x.to)

    def dfs(self, now, goal, val):
        if goal == now:
            return val
        for i in range(len(self.Graph[now])):
            target = self.Graph[now][i]
            if target.cap > 0 and self.level[now] < self.level[target.to]:
                d = self.dfs(target.to, goal, min(val, target.cap))
                if d > 0:
                    target.cap -= d
                    self.Graph[target.to][target.rev].cap += d
                    return d
        return 0

    def run(self, s, t):
        ans = 0
        f = 0
        while True:
            self.bfs(s)
            if self.level[t] == -1:
                break
            self.itr = [0] * len(self.Graph)
            while (f := self.dfs(s, t, 1e9)) > 0:
                ans += f
        return ans

class id7:
    def __init__(self, n):
        self.vertexs = [[] for _ in range(n)]
        self.depth = [0] * n
        self.zip = [0] * n
        self.unzip = self.zip

    def add_edge(self, a, b):
        self.vertexs[a].append(b)
        self.vertexs[b].append(a)

    def depth_dfs(self, now, back):
        self.depth[now] = 0
        for x in self.vertexs[now]:
            if x == back:
                continue
            self.depth[now] = max(self.depth[now], 1 + self.depth_dfs(x, now))
        return self.depth[now]

    def dfs(self, now, backing):
        self.zip[now] = len(self.backs)
        self.unzip[len(self.backs)] = now
        self.backs.append(backing)
        now_max = -1
        itr = -1
        for x in self.vertexs[now]:
            if self.depth[x] > self.depth[now]:
                continue
            if now_max < self.depth[x]:
                now_max = self.depth[x]
                itr = x
        if itr == -1:
            return
        self.connections.append(self.connections[-1])
        self.dfs(itr, backing)
        for x in self.vertexs[now]:
            if self.depth[x] > self.depth[now]:
                continue
            if x == itr:
                continue
            self.connections.append(self.zip[now])
            self.dfs(x, len(self.backs))

    def build(self):
        self.backs = []
        self.depth_dfs(0, -1)
        self.connections = [-1]
        self.dfs(0, -1)

    def query(self, a, b):
        a = self.zip[a]
        b = self.zip[b]
        ans = []
        while self.backs[a] != self.backs[b]:
            if a < b:
                a, b = b, a
            ans.append((self.backs[a], a + 1))
            a = self.connections[a]
        if a > b:
            a, b = b, a
        ans.append((a, b + 1))
        return ans

    def lca(self, a, b):
        a = self.zip[a]
        b = self.zip[b]
        while self.backs[a] != self.backs[b]:
            if a < b:
                a, b = b, a
            a = self.connections[a]
        return self.unzip[min(a, b)]

class SegmentTree:
    def __init__(self, n, f, M1):
        self.sz = 1
        while self.sz < n:
            self.sz <<= 1
        self.seg = [M1] * (2 * self.sz + 1)
        self.f = f
        self.M1 = M1

    def set(self, k, x):
        self.seg[k + self.sz] = x

    def build(self):
        for k in range(self.sz - 1, 0, -1):
            self.seg[k] = self.f(self.seg[2 * k + 0], self.seg[2 * k + 1])

    def update(self, k, x):
        k += self.sz
        self.seg[k] = x
        while k >>= 1:
            self.seg[k] = self.f(self.seg[2 * k + 0], self.seg[2 * k + 1])

    def query(self, a, b):
        L = self.M1
        R = self.M1
        for a += self.sz, b += self.sz; a < b; a >>= 1, b >>= 1:
            if a & 1:
                L = self.f(L, self.seg[a])
                a += 1
            if b & 1:
                b -= 1
                R = self.f(self.seg[b], R)
        return self.f(L, R)

    def __getitem__(self, k):
        return self.seg[k + self.sz]

def init():
    sys.stdin = open(0)
    sys.stdout = open(1)
    print(f"{0:.20f}")

def solve():
    n = int(input())
    inputs = []
    for _ in range(n):
        a = list(map(int, input().split()))
        inputs.append(a)
    ans = []
    for i in range(n):
        ok = 1
        for q in range(n):
            if i == q:
                continue
            for j in range(q + 1, n):
                if i == j:
                    continue
                A = [inputs[q][k] - inputs[i][k] for k in range(5)]
                B = [inputs[j][k] - inputs[i][k] for k in range(5)]
                if sign(A, B) == 0:
                    ok = 0
                    break
            if ok == 0:
                break
        if ok == 1:
            ans.append(i)
    print(len(ans))
    print(" ".join(str(x + 1) for x in ans))

if __name__ == "__main__":
    init()
    solve()
