import sys
from collections import defaultdict
from bisect import bisect_left

class FenwickTree:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (size + 1)

    def add(self, pos):
        while pos <= self.size:
            self.tree[pos] += 1
            pos += pos & -pos

    def sum(self, pos):
        res = 0
        while pos > 0:
            res += self.tree[pos]
            pos -= pos & -pos
        return res

    def range_sum(self, l, r):
        return self.sum(r) - self.sum(l - 1)

class F:
    def __init__(self, p, q):
        self.p = p
        self.q = q

    def __lt__(self, other):
        return self.p * other.q < other.p * self.q

    def __eq__(self, other):
        return self.p * other.q == other.p * self.q

def solve1(v, w):
    allF = []
    for p in v:
        from_f = F(p[0], p[1] + w)
        to_f = F(p[0], p[1] - w)
        allF.append(from_f)
        allF.append(to_f)
    allF.append(F(0, 1))
    allF = sorted(set(allF), key=lambda x: (x.p, x.q))

    for i in range(len(v)):
        from_f = F(v[i][0], v[i][1] + w)
        to_f = F(v[i][0], v[i][1] - w)
        v[i] = (bisect_left(allF, from_f), bisect_left(allF, to_f))

    v.sort(key=lambda p: (p[0], -p[1]))
    res = 0
    f1 = FenwickTree(200020)

    for i in range(len(v)):
        res += i - f1.sum(v[i][1] - 1)
        f1.add(v[i][1])

    return res

def solve2(v, w):
    allF = []
    f = [FenwickTree(200020) for _ in range(2)]

    for i in range(2):
        for p in v[i]:
            from_f = F(p[0], p[1] + w)
            to_f = F(p[0], p[1] - w)
            allF.append(from_f)
            allF.append(to_f)

    allF.append(F(0, 1))
    allF = sorted(set(allF), key=lambda x: (x.p, x.q))
    res = 0

    for i in range(2):
        for j in range(len(v[i])):
            from_f = F(v[i][j][0], v[i][j][1] + w)
            to_f = F(v[i][j][0], v[i][j][1] - w)
            v[i][j] = (bisect_left(allF, from_f), bisect_left(allF, to_f))
            f[i].add(v[i][j][0])

    for p in v[0]:
        res += f[1].range_sum(p[0], p[1])

    for p in v[1]:
        res += f[0].range_sum(p[0] + 1, p[1])

    return res

def solve():
    n = int(sys.stdin.readline().strip())
    w = int(sys.stdin.readline().strip())
    x = [0] * n
    a = [0] * n
    v = [[], []]

    for i in range(n):
        x[i], a[i] = map(int, sys.stdin.readline().strip().split())
        v[x[i] < 0].append((abs(x[i]), abs(a[i])))

    ans = 0
    ans += solve1(v[0], w)
    ans += solve1(v[1], w)
    ans += solve2(v, w)
    print(ans)

if __name__ == "__main__":
    solve()
