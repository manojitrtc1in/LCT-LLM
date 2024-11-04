import sys
from collections import deque
from typing import List, Tuple, Dict, Any, Union


def touch_pos(r: int, c: int, d: int, len: List[int], dist: List[List[int]], q: deque) -> Tuple[int, int]:
    pos = (r, min(c, len[r]))
    if d < dist[r][pos[1]]:
        dist[r][pos[1]] = d
        q.append(pos)
    return pos


def c253() -> None:
    len = list(map(int, input().split()))
    nrow = len(len)
    first = tuple(map(int, input().split()))
    last = tuple(map(int, input().split()))

    first = (first[0] - 1, min(first[1] - 1, len[first[0]] - 1))
    last = (last[0] - 1, min(last[1] - 1, len[last[0]] - 1))

    if first == last:
        print(0)
        return

    INF = sys.maxsize
    dist = [[INF] * (len[j] + 1) for j in range(nrow)]
    q = deque()
    q.append(first)
    dist[first[0]][first[1]] = 0

    while q:
        r, c = q.popleft()
        d = dist[r][c] + 1

        if 0 < r and last == touch_pos(r - 1, c, d, len, dist, q):
            break

        if r + 1 < nrow and last == touch_pos(r + 1, c, d, len, dist, q):
            break

        if 0 < c and last == touch_pos(r, c - 1, d, len, dist, q):
            break

        if c < len[r] and last == touch_pos(r, c + 1, d, len, dist, q):
            break

    print(dist[last[0]][last[1]])


def d34() -> None:
    n, fst, lst = map(int, input().split())
    fst -= 1
    lst -= 1

    a = list(map(int, input().split()))
    a = [x - 1 for x in a]

    adj = [[] for _ in range(n)]
    for j in range(n - 1):
        u = j if j < fst else j + 1
        v = a[j]
        adj[u].append(v)
        adj[v].append(u)

    NIL = n + 1
    tag = [NIL] * n
    q = deque()

    tag[lst] = lst
    q.append(lst)
    while q:
        u = q.popleft()

        for v in adj[u]:
            if tag[v] == NIL:
                tag[v] = u
                q.append(v)

    tag.pop(lst)
    tag = [x + 1 for x in tag]
    print(*tag)


def b140() -> None:
    n = int(input())
    l = [list(map(int, input().split())) for _ in range(n)]
    xs = list(map(int, input().split()))

    a = [0] * n
    b = [0] * n
    a[0] = xs[0]
    b[0] = sys.maxsize

    for j in range(1, n):
        if xs[j] < a[j - 1]:
            b[j] = a[j - 1]
            a[j] = xs[j]
        else:
            a[j] = a[j - 1]
            b[j] = min(b[j - 1], xs[j])

    pos = [0] * (n + 1)
    for j in range(n):
        pos[xs[j]] = j

    soln = []
    for j in range(n):
        for i in range(n):
            if l[j][i] != j + 1:
                k = pos[l[j][i]]
                run_min = a[k] if a[k] != j + 1 else b[k]

                if l[j][i] <= run_min:
                    soln.append(l[j][i])
                    break

    print(*soln)


def a51() -> int:
    n = int(input())

    xs = []
    for _ in range(n):
        a, b = map(int, input().split())
        xs.append([a // 10, a % 10, b % 10, b // 10])
        if _ + 1 != n:
            input()

    for a in xs:
        b = a[:]
        for _ in range(4):
            a = a[1:] + [a[0]]
            if a < b:
                b = a
        a = b

    xs.sort()
    return len(set(map(tuple, xs)))


def b444() -> None:
    n, d, x = map(int, input().split())
    a = list(range(1, n + 1))
    b = [False] * n

    for _ in range(n):
        x = (x * 37 + 10007) % 1000000007
        a[_], a[x % (_ + 1)] = a[x % (_ + 1)], a[_]
    b[:d] = [True] * d

    soln = [0] * n

    idx = [j for j in range(n) if b[j]]
    heap = []
    budget = 1000000

    for j in range(n):
        heap.append((a[j], j))
        if budget < len(heap) * len(idx):
            heap.sort()
            heap.pop(0)

    while heap:
        i, val = heap.pop(0)
        for j in idx:
            if j + i < n:
                soln[j + i] = val
            else:
                break

    for j in range(n):
        if soln[j] == 0:
            for i in idx:
                if j < i:
                    break
                else:
                    soln[j] = max(soln[j], a[j - i])

    print(*soln, sep="\n")


def main() -> None:
    b444()


if __name__ == "__main__":
    main()
