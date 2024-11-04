import sys
from collections import defaultdict
import math

MOD = 1000000007

class FastReader:
    def __init__(self, input_stream):
        self.input_stream = input_stream
        self.buffer = []
        self.index = 0

    def next(self):
        while self.index >= len(self.buffer):
            self.buffer = self.input_stream.readline().strip().split()
            self.index = 0
        token = self.buffer[self.index]
        self.index += 1
        return token

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

class Main:
    def __init__(self):
        self.dirs8 = [(0, 1), (0, -1), (-1, 0), (1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]
        self.dirs4 = [(0, 1), (0, -1), (-1, 0), (1, 0)]
        self.WALL = -1
        self.EMPTY = -2
        self.VISITED = 1
        self.FULL = 2
        self.START = 1
        self.END = 0
        self.UNVISITED = -2

        input_stream = sys.stdin
        in_reader = FastReader(input_stream)

        nt = in_reader.next_int()
        sb = []

        for _ in range(nt):
            n = in_reader.next_int()
            m = in_reader.next_int()
            s = in_reader.next_int()
            t = in_reader.next_int()
            sz = [0] * (n + 1)
            nbs = [[] for _ in range(n + 1)]
            es = []

            for _ in range(m):
                u = in_reader.next_int()
                v = in_reader.next_int()
                es.append((u, v))
                sz[u] += 1
                sz[v] += 1

            for u, v in es:
                nbs[u].append(v)
                nbs[v].append(u)

            sub_tree_size = [0] * (n + 1)
            visited = [False] * (n + 1)
            l = self.dfs(s, 0, s, t, nbs, sub_tree_size, visited)

            for i in range(1, n + 1):
                sub_tree_size[i] = 0
                visited[i] = False

            r = self.dfs(t, 0, t, s, nbs, sub_tree_size, visited)
            tot = (n - 1 - l) * (n - 1 - r)
            sb.append(f"{tot}\n")

        sys.stdout.write(''.join(sb))

    def dfs(self, root, par, chosen_root, special, nbs, size, visited):
        sz = 1
        visited[root] = True
        if len(nbs[root]) == 1 and par > 0:
            size[root] = 1
            return 1 if root == special else 0

        ans = 1 if root == special else 0
        for next in nbs[root]:
            if next != par and not visited[next]:
                sub = self.dfs(next, root, chosen_root, special, nbs, size, visited)
                if root == chosen_root:
                    if sub > 0:
                        return sub
                else:
                    ans += sub
                sz += size[next]

        size[root] = sz
        return sz if ans > 0 else 0

if __name__ == "__main__":
    Main()
