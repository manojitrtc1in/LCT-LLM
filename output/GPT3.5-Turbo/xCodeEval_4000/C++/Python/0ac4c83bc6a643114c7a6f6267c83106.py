import math

def angdis_cmp(a, b):
    p = a[0] * b[1] - a[1] * b[0]
    if p:
        return p > 0
    else:
        return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]

def unite_seg(p1, p2, n):
    if p1[0] == -1 or p2[0] == -1:
        return (-1, -1)
    np1 = (0, (p1[1] - p1[0]) % n)
    np2 = ((p2[0] - p1[0]) % n, (p2[1] - p1[0]) % n)
    if np2[0] <= np2[1]:
        if np2[1] == n - 1:
            return (-1, -1)
        else:
            return ((np1[0] + p1[0]) % n, max(np1[1], np2[1]))
    else:
        if np2[0] <= np1[1] + 1:
            return (-1, -1)
        else:
            return ((np2[0] + p1[0]) % n, max(np1[1], np2[1]))

def count_tro(r):
    return 32 - int(math.log2(r))

def find_min_idx(v):
    ans = 0
    n = len(v)
    for i in range(1, n):
        if v[i] < v[ans]:
            ans = i
    return ans

def convex_hull(a):
    n = len(a)
    if n:
        mt = find_min_idx(a)
        d = a[mt]
        for i in range(n):
            a[i] = (a[i][0] - d[0], a[i][1] - d[1])

        idx = list(range(n))
        idx.sort(key=lambda x: angdis_cmp(a[x], a[idx[0]]))

        h = [idx[0]]
        for it in idx[1:]:
            temp = a[it]
            if len(h) >= 2:
                if are_parallel(a[h[-1]], temp):
                    h.pop()
                while len(h) >= 3 and npocs(a[h[-2]], a[h[-1]], temp):
                    h.pop()
            h.append(it)

        for i in range(n):
            a[i] = (a[i][0] + d[0], a[i][1] + d[1])
        return h
    else:
        return []

def segment(l, r):
    if l == -1 or r == -1:
        return (-1, -1)
    szz = (r - l) % n
    if l == r:
        return sp[0][l]
    g = count_tro(szz) - 1
    return unite_seg(sp[g][l], sp[g][(r + 1 - (1 << g)) % n], n)

def construct(v):
    n = len(v)
    r = count_tro(n - 1)
    sp = [[(0, 0) for _ in range(n)] for _ in range(r)]
    for i in range(n):
        sp[0][i] = v[i]
    for i in range(1, r):
        for j in range(n):
            p1 = sp[i - 1][j]
            p2 = sp[i - 1][(j + (1 << (i - 1))) % n]
            sp[i][j] = unite_seg(p1, p2, n)
    return sp

n = int(input())
if n == 1:
    print("0")
    exit()
r = list(map(int, input().split()))
zz = count_tro(n) + 1
v = construct(r)
prs = []

for i in range(n):
    if r[i] >= n - 1:
        prs.append((-1, -1))
    else:
        prs.append(unite_seg(((i - r[i]) % n, i), (i, (i + r[i]) % n), n))

sp = construct(prs)

for i in range(n):
    my_pr = (i, i)
    ans = 0
    for j in range(zz - 1, -1, -1):
        new_pr = segment(my_pr[0], my_pr[1])
        if new_pr[0] != -1:
            ans += (1 << j)
            my_pr = new_pr
    print(ans + 1, end=' ')
print()
