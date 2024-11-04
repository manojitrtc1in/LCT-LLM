import sys
from collections import defaultdict

class FastScanner:
    def __init__(self, input_file):
        self.input_file = input_file
        self.lines = []
        self.current_line = 0
        self.current_token = 0

    def nextLine(self):
        if self.current_line < len(self.lines):
            line = self.lines[self.current_line]
            self.current_line += 1
            self.current_token = 0
            return line
        else:
            return None

    def next(self):
        line = self.lines[self.current_line]
        tokens = line.split()
        if self.current_token < len(tokens):
            token = tokens[self.current_token]
            self.current_token += 1
            return token
        else:
            self.current_line += 1
            self.current_token = 0
            return self.next()

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

class E:
    def __init__(self):
        self.systemIO = True

    def solve(self):
        n = self.inScanner.nextInt()
        m = self.inScanner.nextInt()
        q = self.inScanner.nextInt()
        v = []
        inv = [0] * n
        for i in range(n):
            val = self.inScanner.nextInt()
            v.append(val)
            inv[val - 1] = i
        a = [0] * m
        b = [0] * m
        for i in range(m):
            a[i] = self.inScanner.nextInt() - 1
            b[i] = self.inScanner.nextInt() - 1
        type = [False] * q
        x = [0] * q
        removed = [False] * m
        for i in range(q):
            if self.inScanner.nextInt() == 1:
                x[i] = self.inScanner.nextInt() - 1
                type[i] = True
            else:
                x[i] = self.inScanner.nextInt() - 1
                removed[x[i]] = True
        dsu = self.DSU(v, m)
        for i in range(m):
            if not removed[i]:
                dsu.unite(a[i], b[i])
        for i in range(q - 1, -1, -1):
            if not type[i]:
                dsu.popEdge()
        for i in range(q):
            if type[i]:
                self.outPrinter.println(dsu.poll(x[i]))
            else:
                dsu.popEdge()

    class DSU:
        def __init__(self, v, m):
            self.p = [0] * len(v)
            self.sz = [1] * len(v)
            self.q = []
            self.less = []
            self.more = []
            self.used = [False] * (len(v) + 1)
            for i in range(len(v)):
                self.p[i] = i
                self.q.append([v[i]])
            self.less.append(-1)
            self.more.append(-1)

        def get(self, x):
            while x != self.p[x]:
                x = self.p[x]
            return x

        def unite(self, a, b):
            pa = self.get(a)
            pb = self.get(b)
            if pa == pb:
                self.less.append(-1)
                self.more.append(-1)
                return False
            if self.sz[pa] < self.sz[pb]:
                self.p[pa] = pb
                self.sz[pb] += self.sz[pa]
                self.less.append(pa)
                self.more.append(pb)
                for i in self.q[pa]:
                    self.q[pb].append(i)
            else:
                self.p[pb] = pa
                self.sz[pa] += self.sz[pb]
                self.less.append(pb)
                self.more.append(pa)
                for i in self.q[pb]:
                    self.q[pa].append(i)
            return True

        def popEdge(self):
            pa = self.less.pop()
            pb = self.more.pop()
            if pa < 0:
                return
            self.p[pa] = pa
            self.sz[pb] -= self.sz[pa]

        def poll(self, x):
            px = self.get(x)
            while len(self.q[px]) > 0:
                v = self.q[px].pop(0)
                if not self.used[v] and self.get(inv[v - 1]) == px:
                    self.used[v] = True
                    return v
            return 0

    def add(self, map, x):
        if x in map:
            map[x] += 1
        else:
            map[x] = 1

    def run(self):
        if self.systemIO:
            self.inScanner = FastScanner(sys.stdin)
            self.outPrinter = sys.stdout
        else:
            self.inScanner = FastScanner(open("input.txt"))
            self.outPrinter = open("output.txt", "w")
        self.solve()
        self.outPrinter.close()

E().run()
