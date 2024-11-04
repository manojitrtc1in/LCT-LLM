import sys

def dijkstra(e, start, start_dist):
    n = len(e)
    added = [False] * n
    res = [float('inf')] * n
    res[start] = start_dist
    added[start] = True
    pq = [(start_dist, start)]
    while pq:
        d, i = pq.pop(0)
        if res[i] < d:
            continue
        for j, ew in e[i]:
            if not added[j] or d + ew < res[j]:
                res[j] = d + ew
                added[j] = True
                pq.append((res[j], j))
    return res, added

def solve():
    n, k = map(int, input().split())
    sums = []
    arrs = []
    for _ in range(n):
        t = int(input())
        arr = list(map(int, input().split()))
        if t > k:
            arr = arr[:k]
        sums.append(sum(arr))
        arrs.append(arr)
    dps = [[0] * (k + 1) for _ in range(13)]
    ans = rec(0, n, 0)
    print(ans)

def rec(l, r, dpi):
    ans = 0
    carr = arrs[l]
    dp = dps[dpi]
    if l + 1 == r:
        ans = max(ans, dp[k])
        sm = 0
        for i in range(min(k, len(carr))):
            sm += carr[i]
            ans = max(ans, dp[k - i - 1] + sm)
    else:
        m = (l + r) // 2
        do_copy(dpi)
        for i in range(l, m):
            add_to_knap(i, dpi + 1)
        ans = max(ans, rec(m, r, dpi + 1))
        do_copy(dpi)
        for i in range(m, r):
            add_to_knap(i, dpi + 1)
        ans = max(ans, rec(l, m, dpi + 1))
    return ans

def do_copy(dpi):
    dps[dpi + 1] = dps[dpi][:]

def add_to_knap(i, dpi):
    v = sums[i]
    k1 = len(arrs[i])
    for j in range(k, k1 - 1, -1):
        dps[dpi][j] = max(dps[dpi][j], dps[dpi][j - k1] + v)

if __name__ == "__main__":
    solve()
