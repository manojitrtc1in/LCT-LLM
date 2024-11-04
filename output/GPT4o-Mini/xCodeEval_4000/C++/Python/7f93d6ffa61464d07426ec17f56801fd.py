import sys
from bisect import bisect_left

MAX = 1000000
pr = [2, 3, 5, 7, 11, 13, 17, 19]
num = [
    [0, 1], [0, 2], [0, 3], [0, 4], [0, 5], [0, 6],
    [1, 0], [1, 1], [1, 2], [1, 3], [1, 4], [1, 5],
    [1, 6], [1, 7], [2, 0], [2, 1], [2, 2], [2, 3],
    [2, 4], [2, 5], [2, 6], [2, 7], [3, 0], [3, 1],
    [3, 2], [3, 3], [3, 4], [3, 5], [3, 6], [3, 7],
    [4, 0], [4, 1], [4, 2], [4, 3], [4, 4], [4, 5],
    [4, 6], [4, 7], [5, 0], [5, 1], [5, 2], [5, 3],
    [5, 4], [5, 5], [5, 6], [5, 7], [6, 0], [6, 1],
    [6, 2], [6, 3], [6, 4], [6, 5], [6, 6], [6, 7],
    [7, 0], [7, 2], [7, 3], [7, 4], [7, 5], [7, 6],
    [7, 7], [7, 8], [8, 1], [8, 3], [8, 4], [8, 5],
    [8, 6], [8, 7], [8, 8], [8, 9], [9, 3], [9, 5],
    [9, 6], [9, 7], [9, 8], [9, 9], [9, 10], [10, 7]
]

L = []
ans = [[0] * 300 for _ in range(300)]
cnt = 0

def init(i, x, la, v):
    global cnt
    L.append(v.copy())
    cnt += 1
    sz = len(v)
    v.append(0)
    for d in range(1, la + 1):
        if x // pr[i] > 0:
            x //= pr[i]
            v[sz] += 1
            init(i + 1, x, d, v)
    v.pop()

mp = [0] * (MAX + 1)

def get(x):
    v = []
    while x > 1:
        p = mp[x]
        c = 0
        while x % p == 0:
            x //= p
            c += 1
        v.append(-c)
    v.sort()
    for i in range(len(v)):
        v[i] *= -1
    return bisect_left(L, v)

def main():
    global cnt
    v = []
    init(0, MAX, 1 << 30, v)
    for i in range(2, MAX + 1):
        if mp[i] == 0:
            for j in range(i, MAX + 1, i):
                if mp[j] == 0:
                    mp[j] = i
    i = 0
    j = 1
