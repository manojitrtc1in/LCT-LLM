import sys
import random
from collections import deque, defaultdict
from itertools import islice

class ScopeTimer:
    def __init__(self, msg=""):
        self.tic = self.current_time()
        self.msg = msg

    def __del__(self):
        toc = self.current_time()
        dt = toc - self.tic
        print(f'\n{self.msg}\n\telapsed time: {dt:.2f} sec')

    @staticmethod
    def current_time():
        return random.random()  # Placeholder for actual time measurement

def touch_pos(r, c, d, lengths, dist, q):
    pos = (r, min(c, lengths[r]))
    if d < dist[r][pos[1]]:
        dist[r][pos[1]] = d
        q.append(pos)
    return pos

def c253():
    with open("input.txt", "r") as fin, open("output.txt", "w") as fout:
        lengths = list(map(int, fin.readline().strip().split()))
        nrow = len(lengths)
        first = tuple(map(int, fin.readline().strip().split()))
        last = tuple(map(int, fin.readline().strip().split()))

        first = (first[0] - 1, first[1] - 1)
        last = (last[0] - 1, last[1] - 1)

        if first == last:
            fout.write("0\n")
            return

        INF = float('inf')
        dist = [[INF] * (lengths[j] + 1) for j in range(nrow)]
        q = deque()
        q.append(first)
        dist[first[0]][first[1]] = 0

        while q:
            r, c = q.popleft()
            d = dist[r][c] + 1

            if r > 0 and touch_pos(r - 1, c, d, lengths, dist, q) == last:
                break
            if r + 1 < nrow and touch_pos(r + 1, c, d, lengths, dist, q) == last:
                break
            if c > 0 and touch_pos(r, c - 1, d, lengths, dist, q) == last:
                break
            if c < lengths[r] and touch_pos(r, c + 1, d, lengths, dist, q) == last:
                break

        fout.write(f"{dist[last[0]][last[1]]}\n")

def d34():
    n, fst, lst = map(int, input().strip().split())
    fst -= 1
    lst -= 1

    a = list(map(int, input().strip().split()))
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
    print(" ".join(str(x + 1) for x in tag))

def b140():
    n = int(input().strip())
    l = [list(map(int, input().strip().split())) for _ in range(n)]
    xs = list(map(int, input().strip().split()))

    a = [xs[0]]
    b = [float('inf')]

    for j in range(1, n):
        if xs[j] < a[j - 1]:
            b.append(a[j - 1])
            a.append(xs[j])
        else:
            a.append(a[j - 1])
            b.append(min(b[j - 1], xs[j]))

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

    print(" ".join(map(str, soln)))

def a51():
    n = int(input().strip())
    xs = [list(map(int, input().strip().split())) for _ in range(n)]

    for a in xs:
        b = a.copy()
        for i in range(4):
            a = a[1:] + a[:1]  # Rotate
            if a < b:
                b = a
        a[:] = b

    xs = sorted(set(tuple(x) for x in xs))
    return len(xs)

def b444():
    n, d, x = map(int, input().strip().split())
    a = list(range(1, n + 1))
    b = [False] * n

    for i in range(n):
        x = (x * 37 + 10007) % 1000000007
        a[i], a[x % (i + 1)] = a[x % (i + 1)], a[i]

    for i in range(n):
        x = (x * 37 + 10007) % 1000000007
        b[i], b[x % (i + 1)] = b[x % (i + 1)], b[i]

    soln = [0] * n
    idx = [j for j in range(n) if b[j]]

    min_heap = []
    budget = 1000000

    for j in range(n):
        min_heap.append((a[j], j))
        if len(min_heap) > budget:
            min_heap.sort()
            min_heap.pop(0)

    heap = []
    while min_heap:
        heap.append(min_heap.pop())
    
    while heap:
        val, i = heap.pop()
        for j in idx:
            if j + i < n:
                soln[j + i] = max(soln[j + i], val)
            else:
                break

    for j in range(n):
        if soln[j] == 0:
            for i in idx:
                if j < i:
                    break
                else:
                    soln[j] = max(soln[j], a[j - i])

    print("\n".join(map(str, soln)))

def main():
    b444()

if __name__ == "__main__":
    main()