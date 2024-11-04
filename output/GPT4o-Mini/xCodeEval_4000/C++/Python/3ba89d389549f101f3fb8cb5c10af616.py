MOD = 1000000007

def rep(i, m, n):
    for i in range(m, n):
        yield i

def REP(i, n):
    return rep(i, 0, n)

def add_edge(G, from_, to, cap, revFlag, revCap):
    G[from_].append(Edge(to, cap, len(G[to])))
    if revFlag:
        G[to].append(Edge(from_, revCap, len(G[from_]) - 1))

def max_flow_dfs(G, v, t, f, used):
    if v == t:
        return f
    used[v] = True
    for i in range(len(G[v])):
        e = G[v][i]
        if not used[e.to] and e.cap > 0:
            d = max_flow_dfs(G, e.to, t, min(f, e.cap), used)
            if d > 0:
                e.cap -= d
                G[e.to][e.rev].cap += d
                return d
    return 0

def max_flow(G, s, t):
    flow = 0
    while True:
        used = [False] * len(G)
        f = max_flow_dfs(G, s, t, float('inf'), used)
        if f == 0:
            return flow
        flow += f

def dfs(g, v, t, st, used, s):
    used[v] = 1
    if v != s:
        st.add(v)
    if v == t:
        return
    if v != s:
        for i in range(len(g[v])):
            to = g[v][i].to
            if used[to] == 0:
                dfs(g, to, t, st, used, s)
            elif used[to] == 2:
                st.add(t)
    else:
        for i in range(len(g[v])):
            to = g[v][i].to
            if used[to] != 0:
                continue
            dfs(g, to, t, st, used, s)
            if t in st:
                for itr in st:
                    used[itr] = 2
            st.clear()

def solve():
    n, m, a, b = map(int, input().split())
    a -= 1
    b -= 1
    g = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        add_edge(g, u, v, 1, True, 1)
    used = [0] * n
    st = set()
    dfs(g, a, b, st, used, a)
    s = sum(1 for x in used if x == 1) - 1
    t = sum(1 for x in used if x == 0)
    print(s * t)

t = int(input())
for _ in range(t):
    solve()
