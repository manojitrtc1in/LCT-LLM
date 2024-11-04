import math
from typing import List, Tuple, Dict, Set

PI = 3.141592653589793238463

pi = Tuple[int, int]
ppi = Tuple[pi, int]
vi = List[int]
vvi = List[vi]
vpi = List[pi]
vvpi = List[vpi]
vppi = List[ppi]
vb = List[bool]
vvb = List[vb]
mii = Dict[int, int]
spi = Set[pi]
si = Set[int]
msi = Set[int]
mspi = Set[pi]
vsi = List[si]
V = List
VV = List[V]
Mi = Dict[int, T]
MMi = Dict[int, Mi[T]]

zero = (-1, -1)


def cinArr(arr: vi) -> None:
    for i in range(len(arr)):
        arr[i] = int(input())


def id0(matr: vvi) -> None:
    n = len(matr)
    m = len(matr[0])
    for i in range(n):
        for j in range(m):
            matr[i][j] = int(input())


xx = [1, -1, 0, 0]
yy = [0, 0, 1, -1]

prim = []
prims = []


def er() -> None:
    n = int(1e6)
    prim = [0] * (n + 1)
    for i in range(n + 1):
        prim[i] = i
    for i in range(2, n + 1):
        if prim[i] == i:
            prims.append(i)
            for j in range(i * i, n + 1, i):
                if prim[j] == j:
                    prim[j] = i


class LCA:
    def __init__(self, parent: vi) -> None:
        n = len(parent)
        self.N = int(math.log2(n) + 1)
        self.g = [[] for _ in range(n)]
        self.lvl = [0] * n
        core = -1
        for i in range(n):
            if parent[i] != -1:
                self.g[parent[i]].append(i)
            else:
                core = i
        self.dfs(core, 0)
        self.up = [[0] * n for _ in range(self.N)]
        self.up[0] = parent
        for i in range(1, self.N):
            for j in range(n):
                parent = self.up[i - 1][j]
                if parent == -1:
                    self.up[i][j] = -1
                else:
                    self.up[i][j] = self.up[i - 1][parent]

    def dfs(self, v: int, h: int) -> None:
        self.lvl[v] = h
        for u in self.g[v]:
            self.dfs(u, h + 1)

    def get_parent(self, v: int, need_up: int) -> int:
        for i in range(self.N - 1, -1, -1):
            if self.up[i][v] != -1 and self.lvl[v] - self.lvl[self.up[i][v]] <= need_up:
                need_up -= self.lvl[v] - self.lvl[self.up[i][v]]
                v = self.up[i][v]
        if need_up != 0:
            return -1
        else:
            return v

    def get_lca(self, a: int, b: int) -> int:
        if self.lvl[a] > self.lvl[b]:
            del_ = abs(self.lvl[a] - self.lvl[b])
            a = self.get_parent(a, del_)
        if self.lvl[a] < self.lvl[b]:
            del_ = abs(self.lvl[a] - self.lvl[b])
            b = self.get_parent(b, del_)
        if a == b:
            return a
        for i in range(self.N - 1, -1, -1):
            if self.up[i][a] != self.up[i][b]:
                a = self.up[i][a]
                b = self.up[i][b]
        return self.up[0][a]

    def get_lvl(self, v: int) -> int:
        return self.lvl[v]


class Node:
    def __init__(self, l: int, r: int, arr: vi, lca: LCA) -> None:
        self.l = l
        self.r = r
        if l == r:
            self.a = -1
            self.del_ = arr[l]
        else:
            mid = (l + r) // 2
            self.lChildren = Node(l, mid, arr, lca)
            self.rChildren = Node(mid + 1, r, arr, lca)
            len1 = mid - l + 1
            len2 = r - mid
            p = self.merge(self.lChildren.get_value(), self.rChildren.get_value(), len1, len2)
            self.a = p[0]
            self.del_ = p[1]

    def get_value(self) -> pi:
        return self.a, self.del_

    def get_value_range(self, left: int, right: int) -> pi:
        if self.l == left and self.r == right:
            return self.get_value()
        mid = (self.l + self.r) // 2
        p1, p2 = zero, zero
        len1, len2 = 0, 0
        if left <= mid:
            p1 = self.lChildren.get_value_range(left, min(right, mid))
            len1 = min(right, mid) - left + 1
        if right > mid:
            p2 = self.rChildren.get_value_range(max(mid + 1, left), right)
            len2 = right - max(mid + 1, left) + 1
        p = self.merge(p1, p2, len1, len2)
        return p

    def update(self, l: int, r: int, value: int) -> None:
        if l == self.l and r == self.r:
            return
        mid = (self.l + self.r) // 2
        if l <= mid:
            self.lChildren.update(l, min(mid, r), value)
        if r > mid:
            self.rChildren.update(max(mid + 1, l), r, value)

    @staticmethod
    def merge(x: pi, y: pi, len1: int, len2: int) -> pi:
        if len1 > 2 and len2 > 2:
            a, b = x
            c, d = y
            ac = lca.get_lca(a, c)
            acb = lca.get_lca(ac, b)
            acd = lca.get_lca(ac, d)
            if lca.get_lvl(acb) > lca.get_lvl(acd):
                return acb, d
            else:
                return acd, b
        if len1 == 0:
            return y
        if len2 == 0:
            return x
        a, b = x
        c, d = y
        if len1 == 1 and len2 == 1:
            if lca.get_lvl(b) > lca.get_lvl(d):
                return b, d
            else:
                return d, b
        if len1 == 1:
            if len2 == 2:
                bc = lca.get_lca(b, c)
                bd = lca.get_lca(b, d)
                cd = lca.get_lca(c, d)
                lbc = lca.get_lvl(bc)
                lbd = lca.get_lvl(bd)
                lcd = lca.get_lvl(cd)
                if lbc > lbd and lbc > lcd:
                    return bc, d
                if lbd > lcd:
                    return bd, c
                return cd, b
            bc = lca.get_lca(b, c)
            cd = lca.get_lca(c, d)
            lbc = lca.get_lvl(bc)
            lcd = lca.get_lvl(cd)
            if lbc > lcd:
                return bc, d
            else:
                return cd, b
        if len2 == 1:
            ab = lca.get_lca(a, b)
            ad = lca.get_lca(a, d)
            bd = lca.get_lca(b, d)
            lab = lca.get_lvl(ab)
            lad = lca.get_lvl(ad)
            lbd = lca.get_lvl(bd)
            if lab > lad and lab > lbd:
                return ab, d
            if lad > lbd:
                return ad, b
            return bd, a
        if len1 == 2 and len2 > 2:
            abc = lca.get_lca(a, lca.get_lca(b, c))
            acd = lca.get_lca(a, lca.get_lca(c, d))
            bcd = lca.get_lca(b, lca.get_lca(c, d))
            labc = lca.get_lvl(abc)
            lacd = lca.get_lvl(acd)
            lbcd = lca.get_lvl(bcd)
            ans = max(labc, lacd, lbcd)
            if labc == ans:
                return abc, d
            if lacd == ans:
                return acd, b
            if lbcd == ans:
                return bcd, a
        if len2 == 2 and len1 > 2:
            abc = lca.get_lca(a, lca.get_lca(b, c))
            abd = lca.get_lca(a, lca.get_lca(b, d))
            acd = lca.get_lca(a, lca.get_lca(c, d))
            labc = lca.get_lvl(abc)
            labd = lca.get_lvl(abd)
            lacd = lca.get_lvl(acd)
            ans = max(labc, labd, lacd)
            if labc == ans:
                return abc, d
            if labd == ans:
                return abd, c
            if lacd == ans:
                return acd, b
        abc = lca.get_lca(a, lca.get_lca(b, c))
        abd = lca.get_lca(a, lca.get_lca(b, d))
        acd = lca.get_lca(a, lca.get_lca(c, d))
        bcd = lca.get_lca(b, lca.get_lca(c, d))
        labc = lca.get_lvl(abc)
        labd = lca.get_lvl(abd)
        lacd = lca.get_lvl(acd)
        lbcd = lca.get_lvl(bcd)
        ans = max(labc, labd, lacd, lbcd)
        if labc == ans:
            return abc, d
        if labd == ans:
            return abd, c
        if lacd == ans:
            return acd, b
        if lbcd == ans:
            return bcd, a
        return zero


def gcd(a: int, b: int) -> int:
    if a < b:
        a, b = b, a
    if b == 0:
        return a
    return gcd(b, a % b)


def gcd_extended(a: int, b: int) -> Tuple[int, int]:
    if a == 0:
        return 0, 1
    x1, y1 = gcd_extended(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return x, y


def nok(a: int, b: int) -> int:
    nnod = gcd(a, b)
    ans = a // nnod * b
    return ans


def divup(a: int, b: int) -> int:
    if a % b == 0:
        return a // b
    else:
        return a // b + 1


class SNM:
    def __init__(self, n: int) -> None:
        self.parent = [0] * n
        self.size = [1] * n
        for i in range(n):
            self.parent[i] = i

    def make_set(self, v: int) -> None:
        self.parent[v] = v

    def find_set(self, v: int) -> int:
        if v == self.parent[v]:
            return v
        ans = self.find_set(self.parent[v])
        self.parent[v] = ans
        return ans

    def union_sets(self, a: int, b: int) -> None:
        a = self.find_set(a)
        b = self.find_set(b)
        if a != b:
            self.parent[b] = a
            self.size[a] += self.size[b]

    def get_size(self, v: int) -> int:
        v = self.find_set(v)
        return self.size[v]


def chec(day: int, pr: spi, arr: vi) -> bool:
    bue = []
    sum_ = 0
    for i in range(len(arr)):
        p = (i, -day)
        it = pr.lower_bound(p)
        if it == pr.end() or it[0] != i:
            sum_ += arr[i]
        else:
            bue.append((-it[1], i))
    bue.sort()

    money_delete = 0
    for p in bue:
        money = p[0] - money_delete
        need = arr[p[1]]
        if need <= money:
            money_delete += need
        else:
            money_delete += money
            sum_ += need - money
    return money_delete + sum_ * 2 <= day


n, m = map(int, input().split())
arr = [0] * n
cinArr(arr)
pr = set()
for _ in range(m):
    a, b = map(int, input().split())
    pr.add((b - 1, -a))
l = 0
r = int(1e18)
while l < r:
    mid = (l + r) // 2
    if chec(mid, pr, arr):
        r = mid
    else:
        l = mid + 1
print(l)
