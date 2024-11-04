import sys
from typing import List, Tuple
from collections import defaultdict
from heapq import heappop, heappush

INF = float('inf')

def read() -> int:
    num = 0
    c = sys.stdin.read(1)
    if c == '-':
        return -read()
    while c >= '0' and c <= '9':
        num = (num << 3) + (num << 1) + int(c) - int('0')
        c = sys.stdin.read(1)
    return num

def READ() -> int:
    num = 0
    c = sys.stdin.read(1)
    if c == '-':
        return -READ()
    while c >= '0' and c <= '9':
        num = (num << 3) + (num << 1) + int(c) - int('0')
        c = sys.stdin.read(1)
    return num

class Matrix:
    def __init__(self):
        self.mat = [[INF] * 77 for _ in range(77)]
    
    def __mul__(self, ma: 'Matrix') -> 'Matrix':
        mat2 = Matrix()
        for i in range(77):
            for j in range(77):
                for k in range(77):
                    mat2.mat[i][k] = min(mat2.mat[i][k], self.mat[i][j] + ma.mat[j][k])
        return mat2

def id0(x: 'Matrix', y: int) -> 'Matrix':
    if y == 1:
        return x
    mat2 = id0(x, y // 2)
    mat2 = mat2 * mat2
    if y % 2:
        mat2 = mat2 * x
    return mat2

def main() -> None:
    id1 = Matrix()
    id1.mat[0][0] = 0
    x, k, n, q = map(int, input().split())
    c = [0] * 15
    for i in range(1, k + 1):
        c[i] = int(input())
    ws_ = [tuple(map(int, input().split())) for _ in range(q)]
    ws_.sort()
    p = [0] * 27
    wp = [0] * 27
    wpp = defaultdict(int)
    for i in range(q):
        p[i] = ws_[i][0]
        wp[i] = ws_[i][1]
        wpp[p[i]] = wp[i]
    dy = [0] * 257
    cntdy = 0
    yd = [0] * 77
    for i in range(1 << k):
        if bin(i).count('1') == x:
            yd[cntdy] = i
            dy[i] = cntdy
            cntdy += 1
    zyj = Matrix()
    for ii in range(cntdy):
        j = yd[ii]
        if j & 1:
            for l in range(1, k + 1):
                if not (j & (1 << l)):
                    zyj.mat[ii][dy[(j + (1 << l)) >> 1]] = c[l]
        else:
            zyj.mat[ii][dy[j >> 1]] = 0
    nowpos = 1
    for i in range(q):
        to = min(n - x + 1, p[i] - k - 1)
        if to - nowpos > 0:
            id1 = id1 * id0(zyj, to - nowpos)
        nm = zyj
        for j in range(max(nowpos, to), min(n - x + 1, p[i])):
            for ii in range(cntdy):
                jj = yd[ii]
                if jj & 1:
                    for l in range(1, k + 1):
                        if not (jj & (1 << l)):
                            nm.mat[ii][dy[(jj + (1 << l)) >> 1]] += wpp[j + l]
            id1 = id1 * nm
            nm = zyj
        nowpos = min(n - x + 1, p[i])
    if n - x + 1 - nowpos > 0:
        id1 = id1 * id0(zyj, n - x + 1 - nowpos)
    print(id1.mat[0][0])

if __name__ == '__main__':
    main()
