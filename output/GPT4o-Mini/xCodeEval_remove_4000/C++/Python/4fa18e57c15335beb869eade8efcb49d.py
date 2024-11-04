from collections import defaultdict

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

    G = defaultdict(list)
    for u, v in ee:
        G[u - 1].append(v - 1)
        G[v - 1].append(u - 1)

    ee2 = []
    markers = [0] * n

    def cur_graph():
        pass

    def id6(graph, vertices, new_tree, enter_vertex, leave_vertex, before_traverse, after_traverse, back_edge, markers):
        for i in vertices:
            if markers[i] == 0:
                new_tree(i)
                dfs_rec(i, -1)

    def dfs_rec(v, parent):
        markers[v] = 1
        enter_vertex(v)
        for e in G[v]:
            if markers[e] == 0:
                dfs_rec(e, v)
                leave_vertex(v)
            elif parent != e:
                back_edge(v, e)

    res = []
    for i in range(n):
        for j in range(n):
            if a[i] != b[i]:
                path = []
                cur_graph()
                if not path_from(G, i, lambda v: (a[v] - b[v]) * (a[i] - b[i]) < 0, path, markers):
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

def path_from(g, v0, f, path, markers):
    def dfs(v):
        if f(v):
            path.append(v)
            return True
        markers[v] = 1
        res = False
        for e in g[v]:
            if not markers[e] and dfs(e):
                path.append(v)
                res = True
                break
        return res

    markers[:] = [0] * len(g)
    return dfs(v0)

