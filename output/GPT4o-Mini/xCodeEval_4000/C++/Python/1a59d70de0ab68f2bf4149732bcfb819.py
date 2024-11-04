import sys
import itertools
from collections import defaultdict, deque
from math import isinf, isnan, sqrt
from functools import reduce

class ScopeTimer:
    def __init__(self, msg=""):
        self.tic = clock()
        self.msg = msg

    def __del__(self):
        toc = clock()
        dt = 1000 * (toc - self.tic) / CLOCKS_PER_SEC
        mil = dt % 1000
        sec = (dt // 1000) % 60
        min = (dt // 60000) % 60
        hrs = (dt // 3600000)

        print(f'\n{self.msg}\n\telapsed time: ', end='')
        if hrs: print(f'{hrs} hrs, ', end='')
        if min: print(f'{min} min, ', end='')
        if sec: print(f'{sec} sec, ', end='')
        print(f'{mil} mil-sec')

def get_gain(xs, l, r):
    length = len(xs) - l - r
    return xs[l + length // 2] if length % 2 else 0

def c388():
    n = int(input())
    xs = [list(map(int, input().split())) for _ in range(n)]

    k = sum(len(row) for row in xs)
    print(k)

    acc = sum(sum(row) for row in xs)
    print(acc)

    left = [0] * n
    right = [0] * n
    left_acc = 0

    for j in range(k):
        imax = 0
        while left[imax] + right[imax] == len(xs[imax]):
            imax += 1

        val = get_gain(xs[imax], left[imax], right[imax])

        for i in range(imax + 1, n):
            if left[i] + right[i] < len(xs[i]):
                g = get_gain(xs[i], left[i], right[i])
                if val < g:
                    val = g
                    imax = i

        if j % 2:
            right[imax] += 1
        else:
            left_acc += xs[imax][left[imax]]
            left[imax] += 1

    print(left_acc, acc - left_acc)

def c20():
    n, m = map(int, input().split())
    adj = defaultdict(list)

    for _ in range(m):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append((v, w))
        adj[v].append((u, w))

    INF = float('inf')
    dist = [INF] * n
    dist[0] = 0

    heap = [(0, 0)]

    while heap:
        d, u = heap.pop(0)

        if dist[u] == d:
            for v, w in adj[u]:
                if d + w < dist[v]:
                    dist[v] = d + w
                    heap.append((dist[v], v))
                    heap.sort()

    if dist[n - 1] != INF:
        path = []
        u = n - 1

        while u != 0:
            path.append(u)
            for v, w in adj[u]:
                if dist[v] + w == dist[u]:
                    u = v
                    break
        path.append(0)

        print(" ".join(str(x + 1) for x in path[::-1]))
    else:
        print(-1)

def b319():
    xs = list(map(int, input().split()))
    n = len(xs)

    m = defaultdict(int)
    m[xs[0]] = 0
    val = 0

    for j in range(1, n):
        iter_ = next((key for key in m if key >= xs[j]), None)
        if iter_ is not None:
            m[iter_] += 1
            next_iter = next((key for key in m if key > iter_), None)
            if next_iter is not None and m[iter_] == m[next_iter]:
                del m[next(iter(m))]
            else:
                del m[iter_]
        else:
            val = max(val, next(iter(m.values())))
            m.clear()
        m[xs[j]] = 0

    val = max(val, next(iter(m.values())))
    return val

def b41():
    n, b = map(int, input().split())
    a = list(map(int, input().split()))

    m = [0] * n
    for j in range(n - 1, -1, -1):
        m[j] = max(m[j + 1] if j + 1 < n else 0, a[j])

    val = b
    for j in range(n):
        val = max(val, b % a[j] + b // a[j] * m[j])

    return val

def b99():
    xs = list(map(int, input().split()))
    i = min(xs)
    j = max(xs)

    if i == j:
        return "Exemplary pages."
    elif (i + j) % 2:
        return "Unrecoverable configuration."
    else:
        v = (j - i) // 2
        i += v
        j -= v

        if min(xs) == max(xs):
            return f"{v} ml. from cup #{xs.index(min(xs)) + 1} to cup #{xs.index(max(xs)) + 1}."
        else:
            return "Unrecoverable configuration."

def b70():
    n = int(input())
    input()  # Skip the first line
    str_ = input()

    xs = []
    i = 0
    while i < len(str_):
        while i < len(str_) and str_[i] == ' ':
            i += 1

        j = i
        while j < len(str_) and str_[j] not in '.!?':
            j += 1

        if j < len(str_):
            j += 1

        if j != i:
            xs.append(j - i)

        i = j

    if any(x < n for x in xs):
        print("Impossible")
    else:
        k = 0
        i = 0
        while i < len(xs):
            k += 1
            length = xs[i]
            while i + 1 < len(xs) and length + xs[i + 1] < n:
                length += 1 + xs[i + 1]
                i += 1
        print(k)

def count_unique(xs, k):
    return len(set(a[k] for a in xs))

def count_bars(a):
    return bin(a).count('1')

def a442():
    cards = input().split()
    cnt_unq_char = count_unique(cards, 0)
    cnt_unq_digit = count_unique(cards, 1)

    char_map = {'R': 0, 'G': 1, 'B': 2, 'Y': 3, 'W': 4}
    xs = [(1 << char_map[a[0]], 1 << (int(a[1]) - 1)) for a in cards]

    val = cnt_unq_char + cnt_unq_digit - 2

    for i in range(1 << 6):
        icnt = count_bars(i)
        if icnt < val:
            for j in range(1 << 6):
                jcnt = count_bars(j)
                if icnt + jcnt < val:
                    flag = True
                    for a in xs:
                        for b in xs:
                            if a != b:
                                u = (a[0] == b[0] or icnt + 1 < cnt_unq_char and not (a[0] & i) and not (b[0] & i))
                                v = (a[1] == b[1] or jcnt + 1 < cnt_unq_digit and not (a[1] & j) and not (b[1] & j))
                                if v and u:
                                    flag = False
                                    break
                    if flag:
                        val = icnt + jcnt

    return val

def main():
    print(a442())

if __name__ == "__main__":
    main()
