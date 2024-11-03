import sys
from typing import List, Tuple, Set

def add(t: int, pop: 'Population') -> None:
    pop.q.add((pop.v[t], t))

def remove(t: int, pop: 'Population') -> None:
    pop.q.remove((pop.v[t], t))

class Population:
    def __init__(self, n: int, p: int):
        self.v = [0] * n
        self.p = p
        self.z = 0
        self.q = set()
        for i in range(n):
            if i != p:
                add(i, self)

    def max_el(self) -> int:
        return max(self.q, key=lambda x: x[0])[1]

    def is_popu(self) -> bool:
        return self.v[self.max_el()] >= self.z

    def change(self, t: int, val: int) -> None:
        if t == self.p:
            self.z += val
        else:
            remove(t, self)
            self.v[t] += val
            add(t, self)

def find_max_gap(n: int, v: List[int]) -> int:
    if n == 1:
        return 0
    else:
        v = [x - 1 for x in v]
        q = [0] * n
        mx = (0, 0)
        for i in range(n):
            q[v[i]] += 1
            mx = max(mx, (q[v[i]], v[i]))
        p = mx[1]
        u = [[] for _ in range(n + 1)]
        for i in range(n):
            if i != p:
                u[q[i]].append(i)
        uu = [i for i in range(n + 1) if u[i]]
        last = 0
        leftmost = [[n + 1] * (q[i] + 1) for i in range(n)]
        leftmost[p][0] = 0
        ans = 0
        for i in range(n):
            if v[i] != p:
                q[v[i]] += 1
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

def main() -> int:
    n = int(input())
    v = list(map(int, input().split()))
    return find_max_gap(n, v)

if __name__ == '__main__':
    print(main())
    sys.stdout.flush()
