import sys
from typing import List, Tuple

class Fenw:
    def __init__(self):
        self.tr = [0] * 202020
    
    def add(self, pos: int) -> None:
        for i in range(pos, 200020, i | (i + 1)):
            self.tr[i] += 1
    
    def sum(self, pos: int) -> int:
        res = 0
        for i in range(pos, -1, (i & (i + 1)) - 1):
            res += self.tr[i]
        return res
    
    def range_sum(self, l: int, r: int) -> int:
        return self.sum(r) - self.sum(l - 1)

def solve1(v: List[Tuple[int, int]]) -> int:
    allF = []
    for p in v:
        from_ = (p[0], p[1] + w)
        to = (p[0], p[1] - w)
        allF.append(from_)
        allF.append(to)
    allF.append((0, 1))
    allF.sort()
    allF = list(set(allF))
    for i in range(len(v)):
        from_ = (v[i][0], v[i][1] + w)
        to = (v[i][0], v[i][1] - w)
        v[i] = (allF.index(from_), allF.index(to))
    v.sort(key=lambda x: (x[0], x[1]))
    res = 0
    f1 = Fenw()
    for i in range(len(v)):
        res += i - f1.sum(v[i][1] - 1)
        f1.add(v[i][1])
    return res

def solve2(v: List[List[Tuple[int, int]]]) -> int:
    allF = []
    for i in range(2):
        for p in v[i]:
            from_ = (p[0], p[1] + w)
            to = (p[0], p[1] - w)
            allF.append(from_)
            allF.append(to)
    allF.append((0, 1))
    allF.sort()
    allF = list(set(allF))
    res = 0
    f = [Fenw() for _ in range(2)]
    for i in range(2):
        for p in v[i]:
            from_ = (p[0], p[1] + w)
            to = (p[0], p[1] - w)
            p = (allF.index(from_), allF.index(to))
            f[i].add(p[0])
    for p in v[0]:
        res += f[1].range_sum(p[0], p[1])
    for p in v[1]:
        res += f[0].range_sum(p[0] + 1, p[1])
    return res

def solve() -> int:
    n = int(input())
    w = int(input())
    x = [0] * n
    a = [0] * n
    v = [[] for _ in range(2)]
    for i in range(n):
        x[i], a[i] = map(int, input().split())
        v[x[i] < 0].append((abs(x[i]), abs(a[i])))
    ans = 0
    ans += solve1(v[0])
    ans += solve1(v[1])
    ans += solve2(v)
    return ans

if __name__ == "__main__":
    print(solve())
