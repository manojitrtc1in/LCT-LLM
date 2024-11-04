import heapq

def umax(a, b):
    if a < b:
        a = b

def umin(a, b):
    if a > b:
        a = b

def abs(a):
    if a > 0:
        return a
    else:
        return -a

def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a // gcd(a, b) * b

def modpow(a, n, temp):
    res = 1
    y = a
    while n > 0:
        if n & 1:
            res = (res * y) % temp
        y = (y * y) % temp
        n //= 2
    return res % temp

def ison(mask, pos):
    return mask & (1 << pos)

def cbit(n):
    k = 0
    while n:
        n &= (n - 1)
        k += 1
    return k

def nbit(n):
    k = 0
    while n:
        n //= 2
        k += 1
    return k

mod = 10**9 + 7

def sgn(x):
    return -1 if x < 0 else bool(x)

eps = 1e-7
pi = acos(-1.0)

def inc(x, y):
    x += y
    if x >= mod:
        x -= mod

def dec(x, y):
    x -= y
    if x < 0:
        x += mod

def chmax(x, y):
    if y > x:
        x = y

def mulm(x, y):
    x *= y
    if x >= mod:
        x -= mod

def xo(i):
    if (i & 3) == 0:
        return i
    if (i & 3) == 1:
        return 1
    if (i & 3) == 2:
        return i + 1
    return 0

adj = [[] for _ in range(200005)]
q = []
vis = [0] * 200005
n, m, t, c = 0, 0, 0, 0

def solve(ind):
    global c
    if ind == n:
        heapq.heappush(q, c)
        if len(q) > t:
            heapq.heappop(q)
        return
    solve(ind + 1)
    for i in range(len(adj[ind])):
        if vis[adj[ind][i][0]] == 0:
            vis[adj[ind][i][0]] = 1
            c += adj[ind][i][1]
            if len(q) < t or c < q[0]:
                solve(ind + 1)
            c -= adj[ind][i][1]
            vis[adj[ind][i][0]] = 0

def main():
    global n, m, t, c
    r, s, x, i, j, k, l, m = 0, 0, 0, 0, 0, 0, 0, 0
    n, m, t = map(int, input().split())
    for _ in range(m):
        x, y, w = map(int, input().split())
        x -= 1
        y -= 1
        adj[x].append((y, w))
    solve(0)
    print(q[0])

if __name__ == "__main__":
    main()
