from sys import stdin, stdout
from math import sqrt

def mp(x, y):
    return (x, y)

def sz(v):
    return len(v)

def raz(a, b, M):
    c = a - b
    return c + M if c < 0 else c

def sum(a, b, M):
    c = a + b
    return c - M if c >= M else c

def id17(r):
    return 32 - (r.bit_length() - 1)

def euc(m, n):
    if n == 0:
        return (1 if m >= 0 else -1, 0)
    t = m // n
    ans1 = euc(n, m - t * n)
    return (ans1[1], ans1[0] - ans1[1] * t)

def prod(a, b, M):
    return (a * b) % M

def id1(p1, p2, n):
    if p1[0] == -1 or p2[0] == -1:
        return (-1, -1)
    np1 = (0, raz(p1[1], p1[0], n))
    np2 = (raz(p2[0], p1[0], n), raz(p2[1], p1[0], n))
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return (-1, -1)
        else:
            return (sum(np1[0], p1[0], n), sum(max(np1[1], np2[1]), p1[0], n))
    else:
        if np2[0] <= np1[1] + 1:
            return (-1, -1)
        else:
            return (sum(np2[0], p1[0], n), sum(max(np1[1], np2[1]), p1[0], n))

class Sparse:
    def __init__(self):
        self.n = 0
        self.sp = []

    def construct(self, v):
        self.n = sz(v)
        r = id17(self.n - 1)
        self.sp = [[(0, 0)] * self.n for _ in range(r)]
        for i in range(self.n):
            self.sp[0][i] = v[i]
        for i in range(1, r):
            for j in range(self.n):
                p1 = self.sp[i - 1][j]
                p2 = self.sp[i - 1][(j + (1 << (i - 1))) % self.n]
                self.sp[i][j] = id1(p1, p2, self.n)

    def segment(self, l, r):
        if l == -1 or r == -1:
            return (-1, -1)
        szz = raz(r, l, self.n)
        if l == r:
            return self.sp[0][l]
        g = id17(szz) - 1
        return id1(self.sp[g][l], self.sp[g][(r + 1 - (1 << g)) % self.n], self.n)

def main():
    input = stdin.read
    data = input().split()
    n = int(data[0])
    if n == 1:
        stdout.write("0\n")
        return

    r = list(map(int, data[1:n + 1]))
    zz = id17(n) + 1
    v = [Sparse() for _ in range(zz)]
    prs = [(0, 0)] * n

    for i in range(n):
        if r[i] >= n - 1:
            prs[i] = (-1, -1)
        else:
            prs[i] = id1((raz(i, r[i], n), i), (i, sum(i, r[i], n)), n)

    v[0].construct(prs)

    for i in range(1, zz):
        id14 = [(0, 0)] * n
        for j in range(n):
            pairr = v[i - 1].segment(j, j)
            id14[j] = v[i - 1].segment(pairr[0], pairr[1])
        v[i].construct(id14)

    result = []
    for i in range(n):
        my_pr = (i, i)
        ans = 0
        for j in range(zz - 1, -1, -1):
            new_pr = v[j].segment(my_pr[0], my_pr[1])
            if new_pr[0] != -1:
                ans += (1 << j)
                my_pr = new_pr
        result.append(ans + 1)

    stdout.write(' '.join(map(str, result)) + '\n')

if __name__ == "__main__":
    main()
