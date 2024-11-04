def doit(a, b, path, res, pos, vol, diff):
    if pos + 1 >= len(path):
        return
    tgt = path[pos + 1]
    before = min(diff, vol - a[tgt])
    src = path[pos]
    if before > 0:
        res.append((src + 1, tgt + 1, before))
    doit(a, b, path, res, pos + 1, vol, diff)
    after = diff - before
    if after > 0:
        res.append((src + 1, tgt + 1, after))

def solve():
    n, vol, e = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    ee = [tuple(map(int, input().split())) for _ in range(e)]

    G = [[] for _ in range(n)]
    for u, v in ee:
        G[u-1].append(v-1)
        G[v-1].append(u-1)

    ee2 = []
    markers = [0] * n
    for i in range(n):
        path = []
        if not path_from(G, i, lambda v: (a[v] - b[v]) % (a[i] - b[i]) < 0, path, markers):
            print("NO")
            return
        if a[path[0]] < b[path[0]]:
            path.reverse()

        src = path[0]
        tgt = path[-1]
        diff = min(abs(a[src] - b[src]), abs(a[tgt] - b[tgt]))
        doit(a, b, path, res, 0, vol, diff)
        a[src] -= diff
        a[tgt] += diff

    print(len(res))
    for x in res:
        print(x[0], x[1], x[2])

solve()
