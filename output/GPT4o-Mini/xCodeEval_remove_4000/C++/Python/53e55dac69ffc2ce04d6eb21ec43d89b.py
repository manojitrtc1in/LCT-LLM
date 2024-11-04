from collections import defaultdict

class Triple:
    def __init__(self, a=0, b=0, c=0):
        self.a = a
        self.b = b
        self.c = c

    def __lt__(self, other):
        if self.a != other.a:
            return self.a < other.a
        elif self.b != other.b:
            return self.b < other.b
        return self.c < other.c

    def __gt__(self, other):
        if self.a != other.a:
            return self.a > other.a
        elif self.b != other.b:
            return self.b > other.b
        return self.c > other.c

def bits_count(v):
    v = v - ((v >> 1) & 0x55555555)
    v = (v & 0x33333333) + ((v >> 2) & 0x33333333)
    return ((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24

def reverse_bits(x):
    x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1))
    x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2))
    x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4))
    x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8))
    return ((x >> 16) | (x << 16))

def sign(x):
    return (x > 0) - (x < 0)

def clamp(x, a, b):
    return max(a, min(x, b))

def read_int():
    return int(input().strip())

def write_int(x, endc='\n'):
    print(x, end=endc)

def print_array(a):
    print(" ".join(map(str, a)))

g = defaultdict(set)
ct = 0
c = []
sz = [0] * 202020
used = [0] * 202020
n = 0
ans = []

def go(cur, iter=1):
    global ct
    sz[cur] = 1
    used[cur] = iter
    t = 0
    for to in g[cur]:
        if used[to] != iter:
            go(to, iter)
            sz[cur] += sz[to]
            t = max(t, sz[to])
    t = max(t, n - sz[cur])
    if t * 2 <= n:
        ct = cur
        c.append(cur)

st = []

def dfs2(cur, p=-1):
    used[cur] = True
    for to in g[cur]:
        if not used[to]:
            dfs2(to, cur)
    st.append((cur, p))

def solve(cur):
    global ans
    st.clear()
    dfs2(cur)
    st.pop()
    last = cur
    for v, par in st:
        if par != cur:
            ans.append(Triple(ct, last, v))
            ans.append(Triple(v, par, cur))
            last = v
    if last != cur:
        ans.append(Triple(ct, last, cur))

def main():
    global n
    n = read_int()
    for _ in range(n - 1):
        x, y = map(int, input().split())
        g[x].add(y)
        g[y].add(x)
    go(1)
    used = [0] * 202020
    assert c
    for x in c:
        used[x] = True
    for x in c:
        ct = x
        for to in g[ct]:
            if not used[to]:
                solve(to)
    write_int(len(ans))
    assert len(ans) <= 2 * n
    for t in ans:
        write_int(f"{t.a} {t.b} {t.c}")

if __name__ == "__main__":
    main()
