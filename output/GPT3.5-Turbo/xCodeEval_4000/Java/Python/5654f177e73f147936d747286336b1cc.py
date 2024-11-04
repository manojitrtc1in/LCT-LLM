import sys
from typing import List, Tuple, Dict, Any


class DSU:
    def __init__(self, n: int):
        self.sz = [1] * n
        self.p = list(range(n))

    def get(self, x: int) -> int:
        if x == self.p[x]:
            return x
        par = self.get(self.p[x])
        self.p[x] = par
        return par

    def unite(self, a: int, b: int) -> bool:
        pa = self.get(a)
        pb = self.get(b)
        if pa == pb:
            return False
        if self.sz[pa] < self.sz[pb]:
            self.p[pa] = pb
            self.sz[pb] += self.sz[pa]
        else:
            self.p[pb] = pa
            self.sz[pa] += self.sz[pb]
        return True


class SegmentTreeAdd:
    def __init__(self, a: List[int]):
        self.pow = 1
        while self.pow < len(a):
            self.pow *= 2
        self.flag = [False] * (2 * self.pow)
        self.max = [float('-inf')] * (2 * self.pow)
        self.delta = [0] * (2 * self.pow)
        for i in range(len(a)):
            self.max[self.pow + i] = a[i]
        for i in range(self.pow - 1, 0, -1):
            self.max[i] = self.f(self.max[2 * i], self.max[2 * i + 1])

    def get(self, v: int, tl: int, tr: int, l: int, r: int) -> int:
        self.push(v, tl, tr)
        if l > r:
            return float('-inf')
        if l == tl and r == tr:
            return self.max[v]
        tm = (tl + tr) // 2
        return self.f(self.get(2 * v, tl, tm, l, min(r, tm)), self.get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r))

    def set(self, v: int, tl: int, tr: int, l: int, r: int, x: int) -> None:
        self.push(v, tl, tr)
        if l > tr or r < tl:
            return
        if l <= tl and r >= tr:
            self.delta[v] += x
            self.flag[v] = True
            self.push(v, tl, tr)
            return
        tm = (tl + tr) // 2
        self.set(2 * v, tl, tm, l, r, x)
        self.set(2 * v + 1, tm + 1, tr, l, r, x)
        self.max[v] = self.f(self.max[2 * v], self.max[2 * v + 1])

    def push(self, v: int, tl: int, tr: int) -> None:
        if self.flag[v]:
            if v < self.pow:
                self.flag[2 * v] = True
                self.flag[2 * v + 1] = True
                self.delta[2 * v] += self.delta[v]
                self.delta[2 * v + 1] += self.delta[v]
            self.flag[v] = False
            self.max[v] += self.delta[v]
            self.delta[v] = 0

    def f(self, a: int, b: int) -> int:
        return max(a, b)


class SegmentTreeSet:
    def __init__(self, a: List[int]):
        self.pow = 1
        while self.pow < len(a):
            self.pow *= 2
        self.flag = [False] * (2 * self.pow)
        self.sum = [0] * (2 * self.pow)
        self.delta = [0] * (2 * self.pow)
        for i in range(len(a)):
            self.sum[self.pow + i] = a[i]

    def get(self, v: int, tl: int, tr: int, l: int, r: int) -> int:
        self.push(v, tl, tr)
        if l > r:
            return 0
        if l == tl and r == tr:
            return self.sum[v]
        tm = (tl + tr) // 2
        return self.f(self.get(2 * v, tl, tm, l, min(r, tm)), self.get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r))

    def set(self, v: int, tl: int, tr: int, l: int, r: int, x: int) -> None:
        self.push(v, tl, tr)
        if l > tr or r < tl:
            return
        if l <= tl and r >= tr:
            self.delta[v] = x
            self.flag[v] = True
            self.push(v, tl, tr)
            return
        tm = (tl + tr) // 2
        self.set(2 * v, tl, tm, l, r, x)
        self.set(2 * v + 1, tm + 1, tr, l, r, x)
        self.sum[v] = self.f(self.sum[2 * v], self.sum[2 * v + 1])

    def push(self, v: int, tl: int, tr: int) -> None:
        if self.flag[v]:
            if v < self.pow:
                self.flag[2 * v] = True
                self.flag[2 * v + 1] = True
                self.delta[2 * v] = self.delta[v]
                self.delta[2 * v + 1] = self.delta[v]
            self.flag[v] = False
            self.sum[v] = self.delta[v] * (tr - tl + 1)

    def f(self, a: int, b: int) -> int:
        return a + b


class Pair:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

    def clone(self) -> 'Pair':
        return Pair(self.x, self.y)

    def __str__(self) -> str:
        return f"{self.x} {self.y}"

    def __lt__(self, other: 'Pair') -> bool:
        if self.y > other.y:
            return False
        if self.y < other.y:
            return True
        if self.x > other.x:
            return False
        if self.x < other.x:
            return True
        return False


class E:
    def __init__(self):
        self.mod = 1000000007
        self.random = Random()

    def shuffle(self, a: List[Pair]) -> None:
        for i in range(len(a)):
            x = self.random.randint(0, i)
            t = a[x]
            a[x] = a[i]
            a[i] = t

    def sort(self, a: List[List[int]]) -> None:
        for i in range(len(a)):
            a[i].sort()

    def add(self, map: Dict[int, int], l: int) -> None:
        if l in map:
            map[l] += 1
        else:
            map[l] = 1

    def remove(self, map: Dict[int, int], s: int) -> None:
        if map[s] > 1:
            map[s] -= 1
        else:
            del map[s]

    def signum(self, x: float) -> int:
        if x > 1e-10:
            return 1
        if x < -1e-10:
            return -1
        return 0

    def abs(self, x: int) -> int:
        return -x if x < 0 else x

    def min(self, x: int, y: int) -> int:
        return x if x < y else y

    def max(self, x: int, y: int) -> int:
        return x if x > y else y

    def gcd(self, x: int, y: int) -> int:
        while y > 0:
            c = y
            y = x % y
            x = c
        return x

    def solve(self, n: int, m: int, q: int, v: List[int], edges: List[Tuple[int, int]], queries: List[Tuple[int, int]]) -> List[int]:
        dsu = DSU(n)
        for a, b in edges:
            dsu.unite(a, b)
        result = []
        for t, x in queries:
            if t == 1:
                result.append(dsu.get(x))
            else:
                dsu.unite(edges[x][0], edges[x][1])
        return result

    def from_input_string(self, input_string: str) -> Tuple:
        lines = input_string.strip().split("\n")
        n, m, q = map(int, lines[0].strip().split())
        v = list(map(int, lines[1].strip().split()))
        edges = [tuple(map(int, line.strip().split())) for line in lines[2:2+m]]
        queries = [tuple(map(int, line.strip().split())) for line in lines[2+m:]]
        return n, m, q, v, edges, queries

    def to_input_string(self, inputs: Tuple) -> str:
        n, m, q, v, edges, queries = inputs
        res = []
        res.append(f"{n} {m} {q}")
        res.append(" ".join(str(x) for x in v))
        for edge in edges:
            res.append(" ".join(str(x) for x in edge))
        for query in queries:
            res.append(" ".join(str(x) for x in query))
        return "\n".join(res)

    def from_output_string(self, output_string: str) -> Any:
        return list(map(int, output_string.strip().split()))

    def to_output_string(self, output: Any) -> str:
        return "\n".join(str(x) for x in output)


def main():
    runner = E()
    runner.run(sys.stdin.buffer, sys.stdout.buffer)


if __name__ == "__main__":
    main()
