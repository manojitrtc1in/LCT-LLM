from collections import deque
from itertools import islice
import sys

def c132():
    str_input = input().strip()
    n = int(input().strip())
    
    soln = [[0] * (n + 1) for _ in range(2)]
    id12 = [[0] * (n + 1) for _ in range(2)]

    if str_input[-1] == 'F':
        for j in range(n + 1):
            soln[0][j] = 0 if j & 1 else 1
    else:
        for j in range(n + 1):
            soln[0][j] = 1 if j & 1 else 0

    soln[1] = soln[0][:]

    for char in reversed(str_input[1:]):
        id12, soln = soln, id12
        if char == 'F':
            soln[0][0] = 1 + id12[0][0]
            soln[1][0] = 1 + id12[1][0]

            for j in range(1, n + 1):
                soln[0][j] = max(1 + id12[0][j], -id12[1][j - 1])
                soln[1][j] = min(1 + id12[1][j], -id12[0][j - 1])
        else:
            soln[0][0] = -id12[1][0]
            soln[1][0] = -id12[0][0]

            for j in range(1, n + 1):
                soln[0][j] = max(-id12[1][j], 1 + id12[0][j - 1])
                soln[1][j] = min(-id12[0][j], 1 + id12[1][j - 1])

    return max(soln[0][n], -soln[1][n])

def sched(i, m, rev, deps, load):
    val = 0
    unload = []

    for n in range(len(m), 0, -1):
        i = (i + 1) % 3
        val += 1
        while load[i]:
            n -= len(load[i])
            unload = load[i][:]
            load[i] = []

            for j in unload:
                for k in rev[j]:
                    deps[k] -= 1
                    if deps[k] == 0:
                        load[m[k]].append(k)

    return val - 1

def a213():
    m = list(map(int, input().strip().split()))
    m = [x - 1 for x in m]  # Adjusting for 0-based index

    n = len(m)
    rev = [[] for _ in range(n)]
    deps = [0] * n

    for j in range(n):
        xs = list(map(int, input().strip().split()))
        deps[j] = len(xs)
        for i in xs:
            rev[i - 1].append(j)

    load = [[] for _ in range(3)]
    for j in range(n):
        if deps[j] == 0:
            load[m[j]].append(j)

    return min(sched(0, m, rev, deps, load),
               sched(1, m, rev, deps, load),
               sched(2, m, rev, deps, load)) + n

if __name__ == "__main__":
    print(a213())
