from sys import stdin, stdout
from collections import namedtuple

Point = namedtuple('Point', ['x', 'y'])

def read_int():
    return int(stdin.readline().strip())

def read_ints():
    return list(map(int, stdin.readline().strip().split()))

def solve():
    n = read_int()
    p = [Point(*read_ints()) for _ in range(n)]
    cur = 0

    for i in range(n):
        if (p[i].x < p[cur].x) or (p[i].x == p[cur].x and p[i].y < p[cur].y):
            cur = i

    s = stdin.readline().strip() + 'R'
    ans = [cur]
    used = [False] * n

    for i in range(n - 1):
        used[cur] = True
        zero = p[cur]
        a = [Point(p[j].x - zero.x, p[j].y - zero.y) for j in range(n)]
        idx = -1

        for j in range(n):
            if not used[j]:
                if idx == -1:
                    idx = j
                else:
                    if s[i] == 'R' and a[j] < a[idx]:
                        idx = j
                    if s[i] == 'L' and a[idx] < a[j]:
                        idx = j

        cur = idx
        ans.append(cur)

    stdout.write(' '.join(str(x + 1) for x in ans) + '\n')

if __name__ == "__main__":
    solve()
