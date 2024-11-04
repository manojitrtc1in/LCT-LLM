import sys
from typing import List, Tuple

def can(n: int, s: str, o: List[List[int]], ind: List[int], nxt: List[List[int]]) -> bool:
    if n == 1:
        return True
    
    x = n // 2
    y = (n + 1) // 2
    
    if not can(x, s, o, ind, nxt) or not can(y, s, o, ind, nxt):
        return False
    
    p0 = nxt[0][0]
    p1 = nxt[0][1]
    
    if p0 == len(s) or ind[p0] + x - 1 >= len(o[0]):
        p0 = len(s)
    else:
        p0 = o[0][ind[p0] + x - 1]
    
    if p1 == len(s) or ind[p1] + y - 1 >= len(o[1]):
        p1 = len(s)
    else:
        p1 = o[1][ind[p1] + y - 1]
    
    p0 = min(p0, p1)
    
    if p0 == len(s):
        return False
    
    nxt[0] = [p0 + 1, p0 + 1]
    
    return True

def go(n: int, s: str, o: List[List[int]], ind: List[int], nxt: List[List[int]]) -> bool:
    if not can(n, s, o, ind, nxt):
        return False
    
    if nxt[0][0] != len(s):
        return False
    
    it = 0
    id = [i for i in range(n)]
    
    def gen(l: int, r: int) -> None:
        nonlocal it
        
        if l == r:
            return
        
        m = (l + r - 1) // 2
        gen(l, m)
        gen(m + 1, r)
        
        a = l
        b = m + 1
        c = l
        
        while a <= m and b <= r:
            if s[it] == '0':
                mas[c] = id[a]
                a += 1
            else:
                mas[c] = id[b]
                b += 1
            c += 1
            it += 1
        
        while a <= m:
            mas[c] = id[a]
            a += 1
            c += 1
        
        while b <= r:
            mas[c] = id[b]
            b += 1
            c += 1
        
        for i in range(l, r + 1):
            id[i] = mas[i]
    
    mas = [0] * n
    gen(0, n - 1)
    
    p = [0] * n
    for i in range(n):
        p[id[i]] = i
    
    print(n)
    print(" ".join(str(i + 1) for i in p))
    sys.exit(0)

def solve() -> None:
    counter = [0, 0]
    o = [[], []]
    ind = []
    nxt = [[0, 0] for _ in range(len(s) + 1)]
    
    for i in range(len(s)):
        c = int(s[i])
        counter[c] += 1
        ind.append(len(o[c]))
        o[c].append(i)
    
    nxt[len(s)] = [len(s), len(s)]
    
    for i in range(len(s) - 1, -1, -1):
        nxt[i][0] = nxt[i + 1][0]
        nxt[i][1] = nxt[i + 1][1]
        nxt[i][int(s[i])] = i
    
    l = 0
    r = 1e5 + 10
    
    while r - l > 1:
        m = (l + r) // 2
        if go(m, s, o, ind, nxt):
            l = m
        else:
            r = m
    
    go(l, s, o, ind, nxt)

if __name__ == "__main__":
    s = input().strip()
    solve()
