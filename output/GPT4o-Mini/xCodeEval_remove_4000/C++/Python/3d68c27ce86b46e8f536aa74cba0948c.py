import sys
import random
from collections import defaultdict
from math import gcd, sqrt

INPUT_FILE = "input.txt"
OUTPUT_FILE = "output.txt"

class Popu:
    def __init__(self, n, p):
        self.v = [0] * n
        self.q = set()
        self.p = p
        self.z = 0
        for i in range(n):
            if i != p:
                self.add(i)

    def add(self, t):
        self.q.add((self.v[t], t))

    def remove(self, t):
        self.q.remove((self.v[t], t))

    def max_el(self):
        return max(self.q)[1]

    def is_popu(self):
        return self.v[self.max_el()] >= self.z

    def change(self, t, val):
        if t == self.p:
            self.z += val
        else:
            self.remove(t)
            self.v[t] += val
            self.add(t)

def another_main():
    n = int(sys.stdin.readline().strip())
    if n == 1:
        print("0")
    else:
        v = list(map(int, sys.stdin.readline().strip().split()))
        v = [x - 1 for x in v]
        q = [0] * n
        qq = [0] * n
        mx = (0, -1)

        for i in range(n):
            q[v[i]] += 1
            mx = max(mx, (q[v[i]], v[i]))

        p = mx[1]
        u = [[] for _ in range(n + 1)]
        for i in range(n):
            if i != p:
                u[q[i]].append(i)

        uu = []
        for i in range(n, -1, -1):
            if u[i]:
                uu.append(i)

        last = 0
        leftmost = [[n + 1] * (q[i] + 1) for i in range(n)]
        for i in range(n):
            leftmost[i][0] = 0

        ans = 0
        for i in range(n):
            if v[i] != p:
                q[v[i]] += 1

        for y in range(min(n, 100)):
            if y != p:
                g = [-1]
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

        print(ans)

def main():
    sys.stdin = open(INPUT_FILE, "r")
    sys.stdout = open(OUTPUT_FILE, "w")

    another_main()

if __name__ == "__main__":
    main()
