from collections import deque
import sys
import heapq

INF = 1 << 60

def add_edge(G, from_node, to, cap, rev_flag, rev_cap):
    G[from_node].append(Edge(to, cap, len(G[to])))
    if rev_flag:
        G[to].append(Edge(from_node, rev_cap, len(G[from_node]) - 1))

class Edge:
    def __init__(self, to, cap, rev):
        self.to = to
        self.cap = cap
        self.rev = rev

def id1(G, v, t, f, used):
    if v == t:
        return f
    used[v] = True
    for e in G[v]:
        if not used[e.to] and e.cap > 0:
            d = id1(G, e.to, t, min(f, e.cap), used)
            if d > 0:
                e.cap -= d
                G[e.to][e.rev].cap += d
                return d
    return 0

def max_flow(G, s, t):
    flow = 0
    while True:
        used = [False] * len(G)
        f = id1(G, s, t, INF, used)
        if f == 0:
            return flow
        flow += f

def dfs(G, v, t, st, used, s):
    used[v] = 1
    if v != s:
        st.add(v)
    if v == t:
        return
    if v != s:
        for e in G[v]:
            to = e.to
            if used[to] == 0:
                dfs(G, to, t, st, used, s)
            elif used[to] == 2:
                st.add(t)
    else:
        for e in G[v]:
            to = e.to
            if used[to] != 0:
                continue
            dfs(G, to, t, st, used, s)
            if t in st:
                for itr in st:
                    used[itr] = 2
            st.clear()

def solve():
    n, m, a, b = map(int, input().split())
    a -= 1
    b -= 1
    G = [[] for _ in range(n)]
    for _ in range(m):
        u, v = map(int, input().split())
        u -= 1
        v -= 1
        add_edge(G, u, v, 1, True, 1)
    used = [0] * n
    st = set()
    dfs(G, a, b, st, used, a)
    s = sum(1 for x in used if x == 1) - 1
    t = sum(1 for x in used if x == 0)
    print(s * t)

def main():
    input = sys.stdin.read
    data = input().splitlines()
    t = int(data[0])
    for i in range(t):
        solve()

if __name__ == "__main__":
    main()
