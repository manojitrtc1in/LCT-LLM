import sys
import math
from collections import defaultdict
from bisect import bisect_left

PI = 3.141592653589793238463

zero = (-1, -1)

def cinArr(arr):
    for i in range(len(arr)):
        arr[i] = int(sys.stdin.readline().strip())

def cinMatr(matr):
    n = len(matr)
    m = len(matr[0])
    for i in range(n):
        matr[i] = list(map(int, sys.stdin.readline().strip().split()))

class LCA:
    def __init__(self, parent):
        self.n = len(parent)
        self.N = math.floor(math.log2(self.n)) + 1
        self.g = [[] for _ in range(self.n)]
        self.lvl = [0] * self.n
        core = -1
        for i in range(self.n):
            if parent[i] != -1:
                self.g[parent[i]].append(i)
            else:
                core = i
        self.dfs(core, 0)
        self.up = [[-1] * self.n for _ in range(self.N)]
        self.up[0] = parent
        for i in range(1, self.N):
            for j in range(self.n):
                parent = self.up[i - 1][j]
                if parent == -1:
                    self.up[i][j] = -1
                else:
                    self.up[i][j] = self.up[i - 1][parent]

    def dfs(self, v, h):
        self.lvl[v] = h
        for u in self.g[v]:
            self.dfs(u, h + 1)

    def getParent(self, v, needUp):
        for i in range(self.N - 1, -1, -1):
            if self.up[i][v] != -1 and self.lvl[v] - self.lvl[self.up[i][v]] <= needUp:
                needUp -= self.lvl[v] - self.lvl[self.up[i][v]]
                v = self.up[i][v]
        return -1 if needUp != 0 else v

    def getLCA(self, a, b):
        if self.lvl[a] > self.lvl[b]:
            del_ = abs(self.lvl[a] - self.lvl[b])
            a = self.getParent(a, del_)
        if self.lvl[a] < self.lvl[b]:
            del_ = abs(self.lvl[a] - self.lvl[b])
            b = self.getParent(b, del_)
        if a == b:
            return a
        for i in range(self.N - 1, -1, -1):
            if self.up[i][a] != self.up[i][b]:
                a = self.up[i][a]
                b = self.up[i][b]
        return self.up[0][a]

    def getLvl(self, v):
        return self.lvl[v]

class Node:
    def __init__(self, l, r, arr, lca):
        self.lca = lca
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
            p = self.merge(self.lChildren.getValue(), self.rChildren.getValue(), len1, len2)
            self.a = p[0]
            self.del_ = p[1]

    def merge(self, x, y, len1, len2):
        if len1 > 2 and len2 > 2:
            a, b = x
            c, d = y
            ac = self.lca.getLCA(a, c)
            acb = self.lca.getLCA(ac, b)
            acd = self.lca.getLCA(ac, d)
            return (acb, d) if self.lca.getLvl(acb) > self.lca.getLvl(acd) else (acd, b)
        if len1 == 0:
            return y
        if len2 == 0:
            return x
        a, b = x
        c, d = y
        if len1 == 1 and len2 == 1:
            return (b, d) if self.lca.getLvl(b) > self.lca.getLvl(d) else (d, b)
        if len1 == 1:
            if len2 == 2:
                bc = self.lca.getLCA(b, c)
                bd = self.lca.getLCA(b, d)
                cd = self.lca.getLCA(c, d)
                lbc = self.lca.getLvl(bc)
                lbd = self.lca.getLvl(bd)
                lcd = self.lca.getLvl(cd)
                if lbc > lbd and lbc > lcd:
                    return (bc, d)
                if lbd > lcd:
                    return (bd, c)
                return (cd, b)
            bc = self.lca.getLCA(b, c)
            cd = self.lca.getLCA(c, d)
            lbc = self.lca.getLvl(bc)
            lcd = self.lca.getLvl(cd)
            return (bc, d) if lbc > lcd else (cd, b)
        if len2 == 1:
            if len1 == 2:
                ab = self.lca.getLCA(a, b)
                ad = self.lca.getLCA(a, d)
                bd = self.lca.getLCA(b, d)
                lab = self.lca.getLvl(ab)
                lad = self.lca.getLvl(ad)
                lbd = self.lca.getLvl(bd)
                if lab > lad and lab > lbd:
                    return (ab, d)
                if lad > lbd:
                    return (ad, b)
                return (bd, a)
            ab = self.lca.getLCA(b, a)
            ad = self.lca.getLCA(a, d)
            lab = self.lca.getLvl(ab)
            lad = self.lca.getLvl(ad)
            return (ab, d) if lab > lad else (ad, b)
        if len1 == 2 and len2 > 2:
            abc = self.lca.getLCA(a, self.lca.getLCA(b, c))
            acd = self.lca.getLCA(a, self.lca.getLCA(c, d))
            bcd = self.lca.getLCA(b, self.lca.getLCA(c, d))
            labc = self.lca.getLvl(abc)
            lacd = self.lca.getLvl(acd)
            lbcd = self.lca.getLvl(bcd)
            ans = max(labc, lacd, lbcd)
            if labc == ans:
                return (abc, d)
            if lacd == ans:
                return (acd, b)
            if lbcd == ans:
                return (bcd, a)
        if len2 == 2 and len1 > 2:
            abc = self.lca.getLCA(a, self.lca.getLCA(b, c))
            abd = self.lca.getLCA(a, self.lca.getLCA(b, d))
            acd = self.lca.getLCA(a, self.lca.getLCA(c, d))
            labc = self.lca.getLvl(abc)
            labd = self.lca.getLvl(abd)
            lacd = self.lca.getLvl(acd)
            ans = max(labc, labd, lacd)
            if labc == ans:
                return (abc, d)
            if labd == ans:
                return (abd, c)
            if lacd == ans:
                return (acd, b)

        abc = self.lca.getLCA(a, self.lca.getLCA(b, c))
        abd = self.lca.getLCA(a, self.lca.getLCA(b, d))
        acd = self.lca.getLCA(a, self.lca.getLCA(c, d))
        bcd = self.lca.getLCA(b, self.lca.getLCA(c, d))

        labc = self.lca.getLvl(abc)
        labd = self.lca.getLvl(abd)
        lacd = self.lca.getLvl(acd)
        lbcd = self.lca.getLvl(bcd)
        ans = max(labc, labd, lacd, lbcd)
        if labc == ans:
            return (abc, d)
        if labd == ans:
            return (abd, c)
        if lacd == ans:
            return (acd, b)
        if lbcd == ans:
            return (bcd, a)

        return zero

    def getValue(self):
        return (self.a, self.del_)

    def getValueRange(self, left, right):
        if self.l == left and self.r == right:
            return self.getValue()
        mid = (self.l + self.r) // 2
        p1 = p2 = zero
        len1 = len2 = 0
        if left <= mid:
            p1 = self.lChildren.getValueRange(left, min(right, mid))
            len1 = min(right, mid) - left + 1
        if right > mid:
            p2 = self.rChildren.getValueRange(max(mid + 1, left), right)
            len2 = right - max(mid + 1, left) + 1
        return self.merge(p1, p2, len1, len2)

class SNM:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n

    def find_set(self, v):
        if v == self.parent[v]:
            return v
        ans = self.find_set(self.parent[v])
        self.parent[v] = ans
        return ans

    def union_sets(self, a, b):
        a = self.find_set(a)
        b = self.find_set(b)
        if a != b:
            self.parent[b] = a
            self.size[a] += self.size[b]

    def getSize(self, v):
        v = self.find_set(v)
        return self.size[v]

def gcd(a, b):
    if a < b:
        a, b = b, a
    if b == 0:
        return a
    return gcd(b, a % b)

def gcd_extended(a, b):
    if a == 0:
        return (b, 0, 1)
    x1, y1 = gcd_extended(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return (x, y)

def nok(a, b):
    nnod = gcd(a, b)
    return a // nnod * b

def divup(a, b):
    return a // b + (1 if a % b != 0 else 0)

def chec(day, pr, arr):
    bue = []
    sum_ = 0
    for i in range(len(arr)):
        p = (i, -day)
        idx = bisect_left(pr, p)
        if idx == len(pr) or pr[idx][0] != i:
            sum_ += arr[i]
        else:
            bue.append((-pr[idx][1], i))
    bue.sort()

    moneyDelete = 0
    for p in bue:
        money = p[0] - moneyDelete
        need = arr[p[1]]
        if need <= money:
            moneyDelete += need
        else:
            moneyDelete += money
            sum_ += need - money
    return (moneyDelete + sum_ * 2 <= day)

def main():
    input = sys.stdin.read
    data = input().splitlines()
    n, m = map(int, data[0].split())
    arr = list(map(int, data[1:n + 1]))
    pr = []
    for i in range(m):
        a, b = map(int, data[n + 1 + i].split())
        pr.append((b - 1, -a))
    pr.sort()

    l, r = 0, 10**6
    while l < r:
        mid = (l + r) // 2
        if chec(mid, pr, arr):
            r = mid
        else:
            l = mid + 1

    print(l)

if __name__ == "__main__":
    main()
