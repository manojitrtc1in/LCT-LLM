import sys
from collections import defaultdict
import math
import random

gigamod = 1000000007
epsilon = 1e-8
t = 1

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

    def next_int_array(self, n):
        return [self.next_int() for _ in range(n)]

    def next_long_array(self, n):
        return [self.next_long() for _ in range(n)]

class Edge:
    def __init__(self, fro, t, weigh, i):
        self.from_ = fro
        self.to = t
        self.weight = weigh
        self.id = i

    def __lt__(self, other):
        return self.id < other.id

def sparse_table(a):
    n = len(a)
    b = 32 - (n - 1).bit_length()
    ret = [[0] * (n - (1 << i) + 1) for i in range(b)]
    for i in range(b):
        if i == 0:
            ret[i] = a
        else:
            for j in range(n - (1 << i) + 1):
                ret[i][j] = min(ret[i - 1][j], ret[i - 1][j + (1 << (i - 1))])
    return ret

def sparse_rmq(table, l, r):
    assert l <= r
    if l >= r:
        return float('inf')
    t = 31 - (r - l).bit_length()
    return min(table[t][l], table[t][r - (1 << t)])

class Point:
    def __init__(self, x=0, y=0, z=0, id=0):
        self.x = x
        self.y = y
        self.z = z
        self.id = id

    def __lt__(self, other):
        if self.x != other.x:
            return self.x < other.x
        if self.y != other.y:
            return self.y < other.y
        return self.z < other.z

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y and self.z == other.z

class BinaryLift:
    def __init__(self, tree):
        self.n = tree.V()
        self.max_jmp_pow = int(math.log2(self.n)) + 1
        self.parent_of = [0] * self.n
        self.bin_ancestor_of = [[-1] * self.max_jmp_pow for _ in range(self.n)]
        self.lvl_of = [0] * self.n
        self.parent_construct(0, -1, tree, 0)
        self.bin_construct()

    def parent_construct(self, current, from_, tree, depth):
        self.parent_of[current] = from_
        self.lvl_of[current] = depth
        for adj in tree.adj(current):
            if adj != from_:
                self.parent_construct(adj, current, tree, depth + 1)

    def bin_construct(self):
        for node in range(self.n):
            for lvl in range(self.max_jmp_pow):
                self.bin_construct_helper(node, lvl)

    def bin_construct_helper(self, node, lvl):
        if node < 0:
            return -1
        if lvl == 0:
            return self.bin_ancestor_of[node][lvl] = self.parent_of[node]
        if node == 0:
            return self.bin_ancestor_of[node][lvl] = -1
        if self.bin_ancestor_of[node][lvl] != -1:
            return self.bin_ancestor_of[node][lvl]
        return self.bin_ancestor_of[node][lvl] = self.bin_construct_helper(self.bin_construct_helper(node, lvl - 1), lvl - 1)

    def ancestor(self, node, k):
        if node < 0:
            return -1
        if node == 0:
            return node if k == 0 else -1
        if k > (1 << self.max_jmp_pow) - 1:
            return -1
        if k == 0:
            return node

        ancestor = node
        highest_bit = 1 << (k.bit_length() - 1)

        while k > 0 and ancestor != -1:
            ancestor = self.bin_ancestor_of[ancestor][int(math.log2(highest_bit))]
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

        for power in range(self.max_jmp_pow - 1, -1, -1):
            if self.bin_ancestor_of[u][power] != self.bin_ancestor_of[v][power]:
                u = self.bin_ancestor_of[u][power]
                v = self.bin_ancestor_of[v][power]

        return self.ancestor(u, 1)

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

    def adj(self, from_):
        return self.adj[from_]

    def V(self):
        return len(self.adj)

    def E(self):
        return self.E

def main():
    fr = FastReader()
    out = sys.stdout

    for tc in range(t):
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

        out.write(f"{(dp[1] - dp[2] + mod) % mod}\n")

if __name__ == "__main__":
    main()
