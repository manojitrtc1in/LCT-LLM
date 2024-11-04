import sys
from collections import defaultdict
from math import log2, inf

class FastReader:
    def __init__(self):
        self.bfr = sys.stdin
        self.st = None

    def next(self):
        if self.st is None or not self.st:
            self.st = self.bfr.readline().split()
        return self.st.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_char(self):
        return self.next()[0]

    def next_string(self):
        return self.next()

    def id15(self, n):
        return [self.next_int() for _ in range(n)]

    def id37(self, n):
        return [self.next_double() for _ in range(n)]

    def id42(self, n):
        return [self.next_long() for _ in range(n)]

class UGraph:
    def __init__(self, V):
        self.adj = [set() for _ in range(V)]
        self.E = 0

    def add_edge(self, from_, to):
        if to in self.adj[from_]:
            return
        self.E += 1
        self.adj[from_].add(to)
        self.adj[to].add(from_)

    def degree(self, v):
        return len(self.adj[v])

    def V(self):
        return len(self.adj)

    def E(self):
        return self.E

    def __str__(self):
        result = f"{self.V()} vertices, {self.E()} edges\n"
        for v in range(self.V()):
            result += f"{v}: " + " ".join(map(str, self.adj[v])) + "\n"
        return result

class Point:
    def __init__(self, x=0, y=0, z=0, id_=0):
        self.x = x
        self.y = y
        self.z = z
        self.id = id_

    def __lt__(self, other):
        return (self.x, self.y, self.z) < (other.x, other.y, other.z)

    def __eq__(self, other):
        return (self.x, self.y, self.z) == (other.x, other.y, other.z)

class BinaryLift:
    def __init__(self, tree):
        self.n = tree.V()
        self.id14 = int(log2(self.n)) + 1
        self.parent_of = [-1] * self.n
        self.id38 = [[-1] * self.id14 for _ in range(self.n)]
        self.lvl_of = [0] * self.n
        self.parent_construct(0, -1, tree, 0)
        self.bin_construct()

    def parent_construct(self, current, from_, tree, depth):
        self.parent_of[current] = from_
        self.lvl_of[current] = depth
        for adj in tree.adj[current]:
            if adj != from_:
                self.parent_construct(adj, current, tree, depth + 1)

    def bin_construct(self):
        for node in range(self.n):
            for lvl in range(self.id14):
                self.bin_construct_helper(node, lvl)

    def bin_construct_helper(self, node, lvl):
        if node < 0:
            return -1
        if lvl == 0:
            return self.id38[node][lvl] = self.parent_of[node]
        if node == 0:
            return self.id38[node][lvl] = -1
        if self.id38[node][lvl] != -1:
            return self.id38[node][lvl]
        return self.id38[node][lvl] = self.bin_construct_helper(self.bin_construct_helper(node, lvl - 1), lvl - 1)

    def ancestor(self, node, k):
        if node < 0:
            return -1
        if node == 0:
            return node if k == 0 else -1
        if k > (1 << self.id14) - 1:
            return -1
        if k == 0:
            return node

        ancestor = node
        highest_bit = 1 << (k.bit_length() - 1)

        while k > 0 and ancestor != -1:
            ancestor = self.id38[ancestor][int(log2(highest_bit))]
            k -= highest_bit
            highest_bit = 1 << (k.bit_length() - 1)

        return ancestor

    def lca(self, u, v):
        if u == v:
            return u

        if self.lvl_of[u] < self.lvl_of[v]:
            u, v = v, u

        u = self.ancestor(u, self.lvl_of[u] - self.lvl_of[v])

        if u == v:
            return u

        for power in range(self.id14 - 1, -1, -1):
            if self.id38[u][power] != self.id38[v][power]:
                u = self.id38[u][power]
                v = self.id38[v][power]

        return self.ancestor(u, 1)

def main():
    fr = FastReader()
    t = 1
    mod = 1000000007

    for _ in range(t):
        n = fr.next_int()
        mod = fr.next_long()

        dp = [0] * (n + 1)
        dp[n] = 1

        for i in range(n - 1, 0, -1):
            dp[i] += dp[i + 1]
            dp[i] %= mod

            for div in range(1, n // i + 1):
                lb = div * i
                ub = min(div * (i + 1) - 1, n)
                seg_sum = dp[lb]
                if ub + 1 <= n:
                    seg_sum -= dp[ub + 1]
                dp[i] += seg_sum
                dp[i] %= mod

            dp[i] += dp[i + 1]
            dp[i] %= mod

        print((dp[1] - dp[2] + mod) % mod)

if __name__ == "__main__":
    main()
