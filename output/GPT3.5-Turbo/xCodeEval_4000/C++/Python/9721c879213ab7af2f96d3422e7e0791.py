import math

zero = (-1, -1)

def cinArr(arr):
    for i in range(len(arr)):
        arr[i] = int(input())

def cinMatr(matr):
    n = len(matr)
    m = len(matr[0])
    for i in range(n):
        for j in range(m):
            matr[i][j] = int(input())

xx = [1, -1, 0, 0]
yy = [0, 0, 1, -1]

prim = []
prims = []
def er():
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
    def __init__(self, parent):
        self.N = int(math.log2(len(parent)) + 1)
        self.n = len(parent)
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
            p = self.merge(self.lChildren.getValue(), self.rChildren.getValue(), len1, len2)
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
        p = self.merge(p1, p2, len1, len2)
        return p

    def update(self, l, r, value):
        if l == self.l and r == self.r:
            return
        mid = (self.l + self.r) // 2
        if l <= mid:
            self.lChildren.update(l, min(mid, r), value)
        if r > mid:
            self.rChildren.update(max(mid + 1, l), r, value)

def gcd(a, b):
    if a < b:
        a, b = b, a
    if b == 0:
        return a
    return gcd(b, a % b)

def gcd(a, b, x, y):
    if a == 0:
        x = 0
        y = 1
        return b
    x1, y1 = 0, 0
    d = gcd(b % a, a, x1, y1)
    x = y1 - (b // a) * x1
    y = x1
    return d

def nok(a, b):
    nnod = gcd(a, b)
    ans = a // nnod * b
    return ans

def divup(a, b):
    if a % b == 0:
        return a // b
    else:
        return a // b + 1

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
        it = next((x for x in pr if x[0] == p[0]), None)
        if it is None:
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
arr = [0] * n
cinArr(arr)
pr = set()
for _ in range(m):
    a, b = map(int, input().split())
    pr.add((b - 1, -a))
l = 0
r = int(1e6)
while l < r:
    mid = (l + r) // 2
    if chec(mid, pr, arr):
        r = mid
    else:
        l = mid + 1
print(l)
