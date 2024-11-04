import math

def angdis_cmp(a, b):
    p = a[0] * b[1] - a[1] * b[0]
    if p:
        return p > 0
    else:
        return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1]

def convex_hull(a):
    n = len(a)
    if n:
        mt = min(range(n), key=lambda i: (a[i], -a[i][1], a[i][0]))
        d = a[mt]
        a = [a[i] - d for i in range(n)]
        idx = sorted(range(n), key=lambda i: (a[i], -a[i][1], a[i][0]))
        h = [idx[0]]
        for i in idx[1:]:
            temp = a[i]
            if len(h) >= 2:
                if are_parallel(a[h[-1]], temp):
                    h.pop()
                while len(h) >= 3 and npocs(a[h[-2]], a[h[-1]], temp):
                    h.pop()
            h.append(i)
        a = [a[i] + d for i in range(n)]
        return h
    else:
        return []

def count_tro(r):
    return 32 - int(math.log2(r))

def unite_seg(p1, p2, n):
    if p1[0] == -1 or p2[0] == -1:
        return -1, -1
    np1 = 0, raz(p1[1], p1[0], n)
    np2 = raz(p2[0], p1[0], n), raz(p2[1], p1[0], n)
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

def segment(l, r):
    if l == -1 or r == -1:
        return -1, -1
    szz = raz(r, l, n)
    if l == r:
        return sp[0][l]
    g = count_tro(szz) - 1
    return unite_seg(sp[g][l], sp[g][(r + 1 - (1 << g)) % n], n)

n = int(input())
if n == 1:
    print("0")
    exit()
r = list(map(int, input().split()))
zz = count_tro(n) - 1
v = [0] * zz
prs = [0] * n

for i in range(n):
    if r[i] >= n - 1:
        prs[i] = -1, -1
    else:
        prs[i] = unite_seg(raz(i, r[i], n), i, sum(i, r[i], n), n)

v[0] = prs

for i in range(1, zz):
    new_prs = [0] * n
    for j in range(n):
        pairr = segment(j, j)
        new_prs[j] = segment(pairr[0], pairr[1])
    v[i] = new_prs

for i in range(n):
    my_pr = i, i
    ans = 0
    for j in range(zz - 1, -1, -1):
        new_pr = segment(my_pr[0], my_pr[1])
        if new_pr[0] != -1:
            ans += 1 << j
            my_pr = new_pr
    print(ans + 1, end=' ')
print()
