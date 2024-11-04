class Main:
    def __init__(self):
        nt = int(input())
        sb = []
        for it in range(nt):
            n, m, s, t = map(int, input().split())
            sz = [0] * (n+1)
            nbs = [[] for _ in range(n+1)]
            es = []
            for i in range(m):
                p, q = map(int, input().split())
                es.append([p, q])
                sz[p] += 1
                sz[q] += 1
            for i in range(1, n+1):
                nbs[i] = [0] * sz[i]
                sz[i] = 0
            for e in es:
                p, q = e[0], e[1]
                nbs[p][sz[p]] = q
                nbs[q][sz[q]] = p
                sz[p] += 1
                sz[q] += 1
            subTreeSize = [0] * (n+1)
            visited = [False] * (n+1)
            l = self.dfs(s, 0, s, t, nbs, subTreeSize, visited)
            subTreeSize = [0] * (n+1)
            visited = [False] * (n+1)
            r = self.dfs(t, 0, t, s, nbs, subTreeSize, visited)
            tot = (n - 1 - l) * (n - 1 - r)
            sb.append(str(tot))
        print("\n".join(sb))

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

Main()
