import sys
from typing import List, Tuple, Set

def add(t: int) -> None:
    q.add((v[t], t))

def remove(t: int) -> None:
    q.remove((v[t], t))

def max_el() -> int:
    return max(q, key=lambda x: x[0])[1]

def is_popu() -> bool:
    return v[max_el()] >= z

def change(t: int, val: int) -> None:
    if t == p:
        z += val
    else:
        remove(t)
        v[t] += val
        add(t)

def another_main() -> int:
    n = int(input())
    if n == 1:
        return 0
    else:
        v = list(map(int, input().split()))
        p = v.index(max(v))
        q = [0] * n
        for i in range(n):
            q[v[i]] += 1
        mx = max(enumerate(q), key=lambda x: x[1])
        p = mx[0]
        u = [[] for _ in range(n + 1)]
        for i in range(n):
            if i != p:
                u[q[i]].append(i)
        uu = [i for i in range(n, -1, -1) if u[i]]
        last = 0
        leftmost = [[n + 1] * (q[i] + 1) for i in range(n)]
        leftmost[p][0] = 0
        ans = 0
        for y in range(min(n, 100)):
            if y != p:
                g = [-1] * (n + 1)
                b = 0
                for i in range(n):
                    if v[i] == p:
                        ans = max(ans, i - g[len(g) - b - 1] - 1)
                        if b > 0:
                            b -= 1
                        else:
                            g.append(i)
                    elif v[i] == y:
                        b += 1
                ans = max(ans, n - g[len(g) - b - 1] - 1)
        return ans

if __name__ == '__main__':
    AMR = another_main()
    print(AMR)
    sys.stdout.flush()
