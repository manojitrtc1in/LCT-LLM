import random
import math
import heapq
from collections import deque
from itertools import permutations, combinations
from functools import reduce
from operator import add, sub, mul, truediv
from typing import List, Tuple, Dict, Any, Union


class ScopeTimer:
    def __init__(self, msg: str = ""):
        self.tic = time.time()
        self.msg = msg

    def __enter__(self):
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        toc = time.time()
        dt = int((toc - self.tic) * 1000)

        mil = dt % 1000
        sec = (dt // 1000) % 60
        min = (dt // 60000) % 60
        hrs = dt // 3600000

        print(f"\n{self.msg}\n\telapsed time: ", end="")
        if hrs:
            print(f"{hrs} hrs, ", end="")
        if min:
            print(f"{min} min, ", end="")
        if sec:
            print(f"{sec} sec, ", end="")
        print(f"{mil} mil-sec")


class RandInt:
    def __init__(self, a: int = 0, b: int = 100):
        self.m = a
        self.f = (b - a) / random.randint(0, 100)

    def __call__(self) -> int:
        return self.m + math.ceil(self.f * random.randint(0, 100))


class RandDouble:
    def __init__(self, a: float = 0.0, b: float = 1.0):
        self.m = a
        self.f = (b - a) / random.randint(0, 100)

    def __call__(self) -> float:
        return self.m + self.f * random.randint(0, 100)


class Noisy:
    def __init__(self, msg: str):
        self.msg = msg
        print(f"Noisy ({self.msg})\t@ {id(self)}")

    def __del__(self):
        print(f"~Noisy ({self.msg})\t@ {id(self)}")

    def beep(self):
        print(f"beep ({self.msg})\t@ {id(self)}")

    def beep(self) -> None:
        print(f"const beep ({self.msg})\t@ {id(self)}")


class UnionFind:
    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, s: int) -> int:
        p = self.parent[s]
        if self.parent[p] == p:
            return p
        self.parent[s] = self.find(p)
        return self.parent[s]

    def lazy_union(self, i: int, j: int) -> None:
        i = self.find(i)
        j = self.find(j)
        if i != j:
            if self.rank[i] < self.rank[j]:
                self.parent[i] = j
            else:
                self.parent[j] = i
                self.rank[i] += self.rank[i] == self.rank[j]


class Heap:
    def __init__(self, comp=None):
        self.val = []
        self.comp = comp if comp else lambda x, y: x < y

    def __len__(self) -> int:
        return len(self.val)

    def __bool__(self) -> bool:
        return bool(self.val)

    def __getitem__(self, item: int) -> Any:
        return self.val[item]

    def __setitem__(self, key: int, value: Any) -> None:
        self.val[key] = value

    def __delitem__(self, key: int) -> None:
        del self.val[key]

    def __iter__(self):
        return iter(self.val)

    def __contains__(self, item: Any) -> bool:
        return item in self.val

    def __str__(self) -> str:
        return str(self.val)

    def __repr__(self) -> str:
        return repr(self.val)

    def push(self, a: Any) -> None:
        heapq.heappush(self.val, a)

    def pop(self) -> Any:
        return heapq.heappop(self.val)

    def front(self) -> Any:
        return self.val[0]

    def empty(self) -> bool:
        return not bool(self.val)

    def size(self) -> int:
        return len(self.val)

    def swap(self, other: "Heap") -> None:
        self.val, other.val = other.val, self.val


class HopcroftKarp:
    def __init__(self, adj: List[List[int]], tag: List[bool]):
        self.adj = adj
        self.tag = tag
        self.npair = 0
        self.NIL = len(adj)
        self.INF = len(adj) + 1
        self.g1 = []
        self.dist = []
        self.pair = [self.NIL] * len(adj)

        for j in range(len(tag)):
            if tag[j]:
                self.g1.append(j)

        while self.mf_breadth_first_search():
            for v in self.g1:
                if self.pair[v] == self.NIL and self.mf_depth_first_search(v):
                    self.npair += 1

    def mf_breadth_first_search(self) -> bool:
        bfs_queue = deque()
        for v in self.g1:
            if self.pair[v] == self.NIL:
                self.dist[v] = 0
                bfs_queue.append(v)
            else:
                self.dist[v] = self.INF

        self.dist[self.NIL] = self.INF

        while bfs_queue:
            u = bfs_queue.popleft()
            if self.dist[u] < self.dist[self.NIL]:
                for w in self.adj[u]:
                    if self.dist[self.pair[w]] == self.INF:
                        self.dist[self.pair[w]] = self.dist[u] + 1
                        bfs_queue.append(self.pair[w])
        return self.dist[self.NIL] != self.INF

    def mf_depth_first_search(self, v: int) -> bool:
        if v == self.NIL:
            return True
        else:
            for w in self.adj[v]:
                if self.dist[self.pair[w]] == self.dist[v] + 1 and self.mf_depth_first_search(self.pair[w]):
                    self.pair[w] = v
                    self.pair[v] = w
                    return True
            self.dist[v] = self.INF
            return False


class AllPairsTreeShortestPath:
    INF = math.inf

    def __init__(self, adj: List[List[int]]):
        self.n = len(adj)
        self.depth = [AllPairsTreeShortestPath.INF] * self.n
        self.parent = [0] * self.n
        self.dist = [[AllPairsTreeShortestPath.INF] * j for j in range(self.n)]

        bfs_queue = deque()
        bfs_queue.append(0)
        self.depth[0] = 0
        self.parent[0] = 0

        while bfs_queue:
            u = bfs_queue.popleft()
            for v in adj[u]:
                if self.depth[u] + 1 < self.depth[v]:
                    self.depth[v] = self.depth[u] + 1
                    self.parent[v] = u
                    bfs_queue.append(v)

        for j in range(1, self.n):
            self.dist[j] = [AllPairsTreeShortestPath.INF] * j

    def __call__(self, u: int, v: int) -> int:
        if u == v:
            return 0
        elif u < v:
            return self.__call__(v, u)
        elif self.dist[u][v] == AllPairsTreeShortestPath.INF:
            if self.depth[u] < self.depth[v]:
                self.dist[u][v] = 1 + self.__call__(u, self.parent[v])
            elif self.depth[v] < self.depth[u]:
                self.dist[u][v] = 1 + self.__call__(self.parent[u], v)
            else:
                self.dist[u][v] = 2 + self.__call__(self.parent[u], self.parent[v])
        return self.dist[u][v]


def refill(k: int, left: List[Tuple[int, int, int]], right: List[Tuple[int, int, int]]) -> int:
    idx = list(range(len(left)))
    random.shuffle(idx)
    val = 0

    for i in idx:
        if left[i][0] < right[i][1]:
            w = min(k, left[i][2])
            k -= w
            val += w * (right[i][1] - left[i][0])

    return val


def a176() -> int:
    n, m, k = map(int, input().split())
    a = [[0] * m for _ in range(n)]

    for i in range(n):
        a[i] = list(map(int, input().split()))

    val = 0
    for i in range(n):
        for j in range(n):
            if i != j:
                val = max(val, refill(k, a[i], a[j]))

    return val


if __name__ == "__main__":
    print(a176())
