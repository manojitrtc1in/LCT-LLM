import sys
from typing import List, Tuple

def take(k: int, perm: List[Tuple[Tuple[int, int], int]], points: List[Tuple[Tuple[int, int], int]]):
    n = len(points)
    for i in range(n):
        if points[i][1] == k:
            points[i], points[-1] = points[-1], points[i]
            break
    perm.append(points.pop())

def find_permutation(n: int, p: List[Tuple[Tuple[int, int], int]], s: str) -> List[int]:
    perm = []
    first_idx = 0
    for i in range(n):
        if p[i] < p[first_idx]:
            first_idx = i
    take(first_idx, perm, p)
    for i in range(n - 2):
        q = perm[-1][0]
        best = 0
        for j in range(1, len(p)):
            if (((p[best][0][0] - q[0]) * (p[j][0][1] - q[1])) > 0) == (s[i] == 'R'):
                best = j
        take(p[best][1], perm, p)
    take(p[0][1], perm, p)
    return [x[1] + 1 for x in perm]

def main():
    n = int(input())
    p = []
    for _ in range(n):
        x, y = map(int, input().split())
        p.append(((x, y), _))
    s = input()
    perm = find_permutation(n, p, s)
    print(*perm)

if __name__ == "__main__":
    main()
