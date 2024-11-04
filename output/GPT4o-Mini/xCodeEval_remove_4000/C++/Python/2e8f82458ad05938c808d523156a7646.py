from typing import List, Tuple, Union
import sys
import math

def raz(a: int, b: int, M: int) -> int:
    c = a - b
    return c + M if c < 0 else c

def sum(a: int, b: int, M: int) -> int:
    c = a + b
    return c - M if c >= M else c

def id17(r: int) -> int:
    return 32 - (r.bit_length() - 1)

def id1(p1: Tuple[int, int], p2: Tuple[int, int], n: int) -> Tuple[int, int]:
    if p1[0] == -1 or p2[0] == -1:
        return -1, -1
    np1 = (0, raz(p1[1], p1[0], n))
    np2 = (raz(p2[0], p1[0], n), raz(p2[1], p1[0], n))
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return -1, -1
        else:
            return sum(np1[0], p1[0], n), sum(max(np1[1], np2[1]), p1[0], n)
    else:
        if np2[0] <= np1[1] + 1:
            return -1, -1
        else:
            return sum(np2[0], p1[0], n), sum(max(np1[1], np2[1]), p1[0], n)

class Sparse:
    def __init__(self):
        self.n = 0
        self.sp = []

    def construct(self, v: List[Tuple[int, int]]):
        self.n = len(v)
        r = id17(self.n - 1)
        self.sp = [[(0, 0)] * self.n for _ in range(r)]
        for i in range(self.n):
            self.sp[0][i] = v[i]
        for i in range(1, r):
            for j in range(self.n):
                p1 = self.sp[i - 1][j]
                p2 = self.sp[i - 1][(j + (1 << (i - 1))) % self.n]
                self.sp[i][j] = id1(p1, p2, self.n)

    def segment(self, l: int, r: int) -> Tuple[int, int]:
        if l == -1 or r == -1:
            return -1, -1
        szz = raz(r, l, self.n)
        if l == r:
            return self.sp[0][l]
        g = id17(szz) - 1
        return id1(self.sp[g][l], self.sp[g][(r + 1 - (1 << g)) % self.n], self.n)

def main():
    input = sys.stdin.read
    data = input().split()
    
    n = int(data[0])
    if n == 1:
        print("0")
        return
    
    r = list(map(int, data[1:n + 1]))
    zz = id17(n + 1) - 1
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

    print(' '.join(map(str, result)))

if __name__ == "__main__":
    main()
