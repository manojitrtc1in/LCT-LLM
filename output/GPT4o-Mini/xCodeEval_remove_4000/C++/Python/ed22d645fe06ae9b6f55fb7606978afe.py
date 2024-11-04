import sys
from collections import defaultdict

def read_int():
    return int(sys.stdin.readline().strip())

def read_str():
    return sys.stdin.readline().strip()

N = int(1e2) + 9

a = [0] * N
c = [0] * N
t = [0] * N
tt = [(0, 0)] * N
b, d = map(int, sys.stdin.readline().strip().split())
a = read_str()
c = read_str()
an = len(a)
cn = len(c)

for i in range(cn):
    k = t[i]
    for j in range(an):
        if a[j] == c[(i + k) % cn]:
            k += 1

tt = [(-1, -1)] * N
s = 0
bj = False

for i in range(b):
    s += t[s % cn]

    if bj:
        continue

    if tt[s % cn][0] == -1:
        tt[s % cn] = (i, s)
    else:
        r = i - tt[s % cn][0]
        s += (s - tt[s % cn][1]) * ((b - i) // r)
        i += ((b - i) // r) * r
        bj = True

s //= (cn * d)
print(s)
