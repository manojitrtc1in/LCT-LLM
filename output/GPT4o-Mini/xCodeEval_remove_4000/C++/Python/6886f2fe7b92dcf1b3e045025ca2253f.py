from collections import deque
from cmath import sqrt
from itertools import combinations
from typing import List, Tuple, Dict, Any, Callable, Union

eps = 1e-9
MAX_MOD = 10**9 + 7
MOD = 10**9 + 9

def dot(a: complex, b: complex) -> float:
    return (a.real * b.real + a.imag * b.imag)

def cross(a: complex, b: complex) -> float:
    return (a.real * b.imag - a.imag * b.real)

def id3(a: Tuple[complex, complex], b: complex) -> float:
    if dot(a[1] - a[0], b - a[0]) < eps:
        return abs(b - a[0])
    if dot(a[0] - a[1], b - a[1]) < eps:
        return abs(b - a[1])
    return abs(cross(a[1] - a[0], b - a[0])) / abs(a[1] - a[0])

def id0(a: Tuple[complex, complex], b: Tuple[complex, complex]) -> int:
    return (cross(a[1] - a[0], b[0] - a[0]) * cross(a[1] - a[0], b[1] - a[0]) < eps) and \
           (cross(b[1] - b[0], a[0] - b[0]) * cross(b[1] - b[0], a[1] - b[0]) < eps)

def intersection_l(a: Tuple[complex, complex], b: Tuple[complex, complex]) -> complex:
    da = a[1] - a[0]
    db = b[1] - b[0]
    return a[0] + da * cross(db, b[0] - a[0]) / cross(db, da)

def id8(a: Tuple[complex, complex], b: Tuple[complex, complex]) -> float:
    if id0(a, b) == 1:
        return 0
    return min(id3(a, b[0]), id3(a, b[1]), id3(b, a[0]), id3(b, a[1]))

def id9(a: Dict[str, Any], b: Dict[str, Any]) -> Tuple[complex, complex]:
    dist = abs(a['center'] - b['center'])
    assert dist <= eps + a['r'] + b['r']
    assert dist + eps >= abs(a['r'] - b['r'])
    target = b['center'] - a['center']
    pointer = target.real * target.real + target.imag * target.imag
    aa = (pointer + a['r'] * a['r'] - b['r'] * b['r']) / 2.0
    l = complex((aa * target.real + target.imag * sqrt(pointer * a['r'] * a['r'] - aa * aa)) / pointer,
                (aa * target.imag - target.real * sqrt(pointer * a['r'] * a['r'] - aa * aa)) / pointer)
    r = complex((aa * target.real - target.imag * sqrt(pointer * a['r'] * a['r'] - aa * aa)) / pointer,
                (aa * target.imag + target.real * sqrt(pointer * a['r'] * a['r'] - aa * aa)) / pointer)
    r += a['center']
    l += a['center']
    return l, r

def gcd(a: int, b: int) -> int:
    if b == 0:
        return a
    return gcd(b, a % b)

def pows(val: Any, b: int) -> Any:
    assert b >= 1
    ans = val
    b -= 1
    while b:
        if b % 2:
            ans *= val
        val *= val
        b //= 2
    return ans

class Compressor:
    def __init__(self):
        self.id6 = False
        self.zipper = {}
        self.unzipper = {}
        self.fetcher = deque()

    def add(self, now: Any):
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

    def fetch(self) -> int:
        assert self.id6
        hoge = self.fetcher.popleft()
        return self.zipper[hoge]

    def zip(self, now: Any) -> int:
        assert self.id6
        assert now in self.zipper
        return self.zipper[now]

    def unzip(self, a: int) -> Any:
        assert self.id6
        assert a < len(self.unzipper)
        return self.unzipper[a]

    def next(self, now: Any) -> int:
        x = next((k for k in sorted(self.zipper.keys()) if k > now), None)
        if x is None:
            return len(self.zipper)
        return self.zipper[x]

    def back(self, now: Any) -> int:
        x = next((k for k in sorted(self.zipper.keys()) if k >= now), None)
        if x is None:
            return -1
        return self.zipper[x]

class Matrix:
    def __init__(self, a: List[List[Any]]):
        self.data = a

    def __add__(self, obj: 'Matrix') -> 'Matrix':
        assert len(obj.data) == len(self.data)
        assert len(obj.data[0]) == len(self.data[0])
        ans = []
        for i in range(len(obj.data)):
            ans.append([obj.data[i][j] + self.data[i][j] for j in range(len(obj.data[i]))])
        return Matrix(ans)

    def __sub__(self, obj: 'Matrix') -> 'Matrix':
        assert len(obj.data) == len(self.data)
        assert len(obj.data[0]) == len(self.data[0])
        ans = []
        for i in range(len(obj.data)):
            ans.append([self.data[i][j] - obj.data[i][j] for j in range(len(obj.data[i]))])
        return Matrix(ans)

    def __mul__(self, obj: 'Matrix') -> 'Matrix':
        assert len(obj.data) == len(self.data[0])
        ans = []
        for i in range(len(self.data)):
            ans.append([])
            for q in range(len(obj.data[0])):
                hoge = self.data[i][0] * obj.data[0][q]
                for t in range(1, len(obj.data[i])):
                    hoge += self.data[i][t] * obj.data[t][q]
                ans[-1].append(hoge)
        return Matrix(ans)

    def __imul__(self, obj: 'Matrix') -> 'Matrix':
        self.data = (self * obj).data
        return self

    def __iadd__(self, obj: 'Matrix') -> 'Matrix':
        self.data = (self + obj).data
        return self

    def __isub__(self, obj: 'Matrix') -> 'Matrix':
        self.data = (self - obj).data
        return self

class Fraction:
    def __init__(self, c: int = 0, d: int = 1):
        self.a = c
        self.b = d
        self.simplify()

    def simplify(self):
        g = gcd(abs(self.a), abs(self.b))
        self.a //= g
        self.b //= g
        if self.b < 0:
            self.b *= -1
            self.a *= -1

    def __lt__(self, rhs: 'Fraction') -> bool:
        return self.a * rhs.b < rhs.a * self.b

class ModInt:
    def __init__(self, a: int = 0):
        self.value = (a % MAX_MOD + 2 * MAX_MOD) % MAX_MOD

    def __add__(self, rhs: 'ModInt') -> 'ModInt':
        return ModInt(self.value + rhs.value)

    def __sub__(self, rhs: 'ModInt') -> 'ModInt':
        return ModInt(self.value - rhs.value)

    def __mul__(self, rhs: 'ModInt') -> 'ModInt':
        return ModInt(self.value * rhs.value)

    def __truediv__(self, rhs: 'ModInt') -> 'ModInt':
        rem = MAX_MOD - 2
        while rem:
            if rem % 2:
                self *= rhs
            rhs *= rhs
            rem //= 2
        return self

    def __iadd__(self, rhs: 'ModInt') -> 'ModInt':
        self.value += rhs.value
        if self.value >= MAX_MOD:
            self.value -= MAX_MOD
        return self

    def __isub__(self, rhs: 'ModInt') -> 'ModInt':
        if self.value < rhs.value:
            self.value += MAX_MOD
        self.value -= rhs.value
        return self

    def __imul__(self, rhs: 'ModInt') -> 'ModInt':
        self.value = (self.value * rhs.value) % MAX_MOD
        return self

    def __lt__(self, rhs: 'ModInt') -> bool:
        return self.value < rhs.value

    def __str__(self) -> str:
        return str(self.value)

class Dice:
    def __init__(self, init: List[int]):
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

    def ReachAble(self, now: 'Dice') -> bool:
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

    def __eq__(self, other: 'Dice') -> bool:
        return self.vertexs == other.vertexs

    def __lt__(self, other: 'Dice') -> bool:
        return self.vertexs < other.vertexs

def id1(center: int, up: int) -> Tuple[Dice, Dice]:
    target = 1
    while True:
        if center != target and 7 - center != target and up != target and 7 - up != target:
            break
        target += 1
    return (Dice([up, target, center, 7 - target, 7 - center, 7 - up]),
            Dice([up, 7 - target, center, target, 7 - center, 7 - up]))

def id2(center: int) -> Tuple[Dice, Dice, Dice, Dice]:
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
    def __init__(self, n: int, cost: Callable[[Any], Any]):
        self.vertexs = [[] for _ in range(n)]
        self.Cost_Function = cost

    def add_edge(self, a: int, b: int, c: Any):
        self.vertexs[a].append((b, c))

    def build_result(self, StartPoint: int) -> List[int]:
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
    class Edge:
        def __init__(self, to: int, cap: int, rev: int):
            self.to = to
            self.cap = cap
            self.rev = rev

    def __init__(self, n: int):
        self.Graph = [[] for _ in range(n)]
        self.level = []
        self.itr = []

    def add_edge(self, a: int, b: int, cap: int):
        self.Graph[a].append(self.Edge(b, cap, len(self.Graph[b])))
        self.Graph[b].append(self.Edge(a, 0, len(self.Graph[a]) - 1))

    def bfs(self, s: int):
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

    def dfs(self, now: int, goal: int, val: int) -> int:
        if goal == now:
            return val
        for i in range(self.itr[now], len(self.Graph[now])):
            target = self.Graph[now][i]
            if target.cap > 0 and self.level[now] < self.level[target.to]:
                d = self.dfs(target.to, goal, min(val, target.cap))
                if d > 0:
                    target.cap -= d
                    self.Graph[target.to][target.rev].cap += d
                    return d
        return 0

    def run(self, s: int, t: int) -> int:
        ans = 0
        f = 0
        while True:
            self.bfs(s)
            if self.level[t] < 0:
                break
            self.itr = [0] * len(self.Graph)
            while (f := self.dfs(s, t, int(1e9))) > 0:
                ans += f
        return ans

class Id7:
    def __init__(self, n: int):
        self.vertexs = [[] for _ in range(n)]
        self.depth = [0] * n
        self.backs = []
        self.connections = []
        self.zip = [0] * n
        self.unzip = self.zip

    def add_edge(self, a: int, b: int):
        self.vertexs[a].append(b)
        self.vertexs[b].append(a)

    def depth_dfs(self, now: int, back: int) -> int:
        self.depth[now] = 0
        for x in self.vertexs[now]:
            if x == back:
                continue
            self.depth[now] = max(self.depth[now], 1 + self.depth_dfs(x, now))
        return self.depth[now]

    def dfs(self, now: int, backing: int):
        self.zip[now] = len(self.backs)
        self.unzip.append(now)
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
        self.depth_dfs(0, -1)
        self.connections.append(-1)
        self.dfs(0, -1)

    def query(self, a: int, b: int) -> List[Tuple[int, int]]:
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

    def lca(self, a: int, b: int) -> int:
        a = self.zip[a]
        b = self.zip[b]
        while self.backs[a] != self.backs[b]:
            if a < b:
                a, b = b, a
            a = self.connections[a]
        return self.unzip[min(a, b)]

class SegmentTree:
    def __init__(self, n: int, f: Callable[[Any, Any], Any], M1: Any):
        self.sz = 1
        while self.sz < n:
            self.sz <<= 1
        self.seg = [M1] * (2 * self.sz + 1)
        self.f = f
        self.M1 = M1

    def set(self, k: int, x: Any):
        self.seg[k + self.sz] = x

    def build(self):
        for k in range(self.sz - 1, 0, -1):
            self.seg[k] = self.f(self.seg[2 * k + 0], self.seg[2 * k + 1])

    def update(self, k: int, x: Any):
        k += self.sz
        self.seg[k] = x
        while k >>= 1:
            self.seg[k] = self.f(self.seg[2 * k + 0], self.seg[2 * k + 1])

    def query(self, a: int, b: int) -> Any:
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

    def __getitem__(self, k: int) -> Any:
        return self.seg[k + self.sz]

class Id5:
    def __init__(self, n: int, f: Callable[[Any, Any], Any], g: Callable[[Any, Any, int], Any], h: Callable[[Any, Any], Any], M1: Any, OM0: Any):
        self.sz = 1
        self.height = 0
        while self.sz < n:
            self.sz <<= 1
            self.height += 1
        self.data = [M1] * (2 * self.sz)
        self.lazy = [OM0] * (2 * self.sz)
        self.f = f
        self.g = g
        self.h = h
        self.M1 = M1
        self.OM0 = OM0

    def set(self, k: int, x: Any):
        self.data[k + self.sz] = x

    def build(self):
        for k in range(self.sz - 1, 0, -1):
            self.data[k] = self.f(self.data[2 * k + 0], self.data[2 * k + 1])

    def propagate(self, k: int):
        if self.lazy[k] != self.OM0:
            self.lazy[2 * k + 0] = self.h(self.lazy[2 * k + 0], self.lazy[k])
            self.lazy[2 * k + 1] = self.h(self.lazy[2 * k + 1], self.lazy[k])
            self.data[k] = self.reflect(k)
            self.lazy[k] = self.OM0

    def reflect(self, k: int) -> Any:
        if self.lazy[k] == self.OM0:
            return self.data[k]
        for q in range(self.sz, 0, -1):
            if q & k:
                return self.g(self.data[k], self.lazy[k], self.sz // q)

    def recalc(self, k: int):
        while k >>= 1:
            self.data[k] = self.f(self.reflect(2 * k + 0), self.reflect(2 * k + 1))

    def thrust(self, k: int):
        for i in range(self.height, 0, -1):
            self.propagate(k >> i)

    def update(self, a: int, b: int, x: Any):
        self.thrust(a + self.sz)
        self.thrust(b + self.sz - 1)
        for l, r in zip(range(a + self.sz, b + self.sz + 1), range(a + self.sz, b + self.sz + 1)):
            if l & 1:
                self.lazy[l] = self.h(self.lazy[l], x)
                l += 1
            if r & 1:
                r -= 1
                self.lazy[r] = self.h(self.lazy[r], x)
        self.recalc(a + self.sz)
        self.recalc(b + self.sz)

    def query(self, a: int, b: int) -> Any:
        self.thrust(a + self.sz)
        self.thrust(b + self.sz - 1)
        L = self.M1
        R = self.M1
        for l, r in zip(range(a + self.sz, b + self.sz + 1), range(a + self.sz, b + self.sz + 1)):
            if l & 1:
                L = self.f(L, self.reflect(l))
                l += 1
            if r & 1:
                r -= 1
                R = self.f(self.reflect(r), R)
        return self.f(L, R)

    def __getitem__(self, k: int) -> Any:
        return self.query(k, k + 1)

class KMP:
    def __init__(self, a: List[int]):
        self.build(a)

    def build(self, a: List[int]):
        self.Pattern = a
        self.table = [-1] * (len(a) + 1)
        j = -1
        for i in range(len(a)):
            while j >= 0 and self.Pattern[i] != self.Pattern[j]:
                j = self.table[j]
            self.table[i + 1] = j + 1
            j += 1

    def search(self, a: List[int]) -> List[int]:
        ans = []
        k = 0
        for i in range(len(a)):
            while k >= 0 and a[i] != self.Pattern[k]:
                k = self.table[k]
            k += 1
            if k >= len(self.Pattern):
                ans.append(i - len(self.Pattern) + 1)
                k = self.table[k]
        return ans

def xor128() -> int:
    static_vars = [123456789, 362436069, 521288629, 88675123]
    x, y, z, w = static_vars
    t = (x ^ (x << 11))
    x, y, z, w = y, z, w
    return (w := (w ^ (w >> 19)) ^ (t ^ (t >> 8)))

def init():
    import sys
    input = sys.stdin.read
    sys.stdin = open(0)
    print(f"{0:.200f}")

def solve():
    n = int(input())
    t = input().strip()
    cnter = []
    for i in range(len(t)):
        if t[i] == '0':
            cnter.append(i * 2 + i % 2)
    hoge = [(0, 0)] * (len(cnter) + 1)
    rev = [(0, 0)] * (len(cnter) + 1)
    nexts = (1, 1)
    for i in range(len(cnter)):
        hoge[i + 1] = hoge[i]
        hoge[i + 1] = (hoge[i + 1][0] + nexts[0] * (cnter[i] % 2), hoge[i + 1][1] + nexts[1] * (cnter[i] % 2))
        rev[i + 1] = rev[i]
        rev[i + 1] = (rev[i + 1][0] + nexts[0] * ((cnter[i] + 1) % 2), rev[i + 1][1] + nexts[1] * ((cnter[i] + 1) % 2))
        nexts = (nexts[0] * 2, nexts[1] * 2)
    query = int(input())
    for _ in range(query):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        Left = (next((i for i, x in enumerate(cnter) if x >= a * 2), len(cnter)), 
                 next((i for i, x in enumerate(cnter) if x >= (a + c) * 2), len(cnter)))
        Right = (next((i for i, x in enumerate(cnter) if x >= b * 2), len(cnter)), 
                 next((i for i, x in enumerate(cnter) if x >= (b + c) * 2), len(cnter)))
        if Left[1] - Left[0] != Right[1] - Right[0]:
            print("No")
            continue
        ok = 1
        aa = list(hoge[Left[1]])
        aa = (aa[0] - hoge[Left[0]][0], aa[1] - hoge[Left[0]][1])
        if a % 2 == b % 2:
            bb = list(hoge[Right[1]])
            bb = (bb[0] - hoge[Right[0]][0], bb[1] - hoge[Right[0]][1])
        else:
            bb = list(rev[Right[1]])
            bb = (bb[0] - rev[Right[0]][0], bb[1] - rev[Right[0]][1])
        if Left[0] != 0:
            aa = (aa[0] // pows(2, Left[0]), aa[1] // pows(2, Left[0]))
        if Right[0] != 0:
            bb = (bb[0] // pows(2, Right[0]), bb[1] // pows(2, Right[0]))
        if aa[0] != bb[0] or aa[1] != bb[1]:
            ok = 0
        print("Yes" if ok == 1 else "No")

if __name__ == "__main__":
    init()
    solve()
