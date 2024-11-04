import sys
import math
from collections import defaultdict
from itertools import combinations

def take(k, perm, points):
    n = len(points)
    for i in range(n):
        if points[i][1] == k:
            points[i], points[-1] = points[-1], points[i]
    perm.append(points.pop())

def main():
    input = sys.stdin.read
    data = input().splitlines()
    
    n = int(data[0])
    p = [tuple(map(int, line.split())) + (i,) for i, line in enumerate(data[1:n+1])]
    s = data[n+1]
    
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
            if ((p[best][0] - q) % (p[j][0] - q) > 0) == (s[i] == 'R'):
                best = j
        take(p[best][1], perm, p)
    
    take(p[0][1], perm, p)
    
    print(' '.join(str(x[1] + 1) for x in perm))

if __name__ == "__main__":
    main()
