from typing import List, Tuple

def solve() -> int:
    n = int(input())
    s = input()
    t = input()

    G = [[] for _ in range(20)]
    cur = []
    masks = [0] * 20
    dp = [False] * (1 << 20)
    vis = [False] * 20
    mask = 0

    def dfs(v: int) -> None:
        nonlocal mask
        vis[v] = True
        mask |= 1 << v
        cur.append(v)

        for s in G[v]:
            if not vis[s]:
                dfs(s)

    def count() -> int:
        sub = []
        m = mask
        while m:
            sub.append(m)
            m = (m - 1) & mask
        sub.reverse()

        res = 0
        for m in sub:
            for v in cur:
                if m & (1 << v):
                    dp[m] |= dp[m ^ (1 << v)] and ((m & masks[v] & mask) == 0)
            if dp[m]:
                res = max(res, bin(m).count('1'))
        return res

    res = 0
    dp[0] = True
    for i in range(20):
        if not vis[i]:
            mask = 0
            cur.clear()
            dfs(i)
            tmp = count()
            res += 2 * len(cur) - 1 - tmp

    vis = [False] * 20
    masks = [0] * 20
    dp = [False] * (1 << 20)
    G = [[] for _ in range(20)]

    return res

def main() -> None:
    t = int(input())
    for _ in range(t):
        print(solve())

if __name__ == "__main__":
    main()
