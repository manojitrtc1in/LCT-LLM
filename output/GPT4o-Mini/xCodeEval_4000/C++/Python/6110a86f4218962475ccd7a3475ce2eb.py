import sys
import heapq
from collections import deque

INF = int(1e9)
INF64 = int(1e18)
MOD = INF + 7
EPS = 1e-9
PI = 3.141592653589793

N = 100 * 1000 + 13

n, m, k = 0, 0, 0
h = 0
a = [(0, 0)] * N

def read():
    global h, n, m, k
    line = sys.stdin.readline().strip()
    if not line:
        return False
    h, n, m, k = map(int, line.split())
    for i in range(n):
        a[i] = tuple(map(int, sys.stdin.readline().strip().split()))
    return True

used = [False] * N
mn = [0] * N
cur = []

def add(x):
    q = deque(range(k))
    while q:
        v = q.popleft()
        if mn[v] + x < mn[(v + x) % k]:
            mn[(v + x) % k] = mn[v] + x
            q.append((v + x) % k)

def recalc():
    global cur
    cur.clear()
    for i in range(n):
        if not used[i] and mn[a[i][0] % k] <= a[i][0]:
            heapq.heappush(cur, (-a[i][1], -i))

def solve():
    global cur
    for i in range(k):
        mn[i] = h + 1
    mn[1] = 1
    for i in range(N):
        used[i] = False
    recalc()
    
    for _ in range(m):
        t = int(sys.stdin.readline().strip())
        if t == 1:
            x = int(sys.stdin.readline().strip())
            add(x)
            recalc()
        elif t == 2:
            x, y = map(int, sys.stdin.readline().strip().split())
            x -= 1
            if mn[a[x][0] % k] <= a[x][0]:
                cur.remove((-a[x][1], -x))
                heapq.heapify(cur)
            a[x] = (a[x][0], a[x][1] - y)
            if mn[a[x][0] % k] <= a[x][0]:
                heapq.heappush(cur, (-a[x][1], -x))
        elif cur:
            print(-cur[0][0])
            used[-cur[0][1]] = True
            heapq.heappop(cur)
        else:
            print(0)

if __name__ == "__main__":
    while read():
        solve()
