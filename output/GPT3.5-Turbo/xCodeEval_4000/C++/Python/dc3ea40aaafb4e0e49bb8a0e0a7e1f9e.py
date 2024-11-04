import sys
from typing import List, Tuple
from collections import defaultdict
from heapq import heappop, heappush

def read_int() -> int:
    return int(sys.stdin.readline().strip())

def read_ints() -> List[int]:
    return list(map(int, sys.stdin.readline().strip().split()))

def read_tuple() -> Tuple[int, int]:
    return tuple(map(int, sys.stdin.readline().strip().split()))

def read_tuples() -> List[Tuple[int, int]]:
    return [read_tuple() for _ in range(n)]

def main() -> None:
    x, k, n, q = read_ints()
    c = read_ints()
    ws = read_tuples()
    ws.sort()
    wpp = defaultdict(int)
    for p, wp in ws:
        wpp[p] = wp
    
    MASK = (1 << k)
    dy = [0] * 257
    cntdy = 0
    yd = [0] * 77
    p = [0] * 27
    wp = [0] * 27
    ws_ = [(0, 0)] * 27
    
    for i in range(q):
        p[i], wp[i] = ws[i]
        ws_[i] = (p[i], wp[i])
        wpp[p[i]] = wp[i]
    
    ws_.sort()
    
    for i in range(MASK):
        if bin(i).count('1') == x:
            yd[cntdy] = i
            dy[i] = cntdy
            cntdy += 1
    
    zyj = [[INF] * 77 for _ in range(77)]
    zyj2 = [[0] * 77 for _ in range(77)]
    
    for ii in range(cntdy):
        j = yd[ii]
        if j & 1:
            for l in range(1, k+1):
                if not (j >> l) & 1:
                    zyj[ii][dy[(j + (1 << l)) >> 1]] = c[l]
        else:
            zyj[ii][dy[j >> 1]] = 0
    
    nowpos = 1
    
    for i in range(q):
        to = min(n - x + 1, p[i] - k - 1)
        
        if to - nowpos > 0:
            zyj2 = matrix_multiply(zyj2, matrix_power(zyj, to - nowpos))
        
        nm = [row[:] for row in zyj]
        
        for j in range(max(nowpos, to), min(n - x + 1, p[i])):
            for ii in range(cntdy):
                jj = yd[ii]
                if jj & 1:
                    for l in range(1, k+1):
                        if not (jj >> l) & 1:
                            nm[ii][dy[(jj + (1 << l)) >> 1]] += wpp[j + l]
            
            zyj2 = matrix_multiply(zyj2, nm)
            nm = [row[:] for row in zyj]
        
        nowpos = min(n - x + 1, p[i])
    
    if n - x + 1 - nowpos > 0:
        zyj2 = matrix_multiply(zyj2, matrix_power(zyj, n - x + 1 - nowpos))
    
    print(zyj2[0][0])

def matrix_multiply(a: List[List[int]], b: List[List[int]]) -> List[List[int]]:
    n = len(a)
    m = len(b[0])
    res = [[INF] * m for _ in range(n)]
    
    for i in range(n):
        for j in range(m):
            for k in range(n):
                res[i][j] = min(res[i][j], a[i][k] + b[k][j])
    
    return res

def matrix_power(a: List[List[int]], p: int) -> List[List[int]]:
    n = len(a)
    res = [[INF] * n for _ in range(n)]
    
    for i in range(n):
        res[i][i] = 0
    
    while p > 0:
        if p & 1:
            res = matrix_multiply(res, a)
        a = matrix_multiply(a, a)
        p >>= 1
    
    return res

INF = int(1e18)

if __name__ == "__main__":
    main()
