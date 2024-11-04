import sys

def read_ints():
    return list(map(int, sys.stdin.readline().strip().split()))

def read_str():
    return sys.stdin.readline().strip()

b, d = read_ints()
a = read_str()
c = read_str()

an = len(a)
cn = len(c)
t = [0] * cn

for i in range(cn):
    k = t[i]
    for j in range(an):
        if a[j] == c[(i + k) % cn]:
            k += 1

