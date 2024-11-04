from heapq import heappop, heappush
import sys
from collections import defaultdict, deque

INF = float('inf')
INF_LONG = float('inf')

class Dijkstra:
    def __init__(self, n):
        self.N = n
        self.E = defaultdict(list)

    def insert(self, u, v, w):
        self.E[u].append((v, w))

    def dijkstra(self, start, end):
        dist = [INF] * (self.N + 1)
        dist[start] = 0
        pq = []
        heappush(pq, (0, start))
        while pq:
            w, u = heappop(pq)
            w = -w
            if u == end:
                return dist
            if dist[u] < w:
                continue
            for v, w2 in self.E[u]:
                if dist[v] > w + w2:
                    dist[v] = w + w2
                    heappush(pq, (-dist[v], v))
        return dist

    def g(self):
        n, e = map(int, sys.stdin.readline().split())
        dk = Dijkstra(n)
        s = int(sys.stdin.readline())
        for _ in range(e):
            u, v, w = map(int, sys.stdin.readline().split())
            dk.insert(u, v, w)
        ans = dk.dijkstra(s, n)
        for i in range(1, n + 1):
            print("INF" if ans[i] >= INF else ans[i])

class Prim:
    def __init__(self, n):
        self.N = n
        self.E = defaultdict(list)

    def insert(self, u, v, w):
        self.E[u].append((v, w))

    def execute(self):
        cost = 0
        dist = [INF] * (self.N + 1)
        selected = [False] * (self.N + 1)
        dist[1] = 0
        pq = []
        heappush(pq, (0, 1))
        for _ in range(self.N):
            w, u = heappop(pq)
            w = -w
            if selected[u]:
                continue
            cost += w
            selected[u] = True
            for v, w2 in self.E[u]:
                if not selected[v] and dist[v] > w2:
                    dist[v] = w2
                    heappush(pq, (-w2, v))
        return dist, cost

    def g(self):
        n, e = map(int, sys.stdin.readline().split())
        pm = Prim(n)
        s = int(sys.stdin.readline())
        for _ in range(e):
            u, v, w = map(int, sys.stdin.readline().split())
            pm.insert(u, v, w)
        ans, cost = pm.execute()
        print(cost)

class Floyd:
    def __init__(self, n):
        self.N = n
        self.E = [[INF] * (n + 1) for _ in range(n + 1)]

    def setRC(self, r, c, w):
        self.E[r][c] = w

    def execute(self):
        for i in range(1, self.N + 1):
            self.E[i][i] = 0
        for k in range(1, self.N + 1):
            for i in range(1, self.N + 1):
                for j in range(1, self.N + 1):
                    self.E[i][j] = min(self.E[i][j], self.E[i][k] + self.E[k][j])

class id5:
    def __init__(self, n):
        self.N = n
        self.E = defaultdict(list)
        self.A = [0] * (n + 1)

    def insert(self, u, v, w):
        self.E[u].append((v, w))

    def dfsAll(self, start, end):
        visited = [False] * (self.N + 1)
        return self.dfs(start, end, visited)

    def dfs(self, start, end, visited):
        if start == end:
            return 1
        visited[start] = True
        for v, _ in self.E[start]:
            if not visited[v]:
                if self.dfs(v, end, visited):
                    return 1
        return 0

    def setA(self, a, b):
        self.A[a] = b

    def dfsAll2(self):
        visited = [0] * (self.N + 1)
        seq = 0
        ret = 0
        for i in range(1, self.N + 1):
            self.dfs2(i, visited, seq + 1)
        for i in range(1, self.N + 1):
            a = sum(w for _, w in self.E[i])
            ret = max(ret, a)
        return ret

    def dfs2(self, start, visited, seq):
        visited[start] = seq
        ret = self.A[start]
        for v, c in self.E[start]:
            if visited[v] < seq:
                if c == -1:
                    self.E[start][v][1] = self.dfs2(v, visited, seq)
                ret = max(ret, self.E[start][v][1])
        return ret

    def g(self):
        n, m = map(int, sys.stdin.readline().split())
        dg = id5(n)
        for _ in range(m):
            a, b = map(int, sys.stdin.readline().split())
            dg.insert(a, b, 0)
        m = int(sys.stdin.readline())
        for _ in range(m):
            a, b = map(int, sys.stdin.readline().split())
            if dg.dfsAll(a, b):
                c = -1
            elif dg.dfsAll(b, a):
                c = 1
            else:
                c = 0
            print(c)

class DFS_Map:
    def __init__(self, r, c):
        self.R = r
        self.C = c
        self.E = [[0] * (c + 2) for _ in range(r + 2)]

    def setRC(self, r, c, w):
        self.E[r][c] = w

    def getRC(self, r, c):
        return self.E[r][c]

    def dfs(self, rr, cc, visited):
        visited[rr][cc] = True
        for i in range(4):
            r = rr + dr[i]
            c = cc + dc[i]
            if self.E[r][c] and not visited[r][c]:
                self.dfs(r, c, visited)

    def dfsAll(self):
        visited = [[False] * (self.C + 2) for _ in range(self.R + 2)]
        for r in range(1, self.R + 1):
            for c in range(1, self.C + 1):
                if not visited[r][c]:
                    self.dfs(r, c, visited)

class id7:
    def __init__(self, n):
        self.N = n
        self.E = defaultdict(list)
        self.IN = [0] * (n + 1)

    def is_cycle(self):
        return any(in_degree > 0 for in_degree in self.IN[1:self.N + 1])

    def insert(self, u, v, w):
        self.E[u].append((v, w))
        self.IN[v] += 1

    def bfs(self, start, end, min_weight):
        visited = [False] * (self.N + 1)
        weight = [INF_LONG] * (self.N + 1)
        Q = deque()
        visited[start] = True
        weight[start] = 0
        Q.append(start)
        while Q:
            u = Q.popleft()
            w = weight[u]
            if u == end:
                break
            for v, c in self.E[u]:
                if c >= min_weight and not visited[v]:
                    Q.append(v)
                    weight[v] = w + c
                    visited[v] = True
        return weight

    def topologicalSort(self):
        order = []
        Q = deque()
        for i in range(1, self.N + 1):
            if self.IN[i] == 0:
                Q.append(i)
        while Q:
            u = Q.popleft()
            order.append(u)
            for v, _ in self.E[u]:
                if self.IN[v] > 0:
                    self.IN[v] -= 1
                    if self.IN[v] == 0:
                        Q.append(v)
        return order

    def topologicalSortPQ(self):
        order = []
        pq = []
        for i in range(1, self.N + 1):
            if self.IN[i] == 0:
                heappush(pq, -i)
        while pq:
            u = -heappop(pq)
            order.append(u)
            for v, _ in self.E[u]:
                if self.IN[v] > 0:
                    self.IN[v] -= 1
                    if self.IN[v] == 0:
                        heappush(pq, -v)
        return order

    def f(self):
        for u in range(1, self.N + 1):
            for v, _ in self.E[u]:
                if self.IN[v] == 1:
                    IN2 = self.IN[:]
                    self.IN[v] -= 1
                    self.topologicalSort()
                    if not self.is_cycle():
                        return 1
                    self.IN = IN2
        return 0

    def g(self):
        n, m = map(int, sys.stdin.readline().split())
        bg = id7(n)
        X = []
        for _ in range(m):
            a, b, c = map(int, sys.stdin.readline().split())
            if a > b:
                a, b = b, a
            X.append((a, b, -c))
        start, end = map(int, sys.stdin.readline().split())
        X.sort()
        bg.insert(a, b, -c)
        for i in range(1, m):
            a, b, c = X[i - 1]
            a2, b2, c2 = X[i]
            if a == a2 and b == b2:
                continue
            bg.insert(a2, b2, -c2)
        lo, hi = 1, INF
        while lo < hi:
            mid = (lo + hi + 1) // 2
            y = bg.bfs(start, end, mid)
            if y[end] < INF_LONG:
                lo = mid
            else:
                hi = mid - 1
        print(lo)

class id4:
    def __init__(self, r, c):
        self.R = r
        self.C = c
        self.E = [[0] * (c + 2) for _ in range(r + 2)]

    def setRC(self, r, c, w):
        self.E[r][c] = w

    def getRC(self, r, c):
        return self.E[r][c]

    def bfsAll(self):
        visited = [[0] * (self.C + 2) for _ in range(self.R + 2)]
        ret = 0
        for r in range(1, self.R + 1):
            for c in range(1, self.C + 1):
                if self.E[r][c] and not visited[r][c]:
                    ret += 1
                    self.bfs(r, c, visited)
        return ret

    def bfsAllWithQueue(self, Q):
        visited = [[0] * (self.C + 2) for _ in range(self.R + 2)]
        ret = 0
        for r, c in Q:
            if not visited[r][c]:
                ret += 1
                self.bfs(r, c, visited)
        return ret

    def bfs(self, rr, cc, visited):
        Q = deque()
        Q.append((rr, cc))
        visited[rr][cc] = 1
        while Q:
            r, c = Q.popleft()
            for i in range(4):
                r2 = r + dr[i]
                c2 = c + dc[i]
                if self.E[r2][c2] and not visited[r2][c2]:
                    Q.append((r2, c2))
                    visited[r2][c2] = visited[r][c] + 1

    def g(self):
        R, C = map(int, sys.stdin.readline().split())
        bm = id4(R, C)
        Q = [[], []]
        for r in range(1, R + 1):
            for c in range(1, C + 1):
                a = int(sys.stdin.readline())
                bm.setRC(r, c, a)
                if a:
                    Q[0].append((r, c))
        ans = 0
        idx = 0
        while True:
            a = bm.bfsAll(Q[idx])
            if a > 1:
                break
            elif a == 0:
                ans = 0
                break
            ans += 1
            X = []
            Q[1 - idx] = []
            for r, c in Q[idx]:
                a = sum(1 for j in range(4) if bm.getRC(r + dr[j], c + dc[j]) == 0)
                X.append(a)
            for i, (r, c) in enumerate(Q[idx]):
                a = bm.getRC(r, c) - X[i]
                if a <= 0:
                    a = 0
                else:
                    Q[1 - idx].append((r, c))
                bm.setRC(r, c, a)
            idx = 1 - idx
        print(ans)

class Number:
    def __init__(self):
        pass

    def getDigitNum(self, xx):
        x = 1
        ret = 0
        while x < xx:
            x *= 10
            ret += 1
        return ret

    def getDigitSum(self, xx):
        a = 0
        while xx:
            a += (xx % 10)
            xx //= 10
        return a

    def getMSB(self, xx):
        i = 0
        while (1 << i) <= xx:
            i += 1
        return i - 1

    def convertBinaryToBase(self, x, base):
        if x == 0:
            return 0
        return base * self.convertBinaryToBase(x // 2, base) + (x % 2)

    def findFactor(self, k):
        for d in range(2, int(k**0.5) + 1):
            if k % d == 0:
                return d
        return 0

class Palindrome:
    def __init__(self):
        pass

    def isPalindrome(self, xx):
        v = []
        while xx > 0:
            v.append(xx % 10)
            xx //= 10
        n = len(v)
        for i in range(n // 2):
            if v[i] != v[n - i - 1]:
                return 0
        return 1

class BigNumber:
    def __init__(self):
        pass

    def add(self, s1, s2):
        n1 = len(s1)
        n2 = len(s2)
        v = []
        i, j = n1 - 1, n2 - 1
        while i >= 0 and j >= 0:
            a = int(s1[i]) + int(s2[j])
            v.append(a)
            i -= 1
            j -= 1
        while i >= 0:
            a = int(s1[i])
            v.append(a)
            i -= 1
        while j >= 0:
            a = int(s2[j])
            v.append(a)
            j -= 1
        for i in range(len(v)):
            if i > 0 and v[i] >= 10:
                v[i] -= 10
                v[i - 1] += 1
        s3 = ''.join(str(x) for x in reversed(v)) + '\n'
        return s3

class PrimeNumber:
    def __init__(self, n):
        self.N = n
        self.NP = [0] * (n + 4)
        self.P = []
        for i in range(2, int(n**0.5) + 1):
            if self.NP[i]:
                continue
            for j in range(i * i, n + 1, i):
                self.NP[j] = 1
        for i in range(2, n + 1):
            if not self.NP[i]:
                self.P.append(i)

    def gcd(self, x, y):
        while x:
            z = y % x
            y = x
            x = z
        return y

    def powermod(self, p, q):
        g = self.gcd(p, q)
        p //= g
        q //= g
        return p * pow(q, MOD - 2, MOD) % MOD

    def factorization(self, x):
        ret = [1, x]
        for i in range(2, int(x**0.5) + 1):
            if x % i == 0:
                ret.append(i)
                ret.append(x // i)
        return ret

    def factorization2(self, x):
        ret = 0
        if x == 1:
            return 1
        ret = 2
        for i in range(2, int(x**0.5) + 1):
            if x % i == 0:
                ret += 2
        if int(x**0.5) ** 2 == x:
            ret += 1
        return ret

class BitOperation:
    def __init__(self):
        pass

    def getOneBitNum(self, xx):
        a = 0
        while xx:
            a += 1
            xx &= (xx - 1)
        return a

class Comb:
    def __init__(self, n):
        self.N = n
        self.C = [[0] * (n + 1) for _ in range(n + 1)]
        self.F = [0] * (n + 1)
        for i in range(n + 1):
            self.C[i][0] = self.C[i][i] = 1
        for i in range(1, n + 1):
            for j in range(1, i):
                self.C[i][j] = (self.C[i - 1][j - 1] + self.C[i - 1][j]) % MOD_COMB
        self.F[0] = self.F[1] = 1
        for i in range(2, n + 1):
            self.F[i] = (self.F[i - 1] * i) % MOD_COMB

    def getC(self, n, r):
        return self.C[n][r]

    def getF(self, n):
        return self.F[n]

    def get_comb(self, n, r):
        if n == r or r == 0:
            return 1
        if n <= 1000:
            return self.getC(n, r)
        ret = 1
        if r > n // 2:
            r = n - r
        for i in range(n, n - r, -1):
            ret *= i
        for i in range(2, r + 1):
            ret //= i
        return ret

class Sort:
    def __init__(self, n):
        self.N = n
        self.tmp = [0] * (n + 4)

    def merge_sort(self, x, lo, hi):
        if lo >= hi:
            return
        mid = (lo + hi) // 2
        self.merge_sort(x, lo, mid)
        self.merge_sort(x, mid + 1, hi)
        i, j, k = lo, mid + 1, lo
        while i <= mid and j <= hi:
            if x[i] < x[j]:
                self.tmp[k] = x[i]
                i += 1
            else:
                self.tmp[k] = x[j]
                j += 1
            k += 1
        while i <= mid:
            self.tmp[k] = x[i]
            i += 1
            k += 1
        while j <= hi:
            self.tmp[k] = x[j]
            j += 1
            k += 1
        for i in range(lo, hi + 1):
            x[i] = self.tmp[i]

class PSum:
    def __init__(self):
        pass

    def makeSum(self, a):
        ret = [0] * len(a)
        ret[0] = a[0]
        for i in range(1, len(a)):
            ret[i] = ret[i - 1] + a[i]
        return ret

    def makeSum2D(self, a):
        n = len(a)
        m = len(a[0])
        ret = [[0] * m for _ in range(n)]
        for i in range(n):
            ret[i][0] = a[i][0]
        for i in range(n):
            for j in range(1, m):
                ret[i][j] = ret[i][j - 1] + a[i][j]
        return ret

    def getSum(self, psum, a, b):
        if a == 0:
            return psum[b]
        return psum[b] - psum[a - 1]

    def getSum2D(self, psum, r1, c1, r2, c2):
        ret = psum[r2][c2]
        if r1 > 0:
            ret -= psum[r1 - 1][c2]
        if c1 > 0:
            ret -= psum[r2][c1 - 1]
        if r1 > 0 and c1 > 0:
            ret += psum[r1 - 1][c1 - 1]
        return ret

class id3:
    def __init__(self, n):
        self.N = n
        self.P = list(range(n + 1))
        self.R = [0] * (n + 1)
        self.A = [1] * (n + 1)

    def getA(self, x):
        return self.A[x]

    def find_set(self, x):
        if self.P[x] == x:
            return x
        pa = self.find_set(self.P[x])
        self.P[x] = pa
        return pa

    def union_set(self, x, y):
        px = self.find_set(x)
        py = self.find_set(y)
        if px == py:
            return px
        if self.R[px] > self.R[py]:
            self.P[py] = px
            self.A[px] += self.A[py]
            return px
        else:
            self.P[px] = py
            self.A[py] += self.A[px]
            if self.R[px] == self.R[py]:
                self.R[py] += 1
            return py

class LIS:
    def __init__(self, n):
        self.N = n

    def execute(self, A):
        v = [0] * self.N
        vi = -1
        v.append(A[0])
        for i in range(1, len(A)):
            if A[i] > v[vi]:
                v.append(A[i])
                vi += 1
                continue
            lo, hi = 0, vi
            while lo < hi:
                mid = (lo + hi) // 2
                if v[mid] >= A[i]:
                    hi = mid
                else:
                    lo = mid + 1
            v[hi] = A[i]
