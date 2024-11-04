import sys
from collections import defaultdict
from functools import reduce
import math

LL = int
Mod = 1000000007
Inf = float('inf')

def read():
    return int(sys.stdin.readline().strip())

class Matrix:
    def __init__(self):
        self.mat = [[Inf] * 77 for _ in range(77)]

    def __mul__(self, other):
        mat2 = Matrix()
        for i in range(77):
            for j in range(77):
                for k in range(77):
                    mat2.mat[i][k] = min(mat2.mat[i][k], self.mat[i][j] + other.mat[j][k])
        return mat2

def ksmii(x, y):
    if y == 1:
        return x
    mat2 = ksmii(x, y // 2)
    mat2 = mat2 * mat2
    if y % 2:
        mat2 = mat2 * x
    return mat2

zyj = Matrix()
zyj2 = Matrix()
zyj2.mat[0][0] = 0

x, k, n, q = map(int, sys.stdin.readline().split())
c = [0] * 15
for i in range(1, k + 1):
    c[i] = read()

ws_ = [tuple(map(int, sys.stdin.readline().split())) for _ in range(q)]
ws_.sort()

p = [0] * 27
wp = [0] * 27
wpp = {}
for i in range(q):
    p[i] = ws_[i][0]
    wp[i] = ws_[i][1]
    wpp[p[i]] = wp[i]

cntdy = 0
yd = []
dy = [0] * 257
for i in range(1 << k):
    if bin(i).count('1') == x:
        yd.append(i)
        dy[i] = cntdy
        cntdy += 1

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
        zyj2 = zyj2 * ksmii(zyj, to - nowpos)

    nm = zyj
    for j in range(max(nowpos, to), min(n - x + 1, p[i])):
        for ii in range(cntdy):
            jj = yd[ii]
            if jj & 1:
                for l in range(1, k + 1):
                    if not (jj & (1 << l)):
                        nm.mat[ii][dy[(jj + (1 << l)) >> 1]] += wpp[j + l]
        zyj2 = zyj2 * nm
        nm = zyj

    nowpos = min(n - x + 1, p[i])

if n - x + 1 - nowpos > 0:
    zyj2 = zyj2 * ksmii(zyj, n - x + 1 - nowpos)

print(zyj2.mat[0][0])
