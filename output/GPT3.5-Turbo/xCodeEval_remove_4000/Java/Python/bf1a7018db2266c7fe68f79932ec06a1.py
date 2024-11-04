import sys

class FastReader:
    def __init__(self, file):
        self.file = file
        self.buffer = []
        self.buffer_idx = 0

    def next(self):
        if self.buffer_idx >= len(self.buffer):
            self.buffer = self.file.readline().split()
            self.buffer_idx = 0
        result = self.buffer[self.buffer_idx]
        self.buffer_idx += 1
        return result

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return self.file.readline()

class Main:
    def __init__(self):
        in_file = sys.stdin
        out_file = sys.stdout

        self.in_reader = FastReader(in_file)
        self.out_writer = out_file

        self.solve()

    def solve(self):
        nt = self.in_reader.nextInt()

        for it in range(nt):
            n = self.in_reader.nextInt()
            m = self.in_reader.nextInt()
            s = self.in_reader.nextInt()
            t = self.in_reader.nextInt()
            sz = [0] * (n + 1)
            nbs = [[] for _ in range(n + 1)]
            es = [[0, 0] for _ in range(m)]
            for i in range(m):
                es[i][0] = self.in_reader.nextInt()
                es[i][1] = self.in_reader.nextInt()
                sz[es[i][0]] += 1
                sz[es[i][1]] += 1
            for i in range(1, n + 1):
                nbs[i] = [0] * sz[i]
                sz[i] = 0

            for e in es:
                p = e[0]
                q = e[1]
                nbs[p][sz[p]] = q
                nbs[q][sz[q]] = p
                sz[p] += 1
                sz[q] += 1

            id2 = [0] * (n + 1)
            visited = [False] * (n + 1)
            l = self.dfs(s, 0, s, t, nbs, id2, visited)
            id2 = [0] * (n + 1)
            visited = [False] * (n + 1)
            r = self.dfs(t, 0, t, s, nbs, id2, visited)
            tot = (n - 1 - l) * (n - 1 - r)
            self.out_writer.write(str(tot) + "\n")

    def dfs(self, root, par, chosenRoot, special, nbs, size, visited):
        sz = 1
        visited[root] = True
        if len(nbs[root]) == 1 and par > 0:
            size[root] = 1
            if root == special:
                return 1
            return 0

        ans = 1 if root == special else 0
        for next in nbs[root]:
            if next != par and not visited[next]:
                sub = self.dfs(next, root, chosenRoot, special, nbs, size, visited)
                if root == chosenRoot:
                    if sub > 0:
                        return sub
                else:
                    ans += sub
                sz += size[next]
        size[root] = sz
        if ans == 0:
            return 0
        return sz

if __name__ == "__main__":
    Main()
