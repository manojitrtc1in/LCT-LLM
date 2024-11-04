import math

zero = (-1, -1)

def merge(x, y, len1, len2, lca):
    if len1 > 2 and len2 > 2:
        a, b = x
        c, d = y
        ac = lca.getLCA(a, c)
        acb = lca.getLCA(ac, b)
        acd = lca.getLCA(ac, d)
        if lca.getLvl(acb) > lca.getLvl(acd):
            return (acb, d)
        else:
            return (acd, b)
    if len1 == 0:
        return y
    if len2 == 0:
        return x
    a, b = x
    c, d = y
    if len1 == 1 and len2 == 1:
        if lca.getLvl(b) > lca.getLvl(d):
            return (b, d)
        else:
            return (d, b)
    if len1 == 1:
        if len2 == 2:
            bc = lca.getLCA(b, c)
            bd = lca.getLCA(b, d)
            cd = lca.getLCA(c, d)
            lbc = lca.getLvl(bc)
            lbd = lca.getLvl(bd)
            lcd = lca.getLvl(cd)
            if lbc > lbd and lbc > lcd:
                return (bc, d)
            if lbd > lcd:
                return (bd, c)
            return (cd, b)
        bc = lca.getLCA(b, c)
        cd = lca.getLCA(c, d)
        lbc = lca.getLvl(bc)
        lcd = lca.getLvl(cd)
        if lbc > lcd:
            return (bc, d)
        else:
            return (cd, b)
    if len2 == 1:
        ab = lca.getLCA(a, b)
        ad = lca.getLCA(a, d)
        bd = lca.getLCA(b, d)
        lab = lca.getLvl(ab)
        lad = lca.getLvl(ad)
        lbd = lca.getLvl(bd)
        if lab > lad and lab > lbd:
            return (ab, d)
        if lad > lbd:
            return (ad, b)
        return (bd, a)
    if len1 == 2 and len2 > 2:
        abc = lca.getLCA(a, lca.getLCA(b, c))
        acd = lca.getLCA(a, lca.getLCA(c, d))
        bcd = lca.getLCA(b, lca.getLCA(c, d))
        labc = lca.getLvl(abc)
        lacd = lca.getLvl(acd)
        lbcd = lca.getLvl(bcd)
        ans = max(labc, lacd, lbcd)
        if labc == ans:
            return (abc, d)
        if lacd == ans:
            return (acd, b)
        if lbcd == ans:
            return (bcd, a)
    if len2 == 2 and len1 > 2:
        abc = lca.getLCA(a, lca.getLCA(b, c))
        abd = lca.getLCA(a, lca.getLCA(b, d))
        acd = lca.getLCA(a, lca.getLCA(c, d))
        labc = lca.getLvl(abc)
        labd = lca.getLvl(abd)
        lacd = lca.getLvl(acd)
        ans = max(labc, labd, lacd)
        if labc == ans:
            return (abc, d)
        if labd == ans:
            return (abd, c)
        if lacd == ans:
            return (acd, b)
    abc = lca.getLCA(a, lca.getLCA(b, c))
    abd = lca.getLCA(a, lca.getLCA(b, d))
    acd = lca.getLCA(a, lca.getLCA(c, d))
    bcd = lca.getLCA(b, lca.getLCA(c, d))
    labc = lca.getLvl(abc)
    labd = lca.getLvl(abd)
    lacd = lca.getLvl(acd)
    lbcd = lca.getLvl(bcd)
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

class LCA:
    def __init__(self, parent):
        self.n = len(parent)
        self.N = int(math.log2(self.n)) + 1
        self.g = [[] for _ in range(self.n)]
        self.lvl = [0] * self.n
        core = -1
        for i in range(self.n):
            if parent[i] != -1:
                self.g[parent[i]].append(i)
            else:
                core = i
        self.dfs(core, 0)
        self.up = [[0] * self.n for _ in range(self.N)]
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
        if needUp != 0:
            return -1
        else:
            return v

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
            p = merge(self.lChildren.getValue(), self.rChildren.getValue(), len1, len2, lca)
            self.a = p[0]
            self.del_ = p[1]

    def getValue(self):
        return (self.a, self.del_)

    def getValue(self, left, right):
        if self.l == left and self.r == right:
            return self.getValue()
        mid = (self.l + self.r) // 2
        p1, p2 = zero, zero
        len1, len2 = 0, 0
        if left <= mid:
            p1 = self.lChildren.getValue(left, min(right, mid))
            len1 = min(right, mid) - left + 1
        if right > mid:
            p2 = self.rChildren.getValue(max(mid + 1, left), right)
            len2 = right - max(mid + 1, left) + 1
        p = merge(p1, p2, len1, len2, lca)
        return p

class SNM:
    def __init__(self, n):
        self.parent = [0] * n
        self.size = [1] * n
        for i in range(n):
            self.parent[i] = i

    def make_set(self, v):
        self.parent[v] = v

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

def chec(day, pr, arr):
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

n, m = map(int, input().split())
arr = list(map(int, input().split()))
pr = set()
for i in range(m):
    a, b = map(int, input().split())
    pr.add((b - 1, -a))
l = 0
r = 1e6
while l < r:
    mid = (l + r) // 2
    if chec(mid, pr, arr):
        r = mid
    else:
        l = mid + 1
print(l)
