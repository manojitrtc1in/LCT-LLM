from collections import defaultdict
from itertools import combinations

INF = int(1e9)
LINF = int(1e18)
M = int(1e9 + 7)
C = 20

def dag(g, cur):
    n = len(cur)
    dp = [False] * (1 << n)
    reach = [0] * n

    for i in range(n):
        for s in g[cur[i]]:
            reach[i] |= 1 << cur.index(s)

    res = 0
    dp[0] = True
    for m in range(1 << n):
        for i in range(n):
            if m & (1 << i):
                dp[m] |= dp[m ^ (1 << i)] and (reach[i] & m) == 0
        if dp[m]:
            res = max(res, bin(m).count('1'))

    return res

def solve():
    n = int(input())
    s = input().strip()
    t = input().strip()
    
    G = defaultdict(list)
    g = defaultdict(list)

    for i in range(n):
        if s[i] != t[i]:
            a = ord(s[i]) - ord('a')
            b = ord(t[i]) - ord('a')
            G[a].append(b)
            G[b].append(a)
            g[a].append(b)

    cur = []
    vis = [False] * C

    def dfs(v):
        vis[v] = True
        cur.append(v)
        for s in G[v]:
            if not vis[s]:
                dfs(s)

    res = 0
    for i in range(C):
        if not vis[i]:
            cur.clear()
            dfs(i)
            s = dag(g, cur)
            res += 2 * len(cur) - 1 - s

    return res

def main():
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == "__main__":
    main()
