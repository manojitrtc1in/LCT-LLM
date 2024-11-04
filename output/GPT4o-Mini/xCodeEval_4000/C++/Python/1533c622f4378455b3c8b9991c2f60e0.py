import sys
from collections import defaultdict
from math import sqrt

def count_tro(r):
    ans = 0
    while r:
        ans += 1
        r >>= 1
    return ans

def unite_seg(p1, p2, n):
    if p1[0] == -1 or p2[0] == -1:
        return (-1, -1)
    np1 = (0, (p1[1] - p1[0]) % n)
    np2 = ((p2[0] - p1[0]) % n, (p2[1] - p1[0]) % n)
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return (-1, -1)
        else:
            return ((np1[0] + p1[0]) % n, max(np1[1], np2[1]) + p1[0]) % n
    else:
        if np2[0] <= np1[1] + 1:
            return (-1, -1)
        else:
            return ((np2[0] + p1[0]) % n, max(np1[1], np2[1]) + p1[0]) % n

class Sparse:
    def __init__(self):
        self.n = 0
        self.sp = []

    def construct(self, v):
        self.n = len(v)
        r = count_tro(self.n - 1)
        self.sp = [[(0, 0)] * self.n for _ in range(r)]
        for i in range(self.n):
            self.sp[0][i] = v[i]
        for i in range(1, r):
            for j in range(self.n):
                p1 = self.sp[i - 1][j]
                p2 = self.sp[i - 1][(j + (1 << (i - 1))) % self.n]
                self.sp[i][j] = unite_seg(p1, p2, self.n)

    def segment(self, l, r):
        if l == -1 or r == -1:
            return (-1, -1)
        szz = r - l
        if l == r:
            return self.sp[0][l]
        g = count_tro(szz) - 1
        return unite_seg(self.sp[g][l], self.sp[g][(r + 1 - (1 << g)) % self.n], self.n)

def main():
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    if n == 1:
        print("0")
        return
    r = list(map(int, data[1:n + 1]))
    zz = count_tro(n) + 1
    v = [Sparse() for _ in range(zz)]
    prs = [(0, 0)] * n

    for i in range(n):
        if r[i] >= n - 1:
            prs[i] = (-1, -1)
        else:
            prs[i] = unite_seg((i - r[i]) % n, (i + r[i]) % n, n)

    v[0].construct(prs)

    for i in range(1, zz):
        new_prs = [(0, 0)] * n
        for j in range(n):
            pairr = v[i - 1].segment(j, j)
            new_prs[j] = v[i - 1].segment(pairr[0], pairr[1])
        v[i].construct(new_prs)

    for i in range(n):
        my_pr = (i, i)
        ans = 0
        for j in range(zz - 1, -1, -1):
            new_pr = v[j].segment(my_pr[0], my_pr[1])
            if new_pr[0] != -1:
                ans += (1 << j)
                my_pr = new_pr
        print(ans + 1, end=' ')
    print()

if __name__ == "__main__":
    main()
