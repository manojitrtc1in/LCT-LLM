import sys
from collections import defaultdict
from math import sqrt

MOD = 1000000007

class FastReader:
    def __init__(self, input_stream):
        self.br = input_stream
        self.st = []

    def next(self):
        while not self.st:
            line = self.br.readline()
            if not line:
                return ""
            self.st = line.split()
        return self.st.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

class Main:
    def __init__(self):
        self.dirs8 = [(0, 1), (0, -1), (-1, 0), (1, 0), (1, 1), (1, -1), (-1, 1), (-1, -1)]
        self.dirs4 = [(0, 1), (0, -1), (-1, 0), (1, 0)]
        
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

            id2 = [0] * (n + 1)
            visited = [False] * (n + 1)
            l = self.dfs(s, -1, s, t, nbs, id2, visited)

            for i in range(1, n + 1):
                id2[i] = 0
                visited[i] = False

            r = self.dfs(t, -1, t, s, nbs, id2, visited)
            tot = (n - 1 - l) * (n - 1 - r)
            sb.append(f"{tot}\n")

        sys.stdout.write(''.join(sb))

    def dfs(self, root, par, chosen_root, special, nbs, size, visited):
        sz = 1
        visited[root] = True
        if len(nbs[root]) == 1 and par >= 0:
            size[root] = 1
            return 1 if root == special else 0

        ans = 1 if root == special else 0
        for next in nbs[root]:
            if next != par and not visited[next]:
                sub = self.dfs(next, root, chosen_root, special, nbs, size, visited)
                if root == chosen_root and sub > 0:
                    return sub
                ans += sub
                sz += size[next]

        size[root] = sz
        return sz if ans > 0 else 0

if __name__ == "__main__":
    Main()
